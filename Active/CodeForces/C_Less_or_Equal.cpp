// Problem Link : https://codeforces.com/contest/977/problem/C
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

You are given a sequence of integers of length n and integer number k. You should print any integer number x in the range of [1;1e9] (i.e. 1≤x≤1e9) such that exactly k elements of given sequence are less than or equal to x.

Note that the sequence can contain equal elements.

If there is no such x, print "-1" (without quotes).


Print any integer number x from range [1;1e9] such that exactly k elements of given sequence is less or equal to x.

*/

/*

failed : 

ll n,k;
  cin>>n>>k;
  map<ll,ll>dp; // (elem,freq)
  for(int i =0;i<n;i++){
      ll x;
      cin>>x;
      dp[x]+=1;
  }
  ll count = 0;
  for(auto p : dp){
    if(count>k){
        cout<<-1;
        return 0;
    }
    count+=p.second;
    if(count==k and p.first<=(1e9)){
        cout<<p.first;
        return 0;
    }
  }
  cout<<-1;

*/

int main(){
  FastIO;
  ll n,k;
  cin>>n>>k;
  ll a[n];
  for(int i =0;i<n;i++){
      cin>>a[i];
  }
  sort(a,a+n);
  ll ans = ((k==0)?a[0]-1:a[k-1]);
  ll cnt = 0;
  for(int i = 0;i<n;i++){
      if(a[i]<=ans) cnt+=1;
      else break;
  }
  if(ans<1 or cnt!=k) cout<<-1;
  else cout<<ans;
  return 0;
} 
// If Solved Mark (0/1) here => [1]