#include<iostream>
using namespace std;
const int MAX=100;
int numV,numE;
struct Enode{
    int vertex;
    int value;
    Enode* next;
    Enode(){};
    Enode(int ver,int v):vertex(ver),value(v){};
    Enode(int ver):vertex(ver){};
};
struct Vnode{
    int V;
    Enode* firE;
}Ver[MAX];
void Init(int numV){
    for(int i=1;i<numV;i++){
        Ver[i].V=i;
        Ver[i].firE=NULL;
    }
}
void Inserttail(int a,int b,int v){
    Enode *q=new Enode(b,v);
    if(Ver[a].firE==NULL){
        Ver[a].firE=q;
    }
    else{
        Enode *p=Ver[a].firE;
        if(p->vertex==b){
            if(p->value<v)
                p->value=v;
                return ;
        }
        while(p->next!=NULL){
            if(p->next->vertex==b){
                if(p->next->value<v)
                    p->next->value=v;
                    return ;
            }
            p=p->next;
        }
        p->next=q;
    }
}
void Inserthead(){

}
void Delete(){

}
void Display(){

}

int main(){
    cout<<"Please Input the number of vertex:"<<endl;
    cin>>numV;
    Init(numV);

}