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

void IntervalMergingTechnique(){
    int n;
    cin>>n;
    vector<pair<int,int>>Intervals(n,{0,0});
    for(int i =0;i<n;i++){
        int x,y;
        cin>>x>>y;
        Intervals[i].first = x;
        Intervals[i].second = y;
    }
    sort(Intervals.begin(),Intervals.end());
    for(int i =1;i<n;i++){
        if(Intervals[i].first<=Intervals[i-1].second){
            Intervals[i].first = min(Intervals[i].first,Intervals[i-1].first);
            Intervals[i].second = max(Intervals[i].second,Intervals[i-1].second);
        }
    }
    vector<pair<int,int>>disjoint;
    disjoint.push_back({Intervals[0].first,Intervals[0].second});
    int index = 0;
    for(int i =1;i<n;i++){
        if(Intervals[i].first==Intervals[i-1].first) disjoint[index].second = max(disjoint[index].second,Intervals[i].second);
        else{
            index+=1;
            disjoint.push_back({Intervals[i].first,Intervals[i].second});
        }
    }
}

int main(){
  FastIO;
  
  return 0;
} 
