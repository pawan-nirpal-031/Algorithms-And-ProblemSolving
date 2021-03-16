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


ll Find(vector<ll>&par,ll u){
    return ((par[u]==u)?u:Find(par,par[u]));
}


void SecretPasswordCF(){ // https://codeforces.com/problemset/problem/1263/D
    ll n;
    cin>>n; 
    while(n--){
        string pass;
        cin>>pass;
    }    
    /*
One unknown hacker wants to get the admin's password of AtForces testing system, to get problems from the next contest. To achieve that, he sneaked into the administrator's office and stole a piece of paper with a list of n passwords — strings, consists of small Latin letters.

Hacker went home and started preparing to hack AtForces. He found that the system contains only passwords from the stolen list and that the system determines the equivalence of the passwords a and b as follows:

two passwords a and b are equivalent if there is a letter, that exists in both a and b;
two passwords a and b are equivalent if there is a password c from the list, which is equivalent to both a and b.
If a password is set in the system and an equivalent one is applied to access the system, then the user is accessed into the system.

For example, if the list contain passwords "a", "b", "ab", "d", then passwords "a", "b", "ab" are equivalent to each other, but the password "d" is not equivalent to any other password from list. In other words, if:

admin's password is "b", then you can access to system by using any of this passwords: "a", "b", "ab";
admin's password is "d", then you can access to system by using only "d".
Only one password from the list is the admin's password from the testing system. Help hacker to calculate the minimal number of passwords, required to guaranteed access to the system. Keep in mind that the hacker does not know which password is set in the system.

Input
The first line contain integer n (1≤n≤2⋅105) — number of passwords in the list. Next n lines contains passwords from the list – non-empty strings si, with length at most 50 letters. Some of the passwords may be equal.

It is guaranteed that the total length of all passwords does not exceed 106 letters. All of them consist only of lowercase Latin letters.




*/

// find nof connected componetns
 
}


int main(){
    FastIO;
    SecretPasswordCF();
    return 0;
} 