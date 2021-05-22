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

bool CheckEqual(vector<int>h,vector<int>ch){
    for(int i=0;i<26;i++) if(h[i]!=ch[i]) return 0;
    return 1;
}

void FindAllAnagrams(string s,string p){
    vector<int>hash(26,0),curr_hash(26,0);
    for(char c : p) hash[c-'a']+=1;
    int n = s.length();
    int m = p.length();
    for(int i =0;i<n;i++){
        curr_hash[s[i]-'a']+=1;
        if(i==m-1) if(CheckEqual(curr_hash,hash)) cout<<i-m+1<<' ';
        if(i>=m){
            curr_hash[s[i-m]-'a']-=1;
            if(CheckEqual(hash,curr_hash)) cout<<i-m+1<<' ';
        } 
    }
}


int main(){
  FastIO;
  string s,p;
  cin>>s>>p;
  FindAllAnagrams(s,p);
  return 0;
} 
