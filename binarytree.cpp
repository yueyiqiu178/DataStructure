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
        
        cout <<"\n二元搜尋樹(Binary Search Tree)"<<endl;   
		cout << "\n(1)插入節點\n(2)Level Order列出樹中所有節點\n(3)前序追蹤\n(4)中序追蹤\n(5)後序追蹤\n(6)刪除一節點\n(7)搜尋一節點\n(8)計算樹葉節點數\n(9)計算節點總數\n(10)計算樹高度\n(11)二元樹左右節點交換\n(0)結束 => ";
		cin >> choose;        
       switch(choose){
        case 0:   
             loopflag=0;
             break;      
        case 1:   
             
             cout << "請輸入欲放入之資料=> ";
			 cin >> data;
             BST_insert(data,&root);      
             break;
        case 2:
             levelOrder(root);
             break;
        case 3:
             cout<<"前序走訪:";
             preorder(root);
             break;
        case 4:
             cout<<"中序走訪:";
             inorder(root);
             break;
        case 5:
             cout<<"後序走訪:";
             postorder(root);
             break;
        case 6:
             cout<<"請輸入要刪除的節點鍵值";
             cin>>data;
             BST_delete(&root,data);
             break;
        case 7:
             cout<<"請輸入要搜尋的節點鍵值";
             cin>>data;
             BST_search(root,data);
             break;
        case 8:
             cout<<"樹葉節點樹為:"<<leaves(root)<<"個"<<endl;
             break;
        case 9:
             cout<<"節點總數為:"<<countNode(root)<<"個"<<endl; 
             break;
        case 10:
             cout<<"樹高為:"<<height(root)<<endl;
             break; 
        case 11:
             swap(root);
             cout<<"中序走訪:";
             inorder(root);
             break;                      
         default:
                 cout<<"輸入錯誤"<<endl;    
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

