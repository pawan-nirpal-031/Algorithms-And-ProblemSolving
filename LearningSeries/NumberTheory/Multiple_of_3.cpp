// Problem Link : https://www.codechef.com/problems/MULTHREE
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

Consider a very long K-digit number N with digits d0, d1, ..., dK-1 (in decimal notation; d0 is the most significant and dK-1 the least significant digit). This number is so large that we can't give it to you on the input explicitly; instead, you are only given its starting digits and a way to construct the remainder of the number.

Specifically, you are given d0 and d1; for each i ≥ 2, di is the sum of all preceding (more significant) digits, modulo 10 — more formally, the following formula must hold: 

Determine if N is a multiple of 3.

*/

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) {
      ll k;
      cin>>k;
      int d0,d1;
      cin>>d0>>d1;
      ll ans = d0+d1 + ((d0+d1)%10) + ((k-3)/4)*(((2*(d0+d1))%10) + ((4*(d0+d1))%10) + ((8*(d0+d1))%10) + ((6*(d0+d1))%10));
      if((k-3)%4!=0){
          int rem = (k-3)%4;
          if(rem==1){
              ans+=((2*(d0+d1))%10);
          }else if(rem==2){
              ans+=(((2*(d0+d1))%10) + ((4*(d0+d1))%10));
          }else{
              ans+=(((2*(d0+d1))%10) + ((4*(d0+d1))%10) + ((8*(d0+d1))%10));
          }
      }
      Status(ans%3==0);
  }
  return 0;
} 
// If Solved Mark (0/1) here => [0]