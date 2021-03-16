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
#define CheckState(v) for(auto x : v) cout<<x<<' ';

bool cases =0;
void GenrateRandom(){

}

void SolveCase(){
  int n;
  cin>>n;
  int m = 2*n;
  ll a[m];
  ll sum =0;
  for(int i =0;i<m;i++){
      cin>>a[i];
      sum+=a[i];
  }
  sort(a,a+m);
  ll half =0;
  for(int i =0;i<=n-1;i++) half+=a[i];
  if(half==(sum>>1)){
      cout<<-1;
      return;
  } 
  for(int i=0;i<m;i++) cout<<a[i]<<' ';
}


int main(){
  FastIO;
SolveCase();
  return 0;
} 