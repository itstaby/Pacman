#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;


int dotcount=0;

/* STANDARD DEFINITON OF THE GOTO XY FUNCITON */

void gotoxy(int x,int y)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD cursor_coord;
	cursor_coord.X=x;
	cursor_coord.Y=y;
	SetConsoleCursorPosition(hStdOut,cursor_coord);
}

void color(int x)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle,x);
}

/**********************************************/

/* FUNCTION PROTOTYPES FOR OBJECT MOTION AND PRINTNG THE MAZE AND FOOD*/

void moveup(int& x, int& y, char **a, int& seedcount);
void movedown(int& x, int& y, char **a, int& seedcount);
void moveright(int& x, int& y, char **a, int& seedcount);
void moveleft(int& x, int& y, char **a, int& seedcount);
void moveupe(int& x, int& y, char **a);
void movedowne(int& x, int& y, char **a);
void moverighte(int& x, int& y, char **a);
void movelefte(int& x, int& y, char **a);
void enemyPattern(char**);
void enemychange(char **,int x, int y, char& m);
void maze(char**);
void food(char**);
void game();
void menu();
void flash(int x, int y, int t, int u, char c);

/**********************************************************************/
void main()
{
	system ("mode 80,27");
	system("color 07");
	game();
}

void menu()
{
	system("cls");
	gotoxy(50,50);
	system("color 49");
	cout<<"--> MAIN MENU <--";
}


void game ()
{
	
	srand(time(0));
	char** a= new char*[80];

	for (int i=0; i<80; i++)
		a[i]=new char [23];

	char** b= new char*[80];

	for (i=0; i<80; i++)
		b[i]=new char [23];


	
	
	for  (i=0; i<80; i++)
		for (int j=0; j<23; j++)
		{
			a[i][j]=' ';
		}

	int seedcount=0;
	int randomCount=0;
	
	maze(a);
	food(a);
	enemyPattern(b);
	int y=1;
	int x=1;
	int w=2;
	int u=2;
	char n=77;
	char m=80;
	char q;
	do
	{	
		if(x==u && y==w)
		{
			system("cls");
			gotoxy(50,5);
			cout<<"You lost!\n";
			gotoxy(50,6);
			exit(0);
		}

		do
		{
			
			
			if(x==u && y==w)
			{
				system("cls");
				gotoxy(50,5);
				cout<<"You lost!\n";
				gotoxy(50,6);
				exit(0);
			}
			
			
			if(kbhit()!=0)
			{
				n=getch();
				if(n!=77 && n!=80 && n!=72 && n!= 75 && n!=27 && n!=' ')
				{	
					//n=q;
					//m=q;

				}
				else
					q=n;
			}
			
			switch(n)
			{
				case 72:
					{
						moveup(x,y,a,seedcount);
						
						if(x==u && y==w)
						{
							system("cls");
							gotoxy(50,5);
							cout<<"You lost!\n";
							gotoxy(50,6);
							exit(0);
						}
						break;

					}
				case 80:
					{
						movedown(x,y,a,seedcount);
						
						if(x==u && y==w)
						{
							system("cls");
							gotoxy(50,5);
							cout<<"You lost!\n";
							gotoxy(50,6);
							exit(0);
						}
						break;
					}
				case 75:
					{
						moveleft(x,y,a,seedcount);
						
						if(x==u && y==w)
						{
							system("cls");
							gotoxy(50,5);
							cout<<"You lost!\n";
							gotoxy(50,6);
							exit(0);
						}
						break;
					}
				case 77:
					{
						moveright(x,y,a,seedcount);

						if(x==u && y==w)
						{
							system("cls");
							gotoxy(50,5);
							cout<<"You lost!\n";
							gotoxy(50,6);
							exit(0);
						}

						break;
					}

				case 27:
					{
						system("CLS");
						exit(0);
						break;
					}
				case 'a':
					{
						m=75;
						break;
					}
				case 's':
					{
						m=80;
						break;
					}
				case 'd':
					{
						m=77;
						break;
					}
				case 'w':
					{
						m=72;
						break;
					}


			}

			

			switch(m)
			{
				case 72:
					{
						moveupe(u,w,a);
						break;
					}
				case 80:
					{
						movedowne(u,w,a);
						break;
					}
				case 75:
					{
						movelefte(u,w,a);
						break;
					}
				case 77:
					{
						moverighte(u,w,a);
						break;
					}


			}
			
			
			
			if(x==u && y==w)
			{
				system("cls");
				gotoxy(50,5);
				cout<<"You lost!\n";
				gotoxy(50,6);
				exit(0);
			}
			
		//	randomCount++;
		//	if(randomCount%4==0)
		//	{
				enemychange(b,u,w,m);
			//}

			

			
		//	gotoxy(x,y);
		//	cout<<(char) 15;
			Sleep(150);





		}while(1);
			
			
			
			
		n=getch();
		if(n!=77 && n!=80 && n!=72 && n!= 75 && n!=27 && n!=' ')
		{	
			n=q;
			//m=q;

		}
		q=n;

		

	}while(n!=27);
	
	cout<<seedcount;
}

