TARGET= genQ.out
CC= gcc
CFLAGS= -ansi -g -pedantic 
OBJS= genQ.o genQTest.o 

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
	
genQ.o: genQ.h genQ.c
	$(CC) $(CFLAGS) -c genQ.c
	
genQTest.o: genQTest.c genQ.h 
	$(CC) $(CFLAGS) -c genQTest.c
	
	
	
clean:
	rm -f $(TARGET) $(OBJS)

