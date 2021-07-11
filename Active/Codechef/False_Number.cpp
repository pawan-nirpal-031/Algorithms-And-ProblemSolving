// Problem Link : https://www.codechef.com/LTIME97B/problems/FALSNUM
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

One day, Chef's friend gave him a wrong number W containing N+1 digits and said that the actual number A is the largest possible number that can be obtained from deleting exactly one digit of W. Chef was able to find A but forgot W.

Given A, find the smallest possible number W of length N+1 without leading 0's that is consistent with the story above. We can show that there is always at least one such W consistent with the story.

*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      string A;
      cin>>A;
      if(A[0]!='1') cout<<'1'<<A;
      else{
          cout<<"10";
          for(int i = 1;i<A.length();i++) cout<<A[i];
      }
      cout<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => []