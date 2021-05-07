 unordered_map<ll,ll>frq;
    int max_diff = 0;
    ll a[n];
    for(int i =0;i<n;i++){
        int x;
        cin>>x;
        a[i] = x-i-1;
        frq[x-(i+1)]+=1;
    }
    //for(auto p : frq) cout<<p.first<<' '<<p.second<<'\n';
    for(int i =0;i<n;i++) cout<<a[i]<<" ";