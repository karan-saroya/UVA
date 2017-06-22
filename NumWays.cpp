#include<iostream>
#include<string>
using namespace std;
int ways[1000][100];
int val[100];
int main()
{

	int numC,tar;
	
	cout<<"Enter target value"<<endl;
	cin>>tar;
	cout<<"Enter the number of coins"<<endl;
	cin>>numC;
	for(int i=0;i<=tar;i++)
	{
		for(int j=0;j<numC;j++)
			ways[i][j]=0;
	}
	cout<<"Enter the coin values"<<endl;
	for(int i=0;i<numC;i++)
		{
			cin>>val[i];
			ways[val[i]][i]=1;
			ways[0][i]=1;
		}
	for(int i=1;i<=tar;i++)
	{
		for(int j=0;j<numC;j++)
		{
			if(ways[i][j] != 0)
			{
				for(int k=j;k<numC;k++)
				{
					ways[i+val[k]][k] += ways[i][j];  
				}
			}
			
			
		}
	}
	
	int ans=0;
	for(int j=0;j<numC;j++)
	{
		ans+=ways[tar][j];
	}
	cout<<"Number of ways"<<endl;
	cout<<ans<<endl;
	return 0;
}