void moveup(int& x, int& y, char **a, int& seedcount)
{
	if(a[x][y-1]!='q')
	{
		if(a[x][y]==(char) 249)
		{
		 seedcount++;
		 a[x][y]=' ';
		}
		gotoxy(x,y);
		cout<<" ";
		y--;
		gotoxy(x,y);
		cout<<(char) 30;
		gotoxy(0,24);
		cout<<"Score: "<<seedcount;
	}

		


}
void movedown(int& x, int& y, char **a, int& seedcount)
{
	if(a[x][y+1]!='q')
	{
		if(a[x][y]==(char) 249)
		{
			seedcount++;
			a[x][y]=' ';
		}
		gotoxy(x,y);
		cout<<" ";
		y++;
		gotoxy(x,y);
		cout<<(char) 31;
		;
		gotoxy(0,24);
		cout<<"Score: "<<seedcount;
	}

		
	
}

void moveright(int& x, int& y, char **a, int& seedcount)
{
	if(a[x+1][y]!='q')
	{
		if(a[x][y]==(char) 249)
		{
			seedcount++;
			a[x][y]=' ';
		}
		gotoxy(x,y);
		cout<<" ";
		x++;
		gotoxy(x,y);
		cout<<(char) 16;
		;
		gotoxy(0,24);
		cout<<"Score: "<<seedcount;
	}
	
}
void moveleft(int& x, int& y, char **a, int& seedcount)
{
	if(a[x-1][y]!='q')
	{
		if(a[x][y]==(char) 249)
		{
			seedcount++;
			a[x][y]=' ';
		}
		gotoxy(x,y);
		cout<<" ";
		x--;
		gotoxy(x,y);
		cout<<(char) 17;
		;
		gotoxy(0,24);
		cout<<"Score: "<<seedcount;
	}
}

void moveupe(int& x, int& y, char **a)
{
	if(a[x][y-1]!='q')
	{
		gotoxy(x,y);
		cout<<" ";
		y--;
		gotoxy(x,y);
		color(12);
		cout<<(char) 233;
		color(07);	
		gotoxy(0,24);
		if(a[x][y+1]==(char) 249)
		{	
			gotoxy(x,y+1);
			color(10);
			cout<<(char) 249;
			color(07);		
		}
	}

		


}
void movedowne(int& x, int& y, char **a)
{
	if(a[x][y+1]!='q')
	{
		gotoxy(x,y);
		cout<<" ";
		y++;
		gotoxy(x,y);
		color(12);
		cout<<(char) 233;
		color(07);
		if(a[x][y-1]==(char) 249)
		{
			gotoxy(x,y-1);
			color(10);
			cout<<(char) 249;
			color(07);
		}
		;
		gotoxy(0,24);
	}

		
	
}

void moverighte(int& x, int& y, char **a)
{
	if(a[x+1][y]!='q')
	{
		
		gotoxy(x,y);
		cout<<" ";
		x++;
		gotoxy(x,y);
		color(12);
		cout<<(char) 233;
		color(07);
		if(a[x-1][y]==(char) 249)
		{
			gotoxy(x-1,y);
			color(10);
			cout<<(char) 249;
			color(07);
		}
		;
		gotoxy(0,24);
	}
	
}
void movelefte(int& x, int& y, char **a)
{
	if(a[x-1][y]!='q')
	{
	
		gotoxy(x,y);
		cout<<" ";
		x--;
		gotoxy(x,y);
		color(12);
		cout<<(char) 233;
		color(07);
		gotoxy(0,24);
		if(a[x+1][y]==(char) 249)
		{
			gotoxy(x+1,y);
			color(10);
			cout<<(char) 249;
			color(07);
		}
	}
}

