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
void Create(int numV){
    for(int i=1;i<=numV;i++){
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
void Inserthead(int a,int b,int v){
    Enode *q=new Enode(b,v);
    if(Ver[a].firE==NULL){
        Ver[a].firE=q;
    }
    else{
        Enode *p=Ver[a].firE;
        q->next=p;
        Ver[a].firE=q;
    }
}
void Delete(int a,int b){
    Enode *p=Ver[a].firE;
    if(p->vertex==b){
        Ver[a].firE=p->next;
        delete p;
        return ; 
    }
    while(p->next!=NULL){
        if(p->next->vertex==b){
            p->next=p->next->next;
            delete p->next;
            return ;
        }
    }
}
void Display(){
    for(int i=1;i<=numV;i++){
        cout<<Ver[i].V;
        Enode* p=Ver[i].firE;
        while(p!=NULL){
            cout<<"->("<<p->vertex<<","<<"Value :"<<p->value<<")";
            p=p->next;
        }
        cout<<"->NULL"<<endl;
    }
}
int main(){
    cout<<"This is a undir graph."<<endl;
    cout<<"Please Input the number of vertex and the Edge:"<<endl;
    cin>>numV>>numE;
    Create(numV);
    cout<<"a b v"<<endl;
    int a,b,v;
    while(numE--){
        cin>>a>>b>>v;
        Inserttail(a,b,v);
//deference
        Inserttail(b,a,v);
//      Inserthead(a,b,v);
    }
    cout<<"Create over"<<endl;
    Display();
    cout<<"Now you can delete a,b"<<endl;
    cin>>a>>b;
    Delete(a,b);
//deference
    Delete(b,a);
    cout<<"delete over"<<endl;
    Display();
    return 0;
}