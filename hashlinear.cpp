#include <iostream>
#define N 13
#define EMPTY -1


using namespace std;

void printTable(int []);
int isFull(int []);
void hashInsert(int,int []);
int hashSearch(int,int []);

int main()
{
    int input,addr;
    int choose, loopflag=1;
    
    int table[N];
    
    for(int i=0;i<N;i++)
      table[i]=EMPTY; 
     
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
                       if(isFull(table))
                         cout<<"��l�w��"<<endl;
                       else{
                         cout << "�п�J���[�J�����=>";
				            cin>>input;
							hashInsert(input,table);  
                            }  
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



void printTable(int x[]){
      
      for(int i=0;i<N;i++){
              if(x[i]==EMPTY)
              cout<<"e ";
              else
              cout<<x[i]<<" ";
              
              }
     
     
     }
     
     
int isFull(int x[]){
    
    for(int i=0;i<N;i++){
            
         if(x[i]==EMPTY)   
           return 0;
            
            }
            
    return 1;
    
    }
    
    
    
void hashInsert(int key,int x[]){
     
     int addr=key%N;
    
     while(x[addr]!=EMPTY)
        addr=(addr+1)%N;
       
       x[addr]=key;   
          
          
          }
     
     
int hashSearch(int key,int x[]){
    
     int addr=key%N;
     
     while(x[addr]!=key){
                         
         addr=(addr+1)%N;
          if(x[addr]==EMPTY||addr==key%N)
            return -1;               
         
         }
    
    return addr;
    
    
    }



