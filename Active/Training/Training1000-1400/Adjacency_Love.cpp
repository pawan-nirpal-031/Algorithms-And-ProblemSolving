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





int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      ll a[n];
      int oddcount =0;
      for(int i =0;i<n;i++){
        cin>>a[i];
        int x = a[i];
        oddcount+=(x&1);
      }
      if(oddcount<=1 or (oddcount==n and oddcount&1)){
          cout<<-1;
      }else{
        vector<ll>oddnums;
        for(int i =0;i<n;i++) if(a[i]&1) oddnums.push_back(a[i]);
        vector<ll>evennums;
        for(int i=0;i<n;i++) if(a[i]%2==0) evennums.push_back(a[i]);
        if(oddcount&1){
            for(int i =0;i<2;i++) cout<<oddnums[i]<<" ";
            for(ll x : evennums) cout<<x<<" ";
            for(int i =2;i<oddnums.size();i++) cout<<oddnums[i]<<' ';
        }else{
            for(ll x : oddnums) cout<<x<<' ';
            for(ll x : evennums) cout<<x<<' ';
        }
      }
      cout<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => []