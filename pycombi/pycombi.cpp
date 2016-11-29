#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "crazycombi.cpp"

/*

g++ -c pycombi.cpp crazycombi.cpp cosa.h
g++ pycombi.o -lncurses -o app
./app

*/



int main()
{
	
	initscr();
	noecho();
	raw();
	cbreak();
    //timeout(0);
    keypad(stdscr, 1);
	curs_set(false);
	
	Cosa combi(0,0);

	combi.start(40,34);


	bool game_over=false;
	
	

	while(!game_over)
	{

		//combi.moverv();
		combi.moverh();
		//sleep(30);

	}




	getch();
    endwin();
	return 0;
}
