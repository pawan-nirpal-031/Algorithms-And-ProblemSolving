#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
typedef pair<int,pair<int,int>> Tuple;
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
  priority_queue<int,vector<int>,greater<int>>min_heap;
  int n,k;
  cin>>n>>k;
  for(int i=0;i<n;i++){
      int x;
      cin>>x;
      min_heap.push(x);
      if(min_heap.size()>k) min_heap.pop();
  }
  while(not min_heap.empty()){
      cout<<min_heap.top()<<' ';
      min_heap.pop();
  }
  return 0;
} 
