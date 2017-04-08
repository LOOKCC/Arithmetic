#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int letter=26;
struct node{
    node* fail;
    node* child[letter];
    int pos;
    node(){
        fail=NULL;
        for(int i;i<letter;i++)
            child[i]=NULL;
        pos=-1;
    }
};
node* root;
node* Q[300000];
void Init(){
    root=new (node); 
}
void insert(char* s,int num){
    node* p=root;
    for(char* c=s;*c!='\0';++c){
        int t=(*c)-'a';
        if(p->child[t]==NULL){
            p->child[t]=new (node);
        }
        p=p->child[t];
        if((*(c+1))=='\0')
            p->pos=num;
    }
}
void BFP(){
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
}
int find(char * str){
    int len=strlen(str);
    int res;
    node* p=root;
    for(int i=0;i<len;i++){
        int index;
        index=str[i]-'a';
        while (p->child[index]==NULL && p!=root)
            p=p->fail;
        if (p->child[index]==NULL) 
            continue;
        p=p->child[index];
        node* t=p;
        while(t!=root){
            if(t->pos!=-1)
                res=t->pos;
            t=t->fail;
        }
    }
    return res;
}
int main(){
    Init();
    vector<char*> str;
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
    BFP();
    cout<<find(a3)<<endl;
    return 0;
}