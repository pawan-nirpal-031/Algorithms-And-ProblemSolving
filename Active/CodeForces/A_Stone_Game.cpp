// Problem Link : https://codeforces.com/contest/1538/problem/A
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

Polycarp is playing a new computer game. This game has n stones in a row. The stone on the position i has integer power ai. The powers of all stones are distinct.

Each turn Polycarp can destroy either stone on the first position or stone on the last position (in other words, either the leftmost or the rightmost stone). When Polycarp destroys the stone it does not exist any more.

Now, Polycarp wants two achievements. He gets them if he destroys the stone with the least power and the stone with the greatest power. Help Polycarp find out what is the minimum number of moves he should make in order to achieve his goal.

For example, if n=5 and a=[1,5,4,3,2], then Polycarp could make the following moves:

Destroy the leftmost stone. After this move a=[5,4,3,2];
Destroy the rightmost stone. After this move a=[5,4,3];
Destroy the leftmost stone. After this move a=[4,3]. Polycarp destroyed the stones with the greatest and least power, so he can end the game.
Please note that in the example above, you can complete the game in two steps. For example:

Destroy the leftmost stone. After this move a=[5,4,3,2];
Destroy the leftmost stone. After this move a=[4,3,2]. Polycarp destroyed the stones with the greatest and least power, so he can end the game.

*/

int GetMin(int a,int b,int c){
  return min(a,min(b,c));
}

void Solve(){
  int n;
  cin>>n;
  int max_indx;
  int min_indx;
  for(int i =0;i<n;i++){
    int x;
    cin>>x;
    if(x==1) min_indx = i;
    if(x==n) max_indx = i;
  }
  min_indx+=1;
  max_indx+=1;
  cout<<GetMin(max(min_indx,max_indx),max(n-min_indx,n-max_indx)+1,min(min_indx,max_indx)+n-max(min_indx,max_indx)+1)<<'\n';
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) Solve();
  return 0;
} 
// If Solved Mark (0/1) here => []