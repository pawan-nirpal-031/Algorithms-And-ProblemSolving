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
  for(int i =0;i<n;i++) cin>>a[i];
  sort(a,a+n);
  if(n&1){
      ll med = a[n>>1];
      ll min_dist = 0;
      for(int i =0;i<n;i++) min_dist+=abs(a[i]-med);
      cout<<min_dist;
  }else{
      ll med1  = a[n>>1];
      ll med2 = a[(n>>1) + 1];
      ll min_dist = 0;
      ll min_dist1 = 0;
      for(int i =0;i<n;i++) min_dist+=abs(a[i]-med1);
      for(int i =0;i<n;i++) min_dist1+=abs(a[i]-med2);
      cout<<min(min_dist1,min_dist);
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