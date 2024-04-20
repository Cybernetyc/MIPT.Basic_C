TARGET = Temp
СС = gcc

$(TARGET) : main.o temp_api.o
	$(CC) main.o temp_api.o -o $(TARGET)

main.o : main.c
	$(CC) -c main.c -o main.o

temp_api.o : temp_api.c
	$(CC) -c temp_api.c -o temp_api.o

clean :
	rm $(TARGET) *.o