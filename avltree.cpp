#include<iostream>
#define N 10

using namespace std;

struct TreeNode{
      TreeNode *left;
      TreeNode *right;
      int data;
      int bf; 
       
       
       };

TreeNode* leftRotation(TreeNode *,bool *);
TreeNode* rightRotation(TreeNode *,bool *);
TreeNode* avlInsert(TreeNode *,int,bool *);
void display(TreeNode *);
void findmin(TreeNode *);

int main(void){
    
    TreeNode *head=NULL;
    bool flag;
    
    head=avlInsert(head,3,&flag);
    head=avlInsert(head,5,&flag);
    head=avlInsert(head,11,&flag);
    head=avlInsert(head,8,&flag);
    head=avlInsert(head,4,&flag);
    head=avlInsert(head,1,&flag);
    head=avlInsert(head,12,&flag);
    head=avlInsert(head,7,&flag);
    head=avlInsert(head,2,&flag);
    head=avlInsert(head,6,&flag);
    head=avlInsert(head,10,&flag);
    head=avlInsert(head,9,&flag);
    head=avlInsert(head,8,&flag);
    head=avlInsert(head,5,&flag);
    
    display(head);
    
    cout<<endl;
    
    findmin(head);
    
    system("pause");
    return 0;
}



TreeNode* avlInsert(TreeNode *root,int x,bool *unbalanced){
     TreeNode *temp;
     
     
     
     if(root==NULL){
     *unbalanced=true;         
     TreeNode *s=new TreeNode;
     s->data=x;
     s->left=NULL;
     s->right=NULL;       
     s->bf=0;
     
     
     return s;
     
                 }
     else if(x<(root->data)){
            root->left=avlInsert(root->left,x,unbalanced);
          if(*unbalanced)
           switch(root->bf){
             case -1:root->bf=0;
                     *unbalanced=false;
                      break;
             case 0:root->bf=1;
                      break;
             case 1:temp=leftRotation(root,unbalanced);                           
                    return temp;
                    break;
                    } 
                    
             return root;
          }
     else if(x>root->data){
          root->right=avlInsert(root->right,x,unbalanced);
        if(*unbalanced)
        switch(root->bf){
             case 1:root->bf=0;
                     *unbalanced=false;
                      break;
             case 0:root->bf=-1; 
                      break;
             case -1:
                    temp=rightRotation(root,unbalanced);
                    return temp;
                    break;
               }
               
            return root;   
               
               }
     else{
           *unbalanced=false;
          cout<<"鍵值已經在樹中"<<endl;
          
          }
     
     }
     
     
TreeNode* leftRotation(TreeNode *ptr,bool *unbalanced){
      TreeNode *grandChild,*child;
      child=ptr->left;
      if(child->bf==1){
        ptr->left=child->right;
        child->right=ptr;
        ptr->bf=0;
        ptr=child;
     
     }
     else{
          grandChild=child->right;
          child->right=grandChild->left;
          grandChild->left=child;
          ptr->left=grandChild->right;
          grandChild->right=ptr;
          switch(grandChild->bf){
             case 1:ptr->bf=-1;
                    child->bf=0;
                    break;
             case 0:ptr->bf=child->bf=0;break;
             case -1:ptr->bf=0;
                     child->bf=1;    break;  
          }
          ptr=grandChild;
          
          }
     
     ptr->bf=0;
     *unbalanced=false;
     return ptr;
     
     }
     
     
TreeNode* rightRotation(TreeNode *ptr,bool *unbalanced){
      TreeNode *grandChild,*child;
      child=ptr->right;
      if(child->bf==-1){
        ptr->right=child->left;
        child->left=ptr;
        ptr->bf=0;
        ptr=child;
     
     }
     else{
          grandChild=child->left;
          child->left=grandChild->right;
          grandChild->right=child;
          ptr->right=grandChild->left;
          grandChild->left=ptr;
          switch(grandChild->bf){
             case 1:ptr->bf=0;
                    child->bf=-1;
                    break;
             case 0:ptr->bf=child->bf=0;break;
             case -1:ptr->bf=1;
                     child->bf=0;      
          }
          ptr=grandChild;
          
          }
     
     ptr->bf=0;
     *unbalanced=false;
     
     return ptr;
     }
     
 
TreeNode* avlDelete(TreeNode **root,int x,bool *unbalanced){
          TreeNode *p;
          p=*root;
          if(p==NULL){
                      
                      }
          else if(x>(p->data)){
               p=avlDelete(&(*root)->right,x,unbalanced);
               
               
               }
          else if(x<(p->data)){     
          
          
          }
          else{
               
               
               
               
               } 
 
 
}
     
void display(TreeNode *ptr){
     
    if(ptr!=NULL){
            display(ptr->left);       
            cout<<ptr->data<<" ";
            display(ptr->right);
                   }

     }
     
void findmin(TreeNode *ptr){
     
     if(ptr->left!=NULL)
       findmin(ptr->left);
     else
        cout<<ptr->data<<endl;  
     
     
     }

