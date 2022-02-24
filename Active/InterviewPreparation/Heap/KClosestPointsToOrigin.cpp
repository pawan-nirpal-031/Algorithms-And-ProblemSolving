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
typedef pair<int,pair<int,int>> PointData;


void KClosestPointsToOrigin(){ 
    // a space opti,ization could be done in terms of storage on heap in form of (distance,indxInArray)
    int n,k;
    cin>>n>>k;
    priority_queue<PointData>Kclosest;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        PointData d;
        d.first = sqrt(x*x+y*y);
        d.second.first = x;
        d.second.second = y;
        Kclosest.push(d);
        if(Kclosest.size()>k) Kclosest.pop();
    }
    while(not Kclosest.empty()){
        PointData d = Kclosest.top();
        cout<<d.second.first<<' '<<d.second.second<<'\n';
        Kclosest.pop();
    }
}

int main(){
  FastIO;
  KClosestPointsToOrigin();
  return 0;
} 
