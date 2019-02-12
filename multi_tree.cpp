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
        
void BST_insert(TreeNode **,int);
bool equal(TreeNode *,TreeNode *);    
bool compare(TreeNode *,TreeNode *);        
TreeNode* copy(TreeNode *);  
void BST_sort(TreeNode *,int []); 
void BST_sort2(TreeNode *,int []);
void inorder(TreeNode *);
void mergetwoBST(TreeNode *,TreeNode *,int []);
TreeNode* BST_build(int [],int,int,int);
int isfull(stack *);
int isempty(stack *);
void preorder(TreeNode *);
void inorder(TreeNode *);
void postorder(TreeNode *);
bool BST_Check(TreeNode *,int,int);
TreeNode* Tree_build(int [],int,int);
void BST_sortnew(TreeNode *,int [],int &);


int m=0;
int n=0;
        
int main(void){
    
    TreeNode *tree1=NULL,*tree2=NULL,*tree3=NULL,*tree4=NULL,*tree5=NULL;
    TreeNode *tree6=NULL,*tree7=NULL;
    
    BST_insert(&tree6,10);
    BST_insert(&tree6,5);
    BST_insert(&tree6,20);
    BST_insert(&tree6,3);
    BST_insert(&tree6,8);
    BST_insert(&tree6,15);
    BST_insert(&tree6,30);
    
    
    BST_insert(&tree7,10);
    BST_insert(&tree7,5);
    BST_insert(&tree7,20);
    BST_insert(&tree7,3);
    BST_insert(&tree7,8);
    //BST_insert(&tree7,15);
    BST_insert(&tree7,70);
    
    cout<<compare(tree6,tree7)<<endl;
    
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
    
    BST_insert(&tree2,53);
    BST_insert(&tree2,26);
    BST_insert(&tree2,38);
    BST_insert(&tree2,6);
    BST_insert(&tree2,40);
    BST_insert(&tree2,55);
    BST_insert(&tree2,35);
    BST_insert(&tree2,54);
    BST_insert(&tree2,58);
    BST_insert(&tree2,56);
    
    BST_insert(&tree4,25);
    BST_insert(&tree4,63);
    BST_insert(&tree4,14);
    BST_insert(&tree4,74);
    BST_insert(&tree4,80);
    BST_insert(&tree4,23);
    BST_insert(&tree4,29);
    BST_insert(&tree4,67);
    BST_insert(&tree4,20);
    BST_insert(&tree4,10);
    
    
    if(equal(tree1,tree2))
    cout<<"1,2樹完全相等"<<endl;
    else
    cout<<"1,2樹不相等"<<endl; 
    
    if(compare(tree1,tree2))
    cout<<"1,2樹除了樹葉(leaf)外,內部節點(internal node)的結構與資料均相等"<<endl; 
    else
    cout<<"1,2樹除了樹葉(leaf)外,內部節點(internal node)的結構與資料不相等"<<endl;
    
    
    tree3=copy(tree1);
    
    if(equal(tree1,tree3))
    cout<<"1,3樹完全相等"<<endl;
    else
    cout<<"1,3樹不相等"<<endl; 
    
    if(compare(tree1,tree3))
    cout<<"1,3樹除了樹葉(leaf)外,內部節點(internal node)的結構與資料均相等"<<endl; 
    else
    cout<<"1,3樹除了樹葉(leaf)外,內部節點(internal node)的結構與資料不相等"<<endl;
    
    int result[20]={0};
      
    mergetwoBST(tree2,tree4,result); 
    
    cout<<"最後的陣列為:"<<endl;
    for(int i=0;i<20;i++){
      cout<<setw(3)<<result[i]<<"  ";
      if(i%5==4)
      cout<<endl;
      }
      cout<<endl;
      
      tree5=BST_build(result,0,19,20);
     
      cout<<endl;
      
      preorder(tree1);
      cout<<endl;
      inorder(tree1);
      cout<<endl;
      postorder(tree1);
      cout<<endl;
      
      int aa[10]={12,45,90,34,100,80,23,44,87,20};
      int bb[10]={12,45,90,34,100,80,23,44,87,20};
      TreeNode *rootnew=BST_build(aa,0,9,10);
      inorder(rootnew);
      cout<<endl;
      
      cout<<"是否為一棵二元搜尋數? "<<BST_Check(rootnew,MIN,MAX)<<endl;
      
      TreeNode *notbst=Tree_build(bb,0,9);
      
      cout<<"是否為一棵二元搜尋數? "<<BST_Check(notbst,MIN,MAX)<<endl;
      int i=0;
      int cc[10];
      BST_sortnew(rootnew,cc,i);
      
      for(int i=0;i<10;i++)
        cout<<cc[i]<<" ";
      cout<<endl;
      
     system("pause"); 
     return 0;  
}

