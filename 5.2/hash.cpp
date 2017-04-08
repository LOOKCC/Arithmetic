#include<iostream>
#include<string>
using namespace std;
struct Listnode{
    string str;
    Listnode* next;
};
struct Hash{
    int hash_size;
    Listnode* *lists;
};
Hash* Creste(int hash_size){
    Hash* h;
    h=new (struct Hash);
    h->hash_size=hash_size;
    h->lists=new Listnode*[hash_size];
    for(int i=0;i<hash_size;i++){
        h->lists[i]=new Listnode;
        h->lists[i]->next=NULL;
    }
    return h;
}
int hash(string str,int size){
    int result;
    for(int i=0;i<str.size();i++){
        result+=str[i];
    }
    result=result%size;
    return result;
}
Listnode* Find(Hash* h,string str){
    Listnode* result,*L;
    L=h->lists[hash(str,h->hash_size)];
    result=L->next;
    while(result!=NULL&&str.compare(result->str)!=0)
        result=result->next;
    return result;
}
void Insert(string str,Hash* h){
    Listnode* L,*pos,*newcell;
    pos=Find(h,str);
    if(pos==NULL){
        newcell=new (struct Listnode);
        L=h->lists[hash(str,h->hash_size)];
        newcell->next=L->next;
        newcell->str=str;
        L->next=newcell;
    } 
}
void Delete(string ,Hash* h){
    
}
