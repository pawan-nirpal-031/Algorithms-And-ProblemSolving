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
    Bob is a farmer. He has a large pasture with many sheep. Recently, he has lost some of them due to wolf attacks. He thus decided to place some shepherd dogs in such a way that all his sheep are protected.

    The pasture is a rectangle consisting of R × C cells. Each cell is either empty, contains a sheep, a wolf or a dog. Sheep and dogs always stay in place, but wolves can roam freely around the pasture, by repeatedly moving to the left, right, up or down to a neighboring cell. When a wolf enters a cell with a sheep, it consumes it. However, no wolf can enter a cell with a dog.

    Initially there are no dogs. Place dogs onto the pasture in such a way that no wolf can reach any sheep, or determine that it is impossible. Note that since you have many dogs, you do not need to minimize their number.
*/

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
  FastIO;
  int n,m;
  cin>>n>>m;
  string g[n];
  bool yes =1;
  for(int i=0;i<n;i++){
      cin>>g[i];
  }
  for(int i=0;i<n;i++){
      for(int j =0;j<m;j++){
         if(g[i][j]=='S'){
              for(int d = 0;d<4;d++){
                  int tx = i + dx[d];
                  int ty = j + dy[d];
                  if(tx>=0 and tx<n and ty>=0 and ty<m){
                      if(g[tx][ty]=='W'){
                          Status(0);
                          yes =0;
                          return 0;
                      }else if(g[i][j]=='.') g[i][j] = 'D';
                  }
              }
          }
      }
  }
//   for(int i=0;i<n;i++){
//       for(int j =0;j<m;j++){
//          if(g[i][j]=='S'){
//               for(int d = 0;d<4;d++){
//                   int tx = i + dx[d];
//                   int ty = j + dy[d];
//                   if(tx>=0 and tx<n and ty>=0 and ty<m){
//                       g[tx][ty] = 'D';
//                   }
//               }
//           }
//       }
//   }
  Status(1);
  for(int i =0;i<n;i++){
      for(int j =0;j<m;j++) cout<<g[i][j];
      cout<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => []