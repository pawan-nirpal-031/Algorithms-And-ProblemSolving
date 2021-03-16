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
#define BoolAnsCall(b) (cout<<(b?"YES\n":"NO\n"));

void SpaceNavigation(){
    int px,py;
    cin>>px>>py;
    string cmd;
    cin>>cmd;
    int Rc =0;
    int Uc =0;
    int Lc =0;
    int Dc =0;
    for(int i =0;i<cmd.length();i++){
        if(cmd[i]=='R') Rc+=1;
        if(cmd[i]=='L') Lc+=1;
        if(cmd[i]=='U') Uc+=1;
        if(cmd[i]=='D') Dc+=1;
    }
    if(px>=0 and py>=0){ // q1
        if(Rc>=abs(px) and Uc>=abs(py)){
            BoolAnsCall(1);
        }else{
            BoolAnsCall(0);
        }
    }else if(px>=0 and py<0){// q4 
        if(Rc>=abs(px) and Dc>=abs(py)){
            BoolAnsCall(1);
        }else{
            BoolAnsCall(0);
        }
    }else if(px<0 and py>=0){ //q2
        if(Lc>=abs(px) and Uc>=abs(py)){
            BoolAnsCall(1);
        }else{
            BoolAnsCall(0);
        }
    }else{ // q3
        if(Lc>=abs(px) and Dc>=abs(py)){
            BoolAnsCall(1);
        }else{
            BoolAnsCall(0);
        }
    }
}

void NewColony(){
    int n;
    ll k;
    cin>>n>>k;
    int h[n];
    vector<int>suffixMax(n,0);
    for(int i =0;i<n;i++){
        cin>>h[i];
    }
    suffixMax[n-1]= h[n-1];
    for(int i = n-2;i>=0;i--){
        suffixMax[i] = max(h[i],suffixMax[i+1]);
    }
    for(int i =0;i<n;i++){
        if(h[i]>=suffixMax[i]){
            continue;
        }
        if(h[i]<suffixMax[i]){
            k-= (suffixMax[i]-h[i]);
            //cout<<" k at "<<i<<" is "<<k<<endl;
             if(k<=0){
                cout<<i+1<<'\n';
                //cout<<"Finidnd "<<i<<'\n';
                return;
            }
        }
    }
    cout<<-1<<'\n';
}




int main(){
    FastIO;
    int t;
    cin>>t;
    while(t--){
        SpaceNavigation();
    }
    return 0;
}