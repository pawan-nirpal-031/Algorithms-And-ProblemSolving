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
  ll a,s;
  cin>>a>>s;
  ll b = s-a;
  if(b<0) {
    Status(0);
    return;
  }
  vector<int>fa(10,0),fb(10,0);
  while(a>0){
    fa[a%10]+=1;
    a/=10;
  }
  while(b>0){
    fb[b%10]+=1;
    b/=10;
  }
  for(int i =0;i<10;i++){
      if(fa[i]!=fb[i]){
        Status(0);
        return;
      }
  }
  Status(1);
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