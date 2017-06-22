#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool  comp(int  a, int b)
{
	return a< b;
}
int main()
{
	int n;
	cin>>n;
	int a[200010],b[200010];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	vector<int> v;
	int test;
	for(int i=0;i<n;i++)
	{
		cin>>test;
		b[i] = test;
	
		v.insert(v.end(),test);
	}
	sort(v.begin(),v.end(),comp);
	for(int i=0;i<n-1;i++)
	{
	
		if (find(v.begin(),v.end(),a[i]) == v.end())
		{
			cout<<b[i]<<" ";
		}
		else
		{
			cout<<(a[i]>b[i]?a[i]:b[i])<<" ";
		}
	}
		if (find(v.begin(),v.end(),a[n-1]) == v.end())
		{
			cout<<b[n-1];
		}
		else
		{
			cout<<(a[n-1]>b[n-1])?a[n-1]:b[n-1];
		}
		cout<<endl;
	
}
