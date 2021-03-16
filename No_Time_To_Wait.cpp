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
  
}


int main(){
  FastIO;
  int n,h,x;
  cin>>n>>h>>x;
  bool yes = 0;
  for(int i =0;i<n;i++){
      int t;
      cin>>t;
      if(x+t==h) yes = 1;
  }
  Status(yes);
  return 0;
} 