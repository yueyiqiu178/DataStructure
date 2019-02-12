#include<iostream>

using namespace std;



int main(void)
{
    int d[5]={2,4,3,5,1};
    int cost[5][5];
    int middle[5][5];
    for(int i=0;i<=4;i++)
    for(int j=0;j<=4;j++){
           cost[i][j]=20000;
           middle[i][j]=0; 
            }
       
    for(int i=1;i<=4;i++){
        cost[i][i]=0; 
        middle[i][i]=0;  }
        
        for(int t=2;t<=4;t++)
           for(int i=1,j=i+t-1;j<=4;i++,j++){
                 
                   for(int k=i;k<j;k++){
                      int c=cost[i][k]+cost[k+1][j]+d[i-1]*d[k]*d[j];
                       if(c<cost[i][j]){
                           cost[i][j]=c;
                           middle[i][j]=k;
                                        }
                   }
                   }
        cout<<cost[1][4]<<middle[1][4]<<endl;
     system("pause");
       return 0;
}
