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
#define SortVector(v) sort(v.begin(),v.end())

/*


Chef has N laddus, i-th of which has a size si. There are no two laddues with equal size, i.e.
all the laddus have different sizes. There are K children that came to meet Chef today. Chef wants
to give a single laddu to each of these K children. Also, he wants to minimize the difference in the sizes
which the children get, i.e. he wants to minimize the maximum difference in the sizes of the laddus distributed.
This is because children feel jealous of each other if the other one has a bigger laddu that him/her.
In other words, find a subset of size K which minimizes the value of max_element of the subset - 
min_element of the subset, and output this minimum difference.


*/


void Solve(){
  int n,k;
  cin>>n>>k;
  vector<ll>v(n,0);
  for(ll &x : v) cin>>x;
  SortVector(v);
  ll ans = Mod;
  for(int i = n-1;i>=0;i--) (i-k+1>=0?ans =  min(ans,v[i]-v[i-k+1]):ans = ans);
  cout<<ans<<'\n';
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
    Solve();
  }
  return 0;
} 