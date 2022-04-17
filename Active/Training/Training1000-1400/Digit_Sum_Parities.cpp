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



int get(ll n){
    int sum =0;
    while(n>0){
        sum+=(n%10);
        n/=10;
    }
    return (sum&1);
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      ll n;
      cin>>n; 
      int parity = get(n);
      for(int i =1;i<=10;i++){
        int comp = get(n+i);
        if((not comp)==parity){
            cout<<n+i<<'\n';
            break;
        }
      }
  }

  return 0;
} 
// If Solved Mark (0/1) here => []