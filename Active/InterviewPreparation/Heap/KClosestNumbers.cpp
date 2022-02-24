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



// Given an array give k closest elements to a given number x.


void KClosestToGivenNumber(){
  priority_queue<pair<int,int>>max_heap;
  int n,k,x;
  cin>>n>>k>>x;
  for(int i =0;i<n;i++){
      int v;
      cin>>v;
      max_heap.push({abs(x-v),v});
      if(max_heap.size()>k){
          max_heap.pop();
      }
  }
  stack<pair<int,int>>cache;
  while(not max_heap.empty()){
     cache.push(max_heap.top());
     max_heap.pop();
  }
  while(not cache.empty()){
      auto p = cache.top();
      cout<<p.second<<'\n';
      cache.pop();
  }
}

int main(){
  FastIO;
  KClosestToGivenNumber();
  return 0;
} 
