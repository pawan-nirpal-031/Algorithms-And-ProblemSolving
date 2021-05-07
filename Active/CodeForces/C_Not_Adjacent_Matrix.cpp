// Problem Link : https://codeforces.com/contest/1520/problem/C
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Infinity (ll)1e18
#define Append(a) push_back(a)
#define Pair(a,b) make_pair(a,b)
#define Clear(a) for(ll &x : a){x=0;}
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define DebugCase(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x


/*
Problem Statement : 

We will consider the numbers a and b as adjacent if they differ by exactly one, that is, |a−b|=1.

We will consider cells of a square matrix n×n as adjacent if they have a common side, that is, for cell (r,c) cells (r,c−1), (r,c+1), (r−1,c) and (r+1,c) are adjacent to it.

For a given number n, construct a square matrix n×n such that:

Each integer from 1 to n2 occurs in this matrix exactly once;
If (r1,c1) and (r2,c2) are adjacent cells, then the numbers written in them must not be adjacent.

*/

void Solve(){
    int n;
    cin>>n;
    if(n==2){
        cout<<"-1\n";
        return;
    }
    ll odd = 1;
    ll even = 2;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(odd<=(n*n)){
                cout<<odd<<' ';
                odd+=2;
            }
            else if(odd>(n*n) and even <=(n*n)){
                cout<<even<<' ';
                even+=2;
            }
        }
        cout<<'\n';
    }
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) Solve();
  return 0;
} 
// If Solved Mark (0/1) here => [1]