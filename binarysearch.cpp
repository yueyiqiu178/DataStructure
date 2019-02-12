#include <iostream>


using namespace std;

int binarysearch(int [],int,int);

int main()
{
    int data[10]={1,2,9,16,20,21,52,59,92,97};
    
    cout<<binarysearch(data,10,100)<<endl;
    
    
    
    
    
    	system("pause");
	    return 0;
}



int binarysearch(int a[],int n,int key){
      
      int l=0,r=n-1,m;
      
      while(l<=r){
          
          m=(l+r)/2;        
          if(a[m]==key)
              return m;
          else if(a[m]>key)
             r=m-1;
          else
             l=m+1;           
                  }
        
        return -1;
    
    }
