// Problem Link : https://codeforces.com/contest/1466/problem/A
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

Argus was charged with guarding Io, which is not an ordinary cow. Io is quite an explorer, and she wanders off rather frequently, making Argus' life stressful. So the cowherd decided to construct an enclosed pasture for Io.

There are n trees growing along the river, where Argus tends Io. For this problem, the river can be viewed as the OX axis of the Cartesian coordinate system, and the n trees as points with the y-coordinate equal 0. There is also another tree growing in the point (0,1).

Argus will tie a rope around three of the trees, creating a triangular pasture. Its exact shape doesn't matter to Io, but its area is crucial to her. There may be many ways for Argus to arrange the fence, but only the ones which result in different areas of the pasture are interesting for Io. Calculate the number of different areas that her pasture may have. Note that the pasture must have nonzero area.

*/


void Solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i =0;i<n;i++) cin>>a[i];
    set<int>areas;
    for(int i =0;i<n;++i){
        for(int j = i+1;j<n;++j){
            areas.insert(a[j]-a[i]);
        }
    }
    cout<<areas.size()<<'\n';
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) Solve();
  return 0;
} 
// If Solved Mark (0/1) here => [1]