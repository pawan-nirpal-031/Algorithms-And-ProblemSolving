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
  int r,c;
  cin>>r>>c;
  vector<vector<char>>g(r,vector<char>(c,' '));
  int col_min = c; 
  int col_max = 0;
  int row_min = r;
  int row_max = 0;
  for(int i =0;i<r;i++){
    for(int j = 0;j<c;j++){
        cin>>g[i][j];
        if(g[i][j]=='*'){
            col_min = min(col_min,j);
            row_min = min(row_min,i);
            col_max = max(col_max,j);
            row_max = max(row_max,i);
        }
    }
  }
//    cout<<col_min<<" "<<col_max<<" "<<row_min<<" "<<row_max;
  for(int i = row_min;i<=row_max;i++){
      for(int j = col_min;j<=col_max;j++) cout<<g[i][j];
      cout<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => []