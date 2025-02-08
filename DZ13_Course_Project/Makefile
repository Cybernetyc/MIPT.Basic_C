TARGET = Temp
СС = gcc

$(TARGET) : main.o temp_api.o  module_for_FILE_read.o
	$(CC) main.o temp_api.o  module_for_FILE_read.o -o $(TARGET)

main.o : main.c
	$(CC) -c main.c -o main.o

temp_api.o : temp_api.c
	$(CC) -c temp_api.c -o temp_api.o

module_for_FILE_read.o : module_for_FILE_read.c
	$(CC) -c  module_for_FILE_read.c -o module_for_FILE_read.o

clean :
	rm $(TARGET) *.o