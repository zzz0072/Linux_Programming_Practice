CFLAGS=-Wall -Werror -g
TARGET=hello retrun_status
OBJS=$(patsubst %, %.o, $(TARGET))

all: $(TARGET)

%.o: %.c
	$(CC) -o $(patsubst %.o, %, $@) $^

clean:
	rm *.o *~ $(TARGET) -f
