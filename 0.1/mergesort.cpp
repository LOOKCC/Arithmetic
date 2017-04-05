#include<iostream>
using namespace std;
void Msort (int A[],int Temp[],int left,int right);
void Merge(int A[],int Temp[],int Lstart,int Rstart,int Rend);
int main(){
    int A[5]={5,4,3,2,1};
    int *Temp=new int[5];
    if(Temp==NULL){
        cout<<"No Space"<<endl;
    }
    Msort(A,Temp,0,4);
    delete []Temp;
    for(int i=0;i<5;i++){
        cout<<A[i];
    }
    cout<<endl;
    return 0;
}
void Msort (int A[],int Temp[],int left,int right){
    int center;
    if(left<right){
        center=(left+right)/2;
        Msort(A,Temp,left,center);
        Msort(A,Temp,center+1,right);
        Merge(A,Temp,left,center+1,right);
    }
    

}
void Merge(int A[],int Temp[],int Lstart,int Rstart,int Rend){
    int i,Lend,number,temp;
    Lend=Rstart-1;
    temp=Lstart;
    number=Rend-Lstart+1;
    while(Lstart<=Lend&&Rstart<=Rend){
        if(A[Lstart]<=A[Rstart]){
            Temp[temp++]=A[Lstart++];
        }
        else{
            Temp[temp++]=A[Rstart++];
        }
    }
    while(Lstart<=Lend){
        Temp[temp++]=A[Lstart++];
    }
    while(Rstart<=Rend){
        Temp[temp++]=A[Rstart++];
    }
    for(i=0;i<number;i++,Rend--){
        A[Rend]=Temp[Rend];
    }
}
