#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
using namespace std;
const int letter=26;
vector<int> res;
struct node{
    node* fail;
    node* child[letter];
    int pos;
    node(){
        fail=NULL;
        for(int i=0;i<letter;i++)
            child[i]=NULL;
        pos=-1;
    }
};
node* root;
node* Q[3000000];
void Init(){
    root=new (node); 
}
void insert(char* s,int num){
    node* p=root;
 //   cout<<"insert begin"<<endl;
    for(char* c=s;*c!='\0';++c){
        int t=(*c)-'a';
        if(p->child[t]==NULL){
            p->child[t]=new (node);
        }
        p=p->child[t];
        if((*(c+1))=='\0')
            p->pos=num;
    }
 //   cout<<"insert over"<<endl;
}
void BFP(){
 //   cout<<"begin to build fail point"<<endl;
    int Qh=0,Qt=1;
    Q[1]=root;
    while(Qh<Qt){
        node* now=Q[++Qh];
        for(int i=0;i<letter;i++){
            if(now->child[i]!=NULL){
                if(now==root)
                    now->child[i]->fail=root;
                else{
                    node *p=now->fail;
                    while(p!=NULL){
                        if(p->child[i]!=NULL){
                            now->child[i]->fail=p->child[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL)
                        now->child[i]->fail=root;
                }
                Q[++Qt]=now->child[i];
            }
        }
    }
//    cout<<"build over"<<endl;
}
void find(char * str){
 //   cout<<"begin to find"<<endl;
    int len=strlen(str);
//    cout<<len<<endl;
    node* p=root;
    for(int i=0;i<len;i++){
   //     cout<<i<<endl;
        int index;
        index=str[i]-'a';
        while (p->child[index]==NULL && p!=root)
            p=p->fail;
        if (p->child[index]==NULL) 
            continue;
        p=p->child[index];
        node* t=p;
        while(t!=root&&t->pos!=-1){
            res.push_back(t->pos);
            t->pos=-1;
            t=t->fail;
        }
    }
 //   cout<<"find over"<<endl;

}
int main(){
    Init();

    vector<char*> str;
/*
    char a1[]="her";
    str.push_back(a1);
    char a2[]="say";
    str.push_back(a2);
    char a3[]="she";
    str.push_back(a3);
    char a4[]="shr";
    str.push_back(a4);
    for(int i=0;i<str.size();i++){
        insert(str[i],i);
    }
*/
    char* a100=new char[1000000];
    char* a200=new char[2000000];
    ifstream fin100;
    ifstream fin200;
    fin100.open("100a.txt");
    if(fin100.is_open())
        cout<<"100isopen"<<endl;
    fin200.open("200a.txt");
    if(fin200.is_open())
        cout<<"200isopen"<<endl;
    fin100>>a100;
  //  cout<<"the a100 lenfth is "<<strlen(a100)<<endl;
    fin200>>a200;
  //   cout<<"the a200 lenfth is "<<strlen(a200)<<endl;
    str.push_back(a100);
    insert(a100,0);
    BFP();
    find(a200);
    if(res.size()==0){
        cout<<"no match"<<endl;
    }else{
        cout<<"we have match "<<res.size()<<"words, they are:"<<endl;
        for(int i=0;i<res.size();i++){
            cout<<i<<endl;
            //cout<<str[i]<<endl;
        }
    }
    res.empty();
    delete []a100;
    delete []a200;
    fin100.close();
    fin200.close();
    return 0;
}