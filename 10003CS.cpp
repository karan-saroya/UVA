#include<iostream>
#include<string>
using namespace std;

int cuts[51];
bool bcuts[51];
int max=100000000;
int l,n;
int lc(int l, int r)
{
	int flag=false;
	int m =100000000;
		for(int i=1;i<=n;i++)
		{
			if(!bcuts[i] && l < cuts[i] && r > cuts[i]) 
			{
				flag=true;
				bcuts[i] =true;
				if(r-l+1 + lc(l,cuts[i]) + lc(cuts[i],r) < m )
						m = r-l + lc(l,cuts[i]) + lc(cuts[i],r);
				bcuts[i]=false;
			}
			
		}	
	if(!flag)
	{
		return 0;
	}
	else
		return m;
}
int main()
{
	
	cin>>l>>n;
	for(int i=1;i<=n;i++)
		{
			cin>>cuts[i];
			bcuts[i]=false;
		}
	cout<<lc(0,l);	
	
}
