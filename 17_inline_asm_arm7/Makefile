TARGET=asm
OBJ=$(addprefix $(TARGET), .o)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -rf $(TARGET) $(OBJ)
