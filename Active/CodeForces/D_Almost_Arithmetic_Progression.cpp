// Problem Link : https://codeforces.com/contest/978/problem/D
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

Polycarp likes arithmetic progressions. A sequence [a1,a2,…,an] is called an arithmetic progression if for each i (1≤i<n) the value ai+1−ai is the same. For example, the sequences [42], [5,5,5], [2,11,20,29] and [3,2,1,0] are arithmetic progressions, but [1,0,1], [1,3,9] and [2,3,1] are not.

It follows from the definition that any sequence of length one or two is an arithmetic progression.

Polycarp found some sequence of positive integers [b1,b2,…,bn]. He agrees to change each element by at most one. In the other words, for each element there are exactly three options: an element can be decreased by 1, an element can be increased by 1, an element can be left unchanged.

Determine a minimum possible number of elements in b which can be changed (by exactly one), so that the sequence b becomes an arithmetic progression, or report that it is impossible.

It is possible that the resulting sequence contains element equals 0.

*/

int main(){
  FastIO;
  int n;
  cin>>n;
  vector<ll>b(n,0);
  if(n<3){
    cout<<0;
    return 0;
  }
  for(ll &x : b) cin>>x;
  ll ans = LLONG_MAX;
  for(int d1 = -1;d1<=1;d1++){
    for(int d2 = -1;d2<=1;d2++){
      ll a1 = b[0]+d1;
      ll a2 = b[1]+d2;
      bool np =0;
      ll cnt = abs(d1)+abs(d2);
      for(int i = 2;i<n;i++){
        ll ai = a1 + (i-1)*(a2-a1);
        if(abs(ai-b[i])<=1){
           if(ai!=b[i]) cnt+=1;
        }
      }
      if(np) break;
      else{
        if(cnt<ans) ans = cnt;
      }
    }
  }
  cout<<ans;
  return 0;
} 
// If Solved Mark (0/1) here => []