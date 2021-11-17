#define _CRT_SECURE_NO_WARNINGS 1
#define _WIN32_WINNT 0x500
#define screen_x 100
#define screen_y 40
#include "ScoreBoard.h"
#include<stdio.h> 
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<thread>
#include <stdlib.h>
#include<string.h>
#include <iostream>
#include <utility>

#include <chrono>
HANDLE wHnd;
HANDLE rHnd;
DWORD fdwMode;
COORD bufferSize = { screen_x,screen_y };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
CHAR_INFO consoleBuffer[screen_x * screen_y];

FILE* file;

//---- PLAYER DATA ----//

struct player
{
	char name[50];
	int point;
}P;
errno_t err;

//------- Game Status --------//

static enum game_state
{
	Menu,
	Name,
	PrePlay,
	Play,
	Rank,
	Delay_rank,
	HTP,
	Pause,
	End,
	Exit
};
game_state Gstate = Menu;

int setConsole()
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}

int setMode()
{
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
		ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}

void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}



void area(int chapter)
{
	setcolor(3, 0);
	
	switch (chapter) {
		
	case 1:
		gotoxy(0, 2);
		printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("xxxxxxxxxxxxxxx                                   x\n");
		printf("x        x                                        x\n");
		printf("x        x                       xxx              x\n");
		printf("x        x                       xxx              x\n");
		printf("x        x                       xxx              x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                     xxxxxxx                     x\n");
		printf("x                        x                        x\n");
		printf("x                        x                        x\n");
		printf("xxxxxxxxxxx              x                        x\n");
		printf("x                        x                        x\n");
		printf("x                        x                        x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x          xxx                   x                x\n");
		printf("x          xxx                   x                x\n");
		printf("x          xxx                   x                x\n");
		printf("x                                x                x\n");
		printf("x                                x                x\n");
		printf("x                           xxxxxxxxxxxx          x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		break;
	case 2:
		gotoxy(0, 2);
		printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");		
		printf("x                        xx                       x\n");		
		printf("x                        xx                       x\n");		
		printf("x                        xx                       x\n");		
		printf("x                        xx                       x\n");		
		printf("x                                                 x\n");		
		printf("x                                                 x\n");		
		printf("x              xx                                 x\n");		
		printf("x              xx                                 x\n");		
		printf("x                                         xxxxxxxxx\n");		
		printf("x                                                 x\n");		
		printf("x                                                 x\n");		
		printf("x                                                 x\n");		
		printf("x                                                 x\n");		
		printf("x       xx                                        x\n");
		printf("x       xx                                        x\n");	
		printf("x       xx                                        x\n");
		printf("xxxxxxxxxx                                        x\n");
		printf("x                                                 x\n");
		printf("x                     xxxxx                       x\n");	
		printf("x                      xxx                        x\n");	
		printf("x                     xxxxx                       x\n");	
		printf("x                                                 x\n");	
		printf("x                                                 x\n");	
		printf("x                                                 x\n");		
		printf("x                                           xxxxxxx\n");		
		printf("x                                                 x\n");		
		printf("xxxxxxxxxx                                        x\n");		
		printf("x       xx                                        x\n");		
		printf("x       xx                                        x\n");	
		printf("x                                                 x\n");		
		printf("x                                                 x\n");		
		printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		break;
	case 3:
		gotoxy(0, 2);
		printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		printf("x           x                         x           x\n");
		printf("x           x                         x           x\n");
		printf("x           x                         x           x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                        x                        x\n");
		printf("x                       xxx                       x\n");
		printf("x                        x                        x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("xxxxxxxx                xxx                       x\n");
		printf("xxxxxxxx                xxx                       x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                        x                        x\n");
		printf("x                       xxx                       x\n");
		printf("x                        x                        x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x          x                          x           x\n");
		printf("x          x                          x           x\n");
		printf("x          x                          x           x\n");
		printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		break;
	case 4:
		gotoxy(0, 2);
		printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x          x                            x         x\n");
		printf("x         xxx                          xxx        x\n");
		printf("x          x                            x         x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                        x                        x\n");
		printf("x                       xxx                       x\n");
		printf("x                        x                        x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x          x                             x        x\n");
		printf("x         xxx                           xxx       x\n");
		printf("x          x                             x        x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		break;
	case 5:
		gotoxy(0, 2);
		printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		printf("x                                     xx          x\n");
		printf("x     xx                            xx            x\n");
		printf("x     xx                                          x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                     xx          x\n");
		printf("x                                     xx          x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x               xx          xx                    x\n");
		printf("x               xx          xx                    x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                xx               x\n");
		printf("x                                xx               x\n");
		printf("x                                                 x\n");
		printf("x         xx                                      x\n");
		printf("x         xx                                  xx  x\n");
		printf("x                                             xx  x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                 xx              x\n");
		printf("x                                 xx              x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x    xxx                                          x\n");
		printf("x    xxx                            xxx           x\n");
		printf("x                                  xxx            x\n");
		printf("x                                                 x\n");
		printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		break;
	case 6 :
		gotoxy(0, 2);
		printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("xxxxxxxxxxx                                       x\n");
		printf("x                                                 x\n");
		printf("x                       x                         x\n");
		printf("x                       x                         x\n");
		printf("x                       x             xxxxxxxxxxxxx\n");
		printf("x                       x                         x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("xxxxxxxxxxx                                       x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                       x                         x\n");
		printf("x                       x                         x\n");
		printf("x                       x                         x\n");
		printf("x                       x                         x\n");
		printf("x                       x                         x\n");
		printf("x                       x                         x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("xxxxxxxxxxxx                                      x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                       xxxxxxxxxxx\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		break;
	case 7 :
		gotoxy(0, 2);
		printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("xxxxx                                             x\n");
		printf("x                                                 x\n");
		printf("x              x         x         x              x\n");
		printf("x            xxxxx     xxxxx     xxxxx            x\n");
		printf("x              x         x         x          xxxxx\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("xxxxx                                             x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x           x x        x x       x x              x\n");
		printf("x            x          x         x               x\n");
		printf("x           x x        x x       x x              x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("xxxxx                                             x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x            xxxx     xxxxx      xxxx             x\n");
		printf("x                                            xxxxxx\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("x                                                 x\n");
		printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

	}

}

void draw_tank(int x, int y, char key)
{

	gotoxy(x, y);
	setcolor(10, 0);
	if (key == 'w') {
		printf(" | ");
		gotoxy(x, ++y);
		printf("[O]");
	}
	if (key == 's') {
		printf("[O]");
		gotoxy(x, ++y);
		printf(" | ");
	}
	if (key == 'a') {
		printf("-o ");
		gotoxy(x, ++y);
		printf("***");
	}
	if (key == 'd') {
		printf(" o-");
		gotoxy(x, ++y);
		printf("***");
	}
}
void erase_tank(int x, int y)
{

	gotoxy(x, y);
	setcolor(10, 0);
	printf("   ");
	gotoxy(x, ++y);
	printf("   ");

}

void draw_enemy1(int Ex, int Ey, char keyen)
{

	gotoxy(Ex,Ey);
	setcolor(12, 0);
	if (keyen == 'w') {
		printf(" | ");
		gotoxy(Ex, ++Ey);
		printf("[O]");
	}
	if (keyen == 's') {
		printf("[O]");
		gotoxy(Ex, ++Ey);
		printf(" | ");
	}
	if (keyen == 'a') {
		printf("-o ");
		gotoxy(Ex, ++Ey);
		printf("***");
	}
	if (keyen == 'd') {
		printf(" o-");
		gotoxy(Ex, ++Ey);
		printf("***");
	}
}
void erase_enemy1(int Ex, int Ey)
{

	gotoxy(Ex, Ey);
	setcolor(12, 0);
	printf("   ");
	gotoxy(Ex, ++Ey);
	printf("   ");

}

void draw_bullet(int x, int y)
{
	gotoxy(x, y);
	setcolor(14, 0);
	printf(".");
}
void clear_bullet(int x, int y)
{ 
	gotoxy(x, y);
	setcolor(14, 0);
	printf(" ");
}

void draw_enemy_bullet(int x, int y)
{
	gotoxy(x, y);
	setcolor(13, 0);
	printf("*");
}
void clear_enemy_bullet(int x, int y)
{
	gotoxy(x, y);
	setcolor(13, 0);
	printf(" ");
}

void draw_cursor(int Cx,int Cy)
{
	gotoxy(Cx, Cy);
	//setcolor(14, 0);
	printf(">");
}
void erase_cursor(int Cx, int Cy)
{
	gotoxy(Cx, Cy);
	//setcolor(14, 0);
	printf(" ");
}

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

void score(int point)
{
	setcolor(15, 0);
	gotoxy(2, 1);
	printf("YOUR SCORE : %d", point);
}
void clear_score()
{
	gotoxy(15, 0);
	printf("                  ");
}

void Life(int life)
{
	gotoxy(35, 1);
	
	if (life > 0)
	{
		setcolor(15, 0);
		printf("LIFE : ");
		for (int i = 0; i < life; i++)
		{
			setcolor(12, 0);
			printf("* ");
		}
	}
	else
	{
		setcolor(15, 0);
		printf("LIFE : ");
	}
}
void clear_life()
{
	gotoxy(35, 1);
	printf("                  ");
}

void Chapter(int chapter)
{
	gotoxy(19, 36);
	setcolor(15, 0);
	printf("- CHAPTER %d -", chapter);
}

void pxy(int x, int y)
{
	gotoxy(18, 38);
	printf("x : %d , y : %d", x, y);
}

void printbulletdir(int x, int y, int bulletdir)
{
	gotoxy(x, y);
	printf("bulletdir %d", bulletdir);
}

void clear()
{
	gotoxy(3, 10);
	printf("                                                                                                                                ");
	gotoxy(3, 11);
	printf("                                                                                                                                ");
	gotoxy(3, 12);
	printf("                                                                                                                                ");
	gotoxy(3, 13);
	printf("                                                                                                                                ");
	gotoxy(3, 14);
	printf("                                                                                                                                ");
	gotoxy(3, 16);
	printf("                                                                                                                                ");
	gotoxy(3, 20);
	printf("                                                                                                                                ");
	gotoxy(3, 22);
	printf("                                                                                                                                ");
	gotoxy(3, 24);
	printf("                                                                                                                                ");
}

void menu(int Cx , int Cy)
{

	setcursor(0);
	gotoxy(3, 10);
	printf("#####   ##   ##      ####   ##   ##    ##   ##   ##   ##    ##   #######   ##    ##   ##   ##");

	gotoxy(3, 11);
	printf("##      ##   ##       ##    ##   ##  ##     ##   ##   ##  ##     ##   ##   ##  ##     ##   ##");
	setcolor(4, 0);
	gotoxy(3, 12);
	printf("#####   ##   ##       ##    ##   ####       ##   ##   ####       ##   ##   ####       ##   ##");
	setcolor(7, 0);
	gotoxy(3, 13);
	printf("   ##   ##   ##   ##  ##    ##   ##  ##     ##   ##   ##  ##     ##   ##   ##  ##     ##   ##");

	gotoxy(3, 14);
	printf("#####   #######   ######    ##   ##    ##   #######   ##    ##   #######   ##    ##   #######");

	gotoxy(41, 16);
	setcolor(14, 0);
	printf("- KOBORI'S TANK -");
	setcolor(7, 0);


	setcursor(0);
	gotoxy(47, 20);
	printf("PLAY");

	setcursor(0);
	gotoxy(47, 22);
	printf("SCORE");

	setcursor(0);
	gotoxy(47, 24);
	printf("HOW TO PLAY");

	setcursor(0);
	gotoxy(47, 26);
	printf("EXIT");

	gotoxy(Cx, Cy);
	printf("> ");
	
	
}

void gameover(int point)
{
	setcolor(12, 0);
	setcursor(0);
	gotoxy(43, 15); 
	printf(" G A M E ");
	gotoxy(43, 17);
	printf(" O V E R ");
	
	setcolor(15, 0);
	gotoxy(40, 20);
	printf("Your Score : %d",point);
	setcolor(15, 0);
	
	
	
	
	
}

void winner(int point)
{
	setcolor(2, 0);
	setcursor(0);
	gotoxy(43, 15);
	printf(" YOU'RE THE");
	gotoxy(42, 17);
	printf(" W I N N E R .");

	setcolor(15, 0);
	gotoxy(42, 20);
	printf("Your Score : %d", point);
	setcolor(15, 0);
}

char cursor(int x, int y) {
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (
		!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))

		return '\0';
	else
		return buf[0];

}
void hp(int Hp)
{
	gotoxy(18, 40);
	printf("%d", Hp);
}
void clrscr()
{
	system("@cls||clear");
}

void door()
{
	setcolor(14, 0);
	gotoxy(47,17);
	printf("#");
	setcolor(14, 0);
	gotoxy(47, 20);
	printf("#");

	setcolor(15, 0);
	gotoxy(53, 18);
	printf("Go to the door (between '#') ");
	setcolor(15, 0);
	gotoxy(53, 19);
	printf("for next chapter .");
}
void heal(int x,int y){
	
	gotoxy(x,y);
	setcolor(2,0);
	printf("@");
}


int main()
{
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos(consoleWindow, 0, 250, 150, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	
	srand(time(NULL));
	char key = ' ';
	char keyen[10] ;
	bool visible = 0;
	
	int x = 0 ,y = 0 ; // xy ตัวละคร
	int Ex[10], Ey[10]  ; // xy ศัตรู 1
	int Cx = 45, Cy = 20; // xy cursor หน้า menu
	int bx=0 , by=0 ; //xy กระสุน
	int bex[10] = { 0,0,0,0,0,0,0,0,0 },bey[10]= { 0,0,0,0,0,0,0,0,0 }; // xy กระสุนศัตรู 1
	int PCx = 39, PCy = 14;
	int Hx=0, Hy=0; // item heal pos
	int dir = 1; //1234 wasd // ทิศทางตัวละคร
	int bulletdir = 0; //1234 wasd // ทิศทางกระสุน
	int enemydir[10]; //ทิศทางศัตรู
	int enemywalk[10];
	int bulletenemydir[10] = { 0,0,0,0,0,0,0,0,0,0 };
	
	int bullet = 0; //สถานะกระสุน
	int bullet_en[10] = {0,0,0,0,0,0,0,0,0,0 }; //สถานะกระสุนศัตรู
	int enemy_state[10] = {0,0,0,0,0,0,0,0,0,0}; //สถานะศัตรู
	int heal_state = 0;

	int point = 0;
	int	life = 5; 
	int chapter = 1;
	
	char checkwall1 , checkwall2 , checkwall3 , checkwall4; //เช็คชนตัวละคร
	char check_around_1, check_around_2, check_around_3; //เช็คตำแหน่งเกิดศัตรู
	char check_enemy1 = ' ', check_enemy2 = ' ',check_enemy3 = ' ',check_enemy4 = ' ', check_enemy5 = ' ', check_enemy6 = ' ', check_enemy7 = ' ', check_enemy8 = ' ', check_enemy9 = ' ', check_enemy10=' ';
	char check_item1 = ' ', check_item2 = ' ', check_item3 = ' ',check_item4=' ';
	char bulletenemycheckwall1 = ' ';
	char enemycheckwall1, enemycheckwall2, enemycheckwall3, enemycheckwall4;
	char checkbullet1 = ' ', checkbullet2 = ' ', checkbullet3 = ' '; //เช็คตัวละครโดนยิง
	
	int enemy_hp = 200;
	unsigned long frame=1;
	unsigned long itemframe = 1;
	unsigned long ShootFrame[10] = { 1,1,1,1,1,1,1,1,1,1 };
	
	int n_enemy = 2;
	int amount_enemy = n_enemy;
	int count_enemy = 0;
	int end_drawenemy = 0;
	int walk[10] ;
	int len;
	int countwalk = 0;
	int countitem = 0;

	setConsole();
	setMode();
	
	while (1) {
		switch (Gstate) {

		//-----------------Menu-----------------//

		case Menu:
			gotoxy(10, 38);
			printf("Name : Mr.Safireen Tokanee  /  ID : 64010192  /  Faculty : Computer Engineering");
			
			menu(Cx,Cy);
			if (_kbhit()) {
				key = _getch();

				if (key == 'w' || key == 'ไ') {	
					
					erase_cursor(Cx, Cy);
					Cy-=2;
					std::thread q(Beep,400, 150);
					q.detach();
					if (Cy < 20) { Cy = 20; }
				}

				if (key == 's' || key == 'ห') {	
					erase_cursor(Cx, Cy);
					Cy+=2;
					std::thread q(Beep, 400, 150);
					q.detach();
					if (Cy > 26) { Cy = 26; }
				}

				if (key == 13)
				{
					std::thread q(Beep, 300, 150);
					q.detach();
					if (Cy == 20) {
						Gstate = Name; 
						clrscr();
						Sleep(500);
					}
					if (Cy == 22) {
						Gstate = Rank;
						clrscr();
						Sleep(500);
					}
					if (Cy == 24) {
						Gstate = HTP;
						clrscr();
						Sleep(500);
					}
					if (Cy == 26) {
						Gstate = Exit;
						clrscr();
						Sleep(500);
					}
					
				}

				fflush(stdin);

			}
			
			
			break;

		//----------------- Enter Name --------------------//

		case Name:
			
			gotoxy(40, 16);
			printf("Enter Your Name");
			gotoxy(24, 24);

			setcolor(12, 0);
			printf("Warning : The name is no longer than 8 characters .");
			setcolor(15, 0);
			gotoxy(40, 18);
			setcursor(1);
			gets_s(P.name);

			

			
			len = strlen(P.name);
			if (len <= 8) 
			{ 
				std::thread q(Beep, 300, 150);
				q.detach();
				Gstate = PrePlay; clrscr();Sleep(500);
			}
			else 
			{ 
				Gstate = Name; clrscr();
			}
			
			break;

			//------------- PrePlay -----------------//

		case PrePlay:
			
			Sleep(500);
			life = 5;
			gotoxy(0, 0);
			score(P.point);
			Life(life);
			Chapter(chapter);
			area(chapter);
			x = 23;	y = 32;
			setcursor(0);
			count_enemy=0;

			draw_tank(x, y, 'w');

			//--------------- สุ่มตำแหน่งเกิดศัตรู ------------------//
			for (int i = 0; i < n_enemy; i++)
			{
				enemydir[i] = 1 + (rand() % 4); //สุ่มทิศ
				Ex[i] = 2 + (rand() % 39);
				Ey[i] = 3 + (rand() % 27);

				if (enemydir[i] == 1)//w
				{
					keyen[i] = 'w';
					check_around_1 = cursor(Ex[i] + 1, Ey[i] - 1); // เช็คหน้า
					check_around_2 = cursor(Ex[i] - 1, Ey[i] + 1);	 // เช็คซ้าย
					check_around_3 = cursor(Ex[i] + 3, Ey[i] + 1); // เช็คขวา
					if (check_around_1 == ' ' && check_around_2 == ' ' && check_around_3 == ' ')
					{
						enemy_state[i] = 1;
					}
					else {
						while (1)
						{
							Ex[i] = 2 + (rand() % 39);
							Ey[i] = 3 + (rand() % 27);

							check_around_1 = cursor(Ex[i] + 1, Ey[i] - 1); // เช็คหน้า
							check_around_2 = cursor(Ex[i] - 1, Ey[i] + 1);	 // เช็คซ้าย
							check_around_3 = cursor(Ex[i] + 3, Ey[i] + 1); // เช็คขวา

							if (check_around_1 == ' ' && check_around_2 == ' ' && check_around_3 == ' ')
							{
								enemy_state[i] = 1;
								break;
							}
						}
					}
				}
				if (enemydir[i] == 2)
				{
					keyen[i] = 'a';
					check_around_1 = cursor(Ex[i] - 1, Ey[i]); // เช็คหน้า
					check_around_2 = cursor(Ex[i], Ey[i] + 2);	 // เช็คซ้าย
					check_around_3 = cursor(Ex[i], Ey[i]); // เช็คขวา
					if (check_around_1 == ' ' && check_around_2 == ' ' && check_around_3 == ' ')
					{
						enemy_state[i] = 1;
					}
					else {
						while (1)
						{
							Ex[i] = 2 + (rand() % 39);
							Ey[i] = 3 + (rand() % 27);

							check_around_1 = cursor(Ex[i] - 1, Ey[i]); // เช็คหน้า
							check_around_2 = cursor(Ex[i], Ey[i] + 2);	 // เช็คซ้าย
							check_around_3 = cursor(Ex[i], Ey[i]); // เช็คขวา

							if (check_around_1 == ' ' && check_around_2 == ' ' && check_around_3 == ' ')
							{
								enemy_state[i] = 1;
								break;
							}
						}
					}
				}
				if (enemydir[i] == 3)
				{
					keyen[i] = 's';
					check_around_1 = cursor(Ex[i] + 1, Ey[i] + 2); // เช็คหน้า
					check_around_2 = cursor(Ex[i] + 2, Ey[i]);	 // เช็คซ้าย
					check_around_3 = cursor(Ex[i], Ey[i]); // เช็คขวา
					if (check_around_1 == ' ' && check_around_2 == ' ' && check_around_3 == ' ')
					{
						enemy_state[i] = 1;
					}
					else {
						while (1)
						{
							Ex[i] = 2 + (rand() % 39);
							Ey[i] = 3 + (rand() % 27);

							check_around_1 = cursor(Ex[i] + 1, Ey[i] + 2); // เช็คหน้า
							check_around_2 = cursor(Ex[i] + 2, Ey[i]);	 // เช็คซ้าย
							check_around_3 = cursor(Ex[i], Ey[i]); // เช็คขวา

							if (check_around_1 == ' ' && check_around_2 == ' ' && check_around_3 == ' ')
							{
								enemy_state[i] = 1;
								break;
							}
						}
					}
				}
				if (enemydir[i] == 4)
				{
					keyen[i] = 'd';
					check_around_1 = cursor(Ex[i] + 3, Ey[i]); // เช็คหน้า
					check_around_2 = cursor(Ex[i], Ey[i]);	 // เช็คบน
					check_around_3 = cursor(Ex[i], Ey[i] + 1); // เช็คล่าง
					if (check_around_1 == ' ' && check_around_2 == ' ' && check_around_3 == ' ')
					{
						enemy_state[i] = 1;
					}
					else {
						while (1)
						{
							Ex[i] = 2 + (rand() % 39);
							Ey[i] = 3 + (rand() % 27);

							check_around_1 = cursor(Ex[i] + 3, Ey[i]); // เช็คหน้า
							check_around_2 = cursor(Ex[i], Ey[i]);	 // เช็คบน
							check_around_3 = cursor(Ex[i], Ey[i] + 1); // เช็คล่าง

							if (check_around_1 == ' ' && check_around_2 == ' ' && check_around_3 == ' ')
							{
								enemy_state[i] = 1;
								break;
							}
						}
					}
				}

			}

			//===================== Draw Enemy ======================//

			for (int i = 0; i < n_enemy; i++)
			{
				if (enemy_state[i] == 1) {
					draw_enemy1(Ex[i], Ey[i], keyen[i]);
										
				}
			}

			Gstate = Play;
			break;
		case Play:
			

			//---------------START LOOP----------------//

				
				setcursor(0);

				//---------------- กดปุ่ม -----------------//

				if (_kbhit()) {
					key = _getch();

					if (key == 'w' || key == 'ไ') {	//เดินหน้า
						checkwall1 = cursor(x + 1, y - 1);
						checkwall2 = cursor(x, y - 1);
						checkwall3 = cursor(x + 2, y - 1);

						check_item1 = cursor(x + 1, y );
						check_item2 = cursor(x, y - 1);
						check_item3 = cursor(x + 2, y - 1);
						if ((checkwall1 == ' ' || checkwall1 == '@') && (checkwall2 == ' ' || checkwall2 == '@') && (checkwall3 == ' ' || checkwall3 == '@')) {
							dir = 1;
							if (y > 3) { erase_tank(x, y); draw_tank(x, --y, key); }
							else { draw_tank(x, y, key); }
						}
					}

					if (key == 'a' || key == 'ฟ') {	//ซ้าย
						checkwall1 = cursor(x - 1, y);
						checkwall2 = cursor(x - 1, y + 1);

						check_item1 = cursor(x , y);
						check_item2 = cursor(x, y - 1);

						if ((checkwall1 == ' ' || checkwall1 == '@') && (checkwall2 == ' ' || checkwall2 == '@')) {
							dir = 2;
							if (x >= 3) { erase_tank(x, y); draw_tank(--x, y, key); }
							else { draw_tank(x, y, key); }
						}
					}

					if (key == 's' || key == 'ห') {	//ถอยหลัง
						checkwall1 = cursor(x + 1, y + 2);
						checkwall2 = cursor(x, y + 2);
						checkwall3 = cursor(x + 2, y + 2);

						check_item1 = cursor(x + 1, y + 1);
						check_item2 = cursor(x, y);
						check_item3 = cursor(x + 2, y );
						if ((checkwall1 == ' ' || checkwall1 == '@' )&&( checkwall2 == ' ' || checkwall2 == '@' )&& (checkwall3 == ' ' || checkwall3 == '@')) {
							dir = 3;
							if (y < 32) { erase_tank(x, y); draw_tank(x, ++y, key); }
							else { draw_tank(x, y, key); }
						}
					}

					if (key == 'd' || key == 'ก') {	//ขวา
						checkwall1 = cursor(x + 3, y);
						checkwall2 = cursor(x + 3, y + 1);

						check_item1 = cursor(x + 2, y);
						check_item2 = cursor(x + 2, y + 1);

						if ((checkwall1 == ' '|| checkwall1 == '@') && (checkwall2 == ' ' || checkwall2 == '@')) {
							dir = 4;
							if (x <= 45) {
								erase_tank(x, y); draw_tank(++x, y, key);
							}
							else { draw_tank(x, y, key); }
						}
					}

					if (key == VK_ESCAPE)
					{
						
						//Gstate = Pause;
						Gstate = Exit;
						clrscr();
						Sleep(300);
						
					}

					if ((key == ' ' ) && bullet != 1) { // เปิดการมองเห็นกระสุน
						setcursor(0);

						//std::thread q(Beep, 500, 200);//Soundshoot
						//q.detach();

						if (dir == 1) { //w
							checkwall1 = cursor(x + 1, y - 1);
							if (checkwall1 == ' ') {
								bullet = 1;
								bx = x + 1;
								by = y - 1;
								bulletdir = 1;
							}
						}
						if (dir == 2) { //a
							checkwall1 = cursor(x - 1, y);
							if (checkwall1 == ' ') {
								bullet = 1;
								bx = x - 1;
								by = y; bulletdir = 2;
							}
						}
						if (dir == 3) { //s
							checkwall1 = cursor(x + 1, y + 2);
							if (checkwall1 == ' ') {
								bullet = 1;
								bx = x + 1;
								by = y + 2; bulletdir = 3;
							}
						}
						if (dir == 4) { //d
							checkwall1 = cursor(x + 3, y);
							if (checkwall1 == ' ') {
								bullet = 1;
								bx = x + 3;
								by = y; bulletdir = 4;
							}
						}


					}
					//pxy(x, y);
					fflush(stdin);

				}

				//-------------- ศัตรูเดิน ------------------//
				
				
				for (int i = 0; i < n_enemy; i++)
				{
					if (countwalk == 0 || countwalk == walk[i]) {
						enemywalk[i] = 1 + (rand() % 4);//direction
						walk[i] = 3+ (rand() % 7);// walk
						
					}
				}
				for (int i = 0; i < n_enemy; i++) 
				{
					
					
						//for (int j = 1; j <= walk[i]; j++)
						//{
							if (frame % 10 == 0)
							{
						
							if (enemywalk[i] == 1)
							{
								enemycheckwall1 = cursor(Ex[i] + 1, Ey[i] - 1);
								enemycheckwall2 = cursor(Ex[i], Ey[i] - 1);
								enemycheckwall3 = cursor(Ex[i] + 2, Ey[i] - 1);
								keyen[i] = 'w';
								if (enemy_state[i] == 1) 
								{
									if (enemycheckwall1 == ' ' && enemycheckwall2 == ' ' && enemycheckwall3 == ' ')
									{
										erase_enemy1(Ex[i], Ey[i]);
										draw_enemy1(Ex[i], --Ey[i], 'w');
									}
									else
									{
										draw_enemy1(Ex[i], Ey[i], 'w');
									}
								}
								countwalk++;
							}
							if (enemywalk[i] == 2)
							{
								keyen[i] = 'a';
								enemycheckwall1 = cursor(Ex[i] - 1, Ey[i]);
								enemycheckwall2 = cursor(Ex[i] - 1, Ey[i] + 1);
								if (enemy_state[i] == 1) 
								{
									if (enemycheckwall1 == ' ' && enemycheckwall2 == ' ')
									{
										erase_enemy1(Ex[i], Ey[i]);
										draw_enemy1(--Ex[i], Ey[i], 'a');
									}
									else
									{
										draw_enemy1(Ex[i], Ey[i], 'a');
									}
								}
								countwalk++;
							}

							if (enemywalk[i] == 3)
							{
								keyen[i] = 's';
								enemycheckwall1 = cursor(Ex[i] + 1, Ey[i] + 2);
								enemycheckwall2 = cursor(Ex[i], Ey[i] + 2);
								enemycheckwall3 = cursor(Ex[i] + 2, Ey[i] + 2);
								if (enemy_state[i] == 1) 
								{
									if (enemycheckwall1 == ' ' && enemycheckwall2 == ' ' && enemycheckwall3 == ' ')
									{
										erase_enemy1(Ex[i], Ey[i]);
										draw_enemy1(Ex[i], ++Ey[i], 's');
									}
									else
									{
										draw_enemy1(Ex[i], Ey[i], 's');
									}
									
								}
								countwalk++;
							}
							if (enemywalk[i] == 4)
							{
								keyen[i] = 'd';
								enemycheckwall1 = cursor(Ex[i] + 3, Ey[i]);
								enemycheckwall2 = cursor(Ex[i] + 3, Ey[i] + 1);
								if (enemy_state[i] == 1) {
									if (enemycheckwall1 == ' ' && enemycheckwall2 == ' ')
									{
										erase_enemy1(Ex[i], Ey[i]);
										draw_enemy1(++Ex[i], Ey[i], 'd');
									}
									else
									{
										draw_enemy1(Ex[i], Ey[i], 'd');
									}
								}
								countwalk++;
							}
					
						}
							//Sleep(50);
							//std::thread q(Sleep,1000);
							//q.detach();
							//std::this_thread::sleep_for(std::chrono::milliseconds(25)); 
							
							//Sleep(30);
					//}
				}


				//-------------- ยิงกระสุน -----------------//

				if (bullet == 1)
				{
					if (bulletdir == 1)
					{
						checkwall1 = cursor(bx, by - 1);

						if (checkwall1 == ' ') {
							clear_bullet(bx, by);
							draw_bullet(bx, --by);
						}
						else
						{
							clear_bullet(bx, by);
							bullet = 0;


						}
					}
					if (bulletdir == 2)
					{
						checkwall1 = cursor(bx - 1, by);

						if (checkwall1 == ' ') {
							clear_bullet(bx, by);
							draw_bullet(--bx, by);
						}
						else
						{
							clear_bullet(bx, by);
							bullet = 0;


						}
					}
					if (bulletdir == 3)
					{
						checkwall1 = cursor(bx, by + 1);

						if (checkwall1 == ' ') {
							clear_bullet(bx, by);
							draw_bullet(bx, ++by);
						}
						else
						{
							clear_bullet(bx, by);
							bullet = 0;


						}
					}
					if (bulletdir == 4)
					{
						checkwall1 = cursor(bx + 1, by);

						if (checkwall1 == ' ') {
							clear_bullet(bx, by);
							draw_bullet(++bx, by);
						}
						else
						{
							clear_bullet(bx, by);
							bullet = 0;


						}
					}
				}

				//------------------- ตรวจสอบเมื่อกระสุนโดนศัตรู , Enemy Alert และ set ตำแหน่งกระสุนของศัตรู -------------------//	
				for (int i = 0; i < n_enemy; i++)
				{
					if (enemy_state[i] == 1){
						if (keyen[i] == 'w')
						{
							//forward
							check_enemy1 = cursor(Ex[i] + 1, Ey[i]);
							check_enemy2 = cursor(Ex[i], Ey[i]-1);
							check_enemy3 = cursor(Ex[i] + 2, Ey[i]);
							
							if (check_enemy1 == '.' || check_enemy2 == '.' || check_enemy3 == '.')
							{

								clear_bullet(bx, by);
								clear_enemy_bullet(bex[i], bey[i]);
								erase_enemy1(Ex[i], Ey[i]);
								bullet = 0;
								bullet_en[i] = 0;
								enemy_state[i] = 0;
								amount_enemy -= 1;
								P.point = P.point + 50;
								score(P.point);

							}
							
							if (Ex[i] == x && (Ey[i] - 1 == y || Ey[i] - 2 == y || Ey[i] - 3 == y || Ey[i] - 4 == y || Ey[i] - 5 == y || Ey[i] - 6 == y || Ey[i] - 7 == y || Ey[i] - 8 == y )|| ShootFrame[i] % 15 == 0)
							{
								checkwall1 = cursor(Ex[i] + 1, Ey[i]-1);
								if (bullet_en[i] == 0 && enemy_state[i] == 1 && checkwall1 == ' ')
								{
									//std::thread q(Beep, 800, 200);//Soundenemyshoot
									//q.detach();
									bullet_en[i] = 1;
									bex[i] = Ex[i] + 1;
									bey[i] = Ey[i] - 1;
									bulletenemydir[i] = 1;
								}
							}

						}
					if (keyen[i] == 'a')

					{
						check_enemy1 = cursor(Ex[i] - 1, Ey[i]);
						check_enemy2 = cursor(Ex[i] - 1, Ey[i] + 1);

						

						if (check_enemy1 == '.' || check_enemy2 == '.')
						{

							clear_bullet(bx, by);
							clear_enemy_bullet(bex[i], bey[i]);
							erase_enemy1(Ex[i], Ey[i]);
							bullet = 0;
							bullet_en[i] = 0;
							enemy_state[i] = 0;
							amount_enemy -= 1;
							P.point = P.point + 50;
							score(P.point);
						}
						
						if (Ey[i] == y && (Ex[i] - 1 == x || Ex[i] - 2 == x || Ex[i] - 3 == x || Ex[i] - 4 == x || Ex[i] - 5 == x || Ex[i] - 6 == x || Ex[i] - 7 == x || Ex[i] - 8 == x )|| ShootFrame[i] % 15 == 0)
						{
							checkwall1 = cursor(Ex[i] -1, Ey[i] );
							if (bullet_en[i] == 0 && enemy_state[i] == 1 && checkwall1 == ' ')
							{
								//std::thread q(Beep, 800, 200);//Soundenemyshoot
								//q.detach();
								checkwall1 = cursor(Ex[i] + 1, Ey[i]-1);
								bullet_en[i] = 1;
								bex[i] = Ex[i] - 1;
								bey[i] = Ey[i];
								bulletenemydir[i] = 2;
							}
						}

					}
					if (keyen[i] == 's')
					{
						check_enemy1 = cursor(Ex[i] + 1, Ey[i] + 2);
						check_enemy2 = cursor(Ex[i], Ey[i] + 1);
						check_enemy3 = cursor(Ex[i] + 2, Ey[i] + 1);

						

						if (check_enemy1 == '.' || check_enemy2 == '.' || check_enemy3 == '.')
						{

							clear_bullet(bx, by);
							clear_enemy_bullet(bex[i], bey[i]);
							erase_enemy1(Ex[i], Ey[i]);
							bullet = 0;
							bullet_en[i] = 0;
							enemy_state[i] = 0;
							amount_enemy -= 1;
							P.point = P.point + 50;
							score(P.point);
						}
						
						if (Ex[i] == x && (Ey[i] + 2 == y || Ey[i] + 3 == y || Ey[i] + 4 == y || Ey[i] + 5 == y || Ey[i] + 6 == y || Ey[i] + 7 == y || Ey[i] + 8 == y || Ey[i] + 9 == y )|| ShootFrame[i] % 15 == 0)
						{
							checkwall1 = cursor(Ex[i] + 1, Ey[i] + 2);
							if (bullet_en[i] == 0 && enemy_state[i] == 1 && checkwall1 == ' ')
							{
								//std::thread q(Beep, 800, 200);//Soundenemyshoot
								//q.detach();
								bullet_en[i] = 1;
								bex[i] = Ex[i] + 1;
								bey[i] = Ey[i] + 2;
								bulletenemydir[i] = 3;
							}
						}

					}
					if (keyen[i] == 'd')
					{
						check_enemy1 = cursor(Ex[i] + 3, Ey[i]);
						check_enemy2 = cursor(Ex[i] + 3, Ey[i] + 1);

						
						if (check_enemy1 == '.' || check_enemy2 == '.')
						{

							clear_bullet(bx, by);
							clear_enemy_bullet(bex[i], bey[i]);
							erase_enemy1(Ex[i], Ey[i]);
							bullet = 0;
							bullet_en[i] = 0;
							enemy_state[i] = 0;
							amount_enemy -= 1;
							P.point = P.point + 50;
							score(P.point);

						}
						
						if (Ey[i] == y && (Ex[i] + 3 == x || Ex[i] + 4 == x || Ex[i] + 5 == x || Ex[i] + 6 == x || Ex[i] + 7 == x || Ex[i] + 8 == x || Ex[i] + 9 == x || Ex[i] + 10 == x )|| ShootFrame[i] % 15 == 0)
						{
							checkwall1 = cursor(Ex[i] + 3, Ey[i] );
							if (bullet_en[i] == 0 && enemy_state[i] == 1 && checkwall1 == ' ')
							{
								//std::thread q(Beep, 800, 200);//Soundenemyshoot
								//q.detach();
								bullet_en[i] = 1;
								bex[i] = Ex[i] + 3;
								bey[i] = Ey[i];
								bulletenemydir[i] = 4;
							}
						}

					}

				}
				}

				//------------------ เปลี่ยนด่าน ---------------------//
				if (amount_enemy == 0)
				{
					
					door();
					
					if ( x==46 && y==18)
						{
						Sleep(300);
						std::thread q(Beep, 800, 200);//Soundchangefeild
						q.detach();
							chapter++;			

							if (chapter > 7){Gstate = End;}
							
							switch(chapter)
							{
							case 1:
								n_enemy = 1;
								amount_enemy = n_enemy;
								Gstate = PrePlay;
								break;
							case 2:
								n_enemy = 3;
								amount_enemy = n_enemy;
								countitem = 0;
								Gstate = PrePlay;
								break;
							case 3:
								n_enemy = 3;
								amount_enemy = n_enemy;
								countitem = 0;
								Gstate = PrePlay;
								break;
							case 4:
								n_enemy = 4;
								amount_enemy = n_enemy;
								countitem = 0;
								Gstate = PrePlay;
								break;
							case 5:
								n_enemy = 5;
								amount_enemy = n_enemy;
								countitem = 0;
								Gstate = PrePlay;
								break;
							case 6:
								n_enemy = 6;
								amount_enemy = n_enemy;
								countitem = 0;
								Gstate = PrePlay;
								break;
							case 7:
								n_enemy = 7;
								amount_enemy = n_enemy;
								countitem = 0;
								Gstate = PrePlay;
								break;
							}
							
							heal_state = 0;
							clrscr();
							Sleep(1000);
						}
				}

				

				//------------------ ศัตรูยิงกระสุน ------------------//
				for (int i = 0; i < n_enemy; i++) {
					if (bullet_en[i] == 1)
					{
						if (bulletenemydir[i] == 1)
						{
							bulletenemycheckwall1 = cursor(bex[i], bey[i] - 1);

							if (bulletenemycheckwall1 == ' ') {
								clear_enemy_bullet(bex[i], bey[i]);
								draw_enemy_bullet(bex[i], --bey[i]);
							}
							else
							{
								clear_enemy_bullet(bex[i], bey[i]);
								bullet_en[i] = 0;

							}


						}
						if (bulletenemydir[i] == 2)

						{
							bulletenemycheckwall1 = cursor(bex[i] - 1, bey[i]);

							if (bulletenemycheckwall1 == ' ') {
								clear_enemy_bullet(bex[i], bey[i]);
								draw_enemy_bullet(--bex[i], bey[i]);
							}
							else
							{
								clear_enemy_bullet(bex[i], bey[i]);
								bullet_en[i] = 0;


							}

						}
						if (bulletenemydir[i] == 3)
						{
							bulletenemycheckwall1 = cursor(bex[i], bey[i] + 1);

							if (bulletenemycheckwall1 == ' ') {
								clear_enemy_bullet(bex[i], bey[i]);
								draw_enemy_bullet(bex[i], ++bey[i]);
							}
							else
							{
								clear_enemy_bullet(bex[i], bey[i]);
								bullet_en[i] = 0;


							}

						}
						if (bulletenemydir[i] == 4)
						{
							bulletenemycheckwall1 = cursor(bex[i] + 1, bey[i]);

							if (bulletenemycheckwall1 == ' ') {
								clear_enemy_bullet(bex[i], bey[i]);
								draw_enemy_bullet(++bex[i], bey[i]);
							}
							else
							{
								clear_enemy_bullet(bex[i], bey[i]);
								bullet_en[i] = 0;


							}

						}
					}
				}

				//------------------ โดนศัตรูยิง ------------------//

				if (dir == 1)
				{

					checkbullet1 = cursor(x + 1, y - 1); checkbullet2 = cursor(x , y ); checkbullet3 = cursor(x + 2, y );
					if (checkbullet1 == '*'|| checkbullet2 =='*' || checkbullet3 == '*')
					{

						life = life - 1;
						clear_life();
						Life(life);

						if (life <= 0)
						{
							life = 0;
							Gstate = End;

						}

					}


				}
				if (dir == 2)

				{
					checkbullet1 = cursor(x - 1, y); checkbullet2 = cursor(x-1, y+1); 
					if (checkbullet1 == '*'|| checkbullet2 =='*' )
					{

						life = life - 1;
						clear_life();
						Life(life);

						if (life <= 0)
						{
							life = 0;
							Gstate = End;

						}

					}


				}
				if (dir == 3)
				{
					checkbullet1 = cursor(x + 1, y + 2); checkbullet2 = cursor(x , y + 1); checkbullet3 = cursor(x + 2, y+1);
					if (checkbullet1 == '*' || checkbullet2 == '*' || checkbullet3 == '*')
					{

						life = life - 1;
						clear_life();
						Life(life);

						if (life <= 0)
						{
							life = 0;
							Gstate = End;

						}

					}


				}
				if (dir == 4)
				{
					checkbullet1 = cursor(x + 3, y); checkbullet2 = cursor(x+3, y + 1); 
					if (checkbullet1 == '*' || checkbullet2 == '*')
					{

						life = life - 1;
						clear_life();
						Life(life);

						if (life <= 0)
						{
							life = 0;
							Gstate = End;

						}
					}


				}
	//----------------- Enemy Alert ----------------//


	//----------------- item -------------------//			
				if (itemframe % 400 == 0 && heal_state == 0 && chapter >2 && countitem < 4)
				{
					while (1) {
						Hx = 2 + (rand() % 39);
						Hy = 3 + (rand() % 27);

						check_item1 = cursor(Hx + 1, Hy);
						check_item2 = cursor(Hx - 1, Hy);
						check_item3 = cursor(Hx, Hy + 1);
						check_item4 = cursor(Hx, Hy - 1);

						if (check_item1 == ' ' && check_item2 == ' ' && check_item3 == ' ' && check_item4 == ' ')
						{
							break;
						}
					}
					heal(Hx,Hy);
					heal_state = 1;
					countitem++;
					
					
				}
				
				if (heal_state == 1)
				{
					if (dir == 1 && (x==Hx||x+1==Hx||x+2==Hx)&& (y==Hy))
					{
						life++;
						if (life >= 5) { life = 5; }
						heal_state = 0;
						clear_life();
						Life(life);
						
					}
					if (dir == 2 && (y  ==  Hy || y+1 == Hy ) && x == Hx )
					{
						life++;
						if (life >= 5) { life = 5; }
						heal_state = 0;
						clear_life();
						Life(life);
						
					}
					if (dir == 3 && (x  == Hx || x+1 == Hx || x + 2 == Hx) && y+1 == Hy)
					{
						life++;
						if (life >= 5) { life = 5; }
						heal_state = 0;
						clear_life();
						Life(life);
						
					}
					if (dir == 4 && (y == Hy || y + 1 == Hy) && x+2 == Hx)
					{
						life++;
						if (life >= 5) { life = 5; }
						heal_state = 0;
						clear_life();
						Life(life);
						
					}
				}


				for(int i = 0 ; i<n_enemy ; i++)
				{
					ShootFrame[i] ++ ;
				}

	//==============================================//			

				frame++;
				if (heal_state == 0)
				{
					itemframe++;
				}
				for (int i = 0; i < n_enemy; i++)
				{
					if (countwalk > walk[i])
					{
						countwalk = 0;
					}
				}
				Sleep(30);
				
			
			break;

	//---------------- Score Board -----------------//

		case Rank:
			setcolor(14,0);
			gotoxy(39, 10);
			printf("<< Score Board >>");
			setcolor(15, 0);
			gotoxy(0, 13);
			Read();
			
			setcolor(11, 0);
			gotoxy(2, 38);
			printf("<-ESC ");
			Gstate = Delay_rank;
			break;

	//----------------- Pause read file ---------------//

		case Delay_rank:

			if (_kbhit()) {
				key = _getch();

				
				if (key == VK_ESCAPE)
				{
					std::thread q(Beep, 300, 150);
					q.detach();
					Gstate = Menu;
					clrscr();
					Sleep(300);
				}

				fflush(stdin);

			}

			break;

		case HTP :

			setcolor(14, 0);
			gotoxy(42, 11);
			printf("HOW TO PLAY ?");

			setcolor(15, 0);
			gotoxy(41,15);
			printf("W,A,S,D - MOVE");

			gotoxy(41, 17);
			printf("SPACE BAR - SHOOT");

			gotoxy(41, 19);
			printf("@ ");
			printf("- HEAL ITEM");

			setcolor(4, 0);
			gotoxy(30, 23);
			printf("Destroy all enemies to be the winner .");

			setcolor(11, 0);
			gotoxy(2, 38);
			printf("<-ESC ");
			
			if (_kbhit()) {
				key = _getch();


				if (key == VK_ESCAPE)
				{
					std::thread q(Beep, 300, 150);
					q.detach();
					Gstate = Menu;
					clrscr();
					Sleep(300);
				}

				fflush(stdin);

			}
			break;


		

		//---------------------- End --------------------//

		case End:
			Sleep(500);
			clrscr();
			if (chapter <= 7) 
			{
				gameover(P.point);
			}
			else
			{
				winner(P.point);
			}
			ScoreBoard(P.name, P.point);
			P.point = 0;
			chapter = 1;
			countitem = 0;
			Gstate = Menu;
			Sleep(4000);
			clrscr();
			
			
			break;

		//--------------------- Exit -------------------//

		case Exit:
			
			PostMessage(GetConsoleWindow(), WM_CLOSE, 0, 0);
			break;
		}
	}
	return 0;

}
