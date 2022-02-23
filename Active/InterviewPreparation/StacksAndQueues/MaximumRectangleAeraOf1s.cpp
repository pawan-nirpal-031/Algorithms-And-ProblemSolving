#include <bits/stdc++.h>
// #include "MaximumAreaHistogram.cpp"
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



void SmallestToPrefix(vector<int>&smallestTOPrefix,vector<int>a,int n){
  stack<int>stk;
  for(int i =0;i<n;i++){
    if(stk.empty()) stk.push(i);
    else{
      while(not stk.empty() and a[i]<=a[stk.top()]) stk.pop();
      if(not stk.empty()) smallestTOPrefix[i] = stk.top()+1;
      stk.push(i);
    }
  }
}


void SmallestToSuffix(vector<int>&smallestToSuffix,vector<int>a,int n){
  stack<int>stk;
  for(int i =n-1;i>=0;i--){
    if(stk.empty()) stk.push(i);
    else{
      while(not stk.empty() and a[stk.top()]>=a[i]) stk.pop();
      if(not stk.empty()) smallestToSuffix[i] = stk.top()-1;
      stk.push(i);
    }
  }
}


int MaximumAreaOfHistogram(vector<int>a,int n){
  vector<int>smallestTOPrefix(n,0),smallestToSuffix(n,n-1);
  SmallestToPrefix(smallestTOPrefix,a,n);
  SmallestToSuffix(smallestToSuffix,a,n);
  vector<int>areas(n,0);
  int max_area = 0;
  for(int i =0;i<n;i++) max_area = max(max_area,a[i]*(smallestToSuffix[i]-smallestTOPrefix[i]+1));
  return max_area;
}




int main(){
  FastIO;
  int n,m;
  cin>>n>>m;
  vector<vector<int>>grid(n,vector<int>(m,0));
  for(int i =0;i<n;i++) for(int j =0;j<m;j++) cin>>grid[i][j];
  int max_area = 0;
  vector<int>cache(m,0);
  for(int i=0;i<n;i++){
      if(i==0){
          max_area = max(max_area,MaximumAreaOfHistogram(grid[i],m));
      }else{
          for(int j=0;j<m;j++){
              if(grid[i][j]) cache[j]+=1;
              else cache[j] =0;
          }
          max_area = max(max_area,MaximumAreaOfHistogram(cache,m));
      }
  }
  cout<<max_area;
  return 0;
} 
