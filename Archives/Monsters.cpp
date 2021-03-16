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
#define BoolAnsCall(b) (cout<<(b?"YES\n":"NO\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

class Tuple{
    public:
        int dist,par_x,par_y;
        Tuple(){
            dist = par_x = par_y = -1;
        }
        void Set(int x,int a,int b){
            dist = x;
            par_x = a;
            par_y = b;
        }
        void Show(){
            cout<<"( "<<dist<<", "<<par_x<<", "<<par_y<<") ";
        }
};


bool Valid(int curr_x,int curr_y,int n,int m){
    return curr_x>=0 and curr_x<n and curr_y>=0 and curr_y<m;
}

char GetDirection(int curr_x,int curr_y,int tar_x,int tar_y){
    if(curr_x==tar_x) return ((curr_y>tar_y)?'R':'L');
    return (curr_x>tar_x?'D':'U');
}

void bfs(string g[],vector<vector<Tuple>>&monsters,vector<vector<Tuple>>&person,int n,int m){
    queue<pair<int,int>>mons,pers;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(g[i][j]=='A') pers.push({i,j});
            if(g[i][j]=='M') mons.push({i,j});
        }
    }
    while(not mons.empty()){
        int curr_x = mons.front().first;
        int curr_y = mons.front().second;
        mons.pop();
        for(int i =0;i<4;i++){
            int tar_x= curr_x + dx[i];
            int tar_y = curr_y + dy[i];
            if(Valid(tar_x,tar_y,n,m) and( g[tar_x][tar_y]=='.' or g[tar_x][tar_y]=='A') and monsters[tar_x][tar_y].dist==-1){
                monsters[tar_x][tar_y].dist = 1 + monsters[curr_x][curr_y].dist;
                if(monsters[tar_x][tar_y].par_x==-1 and monsters[tar_x][tar_y].par_y==-1){
                    monsters[tar_x][tar_y].par_x = curr_x;
                    monsters[tar_x][tar_y].par_y = curr_y;
                }
                mons.push({tar_x,tar_y});
            }
        }
    }

    while(not pers.empty()){
        int curr_x = pers.front().first;
        int curr_y = pers.front().second;
        pers.pop();
        for(int i =0;i<4;i++){
            int tar_x = curr_x + dx[i];
            int tar_y = curr_y + dy[i];
            if(Valid(tar_x,tar_y,n,m) and( g[tar_x][tar_y]=='.') and person[tar_x][tar_y].dist==-1){
                person[tar_x][tar_y].dist = 1 + person[curr_x][curr_y].dist;
                if(person[tar_x][tar_y].par_x==-1 and person[tar_x][tar_y].par_y==-1){
                    person[tar_x][tar_y].par_x = curr_x;
                    person[tar_x][tar_y].par_y = curr_y;
                }
                pers.push({tar_x,tar_y});
            }
        }
    }
    int exit_x = -1;
    int exit_y = -1;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(i==0 or i==n-1 or j==0 or j==m-1 and g[i][j]=='.'){
                if((person[i][j].dist>=0 and monsters[i][j].dist>=0 and person[i][j].dist<monsters[i][j].dist) or (person[i][j].dist>=0 and monsters[i][j].dist==-1)){
                    exit_x = i;
                    exit_y = j;
                    break;
                }
            }
        }
        if(exit_x>-1) break;
    }
    if(exit_x==-1){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    cout<<person[exit_x][exit_y].dist<<'\n';
    string path;
    int tmp_x = exit_x;
    int tmp_y = exit_y;
    while(person[tmp_x][tmp_y].dist!=0){
        path+=GetDirection(tmp_x,tmp_y,person[tmp_x][tmp_y].par_x,person[tmp_x][tmp_y].par_y);
        int tx = person[tmp_x][tmp_y].par_x;
        int ty = person[tmp_x][tmp_y].par_y;
        tmp_x  = tx;
        tmp_y = ty;
    }
    reverse(path.begin(),path.end());
    cout<<path;
}


int main(){
  FastIO;
  int n,m;
  cin>>n>>m;
  string g[n];
  for(string &x : g) cin>>x;
  vector<vector<Tuple>>monsters(n,vector<Tuple>(m)),person(n,vector<Tuple>(m));
  for(int i =0;i<n;i++){
      for(int j =0;j<m;j++){
        if(g[i][j]=='M') monsters[i][j].Set(0,i,j);
        else if(g[i][j]=='A') person[i][j].Set(0,i,j);
      }
  }
  bfs(g,monsters,person,n,m);
  return 0;
} 

