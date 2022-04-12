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

struct Matrix{
    ll mat[2][2];
};

ll Power(ll x,int n){ // O(1) space O(logn) time
    ll res = 1;
    while(n){
        if(n&1) res*=x;
        n>>=1;
        x=x*x;
    }
    return res;
}

Matrix MatrixProduct(Matrix a, Matrix b){
    Matrix c;
    for(int i =0;i<2;i++){
        for(int j =0;j<2;j++){
            ll val =0;
            for(int k =0;k<2;k++){
                val = (val%Mod + (a.mat[i][k]%Mod*b.mat[k][j]%Mod)%Mod)%Mod;
            }
            c.mat[i][j] = val;
        }
    }
    return c;
}

Matrix Identity(){
    Matrix a;
    a.mat[0][0] = a.mat[1][1] = 1;
    a.mat[0][1] = a.mat[1][0] = 0;
    return a;
}

Matrix MatrixExponentiaion(Matrix a,int n){
    if(n==0) return Identity();
    Matrix res = MatrixExponentiaion(a,(n>>1));
    return (n&1? MatrixProduct(a,MatrixProduct(res,res)):MatrixProduct(res,res));
}


void PointTransformation(int x,int y,Matrix transform,int n){
    Matrix converted = MatrixExponentiaion(transform,n);
    // do converted*[x y] product and [x1 y1] should be the transformed point co-ordinates

}

ll FibonacciUsingMatrixExponantion(int n){
    /*
        a = [1 1 
             1 0 ] 
        and f(0) = f(1) = 1 
        the recurance for fibonacci in matrix form is (a^n)*[f(0) f(1)] is 

        a^n*[1 1] 

        final recurance : 
            (a^n)*[f(0) f(1)] = [f(n+1) f(n)] 
    */
   Matrix fib;
   fib.mat[0][0] = fib.mat[0][1] = fib.mat[1][0] = 1;
   fib.mat[1][1] = 0;
   Matrix res_tranform = MatrixExponentiaion(fib,n);
   return (res_tranform.mat[1][0]%Mod+res_tranform.mat[1][1]%Mod)%Mod;
}


/*
    Basic premise is Gcd(a,b) is also same as Gcd(a,a-b) assuming a-b>=0 ie Gcd of two numbers is same as Gcd of thier diffrance so keep doing the diffrance eventually we get Gcd(a,a-2b), Gcd(a,a-3b)...Gcd(a,a-kb) where k is largest such number such that a-kb>=0 the max such k is k <=(a/b) max(k) = a/b floor so Gcd(a,b) = Gcd(a,a-floor(a/b)*b) and we know a-floor(a/b)*b = a%b so Gcd(a,b) = Gcd(a,a%b)
*/
ll Gcd(ll a,ll b){
    return (b==0?a:Gcd(b,a%b));
}

/*
    Extended Euclidian algorithm for finding solutions to ax+by=c  where all a,b,c,x,y are integers, the solution exits only when c is divisible by gcd(a,b) 
*/

ll ExtendedGcd(ll a,ll b, ll &x,ll &y){
    if(b==0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1,y1;
    ll d = ExtendedGcd(b,a%b,x1,y1);
    x = y1;
    y = x1-y1*(a/b);
    return d;
}


vector<bool> PrimesPreprocessing(int n){
    vector<bool>IsPrime(n+1,1);
    IsPrime[0] = IsPrime[1] =0;
    for(ll i = 2;i<=n;i++){
        if(IsPrime[i]) for(ll j = i*i;j<=n;j+=i) IsPrime[j] = 0;
    }
    return IsPrime;
}



int main(){    
  FastIO;
  
  return 0;
} 
