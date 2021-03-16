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

bool cases =1;
void GenrateRandom(){

}

void SolveCase(){
  string s;
  cin>>s;
  ll n = s.size();
  ll g = 0;
  for(int i =0;i<n-1;i++) if(s[i]=='1' and s[i+1]=='0') g+=1;
  g+=(s[n-1]-'0');
  cout<<g<<'\n';
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