all: add_nbo

add_nbo: main.o func.o
	g++ -o add_nbo main.o func.o

main.o: func.h main.cpp
	g++ -c -o main.o main.cpp

func.o: func.h func.cpp
	g++ -c -o func.o func.cpp

clean:
	rm -f *.o