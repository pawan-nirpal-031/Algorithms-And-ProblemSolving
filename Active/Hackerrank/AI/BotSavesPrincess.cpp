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

int Dist(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
  FastIO;
  int n;
  cin>>n;
  vector<vector<char>>grid(n,vector<char>(n,'-'));
  int gx = 0;
  int gy = 0;
  for(int i=0;i<n;i++){
       for(int j =0;j<n;j++){
           cin>>grid[i][j];
           if(grid[i][j]=='p'){
               gx = i;
               gy = j;
           }
       }
  }
  int x = n/2;
  int y = n/2;
  int steps =0;
  while(x!=gx and y!=gy){
      int mx = 2*n;
      int my = 2*n;
      int min_dist = 2*n;
      for(int i =0;i<4;i++){
          int xn = x+dx[i];
          int yn = y+dy[i];
          int d = Dist(xn,yn,gx,gy);
          if(d<min_dist){
              min_dist = d;
              mx = xn;
              my = yn;
          }
      }
      cout<<"At "<<x<<", "<<y<<" moving to "<<mx<<", "<<my<<"\n";
      steps++;
      x = mx;
      y = my;
  }
  cout<<"At "<<x<<", "<<y<<':';
  cout<<steps;
  return 0;
} 
