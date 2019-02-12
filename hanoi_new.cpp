#include<iostream>

using namespace std;

void swap(char &,char &);
void move(int,char,char,char);


int main(){
    
    
    move(3,'A','B','C');
    
    
    
    
     system("pause");
     return 0;
     
     
     }
     
     
void move(int n,char source,char temp,char dest){
      while(n>0){
           move(n-1,source,dest,temp);
           cout<<"Move disk"<<n<<" from "<<source<<" to "<<dest<<endl;
           n--;
           swap(source,temp);
     
     }
     
     }
     
     
void swap(char &p,char &q){
     
     char t;
     t=p;
     p=q;
     q=t;
     
     
     
     }
