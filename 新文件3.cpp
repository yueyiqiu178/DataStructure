#include <iostream>

using namespace std;

int comparison(char [],char [],int,int);


int main(void)
{	
  
   char x[]={'A','d','w','m','p','W'};
   char y[]={'G','e','3','i','e','d'};
   
   cout<<comparison(x,y,6,6)<<endl;
  
  if(x[0]>y[0])
  cout<<"123"<<endl;
  else
  cout<<"456"<<endl;
  
  
   system("pause");
   return 0;
}


int comparison(char a[],char b[],int length1,int length2){
    
    int x=sizeof(a)/4;
    int y=sizeof(b)/4;
    int r=0;
    int i=0;
    cout<<"r="<<r<<endl;
    cout<<a[0]<<"===="<<b[0]<<endl;
    if(a[0]>b[0])
       cout<<"123"<<endl;
     else
      cout<<"456"<<endl;
    
    while(r==0&&i<length1&&i<length2){
          if(a[i]>b[i])                          
           {r=1;}
          else if(a[i]<b[i])                          
           {r=-1;}
           else
             {i++;}                                                                                   
                                     }
     cout<<"r="<<r<<endl;
    if(r==0){
       if(length1>length2)      
         r=1;
       else if(length1<length2)
         r=-1;    
        else
        r=0;     
             }
     cout<<"r="<<r<<endl;
    return r;
    
    
    }

