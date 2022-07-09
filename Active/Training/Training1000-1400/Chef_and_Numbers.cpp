#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Pair(a,b) make_pair(a,b)
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define Case(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));


/*
Problem
Chef has NN dishes of different types arranged in a row: A_1, A_2, where A_iA denotes the type of the i^{th}i 
th dish. He wants to choose as many dishes as possible from the given list but while satisfying two conditions:
He can choose only one type of dish. No two chosen dishes should be adjacent to each other.
Chef wants to know which type of dish he should choose from, so that he can pick the maximum number of dishes.

Example:
Given NN=99 and AA=[1, 2, 2, 1, 2, 1, 1, 1, 1][1,2,2,1,2,1,1,1,1].
For type 1, Chef can choose at most four dishes. One of the ways to choose four dishes of type 1 is A_1A 
So in this case, Chef should go for type 1, in which he can pick more dishes.
*/


void solve(){
    int n; 
    cin>>n; 
    vector<int>nonadjcent_count(1002,0);
    int a[n]; 
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    int prev = a[0];
    int count =1;
    for(int i = 1;i<n;i++){
        if(a[i]==a[i-1]){
            prev = a[i];
            count+=1;
            continue;
        }else{
            nonadjcent_count[prev]+=((count>>1)+(count&1));
            count = 1; 
            prev = a[i];
        }
    }
    nonadjcent_count[prev]+=((count>>1)+(count&1));
    int maximum =1; 
    for(int i =1;i<1001;i++) maximum = max(maximum,nonadjcent_count[i]);
    int ans  =0; 
    for(int i =1;i<1001;i++){
        if(maximum==nonadjcent_count[i]){
            ans = i; 
            break;
        }
    }
    cout<<ans<<'\n';
}

int main(){
  FastIO;
  int t; 
  cin>>t; 
  while(t--){
    solve();
  }
  return 0;
} 
