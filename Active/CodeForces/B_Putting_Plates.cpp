// Problem Link : 
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



*/


/*
Author's solution : 



*/

void solve(){
    int h,w;
    cin>>h>>w;
    bool tab[h][w];
    for(int i=0;i<h;i++) for(int j = 0;j<w;j++) tab[i][j] =0;
    for(int i =0;i<w;i+=2) tab[h-1][i] = tab[0][i] = 1;
    for(int i =0;i<h;i+=2) tab[i][0] = 1;  
    for(int i = 2;i<h;i+=2) tab[i][w-1] = 1;
    if(h%2==0 and tab[h-2][0]) tab[h-2][w-1] = tab[h-2][0]= 0; 
    tab[h-1][w-1] = tab[0][w-1];
    for(int i=0;i<h;i++) {
        for(int j = 0;j<w;j++) cout<<tab[i][j];
        cout<<'\n';
    }
    cout<<'\n';  
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
     solve();
  }
  return 0;
} 
// If Solved Mark (0/1) here => []