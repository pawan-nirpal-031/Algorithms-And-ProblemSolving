#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)
const ll N = 100002;
bool p[100002];
void seive(){
    p[0]=p[1]=0;
    for(ll i =2;i<N;i++){
        p[i]=1;
    }
    for(ll i =2;i*i<=N;i++){
        if(p[i]){
            for(ll j = i*i;j<=N;j+=i){
                p[j]=0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    seive();
    while(t--){
        ll n;
        cin>>n;
        cout<<(p[n]?"yes":"no")<<'\n';
    }
    return 0;
}
