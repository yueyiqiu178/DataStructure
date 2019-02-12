#include<iostream>
using namespace std;


int createtree_version1(int [],int [],int);
void createtree_version2(int [],int [],int);
void preorder(int [],int,int,int);
void inorder(int [],int,int,int);
void postorder(int [],int,int,int);

int main(void){
    
    int binarytree1[100]={0};
    int binarytree2[100]={0};
    int data[10]={37,41,19,81,45,25,56,61,49,10};
    int maxnode;
    
    maxnode=createtree_version1(binarytree1,data,10);
    
    cout<<"maxnode="<<maxnode<<endl;
    
    
    cout<<"�`�I"<<binarytree1[6]<<"�����ˬO"<<binarytree1[6/2]<<endl;
    cout<<"�`�I"<<binarytree1[1]<<"������l�O"<<binarytree1[1*2]<<endl;
    cout<<"�`�I"<<binarytree1[1]<<"���k��l�O"<<binarytree1[1*2+1]<<endl;
    cout<<"�`�I"<<binarytree1[4]<<"���S�̬O"<<binarytree1[4+1]<<endl;
    cout<<"�`�I"<<binarytree1[7]<<"���S�̬O"<<binarytree1[7-1]<<endl;
    
    cout<<endl;
    
    createtree_version2(binarytree2,data,10);
    
    cout<<"�`�I"<<binarytree2[5]<<"�����ˬO"<<binarytree2[5/2]<<endl;
    cout<<"�`�I"<<binarytree2[0]<<"������l�O"<<binarytree2[0*2+1]<<endl;
    cout<<"�`�I"<<binarytree2[0]<<"���k��l�O"<<binarytree2[0*2+2]<<endl;
    cout<<"�`�I"<<binarytree2[3]<<"���S�̬O"<<binarytree2[3+1]<<endl;
    cout<<"�`�I"<<binarytree2[6]<<"���S�̬O"<<binarytree2[6-1]<<endl;
 
    cout<<"�e��:"<<endl;
    preorder(binarytree1,10,1,maxnode);
    cout<<endl<<"����:"<<endl;
    inorder(binarytree1,10,1,maxnode);
    cout<<endl<<"���:"<<endl;
    postorder(binarytree1,10,1,maxnode); 

    system("pause"); 
     return 0;  
}



int createtree_version1(int tree[],int data[],int length){
      int no;
      tree[1]=data[0];
      int maxnodevalue=0;
      for(int i=1;i<length;i++){
              no=1;
              while(tree[no]!=0){
                    if(data[i]>tree[no])            
                        no=no*2+1;
                    else
                        no=no*2;            
                                
                                }
              
              tree[no]=data[i];
              
              if(no>maxnodevalue)
              maxnodevalue=no;
              }
              
          return maxnodevalue;
    
      
     }
     
     
void createtree_version2(int tree[],int data[],int length){
      int no;
      tree[0]=data[0];
      
      for(int i=1;i<length;i++){
              no=0;
              while(tree[no]!=0){
                    if(data[i]>tree[no])            
                        no=no*2+2;
                    else
                        no=no*2+1;            
                                
                                }
              
              tree[no]=data[i];
              
              }
     }
     
     
void preorder(int tree[],int length,int i,int max){
     
     if(i>max)
     return;
     
       else{
         
         cout<<"Visit"<<tree[i]<<" ";
         if(tree[i*2]!=0)
         preorder(tree,length,i*2,max);
         if(tree[i*2+1]!=0)
         preorder(tree,length,i*2+1,max); 
         
          
          }
     }
     
     
void inorder(int tree[],int length,int i,int max){
     
     if(i>max)
     return;
     
       else{
         
         if(tree[i*2]!=0) 
         inorder(tree,length,i*2,max);
         
         cout<<"Visit"<<tree[i]<<" ";
         
         if(tree[i*2+1]!=0)
         inorder(tree,length,i*2+1,max); 
         
          
          }
     }
     
     
void postorder(int tree[],int length,int i,int max){
     
     if(i>max)
     return;
     
       else{
         
         
         if(tree[i*2]!=0)
         postorder(tree,length,i*2,max);
         if(tree[i*2+1]!=0)
         postorder(tree,length,i*2+1,max); 
         cout<<"Visit"<<tree[i]<<" ";
         
          
          }
     }
