#include<iostream>
#define N 10
using namespace std;



struct stack{
       int stackarray[N];
       int top1;
       int top2;
       
       };
void createstack(stack *);
int push(stack *,int,int);
int pop(stack *,int);
void printstack(stack *,int);
int isempty(stack *,int);
int isfull(stack *);



int main(){
   stack s;
   createstack(&s);
   for(int i=0;i<N;i++)
   s.stackarray[i]=0;
   
   int choose,loopflag=1;
   int data;
  
   
   
    

    while(loopflag){
                    cout<<"1:(Stack1)push\n2:(Stack1)pop\n3:(Stack2)push\n4:(Stack2)pop\n5:�C�XStack1\n6:�C�XStack2\n0:����";
                    cin>>choose;
    switch(choose)
		{
		case 0:
			loopflag=0;			
			break;
		case 1:
			cout << "�п�J���ޢ��֤���� => ";
			cin >> data;
			if(push(&s,1,data))
				cout << "���|�w��,�ޢ��֥���"<<endl;
			break;
		case 2:
             int tag;
             tag=pop(&s,1);
			if(tag==1)
				cout << "���|�w��,�ޢݢޥ���"<<endl;
			else
			cout << "Pop �X : " <<tag<<endl;
			break;
    	case 3:
			cout << "�п�J���ޢ��֤���� => ";
			cin >> data;
			if(push(&s,2,data))
				cout << "���|�w��,�ޢ��֥���"<<endl;
			break;
		case 4:
             int tag2;
             tag2=pop(&s,2);
			if(tag2==1)
				cout << "���|�w��,�ޢݢޥ���"<<endl;
			else
			cout << "Pop �X : " <<tag2<<endl;
			break;
		case 5:
            printstack(&s,1);
            break;
        case 6:
            printstack(&s,2);
            break; 
		default:
			cout << "�ﶵ���~"<<endl;
		}
}
     return 0;
     
     }
 
void createstack(stack *p){
     p->top1=-1;
     p->top2=N;
    
     } 
     
void printstack(stack *p,int i){
     if(i==1){
     for(int i=0;i<=p->top1;i++)
     cout<<p->stackarray[i]<<" ";
     cout<<endl;
     }
     else{
      for(int i=N-1;i>=p->top2;i--)
     cout<<p->stackarray[i]<<" ";
     cout<<endl;    
          }     
}


int push(stack *p,int i,int x){
     if(isfull(p)) 
     return 1;
     if(i==1){
     p->top1++;
     p->stackarray[p->top1]=x;}
     else{
     p->top2--;
     p->stackarray[p->top2]=x;
     }
     
     }
     
int pop(stack *p,int i){
     if(isempty(p,i))
     return 1;
     else if(i==1)
     return p->stackarray[p->top1--];
     else
     return p->stackarray[p->top2++];
     
     
      
     } 
     
int isempty(stack *p,int i){
     if(i==1){
       if(p->top1==-1)
          return 1;
       else
          return 0;      
     }
     else{
       if(p->top2==N)
          return 1;
       else
          return 0;        
          }
}  
int isfull(stack *p){
    if(p->top1+1==p->top2)   
    return 1;
    else
    return 0;   
}


