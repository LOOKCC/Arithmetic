#include<iostream>
#include<stack>
#include<vector>
using namespace std;
const int MAX=100;
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
void Create(int numV,Vnode Ver[]){
    for(int i=1;i<=numV;i++){
        Ver[i].V=i;
        Ver[i].firE=NULL;
    }
}
void Inserttail(int a,int b,int v,Vnode Ver[]){
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
void Display(Vnode Ver[]){
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
void Displaytree(Vnode tree[]){

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
int dijkstra(int a1,int a2){
    stack<int> sequence;
    put(a1);
    dis[a1]=0;
    while(heap_size>0){
        int top=get();
        sequence.push(top);
        if(top==a2){
            int x1=sequence.top();
            sequence.pop();
            int x2=sequence.top();
            sequence.empty();
            x2=x2*10+x1;
            return x2;
            break;
        }
        Enode* temp=Ver[top].firE;
        while(temp!=NULL){
            if(dis[temp->vertex]>dis[top]+temp->value){
                dis[temp->vertex]=dis[top]+temp->value;
                if(in_heap[temp->vertex])
                    shift_up(pos[temp->vertex]);
                else
                    put(temp->vertex);
            }
            temp=temp->next;
        }
    }
    return 0;
}
/*
struct treenode{
    int now;
    treenode* brother;
    treenode* children;
};
struct treenode* createtree(int tree1[]){
    treenode* head=new (struct treenode);
    head->now=1;
    head->brother=NULL;
    head->children=NULL;
    bool have=false;
    for(int i=2;i<=numV;i++){
        if(tree1[i]!=0){
            treenode* node=new (struct treenode);
            node->now=tree1[i]%10;
            node->brother=NULL;
            node->children=NULL;
            if(!have){
                head->children=node;
                have=true;
            }else{
                treenode* temp=head->children;
                while(temp->brother)
                    temp=temp->brother;
                temp->brother=node;
            }
        }
    }
    return head;
}
struct treenode* addtree(treenode* head,int tree[]){
    for(int i=2 ;i<numV+1;i++){
        if(tree[i]>20){
            
        }
    }
}
*/
int main(){
    cout<<"This is a dir graph"<<endl;
    cout<<"Please Input the number of vertex and the Edge:"<<endl;
    cin>>numV>>numE;
    Create(numV,Ver);
    cout<<"a b v"<<endl;
    int a,b,v;
    while(numE--){
        cin>>a>>b>>v;
        Inserttail(a,b,v,Ver);
    }
    cout<<"Create over"<<endl;
    Display(Ver);

//Begin to find 
    for(int i=1;i<=numV;i++)
        dis[i]=100;
//    int tree1[numV+1];
    int mtree[numV+1];
    for(int i=0;i<=numV+1;i++){
        mtree[i]=0;
//        tree1[i]=0;
    }
    for(int i=2;i<=numV;i++){
        mtree[i]=dijkstra(1,i);
        cout<<mtree[i]<<endl;
//        if(tree[i]>10&&tree[i]<20){
//            tree1[i]=tree[i];
//        }
    }
//    struct treenode* head=new (treenode);
//    head=createtree(tree1);
//    head=addtree(head,tree);

/*
     Create(numV,tree);
     for(int i=1;i<=numV;i++){
         Inserttail(mtree[i]/10,mtree[i]%10,1,tree);
     }
     Display(tree);


*/
    return 0;
}