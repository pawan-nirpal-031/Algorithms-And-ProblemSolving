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

int comp_size;

void Dfs(vector<int>g[],vector<bool>&vis,int u,bool show){
    vis[u] = 1;
    comp_size+=1;
    if(show) cout<<u<<' ';
    for(int &v : g[u]) if(not vis[v]) Dfs(g,vis,v,show);
}

int main(){
  FastIO;
  int n,m;
  cin>>n>>m;
  vector<int>g[n+1];
  while(m--){
    int a,b;
    cin>>a>>b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  vector<bool>vis(n+1,0);
  vector<int>three,one,two;
  for(int i = 1;i<=n;i++){
    if(not vis[i]){
      comp_size =0;
      Dfs(g,vis,i,0);
      if(comp_size>3){
        cout<<-1;
        return 0;
      }
      if(comp_size==2){
        two.emplace_back(i);
        two.emplace_back(g[i][0]);
      }
      if(comp_size==1){
        one.emplace_back(i);
      }
      if(comp_size==3){
        three.emplace_back(i);
        three.emplace_back(g[i][0]);
        three.emplace_back(g[i][1]);
      }
    }
  }
  int two_size = two.size();
  int one_size = one.size();
  int three_size = three.size();
  if(two_size>2*one_size or ( 2*one_size>two_size and (2*one_size - two_size)%3!=0) or (two_size%2!=0)){
    cout<<-1;
    return 0;
  }
  for(int i = 0;i<three_size;i++){
    if(i%3==0){
      cout<<'\n';
    }
    cout<<three[i]<<' ';
  }
  cout<<'\n';
  int one_ptr = 0;
  for(int i =0;i<two_size-1;i+=2){
    cout<<two[i]<<' '<<two[i+1]<<' '<<one[one_ptr]<<'\n';
    one_ptr+=1;
  }
  if(one_size>one_ptr){
    for(int i = one_ptr;i<one_size-2;i+=3){
      cout<<one[i]<<' '<<one[i+1]<<' '<<one[i+2]<<'\n';
    }
  }
  return 0;
} 