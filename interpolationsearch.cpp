#include <iostream>


using namespace std;

int interpolation_search(int [],int,int);

int main()
{
    int data[10]={1,2,9,16,20,21,52,59,92,97};
    
    cout<<interpolation_search(data,10,488)<<endl;
    
    
    
    
    
    	system("pause");
	    return 0;
}



int interpolation_search(int a[],int n,int key){
      
      int l=0,r=n-1,m;
      double x;
      
      while(l<=r){
          
          if(a[r]-a[l]!=0)
            x=(double)(key-a[l])/(a[r]-a[l]);
          else
            x=0;  
          
          m=l+(int)(x*(r-l));
          
          
          if(a[m]==key)
              return m;
          else if(a[m]>key)
             r=m-1;
          else
             l=m+1;           
                  }
        
        return -1;
    
    }
