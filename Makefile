all:
	g++ -lm main.cpp -o calculator
	./calculator

clean:
	rm calculator