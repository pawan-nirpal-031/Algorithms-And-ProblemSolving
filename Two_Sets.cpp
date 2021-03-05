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
  vector<ll>suffix(n+1,0);
  suffix[n] = n;
  vector<int>v(n+1,0);
  v[n] = 1;
  int cnt1 =0;
  for(int i = n-1;i>=1;i--){
    suffix[i] = i + suffix[i+1];
    if(suffix[i]<=(x>>1)){
      v[i] = 1;
      if((x>>1)-suffix[i]<10 and ((x>>1)- suffix[i])>0){
        v[(x>>1)-suffix[i]] = 1;
        break;
      }
    }
  }
  for(int i =1;i<=n;i++){
    if(v[i]){
      cnt1+=1;
    }else{
      v[i] = 2;
    }
  }
  cout<<cnt1<<'\n';
  for(int i =1;i<=n;i++) if(v[i]==1) cout<<i<<' ';
  cout<<'\n'<<(n - cnt1)<<'\n';
  for(int i = 1;i<=n;i++) if(v[i]==2) cout<<i<<' ';
  return 0;
} 