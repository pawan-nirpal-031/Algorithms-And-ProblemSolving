// Problem Link : https://codeforces.com/problemset/problem/977/F
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

You are given an integer array of length n.

You have to choose some subsequence of this array of maximum length such that this subsequence forms a increasing sequence of consecutive integers. In other words the required sequence should be equal to [x,x+1,…,x+k−1] for some value x and length k.

Subsequence of an array can be obtained by erasing some (possibly zero) elements from the array. You can erase any elements, not necessarily going successively. The remaining elements preserve their order. For example, for the array [5,3,1,2,4] the following arrays are subsequences: [3], [5,3,1,2,4], [5,1,4], but the array [1,3] is not.


 
*/


int main(){
  FastIO;
  int n;
  cin>>n;
  vector<ll>a(n,0);
  for(ll &x : a) cin>>x;
  map<ll,ll>dp;
  ll ans = 1;
  ll elem = a[0];
  for(int i =0;i<n;i++){
    ll x = a[i];
    dp[x] = 1 + dp[x-1];
    if(dp[x]>ans){
      ans = dp[x];
      elem = x;
    }
  }
  vector<ll>seq;
  cout<<ans<<"\n";
  for(int i = n-1;i>=0;i--){
    if(a[i]==(elem)){
      seq.push_back(i+1);
      elem--;
    }
  }
  reverse(seq.begin(),seq.end());
  for(ll x : seq) cout<<x<<" ";
  return 0;
} 
// If Solved Mark (0/1) here => [1]

/*

Failed approach : find out why?

ll limt = Mod;
  unordered_multimap<ll,pair<ll,ll>>dp; // (elem,(index,len))
  ll ans = 0;
  for(int i =1;i<=n;i++){
    ll x;
    cin>>x;
    auto prev = dp.find(x-1);
    ll leng = 0;
    if(prev!=dp.end()){
      ll prev_indx = (prev->second).first;
      if(prev_indx<i) leng = (prev->second).second+1;
    }else{
      leng = 1LL;
    }
    dp.insert({x,{i,leng}});
    ans = max(ans,leng);
  }
  ll elem = 0;
  for(auto p : dp) if(p.second.second==ans) elem = p.first;
  cout<<ans<<'\n';
  set<ll>seq;
  auto it = dp.find(elem);
  while(it->second.second!=1){
    seq.insert(it->second.first);
    it = dp.find(it->first-1);
  }
  seq.insert(it->second.first);
  for(auto i : seq) cout<<i<<" ";

*/