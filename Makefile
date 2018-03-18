CC=g++

all: entity

entity:
	$(CC) -O2 -o entity src/*.cpp -l sqlite3
	mkdir -p build
	mv entity build/entity

test:
	./build/entity

clean:
	rm *.o
