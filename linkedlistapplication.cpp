#include<iostream>


using namespace std;

struct Node{
       
        
     char name[10];
     int price;
     int quantity;   
     Node  *link;   
        };
        
        
void addNode(Node **,char [],int,int);       
void sum_recursive(Node *,double &);      
void sum(Node *);        

int main(void){
    
    Node *head=NULL;
    char str1[]={'a','p','p','l','e'};
    char str2[]={'o','r','a','n','g','e'};
    char str3[]={'b','a','n','a','n','a'};
    char str4[]={'l','e','m','o','n'};
    
    
    addNode(&head,str1,100,9);
    addNode(&head,str2,150,3);
    addNode(&head,str3,130,13);
    addNode(&head,str4,170,4);
    
    double total=0.0;
    
    sum(head);
    sum_recursive(head,total);
    cout<<"總合為:"<<total<<endl;
    
    
    
    sum_recursive(head,total);
    
    
    
    
     system("pause");
     return 0;
    
    
}



void addNode(Node **head,char str[],int p,int q){
     
     Node *ptr=*head;
     Node *newNode=new Node;
     strcpy(newNode->name,str);
     newNode->price=p;
     newNode->quantity=q;
     newNode->link=NULL;
     
     if(*head==NULL) 
        *head=newNode;
     else{
          
        while(ptr->link!=NULL)
          ptr=ptr->link;
          
        ptr->link=newNode;  
          
          }
        
        
     }
     
void sum(Node *ptr){
      
      double sum=0; 
      
      while(ptr!=NULL){
                    
         sum+=(ptr->price)*(ptr->quantity);           
        ptr=ptr->link;         
           
                    }
       
     cout<<"總合為"<<sum<<endl; 
     
     }
     
     
     
void sum_recursive(Node *ptr,double &sum){
       
       
        
       if(ptr==NULL)
             sum+=0;     
       else{
           sum+=((ptr->price)*(ptr->quantity));  
           sum_recursive(ptr->link,sum);
           }
           
           
     }
