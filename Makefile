CPP=g++
CPP_STD=c++98
CPP_OPTIONS=-Wall -Wextra -pedantic

all: main

main.o: main.cpp lib/iostream.hpp lib/iomanip.hpp
	$(CPP) -std=$(CPP_STD) $(CPP_OPTIONS) -c main.cpp -o main.o

definitions.o: lib/definitions.cpp lib/iostream.hpp
	$(CPP) -std=$(CPP_STD) $(CPP_OPTIONS) -c lib/definitions.cpp -o definitions.o

main: main.o definitions.o
	$(CPP) main.o definitions.o -o main

clean:
	rm -f *.o main

run: main
	./main