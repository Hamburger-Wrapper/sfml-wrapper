all:
	g++ -c ./src/*.cpp
	g++ -std=c++11 ./src/*.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

rm:
	rm sfml-app