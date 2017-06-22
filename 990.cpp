#include<iostream>
#include<fstream>
#define INF 3000
using namespace std;
int values[40];
int weight[40];
int dp[1010][40];
string path[1010][40];
int num_t[1010][40];
int main()
{
	
//	ofstream file;
//	file.open("output.txt");
	int bal,c;
	int counter=0;
	while(scanf("%d%d",&bal,&c)!= EOF)
	{
		if(counter != 0)
		{
			cout<<endl;
		//	file<<endl;
		}	
			int n;
			cin>>n;
			
			for(int i=1;i<=n;i++)
			{
				cin>>weight[i];
				cin>>values[i];
				weight[i]=3*c*weight[i];
			}
			//cout<<"Here"<<endl;
			for(int i=0;i<=bal;i++)
			{
				for(int j=0;j<=n;j++)
				{
					dp[i][j]=0;
					path[0][i]="";
					num_t[i][j]=0;	
				}
			}
			for(int i=0;i<=n;i++)
			{
				dp[0][i]=0;
				
			}
		
			for(int i=0;i<=bal;i++)
			{
				dp[i][0]=0;
			}
			for(int i=1;i<=bal;i++)
			{
				for(int j=1;j<=n;j++)
				{
				
					dp[i][j] = dp[i][j-1];
					path[i][j] = path[i][j-1];
					num_t[i][j] = num_t[i][j-1];
					if(i-weight[j] >=0)
					{
						if(dp[i][j] > values[j]+dp[i-weight[j]][j-1])
							{
								
							
							}
						else
						{
								dp[i][j] = values[j]+dp[i-weight[j]][j-1];
								path[i][j]=path[i-weight[j]][j-1]+to_string(weight[j]/(3*c))+" "+to_string(values[j])+"\n" ;
								num_t[i][j] = num_t[i-weight[j]][j-1] +1;
							
						}
					}
						
				}
			}
	/*	for(int i=0;i<=bal;i++)
		{
			for(int j=0;j<=n;j++)
			{
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
	*/
			cout<<dp[bal][n]<<endl;
			cout<<num_t[bal][n]<<endl;
			cout<<path[bal][n];
	//		file<<dp[bal][n]<<endl;
	//		file<<num_t[bal][n]<<endl;
	//		file<<path[bal][n];
			counter++;
	}
}
