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

bool cases =1;
void SolveCase(){
  int nc,ns;
  cin>>nc>>ns;
  pair<int,int> clgRnks[nc];
  pair<int,int> studRnks[ns];
  for(int i=0;i<nc;i++){ cin>>clgRnks[i].first; clgRnks[i].second=-1; }
  for(int i=0;i<ns;i++) {cin>>studRnks[i].first; studRnks[i].second =-1; }
  int chfid =0;
  int chfclg = -1;
  int chfRnk = studRnks[0].first;
  sort(studRnks,studRnks+ns);
  for(int s = 0;s<ns;s++){
    int k;
    cin>>k;
    if(s==0){
        
    }else{

    }
  }

  
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