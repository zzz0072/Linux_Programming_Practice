CFLAGS=-Wall -Werror -g
TARGET=hello retrun_status
OBJS=$(patsubst %, %.o, $(TARGET))

all: $(TARGET)

%.o: %.c
	$(CC) -o $(patsubst %.o, %, $@) $^

test: $(TARGET)
	./retrun_status 147

clean:
	rm *.o *~ $(TARGET) -f
