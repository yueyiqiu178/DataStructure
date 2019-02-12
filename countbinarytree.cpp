#include<iostream>
#define N 100

using namespace std;

struct TreeNode{
        
     int value;   
     TreeNode *left;
     TreeNode *right; 
     int size;
       
        }; 



struct Queue{
        TreeNode* queuearray[N];
        int rear;
        int front;
        
        
        };
Queue q;


int isEmpty(Queue *);   
void BST_insert(int,TreeNode **);
void queueMove(Queue *);
void levelOrder(TreeNode *);
void preorder(TreeNode *);
void inorder(TreeNode *);
void postorder(TreeNode *);
TreeNode* BST_delete(TreeNode **,int);
void createQueue(Queue *);
void BST_search(TreeNode *ptr,int x);
int leaves(TreeNode *);
int countNode(TreeNode *);
int height(TreeNode *);
void swap(TreeNode *);
void findmin(TreeNode *ptr);
void findmax(TreeNode *ptr);
int find_Number(TreeNode *,int);
int findkth(TreeNode *,int);
int reserve(TreeNode *,int,int);
        
int main(void){
        
     TreeNode *head=NULL;
     
     BST_insert(70,&head); 
     BST_insert(65,&head); 
     BST_insert(80,&head); 
     BST_insert(50,&head);
     BST_insert(68,&head);
     BST_insert(72,&head);
     BST_insert(90,&head);
     BST_insert(40,&head); 
     
     head->size=8;
     head->left->size=4;
     head->right->size=3;
     head->left->left->size=2;
     head->left->right->size=1;
     head->left->left->left->size=1;
     head->right->left->size=1;
     head->right->right->size=1; 
    
        
     inorder(head);
     cout<<endl;
     findmin(head);
     findmax(head);
     
     cout<<find_Number(head,73)<<endl;
     cout<<findkth(head,77)<<endl;
     cout<<reserve(head,72,85)<<endl;
     
     
     
     system("pause");
     return 0;
    
    
}


