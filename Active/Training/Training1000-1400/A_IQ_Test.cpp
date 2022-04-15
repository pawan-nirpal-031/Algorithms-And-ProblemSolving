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





int main(){
  FastIO;
  int n = 4;
  char a[n][n];
  for(int i=0;i<4;i++) for(int j=0;j<4;j++) cin>>a[i][j];
  bool can = 0;
  for(int i=0;i<n;i++){
      for(int j =0;j<n;j++){
        int cnt = (a[i][j]=='#'?1:0);
        if(i+1<n and a[i+1][j]=='#') cnt+=1;
        if(j+1<n and a[i][j+1]=='#') cnt+=1;
        if(i+1<n and j+1<n and a[i+1][j+1]=='#') cnt+=1;
        if(cnt>=3) can = 1;
      }
  }
  if(not can){
      for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            int cnt = (a[i][j]=='.'?1:0);
            if(i+1<n and a[i+1][j]=='.') cnt+=1;
            if(j+1<n and a[i][j+1]=='.') cnt+=1;
            if(i+1<n and j+1<n and a[i+1][j+1]=='.') cnt+=1;
            if(cnt>=3) can = 1;
        }
    }
  }
  Status(can);
  return 0;
} 
// If Solved Mark (0/1) here => []