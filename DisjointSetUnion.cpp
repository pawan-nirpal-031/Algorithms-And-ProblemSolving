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


class DisjointSetUnion{
    private:
        /*
            Complexity : O(log*(n)) it is an inverse ackerman function, grows extremly slowly near constant.
        */

        vector<ll>par;
        vector<ll>size;
        ll nocomp;
        ll GetUtil(vector<ll>&par,ll a){
            return par[a] = ((par[a]==a)?a:GetUtil(par,par[a]));
        }

        ll UnionUtil(vector<ll>&par,vector<ll> &size, ll a,ll b){
            a = GetUtil(par,a); // leader of a  
            b = GetUtil(par,b); // leader of b
            if(a!=b){
                if(size[a]>=size[b]){
                    size[a]+=size[b];
                    par[b] =a;
                }else {
                    size[b]+=size[a];
                    par[a] = b;
                }
                nocomp -=1;
            }
            return nocomp;
        }

    public:
        
        DisjointSetUnion(ll n){
            par.resize(n+1);
            size.resize(n+1);
            nocomp = n;
            for(ll i=0;i<=n;i++){
                par[i]=i;
                size[i]=1;
            }
        }

        ll Get(ll a){
            return GetUtil(par,a);
        }

        ll GetSize(ll u){
            return size[Get(u)];
        }

        ll Union(ll a,ll b){
           return UnionUtil(par,size,a,b);
        }

        ll NumberOfComponents(){
            return nocomp;
        }
};




int main(){
  FastIO;
  ll n,m;
  
  return 0;
}
