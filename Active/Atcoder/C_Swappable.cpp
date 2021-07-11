// Problem Link : https://atcoder.jp/contests/abc206/tasks/abc206_c
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



*/


/*
Author's solution : 



*/

int SolveByDs(ll a[],int n){
  map<ll,ll>cache;
  cache[a[n-1]]+=1;
  ll ans = 0;
  for(int i = n-2;i>=0;i--){
      ans+=((n-1-i)-cache[a[i]]);
      cache[a[i]]+=1;
  }
  return ans;
}

int BinarySrchUtil(ll a[],int n,ll x){
    int low = -1;
    int high = n;
    while(high>low+1){
        int mid = ((low+high)>>1);
        if(a[mid]>x) high = mid;
        else low = mid;
    }
    return (a[low]>x?low:high);
}

int Binsrch(ll a[],ll n){
  sort(a,a+n);
  ll cnt = 0;
  for(int i = 0;i<n-1;i++){
      int next = BinarySrchUtil(a,n,a[i]);
      if(next>=n or next<0) continue;
      cnt+=(n-next);
  }
  return cnt;
}

int testing(){
  int n = 1 + rand()%10; 
  // cin>>n;
  ll a[n];
  for(ll &x : a) x = rand()%10;
  ll bs = Binsrch(a,n);
  ll ds = SolveByDs(a,n);
  if(bs==ds) cout<<"ok\n";
  else{
      cout<<"bs : "<<bs<<", ds : "<<ds<<'\n';
      return -1;
  }
  return 0;
}


int main(){
  FastIO;
  int n;
  cin>>n;
  ll a[n];
  for(ll &x : a) cin>>x;
  cout<<SolveByDs(a,n);
  return 0;
} 
// If Solved Mark (0/1) here => [1]