void BST_insert(int x,TreeNode **root){
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
     
void createQueue(Queue *p){
     p->rear=-1;
     p->front=-1;
     }
     
     
void enQueue(Queue *p,TreeNode *x){
    if(p->rear==N-1)
     queueMove(p);
     
     
     p->rear++;
     p->queuearray[p->rear]=x;
     
     
     
     }
void deQueue(Queue *p,TreeNode **x){
 p->front++;
 *x=p->queuearray[p->front];

 
}

void queueMove(Queue *p){
     int i;
     for(i=p->front+1;i<=p->rear;i++)
     p->queuearray[i-p->front-1]=p->queuearray[i];
     p->rear=p->rear-p->front-1;
     p->front=-1;
     
     }

int isEmpty(Queue *p){
    if(p->rear==p->front)
    return 1;
    else
    return 0;
    }


     
void levelOrder(TreeNode *ptr){
     TreeNode* k;
     
      createQueue(&q);
     
     enQueue(&q,ptr);
     
     while(!(isEmpty(&q))){
         
         deQueue(&q,&k);
        // ptr=k;         
         cout<<"Visit"<<k->value<<"  ";
         
         if(k->left!=NULL)
          enQueue(&q,k->left);
         if(k->right!=NULL)
          enQueue(&q,k->right); 
          
                 
                         } 
     
     }

     

void preorder(TreeNode *ptr){
    
     if(ptr!=NULL){
            cout<<ptr->value<<" ";     
            preorder(ptr->left);
            preorder(ptr->right);   
                 }
     } 
     
     
void inorder(TreeNode *ptr){
      
     if(ptr!=NULL){
            inorder(ptr->left);       
            cout<<ptr->value<<" ";
            inorder(ptr->right);
                   }
     }
     
void postorder(TreeNode *ptr){
     
     if(ptr!=NULL){
       postorder(ptr->left);
       postorder(ptr->right);
       cout<<ptr->value<<" ";
     
     }
     }

void BST_search(TreeNode *ptr,int x){
       
       while(ptr!=NULL){
       if(ptr->value==x){
               cout<<"找到鍵值"<<x<<endl;
               break;
               }
       else if(x>ptr->value)        
               ptr=ptr->right;
       else if(x<ptr->value)
               ptr=ptr->left;                 
                        
       }
       
       if(ptr==NULL)
       cout<<"找不到該節點"<<endl;
}



     
TreeNode* BST_delete(TreeNode **root,int x){
     
     int found=0,direction=0;
     TreeNode *r,*q,*s,*t;
     TreeNode *ptr=*root;
     r=q=s=NULL;
     t=ptr;

    while(ptr!=NULL && !found)
    {
        if((ptr->value)==x)
                found=1;
        else if(x<(ptr->value))
        {
                direction=1;
                r=ptr;
                ptr=ptr->left;
        }
        else
        {
                direction=0;
                r=ptr;
                ptr=ptr->right;
        }
    }
    if(ptr == NULL)
        cout<<"找不到該節點"<<endl; 
     
  
        
    else if((ptr->left==NULL)&&(ptr->right==NULL)){
                  if(direction==1)                 
                       r->left==NULL;
                  else
                       r->right=NULL;        
                                         }    
                                         
   else if((ptr->left==NULL)||(ptr->right==NULL)){
        if(r==NULL){
               if((ptr->right)!=NULL)    
                   *root=ptr->right; 
               else
                   *root=ptr->left;     
        }
        else{
        if(direction==0&&ptr->left==NULL)
        r->right=ptr->right;
        else if((direction==0)&&(ptr->right==NULL))
        r->right=ptr->left;
        else if((direction==1)&&(ptr->left==NULL))
        r->left=ptr->right;
        else if((direction==1)&&(ptr->right==NULL))
        r->left=ptr->left;}
        
        
        }
   else
    {
        s=ptr;
        q=ptr->left;
        while(q->right != NULL)
        {
                s=q;
                q=q->right;
        }
        ptr->value=q->value;
        if(ptr == s)
                s->left=q->left;
        else
                s->right=q->left;
    }
     
     
     }
     
     
int leaves(TreeNode *ptr){
    if(ptr==NULL)
    return 0;
    else{
         if((leaves(ptr->left)+leaves(ptr->right))>1)
         return leaves(ptr->left)+leaves(ptr->right);
         else
         return 1;
         
         }   
}



int countNode(TreeNode *ptr){
    
      if(ptr==NULL)
         return 0;
      else
         return countNode(ptr->left)+countNode(ptr->right)+1;
    
}


int height(TreeNode *ptr){
     if(ptr==NULL)   
       return 0;
     else{
           if((height(ptr->left))>(height(ptr->right)))       
               return height(ptr->left)+1;
           else
               return height(ptr->right)+1;          
}
}


void swap(TreeNode *ptr){
     TreeNode *p;
        if(ptr!=NULL){
            p=ptr->left;
            ptr->left=ptr->right;   
            ptr->right=p;
            swap(ptr->left);
            swap(ptr->right);  
        }
        
        
     }
     
     
void findmin(TreeNode *ptr){
     
     if(ptr->left!=NULL)
       findmin(ptr->left);
     else
        cout<<ptr->value<<endl;  
     
     
     }


void findmax(TreeNode *ptr){
     
     if(ptr->right!=NULL)
       findmax(ptr->right);
     else
        cout<<ptr->value<<endl;  
     
     
     }
     
     
int find_Number(TreeNode *ptr,int key){
     
       if(ptr==NULL)
         return 0;
       else if(ptr->value==key){
            if(ptr->left==NULL)
               return 0;
            else 
                return ptr->left->size; 
            }  
       else if(ptr->value>key)
            return find_Number(ptr->left,key);
       else{
            if(ptr->left==NULL)
               return 1+find_Number(ptr->right,key);
            else
               return ptr->left->size+1+find_Number(ptr->right,key);
            
            }     
     }
     
int findkth(TreeNode *ptr,int k){
       
       int rank;
      
      if(ptr==NULL)
        return -1;
      if(ptr->left==NULL)  
         rank=1;
      else
         rank=ptr->left->size+1;
      if(k==rank)
         return ptr->value;
      else if(k<rank)
         return findkth(ptr->left,k);
      else
         return findkth(ptr->right,k-rank);            
      
      
      }
      
      
int reserve(TreeNode *ptr,int i,int j){
    
    if(ptr==NULL)
      return -1;
    else if((ptr->value)<i)
      return reserve(ptr->right,i,j);  
    else if((ptr->value)>j)  
      return reserve(ptr->left,i,j);
    else
      return ptr->value;
    
    }

