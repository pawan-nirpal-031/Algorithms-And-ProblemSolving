// Problem Link : https://codeforces.com/contest/1551/problem/B2
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

This problem is an extension of the problem "Wonderful Coloring - 1". It has quite many differences, so you should read this statement completely.

Recently, Paul and Mary have found a new favorite sequence of integers a1,a2,…,an. They want to paint it using pieces of chalk of k colors. The coloring of a sequence is called wonderful if the following conditions are met:

each element of the sequence is either painted in one of k colors or isn't painted;
each two elements which are painted in the same color are different (i. e. there's no two equal values painted in the same color);
let's calculate for each of k colors the number of elements painted in the color — all calculated numbers must be equal;
the total number of painted elements of the sequence is the maximum among all colorings of the sequence which meet the first three conditions.
E. g. consider a sequence a=[3,1,1,1,1,10,3,10,10,2] and k=3. One of the wonderful colorings of the sequence is shown in the figure.

The example of a wonderful coloring of the sequence a=[3,1,1,1,1,10,3,10,10,2] and k=3. Note that one of the elements isn't painted.
Help Paul and Mary to find a wonderful coloring of a given sequence a.

Input
The first line contains one integer t (1≤t≤10000) — the number of test cases. Then t test cases follow.

Each test case consists of two lines. The first one contains two integers n and k (1≤n≤2⋅105, 1≤k≤n) — the length of a given sequence and the number of colors, respectively. The second one contains n integers a1,a2,…,an (1≤ai≤n).

It is guaranteed that the sum of n over all test cases doesn't exceed 2⋅105.

Output
Output t lines, each of them must contain a description of a wonderful coloring for the corresponding test case.

Each wonderful coloring must be printed as a sequence of n integers c1,c2,…,cn (0≤ci≤k) separated by spaces where

ci=0, if i-th element isn't painted;
ci>0, if i-th element is painted in the ci-th color.
Remember that you need to maximize the total count of painted elements for the wonderful coloring. If there are multiple solutions, print any one.

Example


*/


/*
Author's solution : 



*/

void look(){
    int n = 13;
    vector<int>f(n+1,0);
    int a[n];
    for(int i =0;i<n;i++){
        cin>>a[i];
        f[a[i]]+=1;
    }
    vector<int>g[n+1];
    vector<pair<int,int>>cache;
    for(int i =0;i<n;i++) if(f[a[i]]<k) cache.push_back({f[a[i]],a[i]});
    sort(cache.begin(),cache.end());
    for(int i =1;i<=n;i++) cout<<"f("<<i<<") : "<<f[i]<<'\n';
}

int main(){
  FastIO;
//   int t;
//   cin>>t;
//   while(t--){
//       int n,k;
//       cin>>n>>k;
//       ll a[n];
//       vector<int>freq(n+1,0);
//       for(ll &x : a){
//           cin>>x;
//           freq[x]+=1;
//       }
    look();

//   }
  return 0;
} 
// If Solved Mark (0/1) here => []