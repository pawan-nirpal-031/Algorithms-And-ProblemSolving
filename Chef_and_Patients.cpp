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
#define Status(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x
#define MinHeap(type,g) priority_queue <type, vector<type>, greater<type>> g
#define MaxHeap(type,g) priority_queue<type>g

bool cases =1;
void SolveCase(){
  int n;
  cin>>n;
  vector<pair<int,int>>g[1001];
  int max_el =0;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    g[x].push_back({i+1,-1});
    max_el = max(max_el,x);
  }
  int ptr = 0;
  vector<int>answr(n+1,0);
  for(int p = max_el;p>=1;p--){
    for(auto &x : g[p]){
        answr[x.first] = x.second = ++ptr;
    }
  }
  for(int i =1;i<=n;i++){
      cout<<answr[i]<<' ';
  }
  cout<<"\n";
}

int main(){
  FastIO;
  int t = 1;
  if(cases) cin>>t;
  while(t--){
    SolveCase();
  }
  return 0;
} 