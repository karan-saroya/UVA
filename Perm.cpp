#include<iostream>
#include<string>
using namespace std;
int flag[3];
void perm( int count, string s)
{
	if(count == 3)
	{
		
		cout<<s<<endl;
	}
	else
	{
		for(int i=0;i<3;i++)
		{
			if(flag[i]==0)
			{
				flag[i]=1;
				perm(count+1,s+""+to_string(i+1));
				
				flag[i]=0;
			}
			
		}
	}
}
int main()
{
	perm(0,"");
}
