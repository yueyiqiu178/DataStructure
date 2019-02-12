#include<iostream>
#define N 10
using namespace std;



typedef struct{
       int stackarray[N];
       int sp;
       
       
       }stack;
void createstack(stack *);
int push(stack *,int);
int pop(stack *);
void printstack(stack *);
int isempty(stack *);
int isfull(stack *);
int getitem(stack *,int);
int get(stack *,int);
int change(stack *,int,int);


int main(){
   stack s;
   int choose,loopflag=1;
   int data;
   int select;
   int cha;
   createstack(&s);
   
   
    

    while(loopflag){
                    cout<<"1:push\n2:pop\n3:list\n4:取出第二項元素值\n5:取得第i項元素值\n6:改變第i項元素值\n0:結束";
                    cin>>choose;
    switch(choose)
		{
		case 0:
			loopflag=0;			
			break;
		case 1:
			cout << "請輸入欲ＰＵＳＨ之資料 => ";
			cin >> data;
			if(push(&s,data))
				cout << "堆疊已滿,ＰＵＳＨ失敗"<<endl;
			break;
		case 2:
             int tag;
             tag=pop(&s);
			if(tag==1)
				cout << "堆疊已空,ＰＯＰ失敗"<<endl;
			else
			cout << "Pop 出 : " <<tag<<endl;
			break;
		case 3:
             printstack(&s);
            break; 
        case 4:
             if(isempty(&s))
             cout<<"空堆疊"<<endl;
             else
             cout<<"第二項元素為"<<getitem(&s,2)<<endl;
             break;
        case 5:
             cout<<"請輸入第幾個元素?";
             cin>>select;
             if(!get(&s,select))
             cout<<"超出堆疊範圍"<<endl;
             else
             cout<<"第"<<select<<"項元素為"<<get(&s,select)<<endl;
             break;   	
		
                
        case 6:
             cout<<"請輸入第幾個元素?";
             cin>>select;
             if(!get(&s,select))
             cout<<"超出堆疊範圍"<<endl;
             else{
              cout<<"請輸入要改變的值?";   
              cin>>cha;    
             change(&s,select,cha);
              }
             break;   	
		default:
			cout << "選項錯誤"<<endl;
		}
}
    
    
     return 0;
     
     }
 
void createstack(stack *p){
     p->sp=-1;
     } 
     
void printstack(stack *p){
     for(int i=0;i<=p->sp;i++)
     cout<<p->stackarray[i]<<" ";
     
     
     cout<<endl;
     
}


int push(stack *p,int x){
     if(isfull(p))
     return 1;
     p->sp++;
     p->stackarray[p->sp]=x;
     
     }
     
int pop(stack *p){
     if(isempty(p))
     return 1;
     else
     return p->stackarray[p->sp--];     
     
      
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

int getitem(stack *p,int i){
    
         return p->stackarray[--i];
         
         
}


int get(stack *p,int i){
     if((p->sp-i+1)<0)   
       return 0;
       else
       return p->stackarray[i-1];    
}



int change(stack *p,int i,int x){
     if((p->sp-i+1)<0)   
       return 0;
       else{
       p->stackarray[i-1]=x;
       return 1;}    
}


