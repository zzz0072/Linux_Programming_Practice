CFLAGS=-Wall -Werror -g
TARGET=hello1 hello2 hello3 hello4 return_status
OBJS=$(patsubst %, %.o, $(TARGET))

all: $(TARGET)

%.o: %.c
	$(CC) -o $(patsubst %.o, %, $@) $^

test: $(TARGET)
	./return_status 147

clean:
	rm *.o *~ $(TARGET) -f
