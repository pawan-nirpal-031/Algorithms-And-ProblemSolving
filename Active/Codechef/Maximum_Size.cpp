// Problem Link : https://www.codechef.com/START3C/problems/RISK
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


/*
Problem Statement : 

Chef is playing an easier variation of the board game ‘Risk’ with his friend Mike. There is an N∗M grid, depicting the world map. Each cell of the grid is either 1 or 0 where 1 denotes that there is land on this cell, while 0 denotes water.

In a turn, a player can capture an uncaptured cell that has land, and keep capturing neighbouring cells that share a side with it if they are on land. A cell once captured by a player can't be captured again by another player. The game continues till no uncaptured cell has land. Each player wants to be in control of as many cells of land as possible in total when the game finishes. Find the maximum number of cells of land that Chef can capture if he plays second, and both players play optimally.

*/

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int k =0;
void dfs(string g[],int i,int j,int n,int m){
    k+=1;
    g[i][j] = '0';
    for(int d =0;d<4;d++){
        int tx = i + dx[d];
        int ty = j + dy[d];
        if(tx>=0 and tx<n and ty>=0 and ty<m and (g[tx][ty]=='1')){
            dfs(g,tx,ty,n,m);
        }
    }
}

void SolveCase(){
    int n,m;
    cin>>n>>m;
    string g[n];
    for(int i=0;i<n;i++) cin>>g[i];
    multiset<int>cache;
    int n_comp =0;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            k =0;
            n_comp+=1;
            if(g[i][j]-'0'){
                dfs(g,i,j,n,m);
                cache.insert(k);
            }
        }
    }
    vector<int>sizes;
    for(int p : cache){
        sizes.push_back(p);
    }
    int comp = sizes.size();
    int chef =0;
    for(int i =0;i<comp;i++){
        if(comp&1){
            if(i&1) chef+=sizes[i];
        }else{
            if(i%2==0) chef+=sizes[i];
        }
    }
    cout<<chef<<'\n';
}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) SolveCase();
  return 0;
} 
// If Solved Mark (0/1) here => [1]
// those who will risk going too far can possibly find out how far one can go