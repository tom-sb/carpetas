#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "cosa.h"



//const chtype borrador[] ={"       "};

Cosa::Cosa(int _y,int _x)
{
	y=_y;
	x=_x;
}

void Cosa::start(int posy,int posx)
{

	sety(posy);
	setx(posx);
	//move(y,x);

}

void Cosa::paint()
{
	
	const chtype techo[18] ={95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95};
    mvaddchstr(y,x+1,techo);
	const chtype combi0[20] ={47,' ',45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,' ',92};
    mvaddchstr(y+1,x,combi0);

	const chtype combi[20] ={124,' ',124,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',124,' ',124};
	mvaddchstr(y+2,x,combi);
    mvaddchstr(y+3,x,combi);
	const chtype combi1[20] ={124,46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,124};
    mvaddchstr(y+4,x,combi1);
	mvaddchstr(y+5,x,combi1);
    mvaddchstr(y+6,x,combi1);
    const chtype combi2[20] ={124,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,111,45,45,124};
    mvaddchstr(y+7,x,combi2);
	const chtype combi3[20] ={' ',85,85,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',85,85,' '};
    mvaddchstr(y+8,x,combi3);

}  

void Cosa::del()
{
	
	const chtype space[100] ={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	mvaddchstr(y,x,space);
	mvaddchstr(y+1,x,space);
	mvaddchstr(y+2,x,space);
	mvaddchstr(y+3,x,space);
	mvaddchstr(y+4,x,space);
	mvaddchstr(y+5,x,space);
	mvaddchstr(y+6,x,space);
	mvaddchstr(y+7,x,space);
	mvaddchstr(y+8,x,space);
	/*move(y,x);
	deleteln();
    move(y+1,x);
	deleteln();
    move(y+2,x);
	deleteln();*/

}

void Cosa::moverv()
{
	
	int key;
	key = getch();//lee un caracter
    if(key>0)
    {
		del();
        switch(key)
        {
	    case KEY_UP:
            if(y > 1)
				y--;
			else
				0;//sube la nave hasta h
	        break;
		case KEY_DOWN:
			if(y<47)
				y++;
			else
				0;
            break;
		case 27://salir con esc
            break;
		}
		paint();
		
	}
}

void Cosa::moverh()
{

	int key;
	key = getch();//lee un caracter

	del();
    if(key>0)
    {
		//del();	
        switch(key)
        {
	    case KEY_LEFT:
            if(x >= 10){	
				x-=28;
				//paint();
			}
			else
				0;//sube la nave hasta h
	        break;
		case KEY_RIGHT:
			if(x<=60){	
				x+=28;
				//paint();
			}
			else
				0;
            break;
        case 27://salir con esc
            break;
		}
		//del();
		paint();
	}
}
