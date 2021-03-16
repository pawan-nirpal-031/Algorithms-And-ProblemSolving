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
#define GoogleOutput(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define BoolAnsCall(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x


int main(){
  FastIO;
  ll n;
  cin>>n;
  ll x = (n*(n+1))>>1;
  if(x&1){
    cout<<"NO\n";
    return 0;
  }
  cout<<"YES\n";
  ll hlf = (x>>1);
  vector<int>v(n+1,1);
  for(int i = n;i>=1;i--){
    if(hlf-i>10) {
      v[i] = 2;
      hlf-=i;
    }
  }
  return 0;
} 