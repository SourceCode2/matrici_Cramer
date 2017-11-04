CC = g++
CFLAGS = -Wall --std=c++11
cramer:
	$(CC) -o ciao main.cpp Fraction/Fraction.cpp cramer/cramer.cpp $(CFLAGS)
install:
	$(CC) -c Fraction/Fraction.cpp cramer/cramer.cpp
	ar r libFraction.a Fraction.o
	sudo mv libFraction.a /usr/lib/
	ar r libcramer.a cramer.o
	sudo mv libcramer.a /usr/lib/
	sudo cp Fraction/Fraction.h /usr/include/
	sudo cp cramer/cramer.h /usr/include/
clean:
	rm -f cramer.o Fraction.o
