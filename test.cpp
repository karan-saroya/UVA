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
	vector<int> v;
	int n;
	cin>>n;
	int test;
	for(int i=0;i<n;i++)
			{
				cin>>test;
				v.insert(v.end(),test);
			}
	int key;
	cin>>key;
	cout<<bsearch(v,-1,v.size(),key);
}