TreeNode* Tree_build(int x[],int low,int high){
     
       
          if(low>high)
          return NULL;
          else{
             int mid=(low+high)/2;
          TreeNode *p=new TreeNode;
          p->value=x[mid];
          p->left=Tree_build(x,low,mid-1);
          p->right=Tree_build(x,mid+1,high);
          
          return p;
          
          }
     
     
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



bool equal(TreeNode *treeA,TreeNode *treeB){
     if(treeA==NULL&&treeB==NULL)
        return true;
     else if(treeA==NULL||treeB==NULL)
        return false;
     else
        return treeA->value==treeB->value&&equal(treeA->left,treeB->left)&&equal(treeA->right,treeB->right);
          
     }
     
bool compare(TreeNode *treeA,TreeNode *treeB){
       if(treeA==NULL&&treeB==NULL)
               return true;
       else if(treeA==NULL||treeB==NULL)
               return false;
       else{
            if(treeA->left==NULL&&treeB->left==NULL&&treeA->right==NULL&&treeB->right==NULL)
                 return true;
            else if(treeA->value==treeB->value) 
                 return compare(treeA->left,treeB->left)&&compare(treeA->right,treeB->right);
            else    
                 return false; 
            
            }        

     }
     
TreeNode* copy(TreeNode *ptr){
          
       TreeNode *newtree;
       if(ptr!=NULL){
          newtree=new TreeNode;
          newtree->value=ptr->value;
          newtree->left=copy(ptr->left);
          newtree->right=copy(ptr->right);
          return newtree;
          
          }
          else
            return NULL; 
          
          }

void BST_sortnew(TreeNode *ptr,int a[],int &i){
     
     
     
     if(ptr!=NULL){
              BST_sortnew(ptr->left,a,i);     
              a[i++]=ptr->value;
              BST_sortnew(ptr->right,a,i);     
              
                   }

     }     



          
void BST_sort(TreeNode *ptr,int a[]){
     
     
     
     if(ptr!=NULL){
              BST_sort(ptr->left,a);     
              a[m++]=ptr->value;
              BST_sort(ptr->right,a);     
              
                   }

     }     
void BST_sort2 (TreeNode *ptr,int a[]){
     
    
     
     if(ptr!=NULL){
              BST_sort2(ptr->left,a);     
              a[n++]=ptr->value;
              BST_sort2(ptr->right,a);     
              
                   }

     }
     

void mergetwoBST(TreeNode *treeA,TreeNode *treeB,int x[]){
     
     int num1[100];
     int num2[100];
     int n1=0;
     int n2=0;
     BST_sortnew(treeA,num1,n1);
     cout<<"第一棵樹陣列內容如下:"<<endl; 
     for(int i=0;i<10;i++)
        cout<<num1[i]<<"  ";
        
        cout<<endl;
    
      
      inorder(treeA);
      cout<<endl;
      
     
        
      BST_sortnew(treeB,num2,n2);
        cout<<"第二棵樹陣列內容如下:"<<endl; 
        for(int j=0;j<10;j++)
           cout<<num2[j]<<"  ";
      
      cout<<endl;
     
       cout<<"n1="<<n1<<" n2="<<n2<<endl; 
      
      int i=0,j=0,k=0;
      
      
      while(i<n1&&j<n2){
         if(num1[i]>num2[j])
         x[k++]=num2[j++];        
         else
         x[k++]=num1[i++];
             }
        while(i<n1)     
        x[k++]=num1[i++];
     
        while(j<n2)     
        x[k++]=num2[j++];
     }
     
     

TreeNode* BST_build(int x[],int low,int high,int n){
          
           int i,j,tmp,flag;
          for(i=n-1;flag&&i>=1;i--){
             flag=0;
             for(j=0;j<i;j++){
                 if(x[j]>x[j+1]){
                         tmp=x[j];
                         x[j]=x[j+1];
                         x[j+1]=tmp;
                         flag=1;  
             }}
     
     
     }
          
          
          if(low>high)
          return NULL;
          else{
             int mid=(low+high)/2;
          TreeNode *p=new TreeNode;
          p->value=x[mid];
          p->left=BST_build(x,low,mid-1,n);
          p->right=BST_build(x,mid+1,high,n);
          
          return p;
          
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
     cout<<"前序:"<<endl;
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
     
     
void inorder(TreeNode *ptr){
     cout<<"中序:"<<endl;
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
              push(&s,p,true);
              push(&s,p->left,false); 
               
               } 
               
               }
                 
             }
     }
     
     
void postorder(TreeNode *ptr){
     cout<<"後序:"<<endl;
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
              push(&s,p,true);
              push(&s,p->right,false); 
              push(&s,p->left,false); 
               
               }   
               
               }
               
             }
     }
     
     
bool BST_Check(TreeNode *ptr,int low,int high){
        if(ptr==NULL)
           return true;
        else if((ptr->value)<low||(ptr->value>high))   
           return false;
        else{
             
     return BST_Check(ptr->left,low,ptr->value)&&BST_Check(ptr->right,ptr->value,high);
             
             }   
     
     
     }
     
