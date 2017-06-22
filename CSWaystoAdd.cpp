#include<iostream>
#include<string>
using namespace std;
int nWays=0;
int tar;
int ways(int n,int k)
{
	if(n == 0 && k == 0)
	{
		nWays++;
	}
	else if(n == 0 || k == 0)
	{
		
	}
	else 
	{
		for(int i=0;i<=tar;i++)
		{
			if(n-i>=0)
			{
				ways(n-i,k-1);
			}
		}
	}
}
int main()
{
	cout<<"Enter target"<<endl;

	cin>>tar;
	cout<<"Enter k"<<endl;
	int k;
	cin>>k;
	ways(tar,k);
	cout<<nWays<<endl;
}
