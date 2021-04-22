// Problem Link : https://codeforces.com/problemset/problem/1472/C
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

Polycarp found under the Christmas tree an array a of n elements and instructions for playing with it:

At first, choose index i (1≤i≤n) — starting position in the array. Put the chip at the index i (on the value ai).
While i≤n, add ai to your score and move the chip ai positions to the right (i.e. replace i with i+ai).
If i>n, then Polycarp ends the game.
For example, if n=5 and a=[7,3,1,2,3], then the following game options are possible:

Polycarp chooses i=1. Game process: i=1⟶+78. The score of the game is: a1=7.
Polycarp chooses i=2. Game process: i=2⟶+35⟶+38. The score of the game is: a2+a5=6.
Polycarp chooses i=3. Game process: i=3⟶+14⟶+26. The score of the game is: a3+a4=3.
Polycarp chooses i=4. Game process: i=4⟶+26. The score of the game is: a4=2.
Polycarp chooses i=5. Game process: i=5⟶+38. The score of the game is: a5=3.
Help Polycarp to find out the maximum score he can get if he chooses the starting index in an optimal way.

*/

void SolveCase(){
    int n;
    cin>>n;
    vector<ll>max_score(n+1,0); // max_score[i] : maximum score attained if index i was chosen
    vector<ll>a(n+1,0);
    ll ans = 0;
    for(int i =1;i<=n;i++) cin>>a[i];
    for(int i = n;i>=1;i--){
        max_score[i] = a[i] + (i+a[i]>n?0:max_score[i+a[i]]);
        ans = max(ans,max_score[i]);
    }
    cout<<ans<<'\n';
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) SolveCase();
  return 0;
} 
// If Solved Mark (0/1) here => [1]