void maze(char** a)
{

	color(19);
	/* THE OUTER BOX*/
	for (int i=0; i<=79; i++)
	{
		gotoxy(i,0);
		cout<<(char)219;
		a[i][0]='q';
	}

	for (i=1; i<=23; i++)
	{
		gotoxy(0,i);
		cout<<(char)219;
		a[0][i]='q';
	}

	for (i=0; i<=23; i++)
	{
		gotoxy(79,i);
		cout<<(char)219;
		a[79][i]='q';
	}

	for (i=1; i<=79; i++)
	{
		gotoxy(i,23);
		cout<<(char)219;
		a[i][23]='q';
	}
	/*********************/
	
	cout<<"\nPress Esc to exit!";

	/* THE FIRST INNER BOX */

	for (i=5; i<=74; i++)
	{
		gotoxy(i,4);
		cout<<(char)219;
		a[i][4]='q';
	}

	for (i=5; i<=19; i++)
	{
		if(i==12 || i==11)
			continue;
		gotoxy(5,i);
		cout<<(char)219;
		a[5][i]='q';
	}

	for (i=5; i<=19; i++)
	{
		if(i==12 || i==11)
			continue;
		gotoxy(74,i);
		cout<<(char)219;
		a[74][i]='q';
	}

	for (i=5; i<=74; i++)
	{
		gotoxy(i,19);
		cout<<(char)219;
		a[i][19]='q';
	}

	/*******************/

	/* THE SECOND INNER BOX */

	for (i=10; i<=69; i++)
	{
		gotoxy(i,8);
		cout<<(char)219;
		a[i][8]='q';
	}

	for (i=8; i<=15; i++)
	{
		if(i==12 || i==11)
			continue;
		gotoxy(10,i);
		cout<<(char)219;
		a[10][i]='q';
	}

	for (i=8; i<=15; i++)
	{
		if(i==12 || i==11)
			continue;
		gotoxy(69,i);
		cout<<(char)219;
		a[69][i]='q';
	}

	for (i=10; i<=69; i++)
	{
		gotoxy(i,15);
		cout<<(char)219;
		a[i][15]='q';
	}
	color(07);
	/***********************/
	/*for  (i=0; i<80; i++)
		for (int j=0; j<23; j++)
		{
			if(a[i][j]==' ')
			{
				gotoxy(i,j);
				cout<<j;
			}
		}*/

}

void food(char** a)
{
	color(10);
	

	/* THE OUTER SEEDS */
	for (int i=2; i<=21; i++)
	{
		if(i%2==0)
			continue;
		a[2][i]=(char) 249;
		gotoxy(2,i);
		cout<<a[2][i];
	}

	for (i=2; i<=77; i++)
	{
		if(i%2==0)
			continue;
		a[i][2]=(char) 249;
		gotoxy(i,2);
		cout<<a[i][2];
	}
	for (i=2; i<=21; i++)
	{
		if(i%2==0)
			continue;
		a[77][i]=(char) 249;
		gotoxy(77,i);
		cout<<a[77][i];
	}
	
	for (i=2; i<=77; i++)
	{
		if(i%2==0)
			continue;
		a[i][21]=(char) 249;
		gotoxy(i,21);
		cout<<a[i][21];
	}

	/* INNER SEEDS */
	for (i=6; i<=17; i++)
	{
		if(i%2==0)
			continue;
		a[8][i]=(char) 249;
		gotoxy(8,i);
		cout<<a[8][i];
	}

	
	for (i=6; i<=17; i++)
	{
		if(i%2==0)
			continue;
		a[72][i]=(char) 249;
		gotoxy(72,i);
		cout<<a[72][i];
	}
	for (i=8; i<=72; i++)
	{
		if(i%2==0)
			continue;
		a[i][17]=(char) 249;
		gotoxy(i,17);
		cout<<a[i][17];
	}

	for (i=8; i<=72; i++)
	{
		if(i%2==0)
			continue;
		a[i][6]=(char) 249;
		gotoxy(i,6);
		cout<<a[i][6];
	}

	for (i=12; i<=67; i++)
	{
		if(i%2==0)
			continue;
		a[i][10]=(char) 249;
		gotoxy(i,10);
		cout<<a[i][10];
	}

	for (i=12; i<=67; i++)
	{
		if(i%2==0)
			continue;
		a[i][13]=(char) 249;
		gotoxy(i,13);
		cout<<a[i][13];
	}
	
	/* THE INNER MOST SEEDS */

	i=12;
	while(i<=67)
	{
	//	if(i%2==0)
		//	continue;
		a[i][11]=(char) 249;
		gotoxy(i,11);
		cout<<a[i][11];
	
		a[i][12]=(char) 249;
		gotoxy(i,12);
		cout<<a[i][12];

		i+=55;
	}

	color(07);
	

}

