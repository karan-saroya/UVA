#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int d;
	while(1)
	{
		scanf("%d",&d);
		if(d == 42)
			break;
		else
			printf("%d\n",d);
		
	}
	return 0;
}
