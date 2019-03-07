TARGET = http_thread_server 
OBJECTS = single_thread_http_server.o http_parser.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	gcc -o $@ $^

clean:
	rm *.o http_thread_server
