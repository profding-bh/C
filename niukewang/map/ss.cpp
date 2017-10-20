#include <iostream>
#include <cstdio>
using namespace std;

char str[50][50];
char str2[50][50];


int search(int x,int y,int n,int m, int step)
{
	int maxstep = 1000000;
	int flagtemp = 0;
	
	if(str[x][y] == '0') return step;
	if( x>0 && (str[x-1][y] == '.' || str[x-1][y] == '0'))
	{
	   char temp=str[x][y];
	   	str[x][y] = '#';
	   	int temp1=search(x-1,y,n,m,step+1);
	   	if(temp1 != -1 && temp1<maxstep) 
		   {
		   	maxstep = temp1;
		   	flagtemp = 4;
		   }
	   	str[x][y] = temp;
	}
	
	if(x<n-1 && (str[x+1][y] == '.' || str[x+1][y] ==  '0'))
	{
		char temp = str[x][y];
		str[x][y] = '#';
		int temp1=search(x+1,y,n,m,step+1); 
		if(temp1 != -1 && temp1<maxstep) {
			maxstep = temp1;
				flagtemp = 1;
		}
		str[x][y] = temp; //
	}
	return step;
}

int main() {
    int n,m,startx,starty,start0x,start0y,endx,endy;
    cin>>n>>m;
    
    for(int i = 0;i<n;i++)
    {
    	for(int j = 0;j<m;++j){
    		cin>>str[i][j];
    		str2[i][j]=str[i][j];
    		if(str[i][j] == 'S')
    		{
    			startx = i;
    			starty = j;
			}
			if(str[i][j] == '0')
    		{
    			start0x = i;
    			start0y = j;
			}
			if(str[i][j] == 'E')
    		{
    			endx = i;
    			endy = j;
			}
		}
	}	
	int num = search(startx,starty,n,m,0);
    cout<<num<<endl;
	if(num == -1) cout<<"-1\n";
	else
	   {
	   	
	   }
	
	return 0;
}
