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



bool cases =1;


int main(){
  FastIO;
  int n,x;
  cin>>n>>x;
  vector<bool>f(105,0);
  for(int i =0;i<n;i++){
      int p;
      cin>>p;
      f[p]=1;
  }
  int absnt =0;
  for(int i=0;i<x;i++) if(not f[i]) absnt+=1;
  cout<<absnt + f[x];
  return 0;
} 
