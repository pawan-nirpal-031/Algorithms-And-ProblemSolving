// Problem Link : 
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

You are given an integer n and an array a1,a2,…,an. You should reorder the elements of the array a in such way that the sum of MEX on prefixes (i-th prefix is a1,a2,…,ai) is maximized.

Formally, you should find an array b1,b2,…,bn, such that the sets of elements of arrays a and b are equal (it is equivalent to array b can be found as an array a with some reordering of its elements) and ∑i=1nMEX(b1,b2,…,bi) is maximized.

MEX of a set of nonnegative integers is the minimal nonnegative integer such that it is not in the set.

For example, MEX({1,2,3})=0, MEX({0,1,2,4,5})=3.v

*/

void Solve(){
    int n;
    cin>>n;
    vector<int>freq(105,0);
    int mx =0;
    for(int i =0;i<n;i++){
        int x;
        cin>>x;
        mx = max(x,mx);
        freq[x]+=1;
    }
    for(int i =0;i<=mx;i++){
        if(freq[i]==0) break;
        cout<<i<<' ';
        freq[i]-=1;
    }
    for(int i =0;i<=mx;i++){
        if(freq[i]==0) continue;
        while(freq[i]>0){
            cout<<i<<" ";
            freq[i]-=1;
        }
    }
    cout<<'\n';
}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) Solve();
  return 0;
} 
// If Solved Mark (0/1) here => [1]