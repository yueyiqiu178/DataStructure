#include <iostream>
using namespace std;


struct Data{
       
       char c1; 
       char c2;
       Data *link;
       
       };

Data *Ahead;
Data *Bhead;
Data *Chead;
Data *Dhead;
Data *Ehead;
Data *Fhead;
Data *Ghead;



int main()
{
    Data *L1=new Data;
    L1->c1='C';
    L1->c2='G';
   
    Data *L2=new Data;
    L2->c1='L';
    L2->c2='A';
    
    
    Data *L3=new Data;
    L3->c1='A';
    L3->c2='C';
    
    Data *L4=new Data;
    L4->c1='D';
    L4->c2='E';
    
    Data *L5=new Data;
    L5->c1='C';
    L5->c2='A';
    
    Data *L6=new Data;
    L6->c1='F';
    L6->c2='G'; 
    
    Data *head=L1;
    L1->link=L2;
    L2->link=L3;
    L3->link=L4;
    L4->link=L5;
    L5->link=L6;
    L6->link=NULL;
    
    
    for(int i=1;i<=2;i++){  
    while(head!=NULL){
                    
        switch(head->c1) {             
        case 'A':;
        case 'B':;
        case 'C':;
        case 'D':;
        case 'E':;
        case 'F':;
        case 'G': ;                            
                                              }
                      }
                      
                      }
    
    
   	system("pause");
	return 0;
}


