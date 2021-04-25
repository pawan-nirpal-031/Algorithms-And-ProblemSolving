// Problem Link : https://www.codechef.com/START3C/problems/HIRETEST
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

A company conducted a coding test to hire candidates. N candidates appeared for the test, and each of them faced M problems. Each problem was either unsolved by a candidate (denoted by 'U'), solved partially (denoted by 'P'), or solved completely (denoted by 'F').

To pass the test, each candidate needs to either solve X or more problems completely, or solve (X−1) problems completely, and Y or more problems partially.

Given the above specifications as input, print a line containing N integers. The ith integer should be 1 if the ith candidate has passed the test, else it should be 0.

*/

void Solve(){
    int n,m;
    cin>>n>>m;
    int x,y;
    cin>>x>>y;
    for(int i =0;i<n;i++){
        int f =0;
        int p =0;
        int u = 0;
        for(int j =0;j<m;j++){
            char c;
            cin>>c;
            if(c=='F') f+=1;
            else if(c=='U') u+=1;
            else p+=1;
        }
        cout<<(f>=x or (f>=x-1 and p>=y));
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