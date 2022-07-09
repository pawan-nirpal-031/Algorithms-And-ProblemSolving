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
#define Status(b) (cout<<(b?"YES\n":"NO\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x


/*
Problem Statement : 



*/


/*
Author's solution : 



*/



int test(int n){
    vector<vector<int>>board(n,vector<int>(n,0));
    int count =0;
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            if(board[i][j]==0){
                board[i][j]=2; 
                count+=1;
                if(j-1>=0 and i+1<n and  not (board[i+1][j-1]>=1)) board[i+1][j-1] = 1;
                if(i+1<n and j+1<n and not (board[i+1][j+1]>=1)) board[i+1][j+1] = 1;
                for(int x = 0;x<n;x++) if(board[i][x]<1) board[i][x] = 1;
                for(int x = 0;x<n;x++) if(board[x][j]<1) board[x][j] = 1;
            }
        }
    }
    return count;
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      cout<<((n%5==0 or n%5==1)?n:n-1)<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => []