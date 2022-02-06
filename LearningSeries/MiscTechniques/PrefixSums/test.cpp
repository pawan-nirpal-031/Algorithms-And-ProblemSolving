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


int main(){
  FastIO;
  int n;
  ll x;
  cin>>n>>x;
  ll a[n];
  ll prefix[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
    prefix[i] = a[i];
    if(i>0) prefix[i]+=prefix[i-1];
  }
  map<ll,ll>cache;
  int cnt =0;
  for(int i =0;i<n;i++){
    cache[prefix[i]]+=1;
    if(prefix[i]==x){
      cnt+=1;
      continue;
    }
    cnt+=cache[prefix[i]-x];
  }
  cout<<cnt;
  
  return 0;
} 