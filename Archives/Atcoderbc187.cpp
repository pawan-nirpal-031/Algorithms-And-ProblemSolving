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
#define GoogleOutput(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int Que1(){
    int a,b;
    cin>>a>>b;
    int sa =0, sb =0;
    while(a>0){
        sa+=(a%10);
        a/=10;
    }
    while(b>0){
        sb+=(b%10);
        b/=10;
    }
    return (sa>sb?sa:sb);
}

int Que2(){
    int n;
    cin>>n;
    vector<pair<int,int>>v(n,{0,0});
    for(int i =0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    int ans =0;
    for(int i =0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(abs(v[j].first-v[i].first)>=abs(v[j].second-v[i].second)){
                ans++;
            }
        }
    }
    return ans;
}

string Que3(){
    int n;
    cin>>n;
    unordered_multiset<string>no,yes;
    for(int i=0;i<n;i++){
        string src;
        cin>>src;
        if(src[0]=='!'){
            yes.insert(src);
        }else{
            no.insert("!"+src);
        }
    }
    for(auto st : yes){
        if(no.find(st)!=no.end()){
            return st;
        }
    }
    return "satisfiable";
}

int Que4(){
    int n;
    cin>>n;
    vector<pair<int,int>>v(n,{0,0});
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    vector<int>prefix(n,0);
    prefix[0] = v[0].first;
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]+v[i].first;
    }
    vector<int>suffix(n,0);
    suffix[n-1] = v[n-1].first+v[n-1].second;
    for(int i=n-2;i>=0;i--){
        suffix[i] = v[i].first+v[i].second+suffix[i+1];
    }
    for(int i =n-1;i>=1;i--){
        if(suffix[i]>prefix[i-1]){
            return n-i;
        }
    }
    return n;
}

int main(){
  FastIO;
 cout<<Que4();

  return 0;
} 
