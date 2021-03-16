#include<bits/stdc++.h>
 
#define ll long long int
#define mod 1000000007
using namespace std;
 
 

  
//--------
//dp[total juice][vitamins ranging from 0-7]
ll dp[1001][8];
// dp and bitmasking

ll recurse(vector<pair<ll , int> > &v , int &n , int current , int vitamins){
	if(vitamins == 7) return 0; // if vitamins == 7 then all the vitamins are taken and no need to take more
	if(current == n) return INT_MAX; // if current(index) >= n and all the vitamins are not taken then return max
	
	// this condition is for if we don't take the current juice and store in dp. Its not already calulated or if calculated then if the juice contains same vitamins which we already have(vitamins) then do calculation again for it
	if(dp[current][vitamins] == -1 or vitamins == v[current].second){
		ll cal = recurse(v , n , current+1 , vitamins);
		dp[current][vitamins] = cal;
	}
		
	// if the vitamins in the current juice is already taken then no need to take the current juice
	if(vitamins == v[current].second) return dp[current][vitamins];
	
	// this condition is if we take the current juice and store in dp newVitamin = (already vitamins | new vitamins we'll get from this juice)
	int newVitamins = vitamins | v[current].second;
	
	if(dp[current][newVitamins] == -1 or newVitamins == v[current].second){
		ll cal = recurse(v , n , current+1 , newVitamins);	
		dp[current][newVitamins] = v[current].first + cal;
	}
	
	// min of (if we don't take the current juice , if we take the current juice)
	return min(dp[current][vitamins] , dp[current][newVitamins]);
}
 
 
void testcase(){
	memset(dp , -1 , sizeof dp);
	int n;
	cin>>n;
	vector<pair<ll , int>> v(n);
	for(int i=0 ; i<n ; i++){
		ll temp;
		cin>>temp;
		bitset<3> tempbit;
		string s;
		cin>>s;
		for(auto j : s){
			//assigning the values
			// if A -> 001 -> 1
			// B -> 010 -> 2
			// C -> 100 -> 4
			// AB -> 011 -> 3 .... upto -> 111 -> 7
			if(j == 'A') tempbit.set(0);
			if(j == 'B') tempbit.set(1);
			if(j == 'C') tempbit.set(2);
		}
		v[i] = {temp , tempbit.to_ulong()};
	}
	
	//recurse(vector , total , starting index , starting vitamins(no vitamins = 000 -> 0))
	ll finalans = recurse(v , n , 0 , 0);
	if(finalans >= INT_MAX) cout<<-1<<endl;
	else cout<<finalans<<endl;
}
 
 
int main(){
    int tt = 1;
    //cin>>tt;
    tt++;
    while(--tt){
        testcase();
    }
    return 0;
    
}
