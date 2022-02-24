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



void FrequencySort(){// counting sort wont be useful numbers could be large
    int n;
    cin>>n;
    unordered_map<int,int>cache;
    priority_queue<pair<int,int>>heap;
    for(int i =0;i<n;i++){
        int x;
        cin>>x;
        cache[x]+=1;
    }
    for(auto p : cache) heap.push({p.second,p.first});
    vector<int>ans;
    while(not heap.empty()){
        auto p = heap.top();
        int f = p.first;
        int x = p.second;
        while(f--) ans.push_back(x);
        heap.pop();
    }
    for(int v : ans) cout<<v<<" ";
}

int main(){
  FastIO;
  FrequencySort();
  return 0;
} 
