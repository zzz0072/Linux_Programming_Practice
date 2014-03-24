CFLAGS=-Wall -Werror -g
TARGET=hello
OBJS=$(patsubst %, %.o, $(TARGET))

all: $(OBJS)

%.o: %.c
	$(CC) -o $(patsubst %.o, %, $@) $^


clean:
	rm *.o *~ $(TARGET) -f
