install:
	sudo apt-get install libsfml-dev

all:
	g++ -c ./src/*.cpp
	g++ -std=c++11 *.o -o dev -lsfml-graphics -lsfml-window -lsfml-system

homepage-dev:
	g++ -c ./src/*.cpp ./pages/homepage.cpp
	g++ -std=c++11 *.o -o dev -lsfml-graphics -lsfml-window -lsfml-system

menu-dev:
	g++ -c ./src/*.cpp ./pages/menu.cpp
	g++ -std=c++11 *.o -o dev -lsfml-graphics -lsfml-window -lsfml-system

game-dev:
	g++ -c ./src/*.cpp ./pages/game.cpp
	g++ -std=c++11 *.o -o dev -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm dev
	rm *.o
