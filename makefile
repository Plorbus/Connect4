game: main.o player.o menu.o leaderboard.o human.o grid.o game.o computer.o
	g++ -g -o game main.o player.o menu.o leaderboard.o human.o grid.o game.o computer.o

main.o: main.cpp game.h
	g++ -g -c main.cpp -o main.o

player.o: player.cpp player.h
	g++ -g -c player.cpp -o player.o

menu.o: menu.cpp menu.h
	g++ -g -c menu.cpp -o menu.o

leaderboard.o: leaderboard.cpp leaderboard.h
	g++ -g -c leaderboard.cpp -o leaderboard.o

human.o: human.cpp human.h
	g++ -g -c human.cpp -o human.o

grid.o: grid.cpp grid.h
	g++ -g -c grid.cpp -o grid.o

game.o: game.cpp game.h
	g++ -g -c game.cpp -o game.o

computer.o: computer.cpp computer.h
	g++ -g -c computer.cpp -o computer.o

clean:
	rm -f *.o game