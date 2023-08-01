#include <iostream>
using namespace std; 

void addMatrix(){
    int n,m; 
    cin>>n>>m; 
    int a[n][m]; 
    int b[n][m];
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++) cin>>a[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++) cin>>b[i][j];
    }
    int res[n][m]; 
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            res[i][j] = a[i][j] + b[i][j];
        }
    }
    cout<<'\n';
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
}


int main(){
    addMatrix();
}
