#include <iostream>
#include<math.h>


using namespace std;

void Radix_Sort(int [],int [],int,int,int);


int main()
{
    
    
     
    int num[]={455,741,119,381,537,925,536,671,449,100};
    int result[10];
   
    cout<<"�Ƨǫe:";
    for(int i=0;i<10;i++)	 
     cout<<num[i]<<"  ";
    Radix_Sort(num,result,10,10,3);
   cout<<endl;
   cout<<"�Ƨǫ�:";
       for(int i=0;i<10;i++)	 
       cout<<num[i]<<"  ";
       
    cout<<endl;    
    
    
    
    
    
   	system("pause");
	return 0;
}


void Radix_Sort(int a[],int b[],int n,int m,int k)
{
	int i,j,d,pass;
    int count[10]={0};
    int tmp; 
    //n:��ƭӼ�  n=10
    //m:radix��   m=10
    //k:���      k=3
     
	for(pass=0;pass<3;pass++)
	{
		  for(j=0;j<m;j++)
	 	   count[j]=0;
			
        for(i=0;i<n;i++)              /*�p��U��ȥX�{����*/
        {   
            tmp=a[i];
           	tmp= tmp/(int)pow(m,pass);
	        tmp= tmp%m;
			count[tmp]++;
        }
        
        for(j=1;j < m;j++)
			count[j]=count[j]+count[j-1];

        for(i=n-1;i>=0;i--)           /*���t*/
        {
            tmp=a[i];
           	tmp= tmp/(int)pow(m,pass);
	        tmp= tmp%m;
	        b[--count[tmp]]=a[i];
			
        }
        
        for(i=0;i < n;i++)           /*�����^a[]*/
        a[i]=b[i];
        
   }

   
}


