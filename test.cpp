#include<iostream>

using namespace std;

struct TreeNode{
        
     int value;   
     TreeNode *left;
     TreeNode *right; 
     
       
        }; 

int main(){
    
    
    int x=10;
    int *p=&x;
    int **pp=&p;
    
    cout<<x<<" "<<&x<<" "<<p<<" "<<*p<<endl;
    printf("\t");
    cout<<pp<<" "<<&p<<" "<<**pp<<" "<<*pp<<endl;
    //cout<<p->x<<endl;
    
    TreeNode *head=new TreeNode;
    head->value=100;
    cout<<head<<endl;
    TreeNode **root=&head;
    cout<<root<<endl;
    cout<<*root<<endl;
    //cout<<*<<endl;
    
    for(int i=1;i<=1;i++)
       cout<<"wewewe"<<endl;
   // printf("\t\t\t");
    
    int intArray[3][2]={{10,20},{15,25},{50,40}};
    int *intPtr2=&intArray[1][1];
    
    //*intPtr2=intArray[1][1];
    cout<<*intPtr2<<endl;
    
    int (*intPtr3)[2]=&intArray[2];
    
    *(*intPtr3+1)=intArray[2][0];
    
    cout<<*(*intPtr3+1)<<endl;
    
    for(int i=0;i<3;i++){
    for(int j=0;j<2;j++){
    cout<<intArray[i][j]<<" ";}
    cout<<endl;   
}

    cout<<*(*(intArray+1)+1)<<endl;
    
    
   system("pause");   
    return 0;
    
    
}
