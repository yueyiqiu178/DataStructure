#include<iostream>
#include<time.h>
using namespace std;

void sift(int [],int,int);
void BuildMaxHeap(int [],int);
void Heap_sort(int [],int);
void Heap_sort_old(int [],int);
void InsertMaxHeap(int,int [],int &);
void DeleteMaxHeap(int[],int &);

int main(void){
    
    srand(time(NULL));
    
    
    int heap[13];
    
    for(int i=0;i<13;i++)
       heap[i]=rand()%100;
    
      cout<<"Heap sort�e:";
      for(int i=0;i<13;i++)
      cout<<heap[i]<<" "; 
      cout<<endl;
    
    Heap_sort(heap,13);
    
    cout<<"Heap sort��:";
    for(int i=0;i<13;i++)
     cout<<heap[i]<<" "; 
     cout<<endl;
     
     int a[20];
     for(int i=0;i<10;i++)
       a[i]=rand()%100;
       cout<<"����:"<<endl;
       for(int i=0;i<10;i++)
     cout<<a[i]<<" "; 
     cout<<endl;
     BuildMaxHeap(a,10);
     cout<<"�إߦ���n��:"<<endl;
      for(int i=0;i<10;i++)
     cout<<a[i]<<" "; 
     cout<<endl;
     int count=10;
    InsertMaxHeap(35,a,count);
    cout<<"���J�@�Ӥ�����:"<<endl;
     for(int i=0;i<11;i++)
     cout<<a[i]<<" "; 
     cout<<endl;
    
    DeleteMaxHeap(a,count);
    cout<<"�R����n���̤j������"<<endl;
    for(int i=0;i<10;i++)
     cout<<a[i]<<" "; 
     cout<<endl;
    
    system("pause"); 
     return 0;  
}



void BuildMaxHeap(int heap[],int n){
        int i;
        for(i=(n-2)/2;i>=0;i--)
         sift(heap,i,n);
     
     }

     
void InsertMaxHeap(int x,int heap[],int &n){
     int flag=true;
     n++;
     int i=n-1;
     
     while(flag){
          if(i==0)       
           flag=false;
          else if(x<=heap[(i-1)/2]) 
           flag=false;
          else{
            heap[i]=heap[(i-1)/2];   
            i=(i-1)/2;   
               
               }     
                 
                 }
     
        heap[i]=x;
     
     }     

void DeleteMaxHeap(int heap[],int &n){
         int x;
      if(n==0)
      cout<<"�S�������i�R��"<<endl;
      else{
         x=heap[0]; 
           
         heap[0]=heap[n-1];  
         n--;
         sift(heap,0,n);  
           
           
           }
     
     
     
     }

     
     
void sift(int a[],int head,int n){
     
     
     int temp,j;
    
    
     while(head*2+1<n){
                  
             j=2*head+1; 
            
            if(j==n-1){
            
             
                 if(a[head]>a[j])
                     break;
             
             
            }
           
            else{
                 if(a[j+1]>a[j])
                     j++;
             
                 if(a[head]>a[j])
                     break;
            }
            
            temp=a[head];
            a[head]=a[j];    
            a[j]=temp;
            head=j;
             
            
     }
     
     }
     
     
     
     
     
     
void Heap_sort(int heap[],int n){
     int temp;
        
     for(int i=(n-2)/2;i>=0;i--)
         sift(heap,i,n);
    
    
     for(int i=n-1;i>=1;i--){
      
      temp=heap[i];
      heap[i]=heap[0];
      heap[0]=temp;
      
      sift(heap,0,i);
    
      }
     }
     
     
     
     
void Heap_sort_old(int heap[],int n){
     int temp;
     
     for(int i=(n-2)/2;i>=0;i--)
         sift(heap,i,n);
     
     
     while(n>1){
     temp=heap[n-1];
     heap[n-1]=heap[0];
     heap[0]=temp;
     n--;
     
     
     for(int i=0;i<=n-1;i++)
     sift(heap,0,n);
     
     
     }
     
     
     }

