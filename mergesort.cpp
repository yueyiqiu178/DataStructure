#include <iostream>
using namespace std;

void mergesort(int [],int,int);
int b[10];

int main()
{
   int num[]={37,41,19,81,45,25,56,61,49,10};
   
   cout<<"排序前:";
   for(int i=0;i<10;i++)	 
     cout<<num[i]<<"  ";
   mergesort(num,0,9);
   cout<<endl;
   cout<<"排序後:";
       for(int i=0;i<10;i++)	 
          cout<<num[i]<<"  ";
          
    cout<<endl;      
	system("pause");
	return 0;
}




void mergesort(int a[],int left,int right)
{
	int i,j,k,m;
	
	if(left < right)
	{
        m=(left+right)/2;
        mergesort(a,left,m);
        mergesort(a,m+1,right);

        for(i=left;i <= m;i++)
			b[i]=a[i];
			
        for(j=m+1;j <= right;j++)
            b[right+(m-j+1)]=a[j];
            
        for(i=left,j=right,k=left;k <= right;k++)
            a[k]=(b[i] <= b[j]) ? b[i++]:b[j--];
           
	}
}



