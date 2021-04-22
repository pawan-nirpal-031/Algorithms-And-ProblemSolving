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



bool cases =1;

void SolveCase(){
    int n;
  cin>>n;
  string g[n];
  pair<int,int>f = {-1,-1}; // x,y
  pair<int,int>s = {-1,-1};
  int t = 0;
  for(int i =0;i<n;i++){
      cin>>g[i];
      for(int j =0;j<n;j++){
          if(g[i][j]=='*'){
              if(t==0){
                t+=1;
                f.first = i;
                f.second = j;
              }else{
                  s.first = i;
                  s.second = j;
              }
          }
      }
  }
  if(f.first==s.first){// *  *
    int x = f.first;
    int y1 = f.second;
    int y2 = s.second;
    if(x-1>=0){
        g[x-1][y1] = g[x-1][y2] = '*';
    }else if(x+1<n){
        g[x+1][y1] = g[x+1][y2] = '*';
    }
  }else if(f.second==s.second){
      int y = f.second;
      int x1 = f.first;
      int x2 = s.first;
      if(y+1<n){
          g[x1][y+1]= g[x2][y+1] = '*';
      }else if(y-1>=0){
          g[x1][y-1] = g[x2][y-1] = '*';
      }
  }else{
      int x1 = f.first;
      int y1 = f.second;
      int x2 = s.first;
      int y2 = s.second;
      g[x1][y2] = g[x2][y1] = '*';
  }
  for(int row=0;row<n;row++){      
    cout<<g[row]<<'\n';
  }

}

int main(){
  FastIO;
  int t = 1;
  if(cases) cin>>t;
  while(t--){
     SolveCase();
  }
  return 0;
} 
