#include <iostream>
using namespace std; 

int compute(int n){
    if(n==1) return 1;
    int factn = n*compute(n-1);
    return factn;
}

int factorial(){
    int n; 
    cin>>n;
    return compute(n);
}

int main(){
    cout<<factorial();
}
