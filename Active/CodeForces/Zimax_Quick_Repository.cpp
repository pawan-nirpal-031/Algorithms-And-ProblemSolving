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



class MathUtility{
  public:

    ull Gcd(ull a,ull b){
        return (a%b==0?b:Gcd(b,a%b));
    }

    ll Lcm(ll a,ll b){
        return (a*b)/Gcd(a,b);
    }

    ll Power(ll a,ll n){
      if(n==1) return a;
      ll half = Power(a,n>>1);
      return (n&1?half*half*a:half*half);
    }
    
    ll ModulorExponention(ll a,ll n,ll m){
      if(n==1) return a%m;
      ll half = ModulorExponention(a,n>>1,m)%m;
      return ((n&1)?(((half*half)%m)*(a%m))%m:(half*half)%m);
    }

    vector<ll> Factorization(ll x){
      vector<ll>factors;
      for(int i =1;i*i<=x;i++){
        if(x%i==0){
          if(i*i==x){
            factors.emplace_back(i);
          }else{
            factors.emplace_back(i);
            factors.emplace_back(x/i);
          }
        }
      }
      return factors;
    }

    vector<pair<int,int>> PrimeFactorization(ll n){
      vector<pair<int,int>> prime_factors;
      for(int i = 2;i*i<=n;i++){
        if(n%i==0){
          int frequency =0;
          while(n%i==0){
            n/=i;
            frequency+=1;
          }
          prime_factors.emplace_back(Pair(i,frequency));
        }
      }
      if(n>1){
        prime_factors.emplace_back(Pair(n,1));
      }
      return prime_factors;
    }

    vector<vector<ll>> FactorizationOfARangeOfNumbers(ll n){ // This could check prime and factors otherwise in O(Nlog(N)) for all numbers betwwen 1 to n
        vector<vector<ll>>Factors(n+1);
        for(int i = 1;i<=n;i++){
          for(int j = i; j<=n;j+=i) Factors[j].emplace_back(i);
        }
        return Factors;
    }

    vector<bool> SievePrimeFactorization(ll max_limit){
      vector<bool>primes(max_limit+1,1);
      primes[0] = primes[1] = 0;
      for(int i = 2;i*i<=max_limit;i++){
        if(primes[i]){
         for(int j = i*i;j<=max_limit;j+=i) primes[j] = 0;
        }
      }
      return primes;
    }
    
};

class StringUtility{
  public:
    bool IsSubsequnece(string s,string t){
        int p1,p2;
        for(p2 =0,p1=0;p2<t.length() and p1<s.length();){
          if(t[p2]==s[p1]){
            p2+=1;
            p1+=1;
          }else{
            p1+=1;
          }
        }
        return (p2==t.length());
      }
};

class GraphUtility{
  private:
    int nodes_per_comp;
    void ConnectedComponentsInfoUtil(vector<int>g[],vector<bool>&vis,int u){
        vis[u] = 1;
        nodes_per_comp+=1;
        for(int v : g[u]) if(not vis[v]) ConnectedComponentsInfoUtil(g,vis,v);
    }
  public:

    vector<pair<int,int>> ConnectedComponentsInfo(vector<int>g[],int n){
        /*
           components_data(i) =  (starting_pt_of_comp,number_of_nodes_in_comp)
           components_data.size() = number of components
        */
        vector<pair<int,int>>components_data;
        vector<bool>vis(n,0);
        for(int i =0;i<n;i++){
            if(not vis[i]){
                nodes_per_comp = 0;
                ConnectedComponentsInfoUtil(g,vis,i);
                components_data.push_back({i,nodes_per_comp});
            }
        }
        return components_data;
    }

    vector<int> BfsSingleSourceShortestPath(vector<int>g[],int n,int src){
        vector<int>dist(n,INT_MAX);
        dist[src] =0;
        vector<bool>vis(n,0);
        queue<int>process;
        process.push(src);
        vis[src] =1;
        while(not process.empty()){
            int curr_node = process.front();
            process.pop();
            for(int v : g[curr_node]){
                if(vis[v]) continue;
                vis[v] =1;
                dist[v] = 1 + dist[curr_node];
                process.push(v);
            }  
        }
        return dist;
    }

    void TreeFlatteningUtil(vector<int>&flattend_tree,vector<pair<int,int>>&range,int curr_node,int par_curr,vector<int>g[]){
      flattend_tree.push_back(curr_node);
      range[curr_node].first = flattend_tree.size();
      for(int &child : g[curr_node]){
        if(child!=par_curr){
          TreeFlatteningUtil(flattend_tree,range,child,curr_node,g);
        }
      }
      range[curr_node].second = flattend_tree.size();
    } 

    pair<vector<int>,vector<pair<int,int>>> TreeFlattening(vector<int>graph[],int n){
      vector<int>flattend_tree;
      vector<pair<int,int>>range(n+1,{0,0});
      GraphUtility().TreeFlatteningUtil(flattend_tree,range,1,0,graph);
      return {flattend_tree,range};
    } 
};

class SegmentTreeUtility{
  public:
    int merge(int a,int b){
        return a+b;
    }

