#include<iostream>
#include<vector>
using namespace std;
int bsearch(vector<int> &v, int l, int r, int key) 
{
    while(r-l>1)
    {
    	int m =(r+l)/2;
    	if(v[m]>=key)
    		r=m;
    	else
    		l=m;
    	
	}
	return r; 
}
int main()
{
	int n,test;
	cin>>n;
	vector<int> vec, lis;
	for(int i=0;i<n;i++)
		{
			cin>>test;
			vec.insert(vec.end(),test);
		}
		lis.insert(lis.begin(),vec[0]);
	for(int i=1;i<n;i++)
	{
		if(vec[i] < lis[0])
		{
			lis[0] = vec[i];
		}
		else if(vec[i] > lis[lis.size()-1])
		{
				lis.insert(lis.end(),vec[i]);
		}
		else
		{
			int ind = bsearch(lis,-1,lis.size(),vec[i]);
			lis[ind] = vec[i];
		}
	}
	cout<<lis.size()<<endl;
}
