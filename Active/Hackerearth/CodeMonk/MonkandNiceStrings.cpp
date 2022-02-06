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

ull Power(ull a,ll x){
  if(x==1) return a;
  ull half = Power(a,(x>>1));
  ull val = half*half;
  if(x&1) return val*a;
  return val;
}

/*
Problem Statement : 



*/


/*
Author's solution : 

string a[n];
  for(int i =0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++){
      int c = 0;
      int x = 0;
      while(x<i){
        c+=(a[i]>a[x]);
        x++;
      }
      cout<<c<<'\n';
  }

*/


int main(){
  FastIO;
  int n;
  cin>>n;
  string a[n];
  for(int i =0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++){
      int c = 0;
      int x = 0;
      while(x<i){
        c+=(a[i]>a[x]);
        x++;
      }
      cout<<c<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => []