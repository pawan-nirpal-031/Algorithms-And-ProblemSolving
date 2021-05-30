// Problem Link : https://www.codechef.com/START4C/problems/CTIME
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

Chef's college is conducting an online exam, where his camera will be monitored by one or more invigilators (supervisors). Once again, Chef failed to prepare for the exam on time and decided to google answers during it.

The exam starts at time 0 and ends at time F minutes. Chef needs a total of K minutes of googling during the exam in order to pass it. There are N invigilators (numbered 1 through N); for each valid i, the i-th invigilator monitors Chef's camera during the time interval starting at Si minutes since the start of the exam and ending at Ei minutes (where 0≤Si≤Ei≤F). He was resourceful enough to somehow get hold of these times and now he wants to know if he would be able to pass the exam if he googles the answers during the times when no one is looking at his camera.

Note: The time of googling need not be continuous and there can be multiple invigilators at some interval of time.

*/

void Solve(){
    int n;
    cin>>n;
    ll k,f;
    cin>>k>>f;
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
    ll ans = 0;
    int m = disjoint.size();
    for(int i =0;i<m;i++){
        if(i==0) ans+=disjoint[i].first-0;
        else ans+=disjoint[i].first - disjoint[i-1].second;
    }
    if(f>disjoint[m-1].second) ans+=f-disjoint[m-1].second;
    Status(ans>=k);
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) Solve();
  return 0;
} 
// If Solved Mark (0/1) here => [1]