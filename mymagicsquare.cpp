#include<iostream>
#include<iomanip>
#define N 5 
using namespace std;
void magic (int,int,int);

int square[N+1][N+1] = {0}; 

int main(void)
{
    
    int m=0;
    int n=(N+1)/2;
     magic(1,m,n);
    for(int i=1;i<=5;i++){
      for(int j=1;j<=5;j++){
              
              cout<<setw(2)<<square[i][j]<<" ";
              
              }
              cout<<endl;
            }
    
    
    
    
     system("pause");
       return 0;
}




void magic (int key,int i,int j){
    
     if(key<=N*N){
     if((key % N) == 1) 
            i++; 
        else { 
            i--; 
            j++; 
        } 

        if(i == 0) 
            i = N; 
        if(j > N) 
            j = 1; 

       square[i][j] = key; 
        
        magic(key+1,i,j);
        
     }
     }
