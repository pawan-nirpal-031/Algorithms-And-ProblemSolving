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


bool sortFunction(std::string s1, std::string s2){
    if(s1[0] < s2[0]) return true;
    if(s2[0] < s1[0]) return false;
    int i = 0;
    int min = s1.size() < s2.size() ? s1.size() : s2.size();
    bool isMinS1 = (min == s1.size());
    bool isMinS2 = (min == s2.size());
    for(i = 1; i<min; i++){
        if(s1[i] < s2[i]) return true;
        if(s2[i] < s1[i]) return false;
    }
    if(isMinS1) return true;
    else if(isMinS2) return false;
    else return false;
}

int main(){
    string myString;
    cin >> myString;
    myString = myString;
    vector<string> transforms;
    for(int i=0; i<myString.size(); i++){
        char lastChar = myString[myString.size()-1];
        vector<char> temp(myString.size());
        for(int i=0; i<myString.size()-1; i++){
            temp[i+1] = myString[i];
        }
        temp[0] = lastChar;
        string newString(temp.begin(), temp.end());
        myString = newString;
        transforms.push_back(myString);
    }

    sort(transforms.begin(), transforms.end(), sortFunction);
    int index = 0;
    for(int i=0; i<transforms.size(); i++){
        if(transforms[i] == myString) index = i; 
        cout << transforms[i][transforms[i].size()-1];
    }
    return 0;
}