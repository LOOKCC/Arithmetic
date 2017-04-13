#ifndef UNDMASTRIX_H_
#define UNDMASTRIX_H_

const int INFINITY=65535;
const int MAX=100;
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