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

// for each height get nearestSamllertoLeft, nearestSamllertoRight arrays this will give the maximum width that this current building can expand that width is (nearestSamllertoRight - nearestSamllertoLeft) simply mulitply the current building's height with this maximum width and get max area for the curr building than do this for every building

void SmallestToPrefix(vector<int>&smallestTOPrefix,int a[],int n){
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

void SmallestToSuffix(vector<int>&smallestToSuffix,int a[],int n){
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

  return 0;
}
