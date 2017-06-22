#include<iostream>
#include<fstream>
using namespace std;
int dp[16][1130][1130];
int values[1130];
bool sieve[1130];
int main()
{
//	ofstream file;
//	file.open("output.txt");
	for(int i=0;i<1130;i++)
		sieve[i]=true;
	sieve[0]=false;
	sieve[1]=false;
	for(int i=2;i<1130;i++)
	{
		if(sieve[i] == true )
		{
			for(int j=i*i;j<1130;j+=i)
				sieve[j]=false;
		}
	}
	int n,c;
	while(true)
	{
		cin>>n>>c;
		if(n == c && c == 0)
			break;
		int count=0;
		for(int j=2;j<=n;j++)
		{
			if(sieve[j])
				{
					count++;
					values[count] = j;
					
				}
				
		}
		for(int k=0;k<=c;k++)
		{			
			for(int i=0;i<=n;i++)
			{
				for(int j=0;j<=count;j++)
				{		
						dp[k][i][j]=0;
				}
			}
		}
		for(int j=0;j<=count;j++)
			dp[0][0][j] =1;
	
	
		for(int k=1;k<=c;k++)
		{		
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=count;j++)
				{		
					
					dp[k][i][j] = dp[k][i][j-1];
					
					if(i-values[j]>=0)	
					{
						dp[k][i][j] = dp[k][i][j] + dp[k-1][i-values[j]][j-1] ;
						
					}
				
					
				
				}
			}
		}
		
		
	
		cout<<dp[c][n][count]<<endl;
		//file<<dp[c][n][count]<<endl;
	}
}
