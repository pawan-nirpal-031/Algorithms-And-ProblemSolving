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



int KthSmallestElement(int a[],int n,int k){
    priority_queue<int>maxheap;
    for(int i=0;i<n;i++){
        maxheap.push(a[i]);
        if(maxheap.size()>k) maxheap.pop();
    }
    return maxheap.top();
}

vector<int> KthLargestElementsInArray(int a[],int n,int k){
    priority_queue<int,vector<int>,greater<int>>process;
    for(int i =0;i<n;i++){
        process.push(a[i]);
        if(process.size()>k) process.pop();
    }
    vector<int>b;
    while(not process.empty()){
        b.push_back(process.top());
        process.pop();
    }
    return b;
}

void SortAKSortedArray(int a[],int n,int k){
    priority_queue<int,vector<int>,greater<int>>process;
    for(int i=0;i<n;i++){
        process.push(a[i]);
        if(process.size()<=k) continue;
        a[i-k] = process.top();
        process.pop();
    }
    int i = n-k;
    while(not process.empty()){
        a[i] = process.top();
        process.pop();
        i+=1;
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}


vector<int> KClosestElementsToGivenNumber(int a[],int n,int k,int x){
    priority_queue<pair<int,int>>process;
    for(int i =0;i<n;i++){
        process.push({abs(a[i]-x),a[i]});
        if(process.size()>k) process.pop();
    }
    vector<int>ans;
    while(not process.empty()){
        ans.push_back(process.top().second);
        process.pop();
    }
    return ans;
}


vector<int> TopKFrequentNumbers(int a[],int n,int k){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>process;
    unordered_map<int,int>cache;
    for(int i =0;i<n;i++) cache[a[i]]++;
    for(auto tuple : cache){
        process.push({tuple.second,tuple.first});
        if(process.size()>k) process.pop();
    }
    vector<int>ans;
    while(not process.empty()){
        ans.push_back(process.top().second);
        process.pop();
    }
    return ans;
}

int main(){
  FastIO;
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int &x : a) cin>>x;  

  return 0;
} 
