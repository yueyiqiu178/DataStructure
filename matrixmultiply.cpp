#include <iostream>
#include<iomanip>

using namespace std;



int main(void) { 
    
    int N=5;
    int M[N][N];
    int P[N][N];    
    int d[5]={2,4,3,5,1};
    
    
    for(int i=1;i<N;i++)
       M[i][i]=0;
    
    for(int t=2;t<N;t++)
       for(int i=1,j=i+t-1;j<N;i++,j++){
               M[i][j]=20000;
               
               for(int k=i;k<j;k++){
                   int c=M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j];    
                       if(c<M[i][j]){
                          M[i][j]=c;           
                          P[i][j]=k;           
                                     }        
                       }
               
               }
    
     cout<<M[1][4]<<endl;    
    
     system("pause");
     return 0; 
} 

