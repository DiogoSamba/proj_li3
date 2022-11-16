CC=gcc

CFLAGS=-Iinclude -Ofast

program: src/main.o src/drivers.o src/users.c src/rides.c src/io.c
	$(CC) $^ $(LDFLAGS) -o $@

src/main.o: src/main.c

src/drivers.o: src/drivers.c

src/users.o: src/users.c

src/rides.o: src/rides.c

src/io.o: src/io.c

clean:
	rm -f program src/*.o
