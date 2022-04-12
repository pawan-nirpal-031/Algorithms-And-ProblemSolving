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
#define DebugCase(i,x) std::cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (std::cout<<(b?"YES\n":"NO\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x


/*
Problem Statement : 



*/


/*
Author's solution : 



*/

bool IsSmall(char c){
    return (c>='a' and c<='z');
}

bool IsLarge(char c){
    return (c>='A' and c<='Z');
}


int main(){
  FastIO;
  int t;
  cin>>t;
  for(int case_ = 1;case_<=t;case_++){
      string correct,typed;
      cin>>correct>>typed;
      vector<int>correct_small(26,0);
      vector<int>correct_big(26,0);
      vector<int>typed_small(26,0);
      vector<int>typed_big(26,0);
      for(int i = 0;i<typed.length();i++){
          
      }
  }
  return 0;
} 
// If Solved Mark (0/1) here => []