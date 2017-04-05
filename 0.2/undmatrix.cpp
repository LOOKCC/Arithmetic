#include<iostream>
#include<stdio.h>
using namespace std;
const int MAX=100;
const int INFINITY=65535;
class Graph{
private:
    char Vexs[MAX];
    int numV;
    int numE;
    int Matrix[MAX][MAX];
public:
    Graph();
    void Gprintf();
};
Graph::Graph(){
    cout<<"Please Input the number of Vertex and Edge :"<<endl;
    cin>>numV>>numE;
    cout<<"Please Input the Vertex:"<<endl;
    for(int i=0;i<numV;i++)
    cin>>Vexs[i];
    for(int i=0;i<numV;i++){
        for(int j=0;j<numE;j++){
            if(i==j)
                Matrix[i][j]=0;
            else
                Matrix[i][j]=INFINITY;
        }
    }
    int i,j,v;
    cout<<"Please Input two vertex and their value"<<endl;
    cout<<"a b v"<<endl;
    for(int k=0;k<numE;k++){
        cin>>i>>j>>v;
        Matrix[i][j]=v;
//defferent
        Matrix[j][i]=v;
    }
}
void Graph::Gprintf(){
    cout<<"       "<<endl;
    for(int i=0;i<numV;i++)
    printf("%7c",Vexs[i]);
    for(int i=0;i<numV;i++){
        printf("%7c",Vexs[i]);
        for(int j=0;j<numV;j++){
            printf("%7d",Matrix[i][j]);
        }
        cout<<endl;
    }
}
int  main(){
    Graph graph;
    graph.Gprintf();
    return 0;
}