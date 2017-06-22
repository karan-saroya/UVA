#include<stdio.h>
int height[10010];
int main()
{
	int l,r,h;
	int end=0;
	int start=100000;
	while(scanf("%d%d%d",&l,&h,&r)!= EOF)
	{
		for(int i=l;i<r;i++)
			{
				if(height[i] < h)
					height[i]=h;
			}
		if(r>end)
			end=r;
		if(l < start)
			start=l;
	}
	int prev_value=0;
/*	for(int i=start;i<end;i++)
		{
			printf("%d %d\n",i,height[i]);
		}
*/	
	printf("%d ",start);
	for(int i=start;i<end;)
		{
			prev_value=height[i];
			int j=end;
			for(j=i+1;j<end;j++)
			{
				if(height[j] != prev_value)
					break;
			}
			printf("%d %d ",height[i],j);
			i=j;
		}
		printf("0\n");
	
	return 0;
	
}
