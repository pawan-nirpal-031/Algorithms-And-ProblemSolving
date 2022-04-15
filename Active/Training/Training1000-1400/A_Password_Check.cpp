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
  string s;
  cin>>s;
  bool cap = 0;
  bool small =0;
  bool dig =0;
  for(char c : s){
      if(c>='a' and c<='z') small = 1;
      else if(c>='A' and c<='Z') cap =1;
      else if(c>='0' and c<='9') dig = 1;
  }
  if(s.length()>=5 and cap and small and dig){
      cout<<"Correct";
  }else cout<<"Too weak";
  return 0;
} 
// If Solved Mark (0/1) here => []