#include<iostream>
#define N 100

using namespace std;

struct TreeNode{
        
     int value;   
     TreeNode *left;
     TreeNode *right; 
     
       
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
        
int main(void){
        
        
        
       int data;
       TreeNode *root=NULL;
       
       int choose,loopflag=1;
        
    while(loopflag){
        
        cout <<"\n�G���j�M��(Binary Search Tree)"<<endl;   
		cout << "\n(1)���J�`�I\n(2)Level Order�C�X�𤤩Ҧ��`�I\n(3)�e�ǰl��\n(4)���ǰl��\n(5)��ǰl��\n(6)�R���@�`�I\n(7)�j�M�@�`�I\n(8)�p��𸭸`�I��\n(9)�p��`�I�`��\n(10)�p��𰪫�\n(11)�G���𥪥k�`�I�洫\n(0)���� => ";
		cin >> choose;        
       switch(choose){
        case 0:   
             loopflag=0;
             break;      
        case 1:   
             
             cout << "�п�J����J�����=> ";
			 cin >> data;
             BST_insert(data,&root);      
             break;
        case 2:
             levelOrder(root);
             break;
        case 3:
             cout<<"�e�Ǩ��X:";
             preorder(root);
             break;
        case 4:
             cout<<"���Ǩ��X:";
             inorder(root);
             break;
        case 5:
             cout<<"��Ǩ��X:";
             postorder(root);
             break;
        case 6:
             cout<<"�п�J�n�R�����`�I���";
             cin>>data;
             BST_delete(&root,data);
             break;
        case 7:
             cout<<"�п�J�n�j�M���`�I���";
             cin>>data;
             BST_search(root,data);
             break;
        case 8:
             cout<<"�𸭸`�I��:"<<leaves(root)<<"��"<<endl;
             break;
        case 9:
             cout<<"�`�I�`�Ƭ�:"<<countNode(root)<<"��"<<endl; 
             break;
        case 10:
             cout<<"�𰪬�:"<<height(root)<<endl;
             break; 
        case 11:
             swap(root);
             cout<<"���Ǩ��X:";
             inorder(root);
             break;                      
         default:
                 cout<<"��J���~"<<endl;    
                 break;
                      
                      
                      }             
                    
                    
                    
                    
                    }

     
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
               cout<<"������"<<x<<endl;
               break;
               }
       else if(x>ptr->value)        
               ptr=ptr->right;
       else if(x<ptr->value)
               ptr=ptr->left;                 
                        
       }
       
       if(ptr==NULL)
       cout<<"�䤣��Ӹ`�I"<<endl;
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
        cout<<"�䤣��Ӹ`�I"<<endl; 
     
  
        
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

