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
  int n;
  cin>>n;
  int tfive = 0;
  int fifty = 0;
  bool yes = 1;
  for(int i =0;i<n;i++){
      int x;
      cin>>x;
      if(x==25) tfive+=1;
      else if(x==50){
          if(tfive>0){
              tfive-=1;
              fifty+=1;
          }else{
              yes =0;
          }
      }else{    
          if(fifty>0 or tfive>0){
              if(fifty){
                  if(tfive){
                     tfive-=1;
                     fifty-=1;
                     continue;
                  }else{
                      yes =0;
                      break;
                  }
              }else{
                 if(tfive>=3) tfive-=3;
                 else yes =0;
              }
          }else yes = 0;
      }
  }
  Status(yes);
  return 0;
} 
// If Solved Mark (0/1) here => []