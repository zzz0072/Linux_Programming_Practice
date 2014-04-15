CFLAGS=-Wall -Werror -g

DATA_SRC=my_data.txt
DATA_OBJ=my_data.o

TARGET=test_obj
OBJS=$(patsubst %, %.o, $(TARGET)) $(DATA_OBJ)

BFN=elf64-x86-64
ARCH=i386


$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

$(DATA_OBJ): $(DATA_SRC)
	objcopy -I binary -O $(BFN) -B $(ARCH) --prefix-sections '.mydata' $^ $@

clean:
	rm *.o *~ $(TARGET) -f
