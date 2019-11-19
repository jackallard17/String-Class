
all: test

test: mytest
	./mytest

testcompile: test.o

mytest: test.o myString.o
	g++ $^ -o $@ -lgtest -lpthread

%.o: %.cpp
	g++ -c $^ -o $@

clean:
	rm -f ./*.o mytest