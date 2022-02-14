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



int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      ll x;
      cin>>x;
      string s;
      cin>>s;
      int chef = 0;
      int karl = 0;
      for(char c : s){
          if(c=='D'){
              karl++;
              chef++;
          }else if(c=='C') karl+=2;
          else chef+=2;
      }
      if(karl==chef){
          cout<<55*x<<'\n';
      }else if(karl>chef){
          cout<<60*x<<'\n';
      }else{
          cout<<40*x<<'\n';
      }
  }
  return 0;
} 
// If Solved Mark (0/1) here => []