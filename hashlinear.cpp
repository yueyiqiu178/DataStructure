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
        cout << "雜湊表內容:" << endl;
        printTable(table);
        cout << endl << "\n(1)加入資料\n(2)搜尋資料\n(0)結束=>";
        cin >> choose;

        switch(choose)
        {
                case 0:
                       
                        loopflag=0;                        /*結束程式*/
						break;
						
				case 1:
                       if(isFull(table))
                         cout<<"桶子已滿"<<endl;
                       else{
                         cout << "請輸入欲加入之資料=>";
				            cin>>input;
							hashInsert(input,table);  
                            }  
                     	break;
                 case 2:
                       cout << "請輸入欲搜尋之資料=>";
                        cin >>input;
                        if((addr=hashSearch(input,table))==-1)
                          cout << "找不到資料" << endl;
                        else
							cout << "資料 " <<input<< " 於表格第 " << addr << " 個位置" << endl;
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



