#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Pair(a,b) make_pair(a,b)
#define Point(x) std::fixed<<setprecision(6)<<x
#define SetBits(x) __builtin_popcount(x);
#define Case(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));


string longestCommonPrefix(vector<string>& strs) {
    int global = strs[0].length();
    int n = strs.size();
    for(int i = 1;i<n;i++){ 
        int local = min(strs[i-1].length(),strs[i].length());
        for(int j = 0;j<min(strs[i-1].length(),strs[i].length());j++){
            if(strs[i-1][j]!=strs[i][j]){
                local = j;
                break;
            }
        }
        global = min(local,global);
    }
    string ans;
    for(int i =0;i<global;i++) ans+=strs[0][i];
    return ans;
}

void solve(){ 
    int n;
    cin>>n;
    vector<string>sts(n,"");
    for(int i =0;i<n;i++) cin>>sts[i];
    cout<<longestCommonPrefix(sts);
}


int main(){
  FastIO;
  int t = 1;
  //cin>>t; 
  while(t--) solve();
  return 0;
} 
