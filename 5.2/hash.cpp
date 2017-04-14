#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
struct Listnode{
    string str;
    Listnode* next;
};
struct Hash{
    int hash_size;
    Listnode* *lists;
};
Hash* Create(int hash_size){
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
int hashfun(string str,int size){
    int result;
    for(int i=0;i<str.size();i++){
        result+=str[i];
    }
    result=result%size;
    return result;
}
Listnode* Find(Hash* h,string str){
    Listnode* result,*L;
    L=h->lists[hashfun(str,h->hash_size)];
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
        L=h->lists[hashfun(str,h->hash_size)];
        newcell->next=L->next;
        newcell->str=str;
        L->next=newcell;
    } 
}
void Delete(string str,Hash* h){
    Listnode* L,*pos,*pre;
    L=h->lists[hashfun(str,h->hash_size)];
    pre=pos=L->next;
    if(str.compare(pos->str)==0){
        L->next=pos->next;
        delete pos;
    }
    while(str.compare(pos->str)!=0){
        pre=pos;
        pos=pos->next;
    }
    pre->next=pos->next;
    delete pos;
}
int main(){
    vector<string> strs;
    ifstream fin;
    fin.open("flipped.txt");
    string str;
    while(fin>>str){
        strs.push_back(str);
    }
    Hash* H;
    H=Create(100);
    for(int i=0;i<strs.size();i++){
        Insert(strs[i],H);
    }
    string tofind;
    cin>>tofind;
    Listnode* p=Find(H,tofind);
    if(p==NULL){
        cout<<"can't find"<<endl;
    }else
        cout<<p->str<<endl;
    fin.close();
    return 0;
}