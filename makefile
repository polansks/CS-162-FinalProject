CXX = g++
CXXFLAGS = -std=c++0x
SPACE_OBJ = Space.o ShowerSpace.o PhoneSpace.o TableSpace.o EmptySpace.o
#CXXFLAGS += -g


main: main.cpp Board.o input.o Menu.o ${SPACE_OBJ} functions.o Game.o Player.o Item.o Bag.o
	${CXX} ${CXXFLAGS} main.cpp Board.o input.o Menu.o ${SPACE_OBJ} functions.o Game.o Player.o Item.o Bag.o -o main

Board.o: Board.cpp Board.hpp ${SPACE_OBJ}
	${CXX} ${CXXFLAGS} -c Board.cpp

input.o: input.cpp input.hpp
	${CXX} ${CXXFLAGS} -c input.cpp

Menu.o: Menu.cpp Menu.hpp input.o
	${CXX} ${CXXFLAGS} -c Menu.cpp

Space.o: Space.cpp Space.hpp direction.h
	${CXX} ${CXXFLAGS} -c Space.cpp

ShowerSpace.o: ShowerSpace.cpp ShowerSpace.hpp Space.o
	${CXX} ${CXXFLAGS} -c ShowerSpace.cpp

PhoneSpace.o: PhoneSpace.cpp PhoneSpace.hpp Space.o
	${CXX} ${CXXFLAGS} -c PhoneSpace.cpp

TableSpace.o: TableSpace.cpp TableSpace.hpp Space.o
	${CXX} ${CXXFLAGS} -c TableSpace.cpp

EmptySpace.o: EmptySpace.cpp EmptySpace.hpp Space.o
	${CXX} ${CXXFLAGS} -c EmptySpace.cpp

functions.o: functions.cpp functions.hpp
	${CXX} ${CXXFLAGS} -c functions.cpp

Player.o: Player.cpp Player.hpp direction.h
	${CXX} ${CXXFLAGS} -c Player.cpp

Game.o: Game.cpp Game.hpp Player.o Board.o Menu.o direction.h
	${CXX} ${CXXFLAGS} -c Game.cpp

Item.o: Item.cpp Item.hpp
	${CXX} ${CXXFLAGS} -c Item.cpp

Bag.o: Bag.cpp Bag.hpp Item.o
	${CXX} ${CXXFLAGS} -c Bag.cpp
clean:
	rm *.o main
