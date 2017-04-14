#include<iostream>
#include<iomanip>
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
    void Delete(int a,int b);
    void Insert(int a,int b,int v);
    void TC();
};
Graph::Graph(){
    cout<<"Please Input the number of Vertex:"<<endl;
    cin>>numV;
//    cout<<"Please Input the Vertex:"<<endl;
//    for(int i=1;i<=numV;i++)
//    cin>>Vexs[i];
    for(int i=1;i<=numV;i++){
        for(int j=1;j<=numV;j++){
                Matrix[i][j]=0;
        }
    }
    int i,j, v;
    cin>>i>>j>>v;
    numE=1;
    while(i!=0&&j!=0&&v!=0){
        Matrix[i-1][j-1]=v;
        numE++;
        cin>>i>>j>>v;
    }
/*
    int i,j,v;
    cout<<"Please Input two vertex and their value"<<endl;
    cout<<"a b v"<<endl;
    for(int k=0;k<numE;k++){
        cin>>i>>j>>v;
        Matrix[i][j]=1;
    }
*/
}
void Graph::Gprintf(){
    cout<<"       ";
    for(int i=0;i<numV;i++)
//    cout<<setw(7)<<Vexs[i];
        cout<<setw(7)<<i+1;    
    cout<<endl;
    for(int i=0;i<numV;i++){
        //cout<<setw(7)<<Vexs[i];
        cout<<setw(7)<<i+1;
        for(int j=0;j<numV;j++){
           cout<<setw(7)<<Matrix[i][j];
        }
        cout<<endl;
    }
}
void Graph::Delete(int a,int b){
    Matrix[a][b]=0;
}
void Graph::Insert(int a,int b,int v){
    Matrix[a][b]=v;
}
void Graph::TC(){
/*
    for(int i=1;i<=numV;i++){
        for(int j=1;j<=numV;j++){
            if(Matrix[i][j]==1){
                for(int k=1;k<=numV;k++){
                    if(Matrix[j][k]==1){
                        Matrix[i][k]=1;
                     }
                }
            }
            
        }
   }
*/
    for(int k=1;k<=numV;k++){
        for(int i=1;i<=numV;i++){
            for(int j=1;j<=numV;j++){
                Matrix[i][j]=Matrix[i][j]|(Matrix[i][k]&Matrix[k][j]);
            }
        }
    }
}
int  main(){
    Graph graph;
    graph.Gprintf();
    cout<<endl;
    graph.TC();
    graph.Gprintf();
    return 0;
}