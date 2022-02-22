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

string FirstNonRepeating(string A){
    vector<int>freq(26,0);
    queue<char>que;
    string ans;
    for(char c : A){
        freq[c-'a']+=1;
        que.push(c);
        while(not que.empty() and freq[que.front()-'a']>1) que.pop();
        if(que.empty()) ans+='#';
        else ans+=que.front();
    }
    return ans;
}

int main(){
  FastIO;
  
  return 0;
} 
