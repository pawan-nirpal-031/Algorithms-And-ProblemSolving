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

class Recursion{
    public:
        void PrintSubsets(vector<int>&v,int n,int i,string osf){
            if(i>=n){
                cout<<osf<<endl;
                return;
            }
            PrintSubsets(v,n,i+1,osf);
            PrintSubsets(v,n,i+1,osf+to_string(v[i]));
        }

        void Permuataions(string src,string osf){
            if(src==""){
                cout<<osf<<endl;
                return;
            }
            for(int i =0;i<src.length();i++){
                char c = src[i];
                string nsrc = src.substr(0,i)+src.substr(i+1);
                Permuataions(nsrc,osf+c);
            }
        }

        void UniquePermuataions(string src,string osf){
            if(src==""){
                cout<<osf<<endl;
                return;
            }
            unordered_set<char>rep;
            for(int i=0;i<src.length();i++){
                char c = src[i];
                if(rep.find(c)==rep.end()){
                    rep.insert(c);
                    UniquePermuataions(src.substr(0,i)+src.substr(i+1),osf+c);
                }
            }
        }

        void LexicographicPrinting(int uppbnd,int curr){
            if(curr>uppbnd){
                return;
            }
            cout<<curr<<' ';
            for(int i = (curr==0?1:0);i<=9;i++){
                LexicographicPrinting(uppbnd,10*curr+i);
            }
        }
};

class Backtracking{
    public:
      void Permutaion_Backtracing(string src,int j){
          if(j==src.length()-1){
              cout<<src<<endl;
              return;
          }
          for(int i =j;i<src.length();i++){
            swap(src[i],src[j]);
            Permutaion_Backtracing(src,j+1);
            swap(src[i],src[j]);
          }
      } 



// Rat in maze
      int TotalPaths =0;
      
      bool ValidCell(vector<vector<bool>>&vis,int n,int i,int j){
          return (i>=0 and i<n and j>=0 and j<n and (not vis[i][j]));
      }

      void RatInMazePathCountHelper(vector<vector<int>>&grid,int n,int i,int j,vector<vector<bool>>&vis){
          if(i==n-1 and j == n-1){
              TotalPaths++;
              return;
          }
          if(not ValidCell(vis,n,i,j)){ // Pruning the call
              return;
          }
          
          vis[i][j] = 1;
          
          if(i+1<n and grid[i+1][j]==0){
              RatInMazePathCountHelper(grid,n,i+1,j,vis);
          }
          if(j-1>=0 and grid[i][j-1] == 0){
              RatInMazePathCountHelper(grid,n,i,j-1,vis);
          }
          if(i-1>=0 and grid[i-1][j]==0){
              RatInMazePathCountHelper(grid,n,i-1,j,vis);
          }
          if(j+1<n and grid[i][j+1]==0){
              RatInMazePathCountHelper(grid,n,i,j+1,vis);
          }

          vis[i][j] =0;
          return;
      }
      
      void RatInMazePathCount(vector<vector<int>>&grid){
          int n = grid.size();
          vector<vector<bool>>vis(n,vector<bool>(n,0));
          RatInMazePathCountHelper(grid,n,0,0,vis);
          cout<<TotalPaths;
      }
      

      void display(vector<vector<int>>&grid,int n ){
          for(int i =0;i<n;i++){
              for(int j =0;j<n;j++){
                  cout<<grid[i][j]<<' ';
              }
              cout<<endl;
          }
      }



// Nqueens Problem
      bool SafeMove(vector<vector<bool>>&grid,int row,int col,int n){
          for(int r = row-1;r>=0;r--){
              if(grid[r][col]){
                  return 0;
              }
          }
          for(int c = 0;c<n;c++){
              if(grid[row][c]){
                  return 0;
              }
          }
          for(int i =row-1, j = col-1; i>=0 and j>=0; i--,j--){
              if(grid[i][j]) return 0;
          }
          for(int i = row-1,j = col+1; i>=0 and j<n; i--, j++){
              if(grid[i][j]) return 0;
          }
          return 1;
          cout<<row<<' '<<col<<endl;
      }

      int TotalWays =0;
      void Nqueens(vector<vector<bool>>&grid,int row,int n){
          if(row==n){
              TotalWays++;
             // display(grid,n);
              cout<<endl;
              return;
          }

          for(int col=0;col<n;col++){
              if(SafeMove(grid,row,col,n)){
                  grid[row][col] = 1;
                  Nqueens(grid,row+1,n);
                  grid[row][col] = 0;
              }
          }
          
      }







// Knight Tour 
      bool IsKnightSafe(vector<vector<int>>&grid,int n,int i,int j,vector<vector<bool>>&vis){
          return i>=0 and j>=0 and j<n and i<n and  not vis[i][j];
      }
      
      void KnightTour(vector<vector<int>>&grid,int n,int i, int j, int count,vector<vector<bool>>&vis){
          if(count==n*n-1){
              grid[i][j] = count;
              display(grid,n);
              cout<<endl<<endl;

              return;
          }
          if(count>=n*n){
              return;
          }
          int xdir[] = {-2,-1,1,2,2,1,-1,-2};
          int ydir[] = {1,2,2,1,-1,-2,-2,-1};
          vis[i][j] = 1;
          grid[i][j] = count;
          for(int d =0;d<8;d++){
              if(IsKnightSafe(grid,n,i+xdir[d],j+ydir[d],vis)){
                  KnightTour(grid,n,i+xdir[d],j+ydir[d],count+1,vis);
              }
          }
          grid[i][j]-=1;
          vis[i][j] =0;
      }
    

};


int main(){
    FastIO;
    Backtracking obj;
    int n;
    cin>>n;
    vector<vector<int>>grid(n,vector<int>(n,-1));
    vector<vector<bool>>vis(n,vector<bool>(n,0));
    obj.KnightTour(grid,n,0,0,0,vis);
    return 0;
}