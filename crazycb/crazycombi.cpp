#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

void init_color_pairs() 
{
	short f, b;
    for( f = 0; f < COLORS; ++f )
        for( b = 0; b < COLORS; ++b )
            init_pair( f * COLORS + b, f, b );
}



#define SET_COLOR(fore, bg)                wattrset(stdscr, COLOR_PAIR(COLOR_##fore * COLORS + COLOR_##bg))
	 
#define PLANE1  "|\\"
#define PLANE2 "}=-O>"
#define PLANE3  "|/"
#define PLANE   \
{\
    move(h-1, 6);\
    printw(PLANE1);\
    move(h, 5);\
    printw(PLANE2);\
    move(h+1,6);\
    printw(PLANE3);\
    move(0,0);\
    refresh();\
}


#define ENEMY1   "/|"
#define ENEMY2 "<O-={"
#define ENEMY3   "\\|"
#define ENEMY(x,y)  \
{\
    move(y-1, x+2);\
    printw(ENEMY1);\
    move(y, x);\
    printw(ENEMY2);\
    move(y+1,x+2);\
    printw(ENEMY3);\
}
	 
/*#define bullet(y,x) \
{\
    SET_COLOR(BLACK, CYAN);\
    mvaddch(y,x,'-');\
}*/
	 
#define RF  (rand() / ((RAND_MAX)+1.))
	 
#define count(x)    sizeof(x)/sizeof(x[0])
#define diff(x,y)   abs(x-y)


int main()
{
    initscr();
    start_color();
    noecho();
    raw();
    cbreak();
    timeout(0);
    keypad(stdscr, 1);//activar/desactivar teclado
  
    init_color_pairs();
	     
    int x,y,p,h, key, c, die, score, bullets[95][2], enemies[50][3];
	     
    start://inicio
     
    p=0;
    h=13;//altura
    die = 0;
    score = 0;
    //memset(bullets, 0, sizeof(bullets));
    memset(enemies, 0, sizeof(enemies));
	    
    loop:
     
	
    usleep(30000);// velocidad 
    p++;//aumenta p
    key = getch();//lee un caracter
    if(key>0)
    {
        switch(key)
        {
	    case KEY_UP:
            if(h > 1)
				h-=10;
			else
				0;//sube la nave hasta h
	        break;
		case KEY_DOWN:
			if(h<47)
				h+=10;
			else
				0;
            //(h < 47) ? h ++ : 0;//baja la nave hasta h
            break;
        /*case ' '://disparo al rpesionar space
            for(x=0;x<count(bullets);x++)
			{
                if(!bullets[x][0])
				{
                    bullets[x][0] = 5;//las balas salen a 5 x 
                    bullets[x][1] = h;//las balas salen a la misma h de la nave
	                break;
                }
            }
            break; */
        case 27://salir con esc
            goto end;
		}
	}
	     
	if((rand() & 0x3F) == 4)
	{
        for(y=0;y<count(enemies);y++)
		{
            if(!enemies[y][0])
			{
                enemies[y][0] =95;//origen de los enemigos eje x
                enemies[y][1] = 8;//origen de los enemigos eje y
                enemies[y][1] =30; //(10 & 1) ? -(10 & 7)-1 : (10 & 7)-1;
                enemies[y][2] = 0;
                break;
            }
        }
    }
     
    for(x=0;x<100;x++)
    {
        for(y=0;y<100;y++)
        {
            y-=70;//
            if(sin((float)(x)/23) > ((float)y / 5.0f))
                SET_COLOR(WHITE, CYAN);
            else
            {
                SET_COLOR(GREEN, GREEN);//pinta verde la montaña
                //if(x == 6 && (h-20 > y))//colicion con lamontaña
                    //die = 1;//muerte
            }
            y+=70;
            mvaddch(y,x,' ');//mueve la posicion actual y agrega caracter
        }
    }
     
    /*for(x=0;x<count(bullets);x++){
	         
        bullets[x][0] += (bullets[x][0]) ? 1 : 0;
        if(bullets[x][0] > 99)
            bullets[x][0] = 0;
        else if(bullets[x][0])
            bullet(bullets[x][1],bullets[x][0]);
    }*/
	     
    for(x=0;x<count(enemies);x++){
        enemies[x][0] -= (enemies[x][0] && !enemies[x][2]) ? 1 : 0;
        if(enemies[x][0] == 1){
            enemies[x][0] = 0;
            score --;
        }
        if(enemies[x][2]){
            enemies[x][2]--;
            SET_COLOR(RED,YELLOW);
            if(!enemies[x][2]){
                enemies[x][0] = 0;
            }
        }
        else{
            SET_COLOR(CYAN, YELLOW);
            if(enemies[x][0] && enemies[x][0] < 10 && diff(h, enemies[x][1]) < 3){
                die= 1;
                goto planedie;
            }
            for(y=0;y<count(bullets);y++){
                if(bullets[y][0] && diff(enemies[x][0],bullets[y][0]) < 2 && diff(enemies[x][1],bullets[y][1]) < 2){
                    score++;
                  planedie:
                    SET_COLOR(RED, YELLOW);
                    enemies[x][2] = 4;
                    bullets[y][0] = 0;
                    break;
                }
            }
        }
        if(enemies[x][0])
            ENEMY(enemies[x][1],enemies[x][0]);
    }
    SET_COLOR(GREEN, BLACK);
    move(3,0);
    printw("Score: %i                   ", score);
    if(!die)
    {
        SET_COLOR(BLUE, WHITE);
        PLANE;
    }
    else
    {
        SET_COLOR(RED, YELLOW);
        PLANE;
        sleep(2);
        goto start;
    }     
    goto loop;
    end:
    refresh();
    endwin();
    return 0;
}
