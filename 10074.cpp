#include<iostream>
#include<fstream>
#define INF -1000
using namespace std;
long long  arr[100][100];
long long sec_sum[100][100];
long long temp[100];
int main()
{
//	ofstream file;
//	file.open("output.txt");
	int m,n;
	while(true)
	{
		cin>>m>>n;
		if(m == 0)
			break;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				sec_sum[i][j]=0;
				temp[j]=0;
			}
			
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>arr[i][j];
				if(arr[i][j] == 0)
					arr[i][j] = 1;
				else 
					arr[i][j] = -1000;
				sec_sum[i][j] = arr[i][j];
			}
			
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<j;k++)
				 {
				 	sec_sum[i][j]+=arr[i][k] ;
				 }
			}
			
		
		}
/*		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<sec_sum[i][j]<<" ";
			}
			cout<<endl;
		
		}
*/	
		int max_max=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				if(i == 0)
				{
					for(int k=0;k<m;k++)
						temp[k] = sec_sum[k][j];
					
				}
				else
				{
					for(int k=0;k<m;k++)
						temp[k] = sec_sum[k][j]-sec_sum[k][i-1];
				}
				
				
					
					for(int k=0;k<m;k++)
					{
						if(k != 0)
						{
							if(temp[k] + temp[k-1] > temp[k]  )
								temp[k] += temp[k-1];
						}	
						if(temp[k]>max_max)
							max_max = temp[k]; 
					}
				
			}
		}
		cout<<max_max<<endl;
		//file<<max_max<<endl;
		
	}
	
}
