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



bool valid(int x,int y){
    return (x>=0 and x<8 and y>=0 and y<8);
}

int main(){
  FastIO;
  char c;
  cin>>c;
  int row;
  cin>>row;
  int col = c-'a';
  int cnt =0;
  row--;
  cnt+=(valid(row,col+1));
  cnt+=valid(row+1,col+1);
  cnt+=valid(row+1,col);
  cnt+=valid(row+1,col-1);
  cnt+=valid(row,col-1);
  cnt+=valid(row-1,col-1);
  cnt+=valid(row-1,col);
  cnt+=valid(row-1,col+1);
  cout<<cnt;
  return 0;
} 
// If Solved Mark (0/1) here => []