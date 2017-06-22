#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int num[12];
int n;
int flag[12];
void perm(int tar,string s,int count,int ind )
{
	if(count == n)
	{
		if(tar == 0)
		{
			cout<<s<<endl;
			
		}
		else if(tar < 0)
		 return;
		else
		{
			return;
		}
	}
	else
	{
		if(tar == 0)
		{
			cout<<s<<endl;
			
		}
		else if(tar < 0)
		 return;
		else
		{
			for(int i=ind;i<n;i++)
			{
				if(flag[i] == 0 && tar-num[i] >=0)
				{
					flag[i]=1;
					if(s.size() == 0)
						perm(tar-num[i],s+to_string(num[i]),count + 1,i+1);
					else
						perm(tar-num[i],s+"+"+to_string(num[i]),count + 1,i+1);
					flag[i] =0;
				}
			}
		}
	}
}
int main()
{
	while(1)
	{
		int t;
		scanf("%d %d",&t,&n);
		if(n ==0)
			break;
		
		for(int i=0;i<n;i++)
			{
				scanf("%d",&num[i]);
				flag[i]=0;
			}
		perm(t,"",0,0);
		
	}
}
