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
#define Status(b) (cout<<(b?"Yes\n":"No\n"));
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
  int n;
  cin>>n;
  vector<vector<bool>>g(n,vector<bool>(n,0));
  for(int i =0;i<n;i++){
      for(int j =0;j<n;j++){
          char c;
          cin>>c;
          g[i][j] = (c=='#'?1:0);
      }
  }
  bool yes =0;
  for(int i =0;i<n;i++){
      for(int j =0;j<n;i++){
          cout<<"at "<<i<<" "<<j<<'\n';
          if(j<=(n-6)){// row check 
            int need =0;
            for(int k = 0;k<6;k++) if(g[i][j+k]==0) need+=1;
            if(need<=2){
                yes =1;
                break;
            }
          }
          if(i<=(n-6)){ // col check 
            int need =0;
            for(int k =0;k<6;k++) if(g[i+k][j]==0) need+=1;
            if(need<=2){
                yes =1;
                break;
            }
          }
          if(i<=(n-6) and j<=(n-6)){// daig check 
            int need =0;
            for(int k =0;k<6;k++){
                if(g[i+k][j+k]==0) need+=1;
            }
            if(need<=2){
                yes =1;
                break;
            }
          }
      }
      if(yes) break;
  }
  Status(yes);
  return 0;
} 
// If Solved Mark (0/1) here => []