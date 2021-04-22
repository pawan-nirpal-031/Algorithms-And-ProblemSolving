// Problem Link : https://www.codechef.com/COOK128C/problems/BUILDB
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

After solving programming problems for years, Chef has become lazy and decided to get a better physique by doing some weight lifting exercises.

On any regular day, Chef does N exercises at times A1,A2,…,AN (in minutes, all distinct) and each exercise provides a tension of B1,B2,…,BN units. In the period between two consecutive exercises, his muscles relax R units of tension per minute.

More formally, Chef's tension is described by a number x. Before any workouts, x=0. When he does a workout at time Ai, the tension x instantly increases by Bi. Between workouts, the number x decreases by R units per minute, maximized with 0.

Considering the time of exercise and hence tension to be negligible, find the maximum tension he will be feeling in his muscles during the entire period of his workout.

*/

void SolveCase(){
    int n,r;
    cin>>n>>r;
    ll max_tension = 0, curr_tension =0;
    ll a[n],b[n];
    for(int i =0;i<n;i++) cin>>a[i];
    for(int i =0;i<n;i++) cin>>b[i];
    for(int i =0;i<n;i++){
        curr_tension+=b[i];
        max_tension = max(max_tension,max(0LL,(ll)curr_tension));
        if(i<n-1){
            curr_tension=max(0LL,(curr_tension-((a[i+1]-a[i])*r)));
        }
        //  max_tension = max(max_tension,max(0LL,(ll)curr_tension)); // [Early mistake made]
    }
    cout<<max_tension<<'\n';
}

/*

lack of clairity of thought was a big mistake on the highlighted line (max_tension should be updated as soon as current tension is added ie. b[i] is added because the below line (line  47) misses the first updation and directly reduces tension )

*/

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      SolveCase();
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]