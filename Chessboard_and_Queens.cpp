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

vector<vector<char>>g(8,vector<char>(8,'.'));
vector<vector<bool>>vis(8,vector<bool>(8,0));
ll Nofways;

inline bool IsValid(int i,int j) {
    return (i>=0 and i<8 and j>=0 and j<8 and (not vis[i][j]));
}

bool IsSafe(int r,int c){
    for(int i = r-1;i>=0;i--) if(vis[i][c]) return 0;
    for(int i = r-1, j = c-1;i>=0 and j>=0; i--,j--) if(vis[i][j]) return 0;
    for(int i = r-1,j = c+1;i>=0 and j<8;i--,j++) if(vis[i][j]) return 0;
    return 1;
}


void Nqueens(int row){
    if(row==8){
        Nofways+=1;
        return;
    }
    for(int col = 0;col<8;col++){
        if(IsValid(row,col) and IsSafe(row,col) and g[row][col]=='.'){
            vis[row][col] = 1;
            Nqueens(row+1);
            vis[row][col] = 0;
        }
    }
}

int main(){
  FastIO;
  Nofways =0;
  for(int i =0;i<8;i++){
      for(int j =0;j<8;j++){
        cin>>g[i][j];
      }
  }
  Nqueens(0);
  cout<<Nofways;
  return 0;
} 