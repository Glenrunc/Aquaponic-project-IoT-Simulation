CC = g++
CFLAGS = -g -Wall -Werror -pedantic 
TARGET = main.exe
SRCS = simulateur.cpp
OBJS = $(filter-out main.o, $(SRCS:.cpp=.o))
LIBNAME = libSimulateur.so

all: $(TARGET)

$(TARGET): main.o $(LIBNAME)

	$(CC) $(CFLAGS) -o $(TARGET) main.o -L. -lSimulateur

main.o: main.cpp

	$(CC) $(CFLAGS) -I. -c main.cpp -o main.o

$(LIBNAME): $(OBJS)

	$(CC) $(CFLAGS) -shared -o  $(LIBNAME) $(OBJS)

$(OBJS) : $(SRCS)

	$(CC) $(CFLAGS) -I. -o $(OBJS) -c $(SRCS)

clean:
	rm -f *.o *.so *.exe *.txt