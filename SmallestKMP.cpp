#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define setA0(a) for(ull i =0;i<n;i++){a[i] = 0;}
#define aout(a) for(auto x : a){cout<<x<<' ';} 
#define ain(a) for(ull i =0;i<n;i++){cin>>a[i];} 
#define NofSetBits(x) __builtin_popcount(x);
#define InpGrph(g,e) while(e--){ll x;ll y;cin>>x>>y ;g[x].pub(y);g[y].pub(x);}
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


string ans1(string s,string p,ll f[]){
    string s1,s2;
    for(int i =0;i<26;i++){
        if(f[i]>0 && (char(i+'a')<=p[0])){
            while(f[i]>0){
                s1+=(char(i+'a'));
                f[i]--;
            }
        }
    }
    for(int i =0;i<26;i++){
        if(f[i]>0){
            while(f[i]>0){
                s2+=(char(i+'a'));
                f[i]--;
            }
        }
    }
    return s1+p+s2;
}

string ans2(string s,string p,ll f[]){
    string s1,s2;
    for(int i =0;i<26;i++){
        if(f[i]>0 && (char(i+'a')<p[0])){
            while(f[i]>0){
                s1+=(char(i+'a'));
                f[i]--;
            }
        }
    }
    for(int i =0;i<26;i++){
        if(f[i]>0){
            while(f[i]>0){
                s2+=(char(i+'a'));
                f[i]--;
            }
        }
    }
    return s1+p+s2;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        string s,p;
        cin>>s>>p;
        ll f[26];
        ll g[26];
        for(int i =0;i<26;i++){
            f[i]=0;
            g[i] =0;
        }
        for(char c : s){
            f[c-'a']++;
            g[c-'a']++;
        }
        for(char c : p){
            f[c-'a']--;
            g[c-'a']--;
        }
        cout<<min(ans1(s,p,f),ans2(s,p,g))<<'\n';
    }
    return 0;
}
