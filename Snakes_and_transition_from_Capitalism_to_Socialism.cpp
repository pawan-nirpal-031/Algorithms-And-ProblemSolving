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

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int Bfs(vector<vector<int>>&vis, vector<vector<int>>&prices,int n,int m,int max_el){
    int ans = 0;
    queue<pair<int,int>>que;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++) {
            if(prices[i][j]==max_el){
                que.push(Pair(i,j));
                vis[i][j] = 0;
            }
        }
    }
    while(not que.empty()){
        int curr_x = que.front().first;
        int curr_y = que.front().second;
        que.pop();
        for(int i =0;i<8;i++){
            int tar_x = curr_x + dx[i];
            int tar_y = curr_y + dy[i];
            if(tar_x>=0 and tar_x<n and tar_y>=0 and tar_y<m and vis[tar_x][tar_y]==-1){
                vis[tar_x][tar_y] = 1 + vis[curr_x][curr_y];
                que.push(Pair(tar_x,tar_y));
                ans = max(vis[tar_x][tar_y],ans);
            }
        }
    }
    return ans;
}




void SnakeTransition(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>prices(n,vector<int>(m,0));
    vector<vector<int>>vis(n,vector<int>(m,-1));
    int max_el =0;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>prices[i][j];
            max_el = max(max_el,prices[i][j]);
        }
    }
    cout<<Bfs(vis,prices,n,m,max_el)<<'\n';
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
    SnakeTransition();
  }
  return 0;
} 