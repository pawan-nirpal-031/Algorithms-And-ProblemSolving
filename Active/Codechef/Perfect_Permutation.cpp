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

class Math{
    public:
    int Floor(int x,int y){
        return floor(x*1.0/y);
    }
    int Ceil(int x,int y){
        return ceil(x*1.0/y);
    }
};


void solve(){
    int n,k;
    cin>>n>>k;
    if(n<=2){
        if(n==1) cout<<1<<' ';
        else{
            if(k==1) cout<<2<<' '<<1<<' ';
            else cout<<1<<' '<<2<<' ';
        }
    }else{
        if(k==n-1){
            cout<<-1;
        }else{
            for(int i=1;i<=k;i++) cout<<i<<" ";
            for(int i =k+1;i<n;i++) cout<<i+1<<' ';
            cout<<k+1<<' ';
        }
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