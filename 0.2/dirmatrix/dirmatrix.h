#ifndef DIRMATRIX_H_
#define DIRMATRIX_H_
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
};
#endif