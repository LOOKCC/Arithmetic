#include<iostream>
#include<stack>
using namespace std;
const int MAX=10000;
int numV,numE;
int pos[MAX],heap_size,heap[MAX],dis[MAX];
bool in_heap[MAX];
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
}Ver[MAX],tree[MAX];
void Create(int numV,Vnode Ve[]){
    for(int i=1;i<=numV;i++){
        Ve[i].V=i;
        Ve[i].firE=NULL;
    }
}
void Inserttail(int a,int b,int v,Vnode Ve[]){
    Enode *q=new Enode(b,v);
    if(Ve[a].firE==NULL){
        Ve[a].firE=q;
    }
    else{
        Enode *p=Ve[a].firE;
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
/*
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
*/
void Display(Vnode Ve[]){
    for(int i=1;i<=numV;i++){
        cout<<Ve[i].V;
        Enode* p=Ve[i].firE;
        while(p!=NULL){
            cout<<"->("<<p->vertex<<","<<"Value :"<<p->value<<")";
            p=p->next;
        }
        cout<<"->NULL"<<endl;
    }
}
void swap(int i,int j){
    int temp=heap[i];
    heap[i]=heap[j];
    heap[i]=temp;
    pos[heap[j]]=i;
    pos[heap[i]]=j;
}
void shift_up(int now){
    int next=0;
    while(now>1){
        next=now/2;
        if(dis[heap[next]]>dis[heap[now]])
            swap(next,now);
        now=next;
    }
}
void put(int x){
    in_heap[x]=true;
    heap[++heap_size]=x;
    pos[x]=heap_size;
    shift_up(heap_size);
}
int get(){
    int now=1,next,res=heap[1];
    in_heap[heap[1]]=false;
    heap[1]=heap[heap_size--];
    pos[heap[1]]=1;
    while(now*2<=heap_size){
        next=now*2;
        if(next<heap_size&&dis[heap[next+1]]<dis[heap[next]]){
            next++;
        }
        if(heap[now]<=heap[next])
            return res;
        swap(now ,next);
        now=next;
    }
    return res;
}
void dijkstra(stack<int> small[],Vnode Ve[]){
    put(1);
    dis[1]=0;
    while(heap_size>0){
        int top=get();
        Enode* temp=Ve[top].firE;
        while(temp!=NULL){
            if(dis[temp->vertex]>dis[top]+temp->value){
                dis[temp->vertex]=dis[top]+temp->value;
               // cout<<x<<endl;
                small[temp->vertex].push(top);
                if(in_heap[temp->vertex])
                    shift_up(pos[temp->vertex]);
                else
                    put(temp->vertex);
            }
            temp=temp->next;
        }
    }
}
int main(){

    cout<<"This is a dir graph"<<endl;
    cout<<"Please Input the number of vertex:"<<endl;
    cin>>numV;
    Create(numV,Ver);
    stack<int> small[numV+1];
    for(int i;i<=numV;i++){
        small[i].push(0);
    }
//    cout<<"a b v"<<endl;
    int a,b,v;
    numE=0;
    cin>>a>>b>>v;
    while(a!=0&&b!=0&&v!=0){
        Inserttail(a,b,v,Ver);
        numE++;
        cin>>a>>b>>v;  
    }
//    cout<<"Create over"<<endl;
    
    for(int i=2;i<=numV;i++){
        dis[i]=100;
    }
     dijkstra(small,Ver);
     Create(numV,tree);
     for(int i=2;i<=numV;i++){
         if(small[i].top()==0){
            continue;
         }
         Inserttail(small[i].top(),i,1,tree);
     }
     Display(tree);
     return 0;
}