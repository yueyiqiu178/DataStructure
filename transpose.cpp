#include<iostream>
#define N 100
#include <iomanip>

using namespace std;

struct term{
       int col;
       int row;
       int value;
       
       };

void transpose(term [],term []);
void fastTranspose(term [],term []);

int main(void){
        
        int a[2][3]={{2,5,8},
                     {10,9,15}};
                     
        int b[3][2];
        
        for(int i=0;i<2;i++)             
        for(int j=0;j<3;j++)
          b[j][i]=a[i][j];
        
        
        for(int i=0;i<3;i++){             
        for(int j=0;j<2;j++){
          cout<<b[i][j]<<" ";}
          cout<<endl;}
          
        term x[9];
        term y[9];
        
        x[0].row=6;
        x[0].col=6;
        x[0].value=8;  
        x[1].row=0;
        x[1].col=0;
        x[1].value=15;
        x[2].row=0;
        x[2].col=3;
        x[2].value=22;
        x[3].row=0;
        x[3].col=5;
        x[3].value=-15; 
        x[4].row=1;
        x[4].col=1;
        x[4].value=11;
        x[5].row=1;
        x[5].col=2;
        x[5].value=3;
        x[6].row=2;
        x[6].col=3;
        x[6].value=-6;
        x[7].row=4;
        x[7].col=0;
        x[7].value=91;
        x[8].row=5;
        x[8].col=2;
        x[8].value=28;                        
          
        
        fastTranspose(x,y);
        cout<<endl;
        for(int i=0;i<9;i++)
          cout<<setw(4)<<x[i].row<<" "<<setw(4)<<x[i].col<<" "<<setw(4)<<x[i].value<<endl;
        cout<<endl;
         for(int i=0;i<9;i++)
          cout<<setw(4)<<y[i].row<<" "<<setw(4)<<y[i].col<<" "<<setw(4)<<y[i].value<<endl;
          
        
    system("pause");
    return 0;
    
    }
    
    
void transpose(term a[],term b[]){
     int i,j,n,currentB;
     n=a[0].value;
     b[0].row=a[0].row;
     b[0].col=a[0].col;
     b[0].value=n;
     
     currentB=1;
     for(i=0;i<a[0].col;i++)
     for(j=1;j<=8;j++)
       if(a[j].col==i){
         b[currentB].row=a[j].col;
         b[currentB].col=a[j].row;
         b[currentB].value=a[j].value;
         currentB++;}
     
     }
     
void fastTranspose(term a[],term b[]){
     
     int rowCount[a[0].col];
     int startingPos[a[0].col];
     int i,position,numCol=a[0].col,numTerm=a[0].value;
     b[0].row=a[0].row;
     b[0].col=a[0].col;
     b[0].value=a[0].value;
     
     for(i=0;i<numCol;i++)
       rowCount[i]=0;
     for(i=1;i<=numTerm;i++)  
       rowCount[a[i].col]++;
    // for(i=0;i<6;i++)  
        //cout<<rowCount[i]<<" ";
        
      startingPos[0]=1;
      for(i=1;i<numCol;i++)
       startingPos[i]=startingPos[i-1]+rowCount[i-1];
        
        
      for(i=1;i<=numTerm;i++){
            position=startingPos[a[i].col]++;
            b[position].col=a[i].row;
            b[position].row=a[i].col;
            b[position].value=a[i].value;                 
                                                          }                
     }
