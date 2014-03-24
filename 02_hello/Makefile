CFLAGS=-Wall -Werror -g
TARGET=hello return_status
OBJS=$(patsubst %, %.o, $(TARGET))

all: $(TARGET)

%.o: %.c
	$(CC) -o $(patsubst %.o, %, $@) $^

test: $(TARGET)
	./return_status 147

clean:
	rm *.o *~ $(TARGET) -f
