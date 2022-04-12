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
Problem Statement : 

Alice (uniformly and independently) randomly picks two integers a,b from the range [1,104], and writes down the values of a+b, a−b, a⋅b and ⌊ab⌋ (integer division) in some random order. Unfortunately, she forgot the values of a and b. You need to help her to find out if there exists two integers a,b such that 1≤a,b≤104 and a+b, a−b, a⋅b, ⌊ab⌋ are the numbers she has written down.

If a solution exists, it is guaranteed to be unique.

*/


/*
Author's solution : 



*/

bool Isvalid(ll sum,ll diff,ll mul,ll div){
  ll a = (sum+diff)>>1;
  ll b = (sum-diff)>>1;
  if(a<1 or a>10000 or b<1 or b>10000) return 0;
  int valid_cnt =0;
  if(a+b==sum) valid_cnt+=1;
  if(a-b==diff) valid_cnt+=1;
  if(a*b==mul) valid_cnt+=1;
  if(b!=0 and a/b==div) valid_cnt+=1;
  return valid_cnt==4;
}


void solve(){
  ll a[4];
  for(ll &x : a) cin>>x;
  int premute[] = {0,1,2,3}; 
  pair<ll,ll>ans;
  do{
    if(Isvalid(a[premute[0]],a[premute[1]],a[premute[2]],a[premute[3]])){
      ans.first  =(a[premute[0]]+ a[premute[1]])/2;
      ans.second = (a[premute[0]]-a[premute[1]])/2;
      break;
    }else ans.first = ans.second = -1;
  }while(next_permutation(premute,premute+4));
  std::cout<<ans.first<<' '<<ans.second<<'\n';
}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
} 
// If Solved Mark (0/1) here => [1] 