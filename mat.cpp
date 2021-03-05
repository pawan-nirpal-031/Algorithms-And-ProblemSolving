#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int

vector<vector<ll>> matMul(vector<vector<ll>> a,vector<vector<ll>> b){
vector<vector<ll>> c(2,vector<ll>(2));
    for(ll i=0;i<2;i++){
        for(ll j=0;j<2;j++){
            for(ll k=0;k<2;k++){
                c[i][j]+=(a[i][k]*b[k][j])%mod;
            }
            c[i][j]%=mod;
        }
    }
    return c;
}

vector<vector<ll>> matExp(vector<vector<ll>> T,ll n){
    if(n==1) return T;
    vector<vector<ll>> temp=matExp(T,n/2);
    if(n%2==0) return matMul(temp,temp);
        return matMul(T,matMul(temp,temp));
}

void solve(){
    ll n;
    cin>>n;
    if(n==1){
        cout<<2<<endl;
        return;
    }else if(n==2){
        cout<<3<<endl;
        return;
    }
    vector<vector<ll>> T(2,vector<ll>(2));
    T[0][0]=0;
    T[0][1]=1;
    T[1][0]=1;
    T[1][1]=1;
    n-=2;
    vector<vector<ll>> temp=matExp(T,n);
    cout<<(2*temp[1][0]+3*temp[1][1])%mod<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}