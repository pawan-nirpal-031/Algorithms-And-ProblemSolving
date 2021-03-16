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
#define GoogleOutput(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define BoolAnsCall(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x

void Solve(){
  int n1,m1;
  cin>>n1>>m1;
  vector<vector<int>>g1(n1,vector<int>(m1,0));
  string s1[n1];
  for(int i =0;i<n1;i++){
    cin>>s1[i];
    for(int j =0;j<m1;j++){
        g1[i][j] = s1[i][j]-'0';
    }
  }
  int n2,m2;
  cin>>n2>>m2;
  vector<vector<int>>g2(n2,vector<int>(m2,0));
  string s2[n2];
  for(int i =0;i<n2;i++){
    cin>>s2[i];
    for(int j =0;j<m2;j++){
        g2[i][j] = s2[i][j] -'0';
    }
  }
  vector<pair<int,int>>cache;
  for(int i =0;i<n1;i++){
    for(int j =0;j<m1;j++){
        if(g1[i][j]==g2[0][0] and (i+n2<n1) and ((j + m2)<m1)){
            if(g1[i][j+m2-1]==g2[0][m2-1] and g1[i+n2-1][j]==g2[n2-1][0] and g1[i+n2-1][j+m2-1]==g2[n2-1][m2-1]) cache.emplace_back(Pair(i,j));
        }
    }
  }
  for(auto co : cache){
      int x = co.first;
      int y = co.second;
      int yes = 1;
      for(int i = x;i<x+n2;i++){
          for(int j = y;j<y+m2;j++){
            int cx = i-x;
            int cy = j-y;
            // if(g1[i][j]!=g2[cx][cy]){
            //     yes = 0;
            //     break;
            // }else{
            //     yes = 1;
            //     if(cx==n2-1 and cy==m2-1 and yes==1){
            //         yes = 2;
            //     }
            // }
            if(g1[i][j]!=g2[cx][cy]) yes = 0;
          }
          if(not yes){
            break;
          }
        //   if(yes==2){
        //     cout<<"YES\n";
        //     return;
        //   }
      }
      if(yes){
          cout<<"YES\n";
          return;
      }
  }
  cout<<"NO\n";
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
   Solve();
  }

  return 0;
} 