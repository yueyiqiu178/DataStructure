#include<iostream>
#define N 20
#define StackNum 5
using namespace std;



struct Stack{
       int stackarray[N];
       int top[StackNum+1];
       int boundary[StackNum+2];
       
       };
       
void createstack(Stack *);
int AddStack(Stack *,int,int);
int DelStack(Stack *,int,int*);
void printstack(Stack *,int i);
int isempty(Stack *,int i);
int isfull(Stack *);
void StackPack(Stack *,int);


int main(){
   Stack s;
   int choose,loopflag=1;
   int num;
   int data;
   createstack(&s);
   
   
    

    while(loopflag){
                    cout<<endl;
                    cout<<"此為多重堆疊,共有5個堆疊,請輸入您的操作:"<<endl; 
                    cout<<"1:push\n2:pop\n3:list\n0:結束 => ";
                    cin>>choose;
    switch(choose)
		{
		case 0:
			loopflag=0;			
			break;
		case 1:
			cout<<"請輸入要PUSH堆疊之編號 => ";
			cin>>num;
			cout<<"請輸入欲PUSH之資料";
			cin>>data; 
			AddStack(&s,num,data); 
			break;
		case 2:
            cout<<"請輸入要Pop堆疊之編號 => ";
			cin>>num;
			DelStack(&s,num,&data);
			cout<<"Pop出"<<data<<endl; 
			break;
		
		case 3:
             cout<<"請輸入欲列出堆疊的編號:";
             cin>>num;
             printstack(&s,num);
             break; 
        
		default:
			cout << "選項錯誤"<<endl;
			break;
		}
}
    
    
     return 0;
     
     }
 
void createstack(Stack *p){
     int i;
     for(i=1;i<=StackNum;i++)
        p->top[i]=p->boundary[i]=(i-1)*N/StackNum;
        
        p->boundary[i+1]=N;   
        p->boundary[0]=0;
     } 
     
void printstack(Stack *p,int i){
     
     if(p->top[i]==p->boundary[i])
       cout<<"堆疊為空"<<endl; 
     else{
     for(int j=p->boundary[i]+1;j<=p->top[i];j++)
     cout<<p->stackarray[j]<<" ";
     
     cout<<endl;
     }
     
}


int AddStack(Stack *p,int i,int x){
    
     if(p->top[i]==p->boundary[i+1])
     StackPack(p,i);
     p->top[i]++;
     p->stackarray[p->top[i]]=x;
     
     }
     
int DelStack(Stack *p,int i,int *x){
     if(isempty(p,i))
     return 1;
     else
     *x=p->stackarray[p->top[i]--];     
     
      
     }
     

int isempty(Stack *p,int i){
    
      if(p->top[i]==p->boundary[i])
         return 1;
      else
         return 0;
    
    
} 


void StackPack(Stack *p,int i){
     int j,k;
     
     for(j=i+1;j<=StackNum&&p->top[j]==p->boundary[i+1];j++);
     if(j<=StackNum){
         for(k=p->top[j];k>p->boundary[i+1];k--)
            p->stackarray[k+1]=p->stackarray[k];
         for(k=i+1;k<=j;k++){
            p->boundary[k]++;   
            p->top[k]++;
                             }}
     else{
          for(j=i-1;j>=1&&p->top[j]==p->boundary[j+1];j--);
          if(j>=1){
              for(k=p->boundary[j+1]+1;k<=p->top[i];k++)     
                 p->stackarray[k-1]=p->stackarray[k];
              for(k=j+1;k<=i;k++) {
                         p->boundary[k]--; 
                         p->top[k]--;         
                                  }
                   }
             else
                cout<<"堆疊整個滿了"<<endl;    
          
          
          }
              
              
     
     
     
     }
     



