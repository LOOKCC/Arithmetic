#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream fout100;
    ofstream fout200;
    fout100.open("100a.txt");
    fout200.open("200a.txt");
    for(int i=0;i<2000000;i++){
        fout200<<"a";
    }
    for(int i=0;i<1000000;i++){
        fout100<<"a";
    }
    fout100.close();
    fout200.close();
    return 0;
}