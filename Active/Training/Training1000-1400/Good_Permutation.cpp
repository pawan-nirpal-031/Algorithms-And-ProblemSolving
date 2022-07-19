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
    int n;
    cin>>n;
    if(n==1 or n==3){
        cout<<-1<<'\n';
        return;
    }else if(n&1){
        int a[5] = {2, 3, 5, 1, 4};
        for(int i=0;i<5;i++) cout<<a[i]<<' ';
        for(int i = 6;i<=n;i++){
           if(i%2==0) cout<<i+1<<' ';
           else cout<<i-1<<' ';
        }   
    }else{
        for(int i = 1;i<=n;i++){
           if(i&1) cout<<i+1<<' ';
           else cout<<i-1<<' ';
        }
    }
    cout<<'\n';
}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) solve();
  return 0; 
} 
// If Solved Mark (0/1) here => []