//
//  ViewController.m
//  WebSocketsMobile
//
//  Created by Vangos Pterneas on 5/5/13.
//  Copyright (c) 2013 LightBuzz. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // Specify the WebSocket configuration. The only necessary parameter is the URL.
    WebSocketConnectConfig *config = [WebSocketConnectConfig configWithURLString:@"ws://echo.websocket.org" origin:nil protocols:nil tlsSettings:nil headers:nil verifySecurityKey:NO extensions:nil];
    
    // Initialize the WebSocket object.
    socket = [WebSocket webSocketWithConfig:config delegate:self];
    
    // Open the WebSocket connection and start listening for events.
    [socket open];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

- (void)didOpen
{
    // JavaScript event: onopen
    NSLog(@"Open");
}

- (void)didClose:(NSUInteger)aStatusCode message:(NSString *)aMessage error:(NSError *)aError
{
    // JavaScript event: onclose
    NSLog(@"Close");
}

- (void)didReceiveError:(NSError *)aError
{
    // JavaScript event: onerror
    NSLog(@"Error");
}

- (void)didReceiveTextMessage:(NSString *)aMessage
{
    // JavaScript event: onmessage
    
    labelChat.text = [NSString stringWithFormat:@"%@\r%@", labelChat.text, aMessage];
}

- (void)didReceiveBinaryMessage:(NSData *)aMessage
{
    // JavaScript event: onmessage
}

- (IBAction)sendTapped:(id)sender
{
    [socket sendText:textMessage.text];
    
    [textMessage resignFirstResponder];
}

@end
