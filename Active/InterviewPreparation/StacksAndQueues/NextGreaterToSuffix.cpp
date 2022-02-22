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

void method1(int a[],int n,vector<int>&nextgreater){
  stack<int>nxtIndx;
  for(int i =0;i<n;i++){
    if(nxtIndx.empty()) nxtIndx.push(i);
    else{
      while(not nxtIndx.empty() and (a[i]>a[nxtIndx.top()])){
        nextgreater[nxtIndx.top()] = a[i];
        nxtIndx.pop();
      }
      nxtIndx.push(i); 
    }
  }
}


void method2(int a[],int n,vector<int>&nextgreater){
  stack<int>stk;
  for(int i =n-1;i>=0;i--){
    if(stk.empty()){
      stk.push(a[i]);
      nextgreater[i] = -1;
    }
    else{
      while(not stk.empty() and (a[i]>=stk.top())) stk.pop();
      if(not stk.empty()) nextgreater[i] = stk.top();
      stk.push(a[i]);
    }
  }
  for(int i =0;i<n;i++) cout<<nextgreater[i]<<' ';
}

int main(){
  FastIO;
  int n;
  cin>>n;
  int a[n];
  for(int &x : a) cin>>x;
  vector<int>nextgreater(n,-1);
  method2(a,n,nextgreater);
  
  return 0;
} 