void enemyPattern(char** b)
{
	for  (int i=0; i<80; i++)
		for (int j=0; j<23; j++)
			b[i][j]='0';


	b[2][21]=b[1][21]=b[1][22]=b[2][22]=b[3][22]=b[1][20]=b[3][1]=b[6][18]=b[7][18]=b[8][18]=b[6][17]=b[7][17]=b[8][17]=b[6][16]=b[7][16]=b[8][16]=b[11][14]=b[12][14]=b[13][14]=b[12][13]=b[13][13]=b[4][22]=b[9][18]='2';
	b[2][2]=b[1][1]=b[1][2]=b[2][1]=b[6][5]=b[7][5]=b[6][6]=b[7][7]=b[1][3]=b[5][8]=b[5][9]=b[4][8]=b[4][9]=b[11][9]=b[12][9]=b[13][9]=b[11][10]=b[12][10]=b[13][10]=b[11][11]=b[9][5]=b[8][5]='1';
//	b[3][3]='1';
//	b[78][1]='1';
	b[77][21]=b[78][21]=b[78][22]=b[77][22]=b[76][22]=b[3][22]=b[73][18]=b[72][18]=b[71][18]=b[73][17]=b[72][17]=b[71][17]=b[73][16]=b[72][16]=b[71][16]=b[69][14]=b[68][14]=b[69][13]=b[68][13]=b[67][13]=b[66][18]=b[70][18]='3';
	b[77][1]=b[77][2]=b[78][1]=b[78][2]=b[76][1]=b[73][5]=b[72][5]=b[71][5]=b[73][6]=b[72][6]=b[71][6]=b[69][9]=b[68][9]=b[70][5]=b[73][7]=b[68][10]=b[67][10]='4';
	
//	b[76][1]='1';

	for(i=1; i<3; i++)
	{
		b[i][11]='5';
		b[i][12]='5';
	}
	for(i=77; i<79; i++)
	{
		b[i][11]='6';
		b[i][12]='6';
	}

	for(i=11; i<13; i++)
	{
		b[i][11]='9';
		b[i][12]='9';
	}
	/*for(i=68; i<70; i++)
	{
		b[i][11]='10';
		b[i][12]='10';
	}*/
	for(i=7; i<10; i++)
	{
		b[i][11]='9';
		b[i][12]='9';
	}
	for(i=70; i<73; i++)
	{
		b[i][11]='9';
		b[i][12]='9';
	}
	
}


void enemychange(char**b, int x, int y, char& m)
{
	int r;
	r=rand()%40;
	if(b[x][y]=='9')
	{
	
		if(r>=0 && r<=9)
		{
			m=72;
		}
		if(r>=10 && r<=19)
		{
			m=80;
		}
		if(r>=20 && r<=29)
		{
			m=75;
		}
		if(r>=30 && r<=39)
		{
			m=77;
		}

	}
	if(b[x][y]=='1')
	{
		
		if(r>=0 && r<=19)
		{
			m=80;
		}
		if(r>=20 && r<=39)
		{
			m=77;
		}

	}
	if(b[x][y]=='2')
	{
		
		if(r>=0 && r<=19)
		{
			m=72;
		}
		if(r>=20 && r<=39)
		{
			m=77;
		}

	}
	if(b[x][y]=='3')
	{
		
		if(r>=0 && r<=19)
		{
			m=72;
		}
		if(r>=20 && r<=39)
		{
			m=75;
		}

	}
	if(b[x][y]=='4')
	{
		
		if(r>=0 && r<=19)
		{
			m=80;
		}
		if(r>=20 && r<=39)
		{
			m=75;
		}

	}
	if(b[x][y]=='5')
	{
	
		if(r>=0 && r<=13)
		{
			m=72;
		}
		if(r>=13 && r<=19)
		{
			m=80;
		}
		if(r>=10 && r<=39)
		{
			m=77;
		}

	}
	if(b[x][y]=='6')
	{
	
		if(r>=0 && r<=9)
		{
			m=72;
		}
		if(r>=10 && r<=19)
		{
			m=80;
		}
		if(r>=20 && r<=39)
		{
			m=75;

		}
	}
	if(b[x][y]=='7')
	{
	
		if(r>=0 && r<=13)
		{
			m=72;
		}
		if(r>=13 && r<=19)
		{
			m=80;
		}
		if(r>=10 && r<=39)
		{
			m=77;
		}
	}
	if(b[x][y]=='8')
	{
	
		if(r>=0 && r<=9)
		{
			m=72;
		}
		if(r>=10 && r<=19)
		{
			m=80;
		}
		if(r>=20 && r<=39)
		{
			m=75;

		}
	}
	if(b[x][y]=='9')
	{
	
		if(r>=0 && r<=13)
		{
			m=72;
		}
		if(r>=13 && r<=19)
		{
			m=80;
		}
		if(r>=10 && r<=39)
		{
			m=77;
		}
	}
	/*if(b[x][y]=='10')
	{
		if(r>=0 && r<=9)
		{
			m=72;
		}
		if(r>=10 && r<=19)
		{
			m=80;
		}
		if(r>=20 && r<=29)
		{
			m=75;
		}
		if(r>=30 && r<=39)
		{
			m=77;
		}
	}
*/

}

