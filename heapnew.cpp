#include<iostream>
#include <time.h>
using namespace std;
 
void sift(int [],int,int);
void BuildMaxHeap(int [],int);
void Heap_sort(int [],int);
 
int main(void){
    
    srand(time(NULL));
    int heap[13]={50,41,19,81,45,25,56,61,49,10,36,15,90};
    BuildMaxHeap(heap,13);
      cout<<"Heap sort«e:";
      for(int i=0;i<13;i++){
      heap[i] = rand() % 100;        
      cout<<heap[i]<<" "; }
      cout<<endl;
    
    Heap_sort(heap,13);
    
    cout<<"Heap sort«á:";
    for(int i=0;i<13;i++)
     cout<<heap[i]<<" "; 
     cout<<endl;
     
     
         system("pause");
         return 0;  
}
 
 
void BuildMaxHeap(int heap[],int n){
        int i;
        for(i=(n-2)/2;i>=0;i--)
         sift(heap,i,n);
     
     }
     
     
void sift(int a[],int i,int n){
     int temp,j;
     temp=a[i];
     j=2*i+1;
     
     while(j<n){
                
            if(j+1<n&&a[j]<a[j+1])
            j++;
            if(temp>a[j])
                break;
     
            a[i]=a[j];    
            i=j;
            
            j=2*i+1;
             
            
     }
     a[i]=temp;
     
     }
     
void Heap_sort(int heap[],int n){
     int k,temp;
     
     while(n>1){
     temp=heap[n-1];
     heap[n-1]=heap[0];
     heap[0]=temp;
     n--;
     
     
     for(int i=0;i<n;i++){
     sift(heap,0,n);
     
     }
     }
     
     }
