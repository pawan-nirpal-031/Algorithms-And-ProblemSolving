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



*/


/*
Author's solution : 



*/




ll get(ll n){
    int count =0;
    while(n){
        count+=1;
        n>>=1;
    }
    return count-1;
}

void solveOP(){
      int n;
      cin>>n;
      vector<int>highest_bit_freq(35,0);
      for(int i =0;i<n;i++){
          ll x;
          cin>>x;
          highest_bit_freq[get(x)]+=1;
      }
      ll ans =0;
      for(int i =0;i<35;i++){
          ll x = highest_bit_freq[i];
          ans+=((x*(x-1))>>1);
      }
      cout<<ans<<'\n';
}





int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
     solveOP();
  }
  return 0;
} 
// If Solved Mark (0/1) here => []