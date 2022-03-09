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


bool HasEdge(int u,int v,vector<int>g[]){
    for(int x : g[u]) if(x==v) return 1;
    return 0;
}

void HamiltionionPathsUtil(int curr,int start,vector<int>g[],vector<bool>&vis,vector<vector<int>>&hamiltionionpaths,int n,vector<int>&path,int vis_count){
    if(path.size()==n){
        if(HasEdge(curr,start,g)){
             cout<<"checking paths bwn "<<curr<<" and "<<start<<endl;
             hamiltionionpaths.push_back(path);
        }
        return;
    }
    vis[curr] = 1;
    for(int adj : g[curr]){
        if(not vis[adj]){
            path.push_back(adj);
            HamiltionionPathsUtil(adj,start,g,vis,hamiltionionpaths,n,path,vis_count+1);
            path.pop_back();
        }
    }
    vis[curr] =0;
}

void HamiltionionPaths(vector<int>g[],vector<bool>&vis,vector<vector<int>>&hamiltionionpaths,int n){
    vector<int>path;
    path.push_back(0);
    HamiltionionPathsUtil(0,0,g,vis,hamiltionionpaths,n,path,1);
    if(hamiltionionpaths.size()==0){
        cout<<"no cycles"<<endl;
    }else{
        for(auto v : hamiltionionpaths){
            for(int x : v) cout<<x<<' ';
            cout<<'\n';
        }
    }
}   



int GetMazePathsWithJumps(int i,int j,int n,int m){
  if(i<0 or j<0 or i>=n or j>=m) return 0;
  if(i==n-1 and j==m-1) return 0;
  if(i==n-1 and (j==m-2 or j==m-3 or j==m-4)) return 1;
  if(j==m-1 and (i==n-2 or i==n-3 or i==n-4)) return 1;
  ll number_of_ways =0;
  for(int x = 1;x<=3;x++) number_of_ways+=GetMazePathsWithJumps(i,j+x,n,m);
  for(int x = 1;x<=3;x++) number_of_ways+=GetMazePathsWithJumps(i+x,j,n,m);
  return number_of_ways;
}

bool IsValid(int i,int j,int n){
    return (i>=0 and i<n and j>=0 and j<n);
}

int nuf =0;
int kinghtmovesx[8] = {-2,-1,1,2,2,1,-1,-2};
int kinghtmovesy[8] = {1, 2, 2,1,-1,-2,-2,-1};
void KnightTour(int i,int j,int n,int count,vector<vector<int>>&grid){
  if(count==n*n){
    grid[i][j] = count;
    for(int p =0;p<n;p++){
      for(int q =0;q<n;q++) cout<<grid[p][q]<<' ';
      cout<<endl;
    }
    grid[i][j] =0;
    cout<<"\n";
    return;
  }
  grid[i][j] = count;
  for(int d =0;d<8;d++){
    int x = i+kinghtmovesx[d];
    int y = j+kinghtmovesy[d];
    if(IsValid(x,y,n) and grid[x][y]==0){
      KnightTour(x,y,n,count+1,grid);
    } 
  }
  grid[i][j] =0;
}


void PrintAbbrevations(string s,int curr_indx,string form,int backlog){
    if(curr_indx==s.length()){
      if(backlog==0){
        cout<<form<<endl;
      }else{
        cout<<form+to_string(backlog)<<endl;
      }
      return;
    }
    if(backlog==0){
      PrintAbbrevations(s,curr_indx+1,form+s[curr_indx],backlog);
      PrintAbbrevations(s,curr_indx+1,form,backlog+1);
    }else{
      PrintAbbrevations(s,curr_indx+1,form+to_string(backlog)+s[curr_indx],0);
      PrintAbbrevations(s,curr_indx+1,form,backlog+1);
    }
}

int main(){
  FastIO;
  
  
  return 0;
} 
