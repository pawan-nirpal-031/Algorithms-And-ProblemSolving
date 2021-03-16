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
#define Status(b) (cout<<(b?"YES\n":"NO\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x

bool cases =0;

void GenrateRandom(){

}

void SolveCase(){
  int n;
  cin>>n;
  bool y=0;
  string g[n];
  for(int i =0;i<n;i++){
      cin>>g[i];
  }
  for(int i =0;i<n;i++){
    if((not y) and ((g[i][0]==g[i][1] and g[i][0]=='O') or (g[i][3]==g[i][4] and g[i][3]=='O'))){
        y=1;
        if((g[i][0]==g[i][1] and g[i][0]=='O')){
            g[i][0] = g[i][1] = '+';
        }else{
            g[i][3] = g[i][4]='+';
        }
        break;
    }
  }
  Status(y);
  if(not y) return;
  for(int i=0;i<n;i++) cout<<g[i]<<'\n';
 
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