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


struct node{
    int time;
    int x,y;
};

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int orangesRotting(vector<vector<int>>& grid) {
    queue<node>basket;
    int n = grid.size();
    int m = grid[0].size();
    int fresh =0;
    int rotten =0;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(grid[i][j]==2){
                node n;
                rotten+=1;
                n.time =0;
                n.x = i;
                n.y = j;
                basket.push(n);
            }else if(grid[i][j]==1) fresh+=1;
        }
    }
    if(fresh==0) return 0;
    if(fresh and rotten==0) return -1;
    int time_taken = -1;
    while(not basket.empty()){
        node curr = basket.front();
        basket.pop();
        time_taken = max(time_taken,curr.time);
        for(int i =0;i<4;i++){
            int tx = curr.x+dx[i];
            int ty = curr.y+dy[i];
            if(tx>=0 and tx<n and ty>=0 and ty<m){
                if(grid[tx][ty]==1){
                    node nxt;
                    grid[tx][ty] = 2;
                    nxt.time = curr.time+1;
                    nxt.x = tx;
                    nxt.y = ty;
                    basket.push(nxt);
                }
            }
        }
    }
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(grid[i][j]==1) return -1;
        }
    }
    return time_taken;       
}


int main(){
  FastIO;
  int n,m;
  cin>>n>>m;
  vector<vector<int>>grid(n,vector<int>(m,0));
  for(int i=0;i<n;i++){
      for(int j =0;j<m;j++) cin>>grid[i][j];
  }
  cout<<orangesRotting(grid);
  
  return 0;
} 
