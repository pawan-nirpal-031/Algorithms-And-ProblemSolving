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
#define BoolAnsCall(b) (cout<<(b?"Yes\n":"No\n"));



void Attendance(){
    ll n;
    cin>>n;
    ll zero =0;
    ll one =0;
    string s;
    cin>>s;
    for(char c : s){
        if(c=='1'){
            one++;
        }
    }
    double cal = (120-n+one);
    double f = 100*((cal*1.0)/120);
    if(f>=75.0000){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

void CatchThief(){
    ll x,y,k,n;
    cin>>x>>y>>k>>n;
    if(abs(x-y)%k==0 && ((abs(x-y)/k)%2==0)){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}


void SelfDistructiveStrings(){
    string s;
    cin>>s;
    if(s.length()&1){
        cout<<"-1\n";
        return;
    }else{
        ll zero =0;
        ll one =0;
        for(char ch : s){
            if(ch=='0'){
                zero+=1;
            }else{
                one+=1;
            }
        }
        if(zero>0&& one>0){
            cout<<((abs(zero-one))>>1)<<'\n';
        }else{
            cout<<"-1\n";
        }
    }
}

void CircleOfChaos(){

}



void ZeroOnes(){
    ll n;
    cin>>n;
    vector<bool>s(n,0),t(n,0);
    for(int i=0;i<n;i++){
        bool b;
        cin>>b;
        s[i] = b;
    }
    for(int i=0;i<n;i++){
        bool b;
        cin>>b;
        t[i] = b;
    }

    int cs=0,ct=0;
    for(int i=0;i<n;i++){
        if(s[i]){
            cs++;
        }
        if(t[i]){
            ct++;
        }
    }
    if(cs!=ct){
        BoolAnsCall(0);
        return;
    }else{
        vector<int>prfxs(n,0),prfxt(n,0);
        prfxs[0] = s[0];
        prfxt[0] = t[0];
        if(prfxt[0]>prfxs[0]){
            BoolAnsCall(0);
            return;
        }
        for(int i=1;i<n;i++){
            prfxs[i] = (s[i])+prfxs[i-1];
            prfxt[i] = (t[i])+prfxt[i-1];
            if(prfxt[i]>prfxs[i]){
                BoolAnsCall(0);
                return;
            }  
        }
        BoolAnsCall(1);
        return;
    }
}

int main(){
    FastIO;
   
    return 0;
}

// g++  CodechefDECCookOFF.cpp