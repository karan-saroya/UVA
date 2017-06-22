#define INF 30000
#include<iostream>
#include<fstream>
using namespace std;
int values[110];
int dp[50100][110];

int main()
{
//	ofstream file;
//	file.open("output.txt");
	int m;
	cin>>m;
	for(int l=0;l<m;l++)
	{
	
			int n;
			cin>>n;
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				cin>>values[i];
				sum+=values[i];
			}
			
			for(int i=0;i<=sum;i++)
			{
				for(int j=0;j<=n;j++)
				{
					dp[i][j]=INF;
				}
			}
			
			for(int i=1;i<=sum;i++)
			{
				dp[i][0]=i;
			}
			for(int i=0;i<=n;i++)
			{
				dp[0][i]=0;
			}
			int bal=sum/2;
			for(int i=1;i<=bal;i++)
			{
				for(int j=1;j<=n;j++)
				{
				
					dp[i][j] = dp[i][j-1];
					if(i-values[j] >=0)
						dp[i][j] = dp[i][j] < dp[i-values[j]][j-1] ? dp[i][j] :dp[i-values[j]][j-1];
				}
			}
				int lower= bal - dp[bal][n];
				int upper = sum-lower;
				cout<<upper-lower<<endl;
			
			//	file<<upper-lower<<endl;
	}
}
