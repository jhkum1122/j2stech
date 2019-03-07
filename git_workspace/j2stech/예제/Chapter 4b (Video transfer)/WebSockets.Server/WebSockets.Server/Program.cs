using Fleck;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WebSockets.Server
{
    class Program
    {
        static void Main(string[] args)
        {
            // Store the subscribed clients.
            var clients = new List<IWebSocketConnection>();

            // Initialize the WebSocket server connection.
            var server = new WebSocketServer("ws://localhost:8181");

            server.Start(socket =>
            {
                socket.OnOpen = () =>
                {
                    // Add the incoming connection to our list.
                    clients.Add(socket);
                };

                socket.OnClose = () =>
                {
                    // Remove the disconnected client from the list.
                    clients.Remove(socket);
                };

                socket.OnMessage = message =>
                {
                    if (message == "get-video")
                    {
                        int NUMBER_OF_FRAMES = new DirectoryInfo("Video").GetFiles().Length;

                        // Send the video as a list of consecutive images.
                        for (int index = 0; index < NUMBER_OF_FRAMES; index++)
                        {
                            foreach (var client in clients)
                            {
                                string path = "Video/" + index + ".jpg";
                                byte[] image = ImageUtil.ToByteArray(path);

                                client.Send(image);
                            }

                            // We send 30 frames per second, so sleep for 34 milliseconds.
                            System.Threading.Thread.Sleep(270);
                        }
                    }
                    else
                    {
                        // Send the text message as-is.
                        foreach (var client in clients)
                        {
                            client.Send(message);
                        }
                    }
                };
            });

            // Wait for a key press to close...
            Console.ReadLine();
        }
    }
}
