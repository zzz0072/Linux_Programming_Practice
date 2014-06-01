TARGET=test_gettext
LOCALE=zh_TW
PO_DIR=$(shell pwd)/po
CFLAGS=-Wall -Werror -g -DPACKAGE=\"$(TARGET)\" -DLOCALEDIR=\"$(PO_DIR)\"
OBJS=$(patsubst %, %.o, $(TARGET))

all: $(TARGET).pot $(LOCALE).po $(TARGET).mo $(TARGET)

$(TARGET).pot: $(TARGET).c
	if [ ! -f $(TARGET).pot ] ; then                                \
		xgettext -o $(TARGET).pot --add-comments=- -k_ $(TARGET).c; \
	fi

$(LOCALE).po: $(TARGET).pot
	if [ -f $(LOCALE).po ] ; then                               \
		msgmerge $(LOCALE).po $(TARGET).pot ;                   \
	else                                                        \
		msginit --locale=$(LOCALE) --input=$^ --no-translator ; \
	fi

$(TARGET).mo: $(LOCALE).po
	mkdir -p $(PO_DIR)/$(LOCALE)/LC_MESSAGES
	msgfmt $^ -o $(PO_DIR)/$(LOCALE)/LC_MESSAGES/$@


%.o: %.c
	$(CC) -o $(patsubst %.o, %, $@) $^

clean:
	rm -f *.o *~ $(TARGET) *.po *.pot *.mo
	@echo To remove po directory, use: rm -rf $(PO_DIR)
