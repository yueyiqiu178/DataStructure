#include<iostream>
#include<time.h>
using namespace std;

void hanoiTower_recursive(int,char,char,char);
void hanoiTower(int);
void permutation(char[],int,int);
void subset(char[],int,int,int);
void MaxMin(int [],int,int,int*,int *);
int sum(int);
int ack_nonrecursive(int,int);

char atom[3]={'a','b','c'};
char s[20];


int main(void){
   
    hanoiTower(3);
    cout<<endl;
    hanoiTower_recursive(3,'A','B','C');
    char element[5]={'A','B','C','D'};
    permutation(element,0,3);
    
    s[0]=127;
    
    subset(s,0,0,3);
    cout<<endl;
    srand(time(NULL));
    
    int data[10];
    
    for(int i=0;i<10;i++)
       data[i]=rand()%100;
    
      cout<<"資料陣列:";
      for(int i=0;i<10;i++)
      cout<<data[i]<<" "; 
      
      
      
    
    
    int max,min;
    
    MaxMin(data,0,9,&max,&min);
    cout<<endl; 
    cout<<"最大為:"<<max<<endl;
    cout<<"最小為:"<<min<<endl; 
    
    
    cout<<sum(5)<<endl;
    
    
    hanoiTower_recursive(3,'A','B','C');
    
    cout<<ack_nonrecursive(2,1)<<endl;
      
    system("pause");
    return 0;
    
    }
    
    
void hanoiTower_recursive(int n,char source,char temp,char dest){
      if(n){
           hanoiTower_recursive(n-1,source,dest,temp);
           cout<<"Move disk"<<n<<" from "<<source<<" to "<<dest<<endl;
           hanoiTower_recursive(n-1,temp,source,dest);
     
     }
     
     }
     
void hanoiTower(int n){
      char source,temp,dest,sp=0;
      char s[1000][4];
      s[0][0]=n;s[0][1]='A';s[0][2]='B';s[0][3]='C';
      while(sp>-1){
         n=s[sp][0];source=s[sp][1];temp=s[sp][2];dest=s[sp][3];   
         sp--;
         if(n==1)         
            cout<< "Move a disk from"<<source<<"to"<<dest<<endl;
         else if(n>1){         
            sp++;
            s[sp][0]=n-1;s[sp][1]=temp;s[sp][2]=source;s[sp][3]=dest;     
            sp++;      
            s[sp][0]=1;s[sp][1]=source;s[sp][2]=temp;s[sp][3]=dest;      
            sp++;      
            s[sp][0]=n-1;s[sp][1]=source;s[sp][2]=dest;s[sp][3]=temp;      
                  }
                  }
     
     }
     
     
void permutation(char element[],int first,int last){
     
     if(first==last){
         cout<<"(";
         for(int i=0;i<=last;i++)
             cout<<element[i]<<" ";
         cout<<")";
   


     }
     
     
     else{
         for(int i=first;i<=last;i++){
              char temp;
              temp=element[first];element[first]=element[i];element[i]=temp;
              permutation(element,first+1,last);
              temp=element[first];element[first]=element[i];element[i]=temp;
     }
     }
     }
     
     
     
void subset(char s[],int k,int i,int n){
                 //subset(s,0,0,3);
     if(i==n){
       s[k+1]=127;           
       for(int i=0;i<=k+1;i++)
       cout<<s[i]<<" ";
       
       cout<<"  ";
      }
     else{
          subset(s,k,i+1,n);
          s[k+1]=atom[i];
          subset(s,k+1,i+1,n);
     
     }
     }
     
void MaxMin(int a[],int low,int high,int *max,int *min){
                     //MaxMin(data,0,9,&max,&min);
       if(low==high)
       *max=*min=a[low];
       else{
             int mid,max2,min2;
             mid=(low+high)/2;
             MaxMin(a,low,mid,max,min);
             MaxMin(a,mid+1,high,&max2,&min2);
             
             if(max2>*max)
             *max=max2;
             if(min2<*min)
             *min=min2;
            
            }
     
     }
     
     
int sum(int n){
    
    if(n<=1)
    return 0;
    else
    return (n-1)*n+sum(n-1);
    
}


int ack_nonrecursive(int m,int n){
     
       int ind[100];
       int val[100];
       ind[0]=0;
       val[0]=1;
       for(int i=1;i<=m;i++){
               
             ind[i]=-1;
             val[i]=1;  
               }
     
     
     while(ind[m]!=n){
                       
            ind[0]=val[1];           
            val[0]=ind[0]+1;           
            int i=1;           
            while(val[i]==ind[i-1]&&i<=m){
                                         
                ind[i]=ind[i]+1;                         
                val[i]=val[i-1];          
                i++;                         
                                         }           
                       }
     
        return val[m];
     
     }
