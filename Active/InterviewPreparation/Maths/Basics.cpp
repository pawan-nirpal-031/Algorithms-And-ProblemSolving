#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define Mod 1000000007

struct Matrix{
    ll mat[2][2];
};

ll Power(ll x,int n){ // O(1) space O(logn) time
    ll res = 1;
    while(n){
        if(n&1) res*=x;
        n>>=1;
        x=x*x;
    }
    return res;
}

Matrix MatrixProduct(Matrix a, Matrix b){
    Matrix c;
    for(int i =0;i<2;i++){
        for(int j =0;j<2;j++){
            ll val =0;
            for(int k =0;k<2;k++){
                val = (val%Mod + (a.mat[i][k]%Mod*b.mat[k][j]%Mod)%Mod)%Mod;
            }
            c.mat[i][j] = val;
        }
    }
    return c;
}

Matrix Identity(){
    Matrix a;
    a.mat[0][0] = a.mat[1][1] = 1;
    a.mat[0][1] = a.mat[1][0] = 0;
    return a;
}

Matrix MatrixExponentiaion(Matrix a,int n){
    if(n==0) return Identity();
    Matrix res = MatrixExponentiaion(a,(n>>1));
    return (n&1? MatrixProduct(a,MatrixProduct(res,res)):MatrixProduct(res,res));
}


void PointTransformation(int x,int y,Matrix transform,int n){
    Matrix converted = MatrixExponentiaion(transform,n);
    // do converted*[x y] product and [x1 y1] should be the transformed point co-ordinates

}

ll FibonacciUsingMatrixExponantion(int n){
    /*
        a = [1 1 
             1 0 ] 
        and f(0) = f(1) = 1 
        the recurance for fibonacci in matrix form is (a^n)*[f(0) f(1)] is 

        a^n*[1 1] 

        final recurance : 
            (a^n)*[f(0) f(1)] = [f(n+1) f(n)] 
    */
   Matrix fib;
   fib.mat[0][0] = fib.mat[0][1] = fib.mat[1][0] = 1;
   fib.mat[1][1] = 0;
   Matrix res_tranform = MatrixExponentiaion(fib,n);
   return (res_tranform.mat[1][0]%Mod+res_tranform.mat[1][1]%Mod)%Mod;
}



int main(){
   
}