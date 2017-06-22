#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int primes[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0};
int num[50];
int flag[50];
int n;
//ofstream fout;
void perm(int count,string s, int prev)
{
	if(count == n)
	{
		cout<<s<<endl;
//		fout<<s<<endl;
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			if(flag[i] ==0 && primes[num[i] + prev] == 1)
			{
				if(count == n-1 && primes[num[i] +1] == 0)
				{
					
				}
				else
				{
				
					flag[i] =1;
					perm(count + 1,s+" "+to_string(num[i]),num[i]);
					flag[i]=0;
				}
			}
		}
	}
}
int main()
{
	
//	fout.open("out.txt",ios::out);
	int cases=0;
	while(scanf("%d",&n)!= EOF)
	{		
		cases++;
		if(cases != 1)
			{
				printf("\n");
//				fout<<endl;
			}	
		for(int i=0;i<n;i++)
			{
				num[i]=i+1;
				flag[i]=0;
			}
		printf("Case %d:\n",cases);
//		fout<<"Case "<<cases<<":"<<endl;
		perm(1,"1",1);					// 1 4 3 2
		
	}
//	fout.close();
	return 0;
}
