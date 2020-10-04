#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width=40;
const int height=20;
int x,y,fruitX, fruitY, score;
int tailX[100] , tailY[100];
int nTail;


enum eDirection {STOP=0 , LEFT , RIGHT , UP , DOWN};
eDirection dir;

void setUp(){
	gameOver=false;
	dir=STOP;
	x=width/2;
	y=height/2;
	fruitX=rand()%width;
	fruitY=rand()%height;
	score=0;
	
	
}
void draw (){
	system("cls");
	char arr[height][width];
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			if(i==0)arr[i][j]='#';
			else if(j==0)arr[i][j]='#';
			else if(i==height-1)arr[i][j]='#';
			else if(j==width-1)arr[i][j]='#';
			else arr[i][j]=' ';
			
		}
	}
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			cout<<arr[i][j];
			if(i==y && j==x)
				cout<<"O";
			else if (i==fruitY && j==fruitX)
				cout<<"F";
			else {
					bool print=0;
				for(int k=0; k<nTail; k++)
				{
		
					if(tailX[k]==j && tailY[k]==i){
						cout<<'o';
						print =1;
					}
				
				}
				if(!print)
					cout<<" ";
			}
		}
		cout<<endl;
	}
	
	cout<<"\n\n\t\tSCORE:" <<score;
	
}
void input(){
	if(_kbhit()){
		switch(_getch()){
			case 'a': 
				dir=LEFT;break;
			case 'd': 
				dir=RIGHT;break;
			case 'w': 
				dir=UP;break;
			case 's': 
				dir=DOWN;break;
			case 'x': 
				gameOver=1;break;
			
		}
	}
	
}

void logic(){
	
	int prevX=tailX[0];	
	int prevY=tailY[0];
	int prev2X,prev2Y;
	tailX[0]=x;
	tailY[0]=y;
	for(int i=1 ; i<nTail;i++){
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevY=prev2Y;
		prevX=prev2X;
	}
	switch (dir){
			case LEFT: 
				x--;
				break;
			case RIGHT:
				x++; 
				break;
			case UP:
				y--; 
				break;
			case DOWN:
				y++;
				break;
			default: break;			
	}
	
	if (x == width-1) x = 0; 
	else if (x < 0) x = width - 1;
    if (y == height-1) y = 0; 
	else if (y < 0) y = height - 1;
	
	for(int i=1 ; i<nTail;i++){
		if(tailX[i]==x && tailY[i]==y ){
			gameOver=1;
			cout<<"\n\n\n\t=========================\n"
			    <<"\t========GAME OVER========\n"
			    <<"\t=========================";
		}
	}
	if(x==fruitX && y==fruitY){
		score+=10;
		fruitX=rand()%(width-1);
		fruitY=rand()%(height-1);
		nTail++;
	}
	
}
int main()
{
	setUp();
	while(!gameOver){
		draw();
		input();
		logic();
		Sleep(100);
	}

}
