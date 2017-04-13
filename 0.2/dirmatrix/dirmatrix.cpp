#include<iostream>
#include"dirmatrix.h"
#include<iomanip>
using namespace std;
Graph::Graph(){
    cout<<"Please Input the number of Vertex"<<endl;
    cin>>numV;
 //   cout<<"Please Input the Vertex:"<<endl;
 //   for(int i=0;i<numV;i++)
 //   cin>>Vexs[i];
    for(int i=0;i<numV;i++){
        for(int j=0;j<numV;j++){
            if(i==j)
                Matrix[i][j]=0;
            else
                Matrix[i][j]=INFINITY;
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
        Matrix[i][j]=v;
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
    Matrix[a][b]=INFINITY;
}
void Graph::Insert(int a,int b,int v){
    Matrix[a][b]=v;
}
