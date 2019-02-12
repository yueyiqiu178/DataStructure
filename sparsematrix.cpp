#include<iostream>

using namespace std;

struct Entry{
       int row;
       int col;
       int value;
       
       };

struct MatrixNode{
       MatrixNode *down;
       MatrixNode *right;
       bool fieldflag;
       union{
             MatrixNode *next;
             Entry entry;
             
             
             }u;
       };

MatrixNode *hdnode[20];

int main(void){
    
    
    
    
    
    
    system("pause");
    return 0;
    
    }
    
    
MatrixNode* buildMatrix(){
     MatrixNode *temp;
     int numRow=5;
     int numCol=4;
     int numHead=(numRow>numCol)?numRow:numCol;
     MatrixNode *node=new MatrixNode;
     node->fieldflag=true;
     node->u.entry.row=numRow;
     node->u.entry.col=numCol;
     
     for(int i=0;i<numHead;i++){
             
             temp=new MatrixNode;
             hdnode[i]=temp;
             hdnode[i]->fieldflag=true;
             hdnode[i]->right=temp;
             hdnode[i]->down=temp;
             hdnode[i]->u.next=temp;
             }
     
     int currentRow=0;
     MatrixNode *last=hdnode[0];
     int col,row,value;
     
     
     row=0;
     col=0;
     value=2;
     if(row>currentRow){
           last->right=hdnode[currentRow];             
           currentRow=row;
           last=hdnode[row];             
                        }
     temp=new MatrixNode;
     temp->fieldflag=false;
     temp->u.entry.row=row;
     temp->u.entry.col=col;
     temp->u.entry.value=value;
     last->right=temp;
     last=temp;
     hdnode[col]->u.next->down=temp;
     hdnode[col]->u.next=temp;
     
     row=1;
     col=0;
     value=4;
     if(row>currentRow){
           last->right=hdnode[currentRow];             
           currentRow=row;
           last=hdnode[row];             
                        }
     temp=new MatrixNode;
     temp->fieldflag=false;
     temp->u.entry.row=row;
     temp->u.entry.col=col;
     temp->u.entry.value=value;
     last->right=temp;
     last=temp;
     hdnode[col]->u.next->down=temp;
     hdnode[col]->u.next=temp;
     
     
     row=1;
     col=3;
     value=3;
     if(row>currentRow){
           last->right=hdnode[currentRow];             
           currentRow=row;
           last=hdnode[row];             
                        }
     temp=new MatrixNode;
     temp->fieldflag=false;
     temp->u.entry.row=row;
     temp->u.entry.col=col;
     temp->u.entry.value=value;
     last->right=temp;
     last=temp;
     hdnode[col]->u.next->down=temp;
     hdnode[col]->u.next=temp;
     
     
     }
    
