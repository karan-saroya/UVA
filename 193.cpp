#include<iostream>
#include<string>
int edges[110][110];
int flag[110];
int max=0;
int color[110];
void perm(string path, int prev)
{
	if()
	{
		
	}
	else
	{
		
	}
}
int main()
{
	int m,n,e,s,d;
	for(int i=0;i<m;i++)
	{
		max=0;
		scanf("%d%d",&n,&e);
		for(int j=1;j<=n;j++)
		{
			flag[j]=0;
			color[j]=0;
			for(int k=1;k<=n;k++)
			{
				edges[j][k]=0;			
			}
		}
		
		for(int j=1;j<=e;j++)
			scanf("%d%d",&s,&d);
		edges[s][d]=edges[d][s]=1;
		for(int j=1;j<=n;j++)
			perm(to_string(j),j);
	}
	return 0;
}
