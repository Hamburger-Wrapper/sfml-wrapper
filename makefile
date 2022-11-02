output: main.o ./src/*.cpp
	g++ -std=c++11 main.cpp ./components/*.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system