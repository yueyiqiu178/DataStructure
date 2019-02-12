#include<iostream>

using namespace std;

void NumConvert(int,int);

int main(void)
{
    int k;
    cin>>k;
    
     NumConvert(k,2);
     cout<<endl;
      NumConvert(k,4);
      cout<<endl;
       NumConvert(k,6);
       cout<<endl;
        NumConvert(k,8);
        cout<<endl;
    
    
     system("pause");
       return 0;
}



void NumConvert(int n,int radix){
     
     if(n>0){
        NumConvert(n/radix,radix);     
         cout<<n%radix;    
             
             
             }
     
     
     }