    void Build(int a[],vector<int>&tree,int seg_left,int seg_right,int tree_indx){
        if(seg_left==seg_right){
            tree[tree_indx] = a[seg_left];
            return;
        }
        int mid = (seg_left+seg_right)>>1;
        Build(a,tree,seg_left,mid,2*tree_indx);
        Build(a,tree,mid+1,seg_right,2*tree_indx+1);
        tree[tree_indx] = merge(tree[2*tree_indx],tree[2*tree_indx+1]);
    }

    void PointUpdate(int a[],vector<int>&tree,int seg_left,int seg_right,int tree_indx,int update_indx,int update_val){
        if(seg_left==seg_right and seg_left==update_indx){
            tree[tree_indx] = a[update_indx] = update_val;
            return;
        }
        int mid = (seg_left+seg_right)>>1;
        if(update_indx>mid){
            PointUpdate(a,tree,mid+1,seg_right,2*tree_indx+1,update_indx,update_val);
        }else{
            PointUpdate(a,tree,seg_left,mid,2*tree_indx,update_indx,update_val);
        }
        tree[tree_indx] = merge(tree[2*tree_indx],tree[2*tree_indx+1]);
    }

    void RangeUpdate(vector<int>&tree,vector<int>&lazy,int tree_indx,int seg_left,int seg_right,int update_left,int update_right,int update_val){
        if(lazy[tree_indx]>0){
            int update_val = lazy[tree_indx];
            tree[tree_indx]+=(seg_right-seg_left+1)*(update_val);
            lazy[tree_indx] =0;
            if(seg_left!=seg_right){
                lazy[2*tree_indx] +=update_val;
                lazy[2*tree_indx+1]+=update_val;
            }
        }
        if(seg_left>update_right or seg_right<update_left){
            return; 
        }
        if( update_left<=seg_left and seg_right<=update_right){
            int update = (seg_right-seg_left+1)*(update_val);
            tree[tree_indx]+=update;

            if(seg_left!=seg_right){
                lazy[2*tree_indx]+=update;
                lazy[2*tree_indx+1]+=update;
            }
            return;
        }
        int mid = (seg_left+seg_right)>>1;
        RangeUpdate(tree,lazy,2*tree_indx,seg_left,mid,update_left,update_right,update_val);
        RangeUpdate(tree,lazy,2*tree_indx+1,mid+1,seg_right,update_left,update_right,update_val);
        tree[tree_indx] = merge(tree[2*tree_indx],tree[2*tree_indx+1]);
    }

    int Query(vector<int>&tree,vector<int>&lazy,int seg_left,int seg_right,int tree_indx,int query_left,int query_right){
        if(lazy[tree_indx]>0){
            int update_val = lazy[tree_indx];
            tree[tree_indx]+=(seg_right-seg_left+1)*(update_val);
            lazy[tree_indx] =0;
            if(seg_left!=seg_right){
                lazy[2*tree_indx] +=update_val;
                lazy[2*tree_indx+1]+=update_val;
            }
        }
        if(query_left>=seg_left and query_right<=seg_right) return tree[tree_indx]; // Full overlap
        if(query_left>seg_right or query_right<seg_left)  return 0; // Return Identity elment as zero overlap
        int mid = (seg_left+seg_right)>>1;
        return merge(Query(tree,lazy,seg_left,mid,2*tree_indx,query_left,query_right),Query(tree,lazy,mid+1,seg_right,2*tree_indx+1,query_left,query_right));
    }

};

class BinarySearchUtility{
public:
    int LowerIndx(ll a[],ll e,ll n){
        if(a[n-1]<e) return -1;
        if(a[0]>=e) return 0;
        int low = 0;
        int high = n-1;
        while(high-low>1){
            ll mid = ((low+high)>>1);
            if(a[mid]>=e) high = mid;
            else low = mid;
        }
        return (a[high]>=e?high:-1);
    }

    int HigherIndx(ll a[],ll e,ll n){
        if(a[0]>e) return -1;
        if(a[n-1]<=e) return n-1;
        int low = 0;
        int high = n-1;
        while(high-low>1){
            ll mid = ((low+high)>>1);
            if(a[mid]<=e) low = mid;
            else high = mid;
        }
        return (a[low]<=e?low:-1);
    }


    pair<ll,ll> QuickLookUpInfo(ll a[],int n,ll x){
        /*
            This function returns (-1,-1)if element is not present, if the element is present in an sorted array, if present it returns a pair of indices required element, if multiple copies exist of required element this function returns (lower_occurnace, higher_occuerance) index pairs, in case of single occurance it returns (x,x) that is same index.
        */
        ll l = 0;
        ll r = n-1;
        ll ret_val = -1;
        while(r>l+1){
            ll mid = ((l+r)>>1);
            if(a[mid]==x) r = mid;
            else if(a[mid]<x) l = mid;
            else r = mid;
        }
        if(a[r]==x) ret_val = r;
        if(a[l]==x) ret_val = l;
        if(ret_val==-1) return {-1,-1};
        ll low = ret_val;
        ll high = n-1;
        while(high>low+1){
            ll mid = ((low+high)>>1);
            if(a[mid]==x) low = mid;
            else if(a[mid]>x) high = mid;
            else low = mid;
        }
        ll upper = low;
        if(a[high]==x) upper = high;
        return {ret_val,upper};
    }


};



int main(){
  FastIO;
  

  return 0;
} 

