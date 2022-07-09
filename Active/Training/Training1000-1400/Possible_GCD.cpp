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




int GetDivisorCount(ll x){
    int count = 0; 
    for(int i = 1;i*i<=x;i++){
      if(x%i==0){
        if(i==x/i) count+=1;
        else count+=2;
      }
    }
    return count;
}

void GetExecutionTime(ll n){
  time_t st,end;
  time(&st);
  cout<<GetDivisorCount(n);
  time(&end); 
  double taken = double(end -  st);
  cout<<"\n time taken : "<<Point(taken);
}

int main(){
  FastIO;
  int t; 
  cin>>t;
  while(t--){
      ll a,b; 
      cin>>a>>b; 
      ll x = abs(a-b); 
      cout<<GetDivisorCount(x)<<'\n';
  }  
  
  return 0;
} 
// If Solved Mark (0/1) here => []