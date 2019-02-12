#include<iostream>

using namespace std;

struct Node{
       
      int vertex;
      Node *link; 
       
       
       };
       
       
struct HNode{
       
      int count;
      Node *link;
       
       
       };
       
       
       
HNode graph[9];       
       
void construct(HNode* ,int);
void topologicalSORT(HNode [],int);

int main(void){
    
      for(int i=1;i<=8;i++){
      graph[i].link=NULL;
    }
      
    HNode *head1=&graph[1];
    HNode *head2=&graph[2];
    HNode *head3=&graph[3];
    HNode *head4=&graph[4];
    HNode *head5=&graph[5];
    HNode *head6=&graph[6];
    HNode *head7=&graph[7];
    HNode *head8=&graph[8];
      
      
      construct(head1,2);
      construct(head1,6);
      construct(head2,3);
      construct(head2,4);
      construct(head3,5);
      construct(head3,7);
      construct(head4,5);
      construct(head5,8);
      construct(head6,4);
      construct(head6,5);
      construct(head7,8);
      
      graph[1].count=0;
      graph[2].count=1;
      graph[3].count=1;
      graph[4].count=2;
      graph[5].count=3;
      graph[6].count=1;
      graph[7].count=1;
      graph[8].count=2;
      
    
      
      
      topologicalSORT(graph,8);
      cout<<endl;
      
    
    
    system("pause");
    return 0;
}



void construct(HNode* ptr,int x){
      Node *ppp=new Node;
      ppp->vertex=x;
      ppp->link=NULL;
      
      if(ptr->link==NULL)
        ptr->link=ppp;
      else{
          Node *temp=ptr->link;
          while(temp->link!=NULL)
           temp=temp->link;
           
           temp->link=ppp;
           
           
           }  
           
     }
     
void topologicalSORT(HNode graph[],int n){
      
      Node *ptr;
      int i,j,k,top;
      top=-1;
      
      for(i=1;i<=n;i++)
          if(!graph[i].count){
                              
                   graph[i].count=top;
                   top=i;                
                              }              
      
      for(i=1;i<=n;i++)
         if(top==-1){
                cout<<"µo²{°j°é!!¦³¿ù»~!!"<<endl;
                break;     
                     }
        else{
             j=top;
             top=graph[top].count;
             cout<<"V:"<<j<<" ";
             for(ptr=graph[j].link;ptr;ptr=ptr->link){
                                                      
                  k=ptr->vertex;                                    
                  graph[k].count--;
                  if(!graph[k].count){
                                      
                     graph[k].count=top;
                     top=k;               
                                      }
                                                      
                  }
             
             }
             
     }
