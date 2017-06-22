#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
int edges[300][300];
int flag[300];
int m;
//ofstream fout;
int numP=0;
/*int perm(int count,string path, int prev)
{
	if(count == m)
	{
		if(edges[prev][1] == 1)
		{
			cout<<path+" "+to_string(1) <<endl;
			//fout<<path+" "+to_string(1) <<endl;
			numP++;
			return 0;
		}
		else 
			return -1;
	}
	else
	{
		int num_true=0;
		for(int i=1;i<=m;i++)
		{
			if(flag[i] == 0 && edges[i][prev] == 1)
			{
				num_true++;
				
				flag[i]=1;
				int ret=  perm(count+1,path+" "+to_string(i),i);
				flag[i]=0;
				if(ret == 0)
					return 0;
			}
		}
		
		return -1;
	}
}
*/

int main()
{
//	fout.open("out598.txt");
	while(scanf(" %d",&m)!= EOF)
	{
		numP=0;
		for(int i=1;i<300;i++)
			flag[i]=0;
		for(int i=1;i<300;i++)
		{
			for(int j=1;j<300;j++)
				edges[i][j]=0;
		
		}
		char c;
		int s,d;
		while(1)
		{
			scanf(" %c",&c);
			if(c == '%')
				break;
			
			else
			{
				scanf(" %d",&d);
			}
			s=(int)c-48;
			edges[s][d]=edges[d][s]=1;
		}
		
			flag[1]=1;
			perm(1,"1",1);
			if(numP == 0)
				{
					cout<<"N"<<endl;
				//	fout<<"N"<<endl;
				}
	}
	//fout.close();
}
