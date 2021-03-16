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

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void Bfs(int hx,int hy,int h_no,vector<vector<char>>&g,vector<vector<int>>&vis,vector<vector<int>>&dis,int n,int m){
   queue<pair<int,int>>que;
   que.push(Pair(hx,hy));
   dis[hx][hy] = 0;
   while ( not que.empty()){
      int cx = que.front().first;
      int cy = que.front().second;
      que.pop();
      vis[cx][cy] = h_no;
      for(int i =0;i<4;i++){
        int tx = cx + dx[i];
        int ty = cy + dy[i];
        if(tx>=0 and tx<n and ty>=0 and ty<m and g[tx][ty]=='.' and vis[tx][ty]!=h_no){
            vis[tx][ty] = h_no;
            dis[tx][ty] = min(dis[tx][ty],1+dis[cx][cy]);
            que.push(Pair(tx,ty));
        }
    }
   }
   
}

int main(){
  FastIO;
  int n,m;
  cin>>n>>m;
  vector<vector<char>>g(n,vector<char>(m,'.'));
  string data[n];
  vector<vector<int>>vis(n,vector<int>(m,0)),dis(n,vector<int>(m,Mod));
  vector<pair<int,int>>hos;
  for(int row=0;row<n;row++){
    cin>>data[row];      
    for(int col=0;col<m;col++){       
        g[row][col] = data[row][col];
        if(g[row][col]=='H') {
           hos.emplace_back(Pair(row,col));
           dis[row][col] =0;
        }
    }
  }
  int h_no = 1;
  for(auto h : hos){
    Bfs(h.first,h.second,h_no,g,vis,dis,n,m);
    h_no+=1;
  }
  for(int row=0;row<n;row++){      
    for(int col=0;col<m;col++){       
        cout<<g[row][col]<<" ";
    }
    cout<<'\n';
  }
  cout<<'\n';
  for(int row=0;row<n;row++){      
    for(int col=0;col<m;col++){       
        cout<<dis[row][col]<<' ';
    }
    cout<<'\n';
  }
  
  return 0;
} 

/*
  The question asked in Uber was 

  given a grid of n, m as dimensions, each cell is either '.' denoting a free cell or 'x' 
  denoting a forbidden cell or 'H' denoting a hospital. You need to compute for each free cell 
  the distance of closest hospital, if reachable else mark it's distance as -1 if it is not reachable from 
  any of the given hospitals and mark cells with x as -1, you can reach only those cells that share a side with 
  current cell.

  ex : 

  input 

  3 6 
  .x..H.
  xx..HH
  H..xx.

  output 
  -1 -1 2 1 0 1
  -1 -1 2 1 0 0 
  0 1 2 -1 -1 1

*/