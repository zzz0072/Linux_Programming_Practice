TEST_DATA=test_data
OUT_DIR=build
TARGET=buf_bench

SRCS=$(shell ls src/*.c)
OBJS=$(patsubst %.c, $(OUT_DIR)/%.o, $(SRCS))

CFLAGS= -g -Wall -Werror -std=c99

all: $(TEST_DATA)/.generated $(OUT_DIR)/$(TARGET)

$(OUT_DIR)/$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

$(TEST_DATA)/.generated:
	mkdir -p $(TEST_DATA)
	tools/generate_test_file.sh
	touch $@

$(OUT_DIR)/%.o:%.c
	mkdir -p $(dir $@)
	$(CC) -c -o $@ $^ $(CFLAGS)

clean:
	rm -rf build

distclean: clean
	rm -rf $(TEST_DATA)
