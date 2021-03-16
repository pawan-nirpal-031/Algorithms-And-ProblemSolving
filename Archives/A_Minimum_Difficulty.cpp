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


int main(){
  FastIO;
  int n;
  cin>>n;
  int a[n];
  for(int &x : a) cin>>x;
  int ptr = 1;
  int ans = 100000;
  for(int ptr = 1;ptr<=n-2;ptr++){
    int diff_ptr = 0;
    for(int j = 0;j<=n-2;j++){
        if(j==ptr){
            diff_ptr = max(diff_ptr,a[j+1]-a[j-1]);
        }else{
            diff_ptr = max(diff_ptr,a[j+1]-a[j]);
        }
    } 
    ans = min(ans,diff_ptr);
  }
  cout<<ans;
  return 0;
} 