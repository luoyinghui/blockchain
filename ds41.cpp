// ds41.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;
#include <iostream>
const int m=6,n=8;
int maze[m+2][n+2];
int mark[m+2][n+2];
int move1[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

        bool SeekPath(int x,int y)
            //���Թ��������(x,y)��λ��Ѱ��ͨ���յ�(m,n)��·�������ҵ���
            //����true�����򷵻�false��(x,y)�ĳ�ʼֵͨ��Ϊ(1,1)
        {
          //i��Ϊѭ������������ӵ�ǰλ���Ƶ���һ��λ�õķ���
            int i;
          //g��h����Ϊ��һ��λ�õ��������������
            int g,h;
          //������ڵ㷵��true�����ݹ�
            if((x==m)&&(y==n)) return true;  
          //���ΰ�ÿ������Ѱ��ͨ���յ��·����i=0,1,2,3�ֱ�Ϊ��,��,��,������
            for(i=0; i<4; i++)
            {
              //�����һ��λ�õ�������������� 
                g=x+move1[i][0]; h=y+move1[i][1]; 
              //����һλ�ÿ�ͨ��ͬʱû�б����ʹ�����Ӹ�λ����Ѱ��
                if((maze[g][h]==0)&&(mark[g][h]==0))
                {
                  //��mark�����ж�Ӧλ��Ϊ1�������ѷ��ʹ�
                    mark[g][h]=1;
                  //����������(������true)ʱ��������(g,h)���յ����
                  //ͨ·��Ӧ�����λ�����꣬ͬʱ����true�����ݹ飬
                  //���������һ��ѭ��������һ��������̽
                    if(SeekPath(g,h)) {
                        cout<<"("<<g<<","<<h<<"), ";
                        return true;
                    }
                }
            }
          //�ӵ�ǰλ��(x,y)û��ͨ���յ��·����Ӧ����false
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
			//ǽ��
	maze[0][0]=1;maze[0][1]=1;maze[0][2]=1;maze[0][3]=1;maze[0][4]=1;
		maze[0][5]=1;maze[0][6]=1;maze[0][7]=1;maze[0][8]=1;maze[0][9]=1;
	maze[7][0]=1;maze[7][1]=1;maze[7][2]=1;maze[7][3]=1;maze[7][4]=1;
		maze[7][5]=1;maze[7][6]=1;maze[7][7]=1;maze[7][8]=1;maze[7][9]=1;
	maze[1][0]=1;maze[2][0]=1;maze[3][0]=1;maze[4][0]=1;maze[5][0]=1;maze[6][0]=1;
	maze[1][9]=1;maze[2][9]=1;maze[3][9]=1;maze[4][9]=1;maze[5][9]=1;maze[6][9]=1;
		*/
	for(i=0;i<m+2;i++){
		cout<<"�������"<<i<<"�����ݣ�"<<endl;
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
		cout<<"���Թ���ͨ·��"<<endl;
	char c;
	cin>>c;
	return 0;
}

