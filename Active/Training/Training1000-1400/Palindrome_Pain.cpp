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
    int x,y;
    cin>>x>>y;
    if((x%2==1 and y%2==1) or (x==1 or y==1)){
        cout<<-1<<'\n';
    }else{
        int lefta = (x>>1);
        int leftb = (y>>1);
        for(int i =0;i<lefta;i++) cout<<'a';
        for(int i =0;i<leftb;i++) cout<<'b';
        if(x&1 or y&1) cout<<(x&1?'a':'b');
        for(int i =0;i<leftb;i++) cout<<'b';
        for(int i =0;i<lefta;i++) cout<<'a';
        cout<<'\n';
        for(int i =0;i<leftb;i++) cout<<'b';
        for(int i =0;i<lefta;i++) cout<<'a';
        if(x&1 or y&1) cout<<(x&1?'a':'b');
        for(int i =0;i<lefta;i++) cout<<'a';
        for(int i =0;i<leftb;i++) cout<<'b';
        cout<<'\n';
    }
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