#include <iostream>
#define FibNum 20 



using namespace std;

int fibsearch(int [],int [],int,int,int);

int main(){   
    int k;
    int n=16;
    int data[16]={1,2,9,16,20,21,52,59,92,97,100,120,122,130,140,145};
    int F[FibNum];
    F[0]=0;
    F[1]=1;
    for(int i=2;i<FibNum;i++){
            F[i]=F[i-1]+F[i-2];
            }
    
    for(k=0;k<FibNum;k++){
    if((n>F[k]-1)&&(n<=F[k+1]-1))
         break;
      }
      
      k++;
      cout<<k<<endl;
      int input;
      cout << endl << "請輸入欲搜尋之資料內容 => ";
	  cin >> input;
      
    cout<<fibsearch(data,F,n,k,input)<<endl;
    
    
    
    
    
    	system("pause");
	    return 0;
}



int fibsearch(int a[],int fib[],int n,int k,int key){
      
      int l=0,r=n-1,m;
      int flag=0;
      for(int i=n;i<fib[k]-1;i++)
          a[i]=a[n-1];
      
      
      while(l<=r){
          
          flag++;
          m=l+fib[k-1]-1;       
          if(a[m]==key){
              if(m<n){
                 cout<<"呼叫次數:"<<flag<<endl;               
                return m;}
              else
                 return n-1;          
                        
                        }
             
          else if(a[m]>key){
             r=m-1;
             k=k-1;
             }
          else{
             l=m+1;
             k=k-2;
             }
                        
                  }
        
        return -1;
    
    }
