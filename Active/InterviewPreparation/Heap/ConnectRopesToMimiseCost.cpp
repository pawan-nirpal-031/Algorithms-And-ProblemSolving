#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
typedef pair<int,pair<int,int>> Tuple;
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


void ConnectRopesToMuinimizeCost(){ 
    // given an array find the minimum cost of adding all values to form minimum ie. implement optimal merge pattern ex 1 2 3 4 5, (1,2) = 3, ((1,2),3) = 6, (4,5) = 9, (((1,2),3),(4,5)) = 15 ie pick two smallest at any time
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>>heap;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        heap.push(x);
    }
    int x =0;
    while(not heap.empty()){
        x+=heap.top();
        heap.pop();
    }
    cout<<x;
}

int main(){
  FastIO;
  ConnectRopesToMuinimizeCost();
  return 0;
} 
