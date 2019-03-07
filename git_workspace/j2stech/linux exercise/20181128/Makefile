CC = gcc
CFLAGS = -W -Wall 
TARGET = db_insert_server
OBJECTS = c_thread_server.o db_con_insert.o 

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ -pthread $(mysql_config --libs)

clean :
	rm *.o db_insert_server 
