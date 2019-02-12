#include<iostream>
#define INFINITE 20000

using namespace std;

int cost[4][4]={{INFINITE,INFINITE,INFINITE,INFINITE},
                {INFINITE,0,4,11},
                {INFINITE,6,0,2},
                {INFINITE,3,INFINITE,0}};
int A[4][4];
int P[4][4];

void floyd();
void find_path(int[4][4]);
     
    
int main(void){
    
    floyd();
    find_path(P);
    
    
    
     system("pause");
    return 0;
}



void floyd(){
     for(int i=1;i<=3;i++){ 
     for(int j=1;j<=3;j++){
        A[i][j]=cost[i][j];
        P[i][j]=j;
     }
     }
     
     for(int k=1;k<=3;k++)
     for(int i=1;i<=3;i++)
     for(int j=1;j<=3;j++)
        if((A[i][k]+A[k][j])<(A[i][j])){
          A[i][j]=A[i][k]+A[k][j];
          P[i][j]=P[i][k];
     }
     
     
     }
     
     
void find_path(int s[4][4]){
     int row;
     for(int i=1;i<=3;i++)
     for(int j=1;j<=3;j++){
      cout<<"最短路徑從V"<<i<<"到V"<<j<<"的成本為"<<A[i][j]<<"  "; 
      cout<<"最短路徑為:從V"<<i; 
      row=s[i][j]; 
      while(row!=j){
             cout<<"到V"<<row;     
             row=s[row][j];       
                    }
      cout<<"到V"<<j<<endl; 
     
     }
     
     
     
     }
