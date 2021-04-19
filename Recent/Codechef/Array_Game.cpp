// Problem Link : 
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

/*
In this problem, you are given N integers. You need to find the maximum number of unique integers among all the possible contiguous subarrays of size M
*/

int main(){
  FastIO;
  int n,m;
  cin>>n>>m;
  int ans =0;
  set<int>s;
  for(int i =0;i<=n-m;i++){
    int x;
    cin>>x;
    if(i==0){
      s.insert(x);
      ans = max(ans,(int)s.size());
    }else{
      
    }
  }
  return 0;
} 
// If Solved Mark (0/1) here => []