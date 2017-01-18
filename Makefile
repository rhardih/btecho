prefix=/usr/local

bt.o: bt.c bt.h
	gcc -c bt.c

btecho: bt.o btecho.c
	gcc -o btecho btecho.c bt.o

install: btecho
	install -m 0755 btecho $(prefix)/bin

clean:
	rm -f *.o btecho

.PHONY: clean install
.DEFAULT_GOAL := btecho
