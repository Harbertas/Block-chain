files:= main
main:
	g++ -o $(files) SHA-256/*.cpp *.cpp -O3
clean:
	rm $(files)