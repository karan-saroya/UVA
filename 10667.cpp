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
	int n;
	int cases;
	cin>>cases;
	for(int l=0;l<cases;l++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				arr[i][j]=1;
				sec_sum[i][j]=0;
				temp[j]=0;
			}
			
		}
		int b;
		cin>>b;
		int l1,r1,l2,r2;
		for(int z=0;z<b;z++)
		{
			cin>>l1>>r1>>l2>>r2;
			for(int p=l1-1;p<l2;p++)
			{
				for(int q=r1-1;q<r2;q++)
					{
						arr[p][q]=INF;
					}
			}
			
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				
				sec_sum[i][j] = arr[i][j];
			}
			
		}
		for(int i=0;i<n;i++)
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
					for(int k=0;k<n;k++)
						temp[k] = sec_sum[k][j];
					
				}
				else
				{
					for(int k=0;k<n;k++)
						temp[k] = sec_sum[k][j]-sec_sum[k][i-1];
				}
				
				
					
					for(int k=0;k<n;k++)
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
//	file<<max_max<<endl;
		
	}
	
}
