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





void TopKFrequentNumbers(){
   int n,k;
   cin>>n>>k;
   unordered_map<int,int>cache;
   for(int i =0;i<n;i++){
       int v;
       cin>>v;
       cache[v]+=1;
   }
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>heap;
   for(auto p : cache){
       heap.push({p.second,p.first});
       if(heap.size()>k) heap.pop();
   }
   while(not heap.empty()){
       cout<<heap.top().second<<' ';
       heap.pop();
   }
}

int main(){
  FastIO;
  TopKFrequentNumbers();
  return 0;
} 
