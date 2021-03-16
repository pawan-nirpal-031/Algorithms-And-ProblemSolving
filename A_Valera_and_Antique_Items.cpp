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
  int n,v;
  cin>>n>>v;
  vector<bool>seller(n,0);
  int count = 0;
  for(int i =0;i<n;i++){
      int x;
      cin>>x;
      for(int j =0;j<x;j++){
        int p;
        cin>>p;
        if(v>p and (not seller[i])){
          count+=1;
          seller[i] = 1;
        }
      }
  }
  cout<<count<<'\n';
  for(int i =0;i<n;i++){
      if(seller[i]) cout<<(i+1)<<" ";
  }
  return 0;
} 