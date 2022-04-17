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

Chef has a binary string S of length N. He wonders if it is possible to divide S into exactly K non-empty substrings such that each Si belongs to exactly one substring and the XOR of each substring is the same. Can you help Chef to determine if it is possible to do so?

Note: XOR of substring SL⋯R is defined as: XOR(SL⋯R)=SL⊕SL+1⊕⋯⊕SR.

*/


/*
Author's solution : 



*/



void solve(){
  int n,k;
  cin>>n>>k;
  vector<bool>a(n,0);
  for(int i =0;i<n;i++){
    char c;
    cin>>c;
    a[i] = c-'0';
  }
  bool curr = 0;
  int count =0;
  int low = 0,high =-1;
  for(int i = 0;i<n;i++){
   if((curr xor a[i])==0){
     curr = curr xor a[i];
     high = i;
   }else{
     high = low = i;
     count+=1;
   }
  }
  cout<<count;
}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
} 
// If Solved Mark (0/1) here => []