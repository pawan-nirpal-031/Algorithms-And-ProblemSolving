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

bool cases =0;
void GenrateRandom(){

}

void SolveCase(){
  int n;
  cin>>n;
  ll a[n];
  for(ll &x : a) cin>>x;
  int lc =1;
  int le =0;
  for(int i = 1;i<n;i++){
    if(a[i]>=a[i-1]){
      lc+=1;
    }
    else {
      le = i;
      break;
    }
  }
  if(lc==n) {
    cout<<lc;
    return;
  }
  int rc =1;
  for(int r = n-2;r>=le;r--){
    if(a[r]>=a[r+1]){
      rc+=1;
    }else break;
  }
  cout<<lc+rc;

  

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