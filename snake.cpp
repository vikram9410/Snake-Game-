#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
bool Gameover;
const int width=30,height=20;
int x,y,FruitX,FruitY,score;
enum edirection {STOP=0,LEFT,RIGHT,UP,DOWN};
edirection dir;
int TailX[100],TailY[100];
int nTail;
int Setup()
{
  Gameover=0;
  dir=STOP;
  x=width/2;
  y=height/2;
  FruitX=rand()%width;
  FruitY=rand()%height;
  score=0;
}
int Draw()
{
  system("cls");

 for(int i=0;i<width+1;i++)
    cout<<"#";
  cout<<endl;
  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++)
  {

  if(j==0)
  cout<<"#";
  if(i==y&&j==x)
    cout<<"O";
  else if(i==FruitY&&j==FruitX)
    cout<<"F";
   else
   {bool print=0;
    for(int k=0;k<nTail;k++)
    {
       if(TailX[k]==j&&TailY[k]==i)
       {cout<<"o";
       print=1;
       }
    }
if(!print)
    cout<<" ";
   }
  if(j==width-1)
    cout<<"#"<<endl;
  }
  }
    for(int i=0;i<width+1;i++)
    cout<<"#";
    cout<<endl<<"Score = "<<score<<endl;
}
int Input()
{
 if(_kbhit())
 {
      switch(_getch())
      {
       case 'a':
       dir=LEFT;
       break;
        case 'w':
       dir=UP;
       break;
        case 'd':
       dir=RIGHT;
       break;
        case 's':
       dir=DOWN;
       break;
        case 'x':
        Gameover=1;
       break;

      }


 }


}
int Logic()
{
   int prevX=TailX[0];
   int prevY=TailY[0];
   int prev2X,prev2Y;
   TailX[0]=x;
   TailY[0]=y;
   for(int i=1;i<nTail;i++)
   {
    prev2X=TailX[i];
    prev2Y=TailY[i];
    TailX[i]=prevX;
    TailY[i]=prevY;
    prevX=prev2X;
    prevY=prev2Y;
   }


   switch(dir)
      {
       case LEFT:
        x--;
       break;
        case UP:
       y--;
       break;
        case RIGHT:
       x++;
       break;
        case DOWN:
       y++;
       break;
        default:
        break;
}
 //  if you want to make your snake die only by hitting himself then do this
//  if(x>=width)x=0;else if(x<0)x=width-1;
// if(y>=height)y=0;else if(y<0)y=height-1;

//your snake will die by hitting wall and himself
 if(x>=width||x<0||y>=height||y<0)
    Gameover=1;

    for(int k=0;k<nTail;k++)
    {
      if(TailX[k]==x&&TailY[k]==y)
            Gameover=1;
    }
 if(x==FruitX&&y==FruitY)
 {
  score+=10;
  FruitX=rand()%width;
  FruitY=rand()%height;
  nTail++;
 }
}
int main()
{
  Setup();
  while(!Gameover)
  {
   Draw();
   Input();
   Logic();
   Sleep(10);
  }


}
