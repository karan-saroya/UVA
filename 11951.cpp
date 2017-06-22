#include<iostream>
#include<fstream>
#define INF -1000
using namespace std;
long long  arr[100][100];
long long sec_sum[100][100];
long long temp[100];
int main()
{
	ofstream file;
	file.open("output.txt");
	int cases;
	cin>>cases;
	for(int l=0;l<cases;l++)
	{
		int n,m,cost;
		cin>>n>>m>>cost;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				arr[i][j]=1;
				sec_sum[i][j]=0;
				temp[j]=0;
			}
			
		}
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>arr[i][j];
				sec_sum[i][j] = arr[i][j];
			}
			
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
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
		int max_cost=100000000;
		int max_area=0;
		for(int i=0;i<m;i++)
		{
			for(int j=i;j<m;j++)
			{
				if(i == 0)
				{
					for(int k=0;k<n;k++)
						temp[k] = sec_sum[k][j];
					
				}
				else
				{
					for(int k=0;k<n;k++)
						temp[k] = sec_sum[k][j]-sec_sum[k][i-1];
				}
				
				
					int counter=1;
					for(int k=0;k<n;k++)
					{
						
						if(k != 0)
						{
							if(temp[k] + temp[k-1] >= temp[k] && temp[k] + temp[k-1]<=cost )
								{
									temp[k] += temp[k-1];
									counter++;
								}		
							else
							
								counter=1;
						}	
							if(temp[k] <= cost&& (j-i+1)*(counter) > max_area)
							{
								max_cost = temp[k];
								max_area = (j-i+1)*(counter);
							} 
							else if(temp[k] <= cost&& (j-i+1)*(counter)== max_area)
							{
								if(max_cost >temp[k])
									max_cost=temp[k];
							}
					}
				
			}
		}
	cout<<"Case #"<<(l+1)<<": "<<max_area<<" "<<max_cost<<endl;
	file<<"Case #"<<(l+1)<<": "<<max_area<<" "<<max_cost<<endl;
		
	}
	
}
