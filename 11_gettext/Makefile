TARGET=test_gettext
LOCALE=zh_TW
CFLAGS=-Wall -Werror -g -DPACKAGE=\"$(TARGET)\" -DLOCALEDIR=\"/usr/share/locale\"
OBJS=$(patsubst %, %.o, $(TARGET))

all: $(TARGET).pot $(LOCALE).po $(TARGET).mo $(TARGET)

$(TARGET).pot: $(TARGET).c
	if [ ! -f $(TARGET).pot ] ; then                                \
		xgettext -o $(TARGET).pot -d $(TARGET) --add-comments=- -k_ \
					$(TARGET).c;                                    \
	fi

$(LOCALE).po: $(TARGET).pot
	if [ -f $(LOCALE).po ] ; then                               \
		msgmerge $(LOCALE).po $(TARGET).pot ;                   \
	else                                                        \
		msginit --locale=$(LOCALE) --input=$^ --no-translator ; \
	fi

$(TARGET).mo: $(LOCALE).po
	msgfmt $^ -o $@


%.o: %.c
	$(CC) -o $(patsubst %.o, %, $@) $^

clean:
	rm -f *.o *~ $(TARGET) *.po *.pot *.mo
