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



int main(){
  FastIO;
  int t;
  cin>>t; 
  while(t--){
    int n;
    cin>>n;
    int freq[11] = {0}; 
    int max_freq =0;
    for(int i =0;i<n;i++){
        int x;
        cin>>x; 
        freq[x]+=1;
        max_freq = max(max_freq,freq[x]);
    }
    int freq_freq[max_freq+2] = {0}; 
    int max_freq_freq =0;
    for(int i = 1;i<=10;i++) freq_freq[freq[i]]+=1;
    for(int i =1;i<=max_freq;i++) max_freq_freq = max(max_freq_freq,freq_freq[i]);
    int ans =0;
    for(int i =1;i<=max_freq;i++) if(max_freq_freq==freq_freq[i]){
        ans = i; 
        break;
    }
    cout<<ans<<'\n';
  }
  return 0;
} 
