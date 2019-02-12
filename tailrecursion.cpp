#include<iostream>
#include<iomanip>
#define N 100
#define MAX 10000
#define MIN 0

using namespace std;


struct TreeNode{
        
     int value;   
     TreeNode *left;
     TreeNode *right; 
     
       
        }; 

 struct stack{
       TreeNode* stackarray[N];
       bool stackbooleanarray[N];
       int sp;
       
       
       };

stack s;
stack t;
        
void BST_insert(TreeNode **,int);
int isfull(stack *);
int isempty(stack *);
void preorder(TreeNode *);
void traverse(TreeNode *);
void traversenon(TreeNode *);
        
int main(void){
    
    TreeNode *tree1=NULL;
   
    
    
    
    BST_insert(&tree1,53);
    BST_insert(&tree1,26);
    BST_insert(&tree1,60);
    BST_insert(&tree1,6);
    BST_insert(&tree1,40);
    BST_insert(&tree1,55);
    BST_insert(&tree1,35);
    BST_insert(&tree1,54);
    BST_insert(&tree1,58);
    BST_insert(&tree1,56);
    traverse(tree1);
     cout<<endl;
     preorder(tree1);
     cout<<endl; 
     traversenon(tree1); 
      
     system("pause"); 
     return 0;  
}


void BST_insert(TreeNode **root,int x){
     TreeNode  *q=*root,*r=NULL,*s,*current,*back;
     current=*root;
     
     s=new TreeNode;
      s->value=x;
      s->left=NULL;
      s->right=NULL;
     
     
     if(current==NULL){ 
      
      *root=s;  
    }
    else{
        while(current!=NULL){
                  back=current;   
            if((current->value)>x)
              current=current->left;
            else
              current=current->right;
                    }
            if((back->value)>x)        
                back->left=s;    
            else
                back->right=s;       
                    
}



     }


          
void createstack(stack *p){
     p->sp=-1;
     } 
     
int push(stack *p,TreeNode*& x,bool flag){
     if(isfull(p))
     return 1;
     p->sp++;
     p->stackarray[p->sp]=x;
     p->stackbooleanarray[p->sp]=flag;
     }
     
int pop(stack *p,TreeNode **x,bool *flag){
     if(isempty(p))
     return 1;
     
     *x=p->stackarray[p->sp];
     *flag=p->stackbooleanarray[p->sp];     
     p->sp--;
      
     } 
     
int isempty(stack *p){
     if(p->sp==-1)
     return 1;
     else
     return 0;      
     }
int isfull(stack *p){
    if(p->sp==N-1)   
    return 1;
    else
    return 0;   
}   
          
void preorder(TreeNode *ptr){
     cout<<"«e§Ç:"<<endl;
     bool flag;
     TreeNode *p;
     createstack(&s);
     push(&s,ptr,false);
     while(!(isempty(&s))){
        pop(&s,&p,&flag);   
          if(p!=NULL){
          if(flag==true)
             cout<<"Visit"<<p->value<<"  ";
          else{
              push(&s,p->right,false); 
              push(&s,p->left,false); 
              push(&s,p,true);
               
               }
                  
                  }
                  
               }
     }
     
     
void traverse(TreeNode *ptr){
     
     while(ptr!=NULL){
                      
         cout<<"Visit:"<<ptr->value<<"  ";
         traverse(ptr->left);             
         ptr=ptr->right;             
                      
         }
       
     
     }
     
     
void traversenon(TreeNode *ptr){
       
        bool fake;
        
        createstack(&t);
        
        while(ptr!=NULL||!isempty(&t)){
           
           if(ptr!=NULL){
                         
              cout<<"Visit:"<<ptr->value<<" ";
              push(&t,ptr,true);
              ptr=ptr->left;  
                       
              }                            
            else{
                 
              pop(&t,&ptr,&fake);
              ptr=ptr->right; 
                 
                 }                 
                                       
                                       
           }
     
     
     }
     
