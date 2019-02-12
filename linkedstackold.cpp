#include<iostream>

using namespace std;

struct Node{
        
     int data;   
     Node* link;   
        };
        
struct stack{
       
     Node *top;  
       
       };        
  
void initial(stack *);  
void push(stack *,int);
int pop(stack *);  
int getTop(stack *);
void listAll(stack *);
  
        
int main(void){
            
   stack s;
   int choose,loopflag=1;
   int data;
   int select;
   int cha;
   initial(&s);
   
   
    

    while(loopflag){
                    cout<<"1:push\n2:pop\n3:���X���ݤ���\n4:�C�X���|�Ҧ�����\n0:����";
                    cin>>choose;
    switch(choose)
		{
		case 0:
			loopflag=0;			
			break;
		case 1:
			cout << "�п�J���ޢ��֤���� => ";
			cin >> data;
			push(&s,data);
				
			break;
		case 2:
             int tag;
             tag=pop(&s);
			if(tag==0)
				cout << "���|�w��,�ޢݢޥ���"<<endl;
			else
			cout << "Pop �X : " <<tag<<endl;
			break;
		case 3:
             getTop(&s);
            break; 
        case 4:
             listAll(&s);
             break;
		default:
			cout << "�ﶵ���~"<<endl;
		}
}     
      
      
      
      
      
            
          
      return 0;
    
}


void initial(stack *p){
     p->top=NULL;
     
     }


void push(stack *p,int x){
     
     Node *newNode=new Node;
     newNode->data=x;
     newNode->link=p->top;
     p->top=newNode;
     
     
     }
     
int pop(stack *p){
      if(p->top==NULL)
        return 0;
     else{
        int x;
        Node *ptr;
        ptr=p->top;
        x=p->top->data;
        p->top=p->top->link;
        x=ptr->data;
        free(ptr);
        return x;  
          
          }
     
     }


int getTop(stack *p){
    if(p->top==NULL)
      return 0;
    else
       return p->top->data;
        
    }
    
    
void listAll(stack *p){
     Node *ptr=p->top;
     while(ptr!=NULL){
     cout<<ptr->data<<" ";
     ptr=ptr->link;
     }
     cout<<endl;
     
     }
