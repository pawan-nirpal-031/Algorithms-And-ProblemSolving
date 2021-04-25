// Problem Link : https://codeforces.com/problemset/problem/1466/B
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


/*
Problem Statement : 

Athenaeus has just finished creating his latest musical composition and will present it tomorrow to the people of Athens. Unfortunately, the melody is rather dull and highly likely won't be met with a warm reception.

His song consists of n notes, which we will treat as positive integers. The diversity of a song is the number of different notes it contains. As a patron of music, Euterpe watches over composers and guides them throughout the process of creating new melodies. She decided to help Athenaeus by changing his song to make it more diverse.

Being a minor goddess, she cannot arbitrarily change the song. Instead, for each of the n notes in the song, she can either leave it as it is or increase it by 1.

Given the song as a sequence of integers describing the notes, find out the maximal, achievable diversity

*/

void Solve(){
    int n;
    cin>>n;
    vector<int>frq(2*n+5,0);
    int max_val = 0;
    for(int i =0;i<n;i++){
      int x;
      cin>>x;
      max_val = max(max_val,x);
      frq[x]+=1;
    }
    for(int i =1;i<=max_val;i++){
      if(frq[i]<=1) continue;
      frq[i]-=1;
      frq[i+1]+=1;
    }
    int ans =0;
    for(int i =1;i<=max_val+1;i++) if(frq[i]>=1) ans+=1;
    cout<<ans<<"\n";
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) Solve();
  return 0;
} 
// If Solved Mark (0/1) here => [1]