CC = g++
CFLAGS = -Wall --std=c++11
LIB = -lFraction -lcramer
cramer:
	$(CC) -o ../bin/cramer main.cpp $(CFLAGS) $(LIB)
esempio_Fraction:
	$(CC) -o ../bin/esempio_Fraction esempio_Fraction.cpp $(CFLAGS) -lFraction
install:
	$(CC) -c Fraction/Fraction.cpp cramer/cramer.cpp $(CFLAGS)
	ar r ../lib/libFraction.a Fraction.o
	sudo cp ../lib/libFraction.a /usr/lib/
	ar r ../lib/libcramer.a cramer.o
	sudo cp ../lib/libcramer.a /usr/lib/
	sudo cp Fraction/Fraction.h /usr/include/
	sudo cp cramer/cramer.h /usr/include/
	rm -f cramer.o Fraction.o
fraction:
	$(CC) -c Fraction/Fraction.cpp $(CFLAGS)
	ar r ../lib/libFraction.a Fraction.o
	sudo cp ../lib/libFraction.a /usr/lib/
	sudo cp Fraction/Fraction.h /usr/include/
	rm -f Fraction.o
