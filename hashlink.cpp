#include <iostream>
#define N 13
#define EMPTY -1

using namespace std;

struct Node{
       
       int key;
       Node* link;
       
       
       };

void printTable(Node []);
void hashInsert(int ,Node []);
int hashSearch(int,Node []);

int main()
{
    int input,addr;
    int choose, loopflag=1;
    
    Node table[N];
    
    for(int i=0;i<N;i++){
      table[i].key=EMPTY; 
      table[i].link=NULL;
     }
     
    while(loopflag)
    {
        cout<<endl;
        cout << "������e:" << endl;
        printTable(table);
        cout << endl << "\n(1)�[�J���\n(2)�j�M���\n(0)����=>";
        cin >> choose;

        switch(choose)
        {
                case 0:
                       
                        loopflag=0;                        /*�����{��*/
						break;
						
				case 1:
                         cout << "�п�J���[�J�����=>";
				            cin>>input;
							hashInsert(input,table);  
       
                     	break;
                 case 2:
                       cout << "�п�J���j�M�����=>";
                        cin >>input;
                        if((addr=hashSearch(input,table))==-1)
                          cout << "�䤣����" << endl;
                        else
							cout << "��� " <<input<< " ����� " << addr << " �Ӧ�m" << endl;
                        break;        	
                
                default:
               	    cout << "Wrong Input !!!! " << endl;
        }
    }
    
	    return 0;
}


void printTable(Node x[]){
       
       Node *ptr;
             
       for(int i=0;i<N;i++){
         ptr=&x[i];
         cout<<"Bucket"<<i<<":";      
          while(ptr!=NULL){     
             cout<<ptr->key<<" ";
             ptr=ptr->link;
             }  
           cout<<endl;    
               }    
             
             
             }
             
void hashInsert(int key,Node x[]){
     
      int addr=key%N;
      
      if(x[addr].key==EMPTY){
          x[addr].key=key;                     
                             } 
      else{
           Node *ptr=&x[addr];
           
           while(ptr->link!=NULL)
             ptr=ptr->link;
             
           Node *p=new Node;
           p->key=key;
           p->link=NULL;
           
           ptr->link=p;  
           
           }
     }
     
int hashSearch(int key,Node x[]){
     
       int addr=key%N;
       
       Node *ptr=&x[addr];
       
       while(ptr->key!=key){
                            
            ptr=ptr->link;
                            
            if(ptr==NULL)                
              return -1;    
                            }
       return addr;
        
     
     }
