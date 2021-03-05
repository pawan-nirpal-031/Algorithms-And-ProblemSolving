#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define setA0(a) for(ull i =0;i<n;i++){a[i] = 0;}
#define aout(a) for(auto x : a){cout<<x<<' ';} 
#define ain(a) for(ull i =0;i<n;i++){cin>>a[i];} 
#define NofSetBits(x) __builtin_popcount(x);
#define InpGrph(g,e) while(e--){ll x;ll y;cin>>x>>y ;g[x].pub(y);g[y].pub(x);}
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
  FastIO;
  ll n,m;
  cin>>n>>m;
  bool rec[n][m];
  ll prfx[n][m];
  string s[n];
  for(int i =0;i<n;i++){
      cin>>s[i];
      for(int j =0;j<m;j++){
          rec[i][j] = s[i][j]-'0';
          prfx[i][j]=0;
      }
  }
  ll q;
  cin>>q;
  while(q--){
      ll x1,y1,x2,y2;
      cin>>x1>>y1>>x2>>y2;
      x1--;
      x2--;
      y1--;
      y2--;
      prfx[x1][y1]++;
      if(1+x2<n && 1+y2<m){
          prfx[1+x2][1+y2]++;
      }
      if(1+x2<n){
          prfx[1+x2][y1]--;
      }
      if(1+y2<m){
          prfx[x1][1+y2]--;
      }
  }
  for(int i=0;i<n;i++){
      for(int j =1;j<m;j++){
          prfx[j][i]+=prfx[j-1][i];
      }
  }
  for(int i=0;i<n;i++){
      for(int j=1;j<m;j++){
          prfx[i][j]+=prfx[i][j-1];
      }
  }
  for(int i=0;i<n;i++){
      for(int j =0;j<m;j++){
          if(prfx[i][j]&1){
              if(rec[i][j]){
                  cout<<0;
              }else{
                  cout<<1;
              }
          }else{
              cout<<rec[i][j];
          }
      }
      cout<<'\n';
  }
  return 0;
}