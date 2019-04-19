// ds41.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;
#include <iostream>
const int m=6,n=8;
int maze[m+2][n+2];
int mark[m+2][n+2];
int move1[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

        bool SeekPath(int x,int y)
            //从迷宫中坐标点(x,y)的位置寻找通向终点(m,n)的路径，若找到则
            //返回true，否则返回false，(x,y)的初始值通常为(1,1)
        {
          //i作为循环变量，代表从当前位置移到下一个位置的方向
            int i;
          //g和h用作为下一个位置的行坐标和列坐标
            int g,h;
          //到达出口点返回true结束递归
            if((x==m)&&(y==n)) return true;  
          //依次按每个方向寻找通向终点的路径，i=0,1,2,3分别为东,南,西,北方向
            for(i=0; i<4; i++)
            {
              //求出下一个位置的行坐标和列坐标 
                g=x+move1[i][0]; h=y+move1[i][1]; 
              //若下一位置可通行同时没有被访问过，则从该位置起寻找
                if((maze[g][h]==0)&&(mark[g][h]==0))
                {
                  //置mark数组中对应位置为1，表明已访问过
                    mark[g][h]=1;
                  //当条件成立(即返回true)时，表明从(g,h)到终点存在
                  //通路，应输出该位置坐标，同时返回true结束递归，
                  //否则进入下一轮循环，向下一个方向试探
                    if(SeekPath(g,h)) {
                        cout<<"("<<g<<","<<h<<"), ";
                        return true;
                    }
                }
            }
          //从当前位置(x,y)没有通向终点的路径，应返回false
            return false;
        }

int main(int argc, _TCHAR* argv[])
{
	cout<<"Hello world!"<<endl;
	int i,j;
	/*
	maze[1][1]=0;maze[1][2]=0;maze[1][3]=1;maze[1][4]=1;maze[1][5]=0;
			maze[1][6]=1;maze[1][7]=0;maze[1][8]=1;
	maze[2][1]=1;maze[2][2]=0;maze[2][3]=0;maze[2][4]=1;maze[2][5]=1;
			maze[2][6]=0;maze[2][7]=0;maze[2][8]=0;
	maze[3][1]=0;maze[3][2]=0;maze[3][3]=0;maze[3][4]=0;maze[3][5]=0;
			maze[3][6]=0;maze[3][7]=1;maze[3][8]=1;
	maze[4][1]=1;maze[4][2]=1;maze[4][3]=0;maze[4][4]=1;maze[4][5]=1;
			maze[4][6]=0;maze[4][7]=0;maze[4][8]=0;
	maze[5][1]=0;maze[5][2]=0;maze[5][3]=0;maze[5][4]=0;maze[5][5]=0;
 			maze[5][6]=1;maze[5][7]=0;maze[5][8]=1;
	maze[6][1]=1;maze[6][2]=0;maze[6][3]=1;maze[6][4]=0;maze[6][5]=0;
			maze[6][6]=0;maze[6][7]=0;maze[6][8]=0;
			//墙壁
	maze[0][0]=1;maze[0][1]=1;maze[0][2]=1;maze[0][3]=1;maze[0][4]=1;
		maze[0][5]=1;maze[0][6]=1;maze[0][7]=1;maze[0][8]=1;maze[0][9]=1;
	maze[7][0]=1;maze[7][1]=1;maze[7][2]=1;maze[7][3]=1;maze[7][4]=1;
		maze[7][5]=1;maze[7][6]=1;maze[7][7]=1;maze[7][8]=1;maze[7][9]=1;
	maze[1][0]=1;maze[2][0]=1;maze[3][0]=1;maze[4][0]=1;maze[5][0]=1;maze[6][0]=1;
	maze[1][9]=1;maze[2][9]=1;maze[3][9]=1;maze[4][9]=1;maze[5][9]=1;maze[6][9]=1;
		*/
	for(i=0;i<m+2;i++){
		cout<<"请输入第"<<i<<"行数据："<<endl;
		for(j=0;j<n+2;j++)
			cin>>maze[i][j];
	}
	for(i=0;i<m+2;i++)
		for(j=0;j<n+2;j++)
		mark[i][j]=0;
	mark[1][1]=1;
	if (SeekPath(1,1))
		cout<<"("<<1<<","<<1<<")"<<endl;
	else
		cout<<"此迷宫无通路！"<<endl;
	char c;
	cin>>c;
	return 0;
}

