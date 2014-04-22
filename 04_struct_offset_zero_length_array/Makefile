TARGET=struct
OBJ=$(patsubst %, %.o, $(TARGET))
CFLAGS= -g -Wall -Werror

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(TARGET) $(OBJ)

