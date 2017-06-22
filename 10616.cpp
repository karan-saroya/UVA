#include<iostream>
#include<fstream>
using namespace std;
long long dp[11][20][201];
long long  values[201];
int main()
{
//	ofstream file;
//	file.open("output.txt");
	int sno=1;
  while(true)
  {
	
	
		int valc,q;
		cin>>valc>>q;
		if(valc == 0 && q == 0)
			break;
		for(int i=1;i<=valc;i++)
		{
			cin>>values[i];
		}
	
	cout<<"SET "<<sno<<":"<<endl;	
//	file<<"SET "<<sno<<":"<<endl;
	for(int p=1;p<=q;p++)
	{
		
		int m,d;
		cin>>d>>m;
		for(int i=0;i<11;i++)
		{
			for(int j=0;j<20;j++)
			{
				for(int k=0;k<201;k++)
					dp[i][j][k]=0;
			}
		}
		for(int k=0;k<=valc;k++)
			dp[0][0][k]=1;
	
		for(int i=1;i<=m;i++)
		{
			for(long long j=0;j<d;j++)
			{
				for(int k=1;k<=valc;k++)
				{
					dp[i][j][k]=dp[i][j][k-1];
					int ind;
					if(j-values[k] < 0)
					{
						ind=(d-(values[k]-j)%d)%d;
					}
					else
					{
						ind = ((j-values[k])%d)%d;
					}
					dp[i][j][k] += dp[i-1][ind][k-1]; 	
				}
			}
		}
		
		cout<<"QUERY "<<p<<": "<<dp[m][0][valc]<<endl;
		//file<<"QUERY "<<p<<": "<<dp[m][0][valc]<<endl;
 	}
	sno++;
  }
}
