install:
	sudo apt-get install libsfml-dev

all:
	g++ -c ./src/*.cpp
	g++ -std=c++11 ./src/*.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

homepage:
	g++ -c ./src/*.cpp ./pages/homepage.cpp
	g++ -std=c++11 ./src/*.cpp ./pages/homepage.cpp -o homepage-dev -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm homepage-dev
	rm sfml-app
	rm *.o
