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
  int n;
  ll x;
  cin>>n>>x;
  multimap<ll,int>bag;
  for(int i =0;i<n;i++){
      ll p;
      cin>>p;
      bag.insert({p,i});
  }
  bool y = 0;
  for(auto p : bag){
      auto itr = bag.find(x-p.first);
      if(itr!=bag.end() and itr->second!=p.second){
          y =1;
          int pos1 = p.second+1;
          int pos2 = itr->second+1;
          cout<<min(pos1,pos2)<<" "<<max(pos1,pos2)<<'\n';
          break;
      }
  }
  if(not y) cout<<"IMPOSSIBLE";
  return 0;
} 