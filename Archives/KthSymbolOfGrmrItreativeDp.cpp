#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define getl(s) getline(cin,s);

/*
    Problem is solely based on observational skills
*/



int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  int dp[n+1][(1<<(n-1))+1]={-1};
  dp[1][1]=0;
  for(int i =2;i<=n;i++){
    for(int j = 1;j<=((1<<(i-1)));j++){
      if(j<=((1<<(i-2)))){
        dp[i][j] = dp[i-1][j];
      }else{
        dp[i][j] = !(dp[i-1][j-(1<<(i-2))]);
      }
    }
  }
  for(int i =1;i<=n;i++){
    for(int j = 1;j<=(1<<(i-1));j++){
      cout<<dp[i][j]<<' ';
    }
    cout<<'\n';
  }
  return 0;
}
