# CC =
# CFLAGS =
PREFIX = /usr

all: Programming\ Language
Programming\ Language: Programming\ Language.c
	$(CC) $(CFLAGS) "$@.c" -o "$@"
clean:
	rm -f Programming\ Language
install: Programming\ Language
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp ./Programming\ Language $(DESTDIR)$(PREFIX)/bin/Programming\ Language
	chmod 755 $(DESTDIR)$(PREFIX)/bin/Programming\ Language
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/Programming\ Language
test: Programming\ Language
	./Programming\ Language example.Programming\ Language
