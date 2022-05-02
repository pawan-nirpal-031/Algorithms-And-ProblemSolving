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
  getline(cin,s);
  vector<string>cache;
  string tmp;
  stringstream stream(s);
  while(stream>>tmp){
      cache.push_back(tmp);
  }
  char c;
  if(cache.back()=="?"){
      cache.pop_back();
      c = cache.back().back();
  }else{
      c = cache.back()[cache.back().size()-2];
  }
  Status(c=='a' or c=='e' or c=='i' or c=='o' or c=='u' or c=='y' or c=='A' or c=='E' or c=='I' or c=='O' or c=='U' or c=='Y');

  
  return 0;
} 
// If Solved Mark (0/1) here => []