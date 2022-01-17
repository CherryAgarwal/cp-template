// Time complexity- VE
// Graph shoud be direced, then only we can use bellman ford

void bellman_ford(){

	ll n,m;
	cin>>n>>m;

	vector<vector<ll>>a;
	for(ll i=0;i<m;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		a.pb({x,y,z});
	}

	vector<ll>dis(n+1,inf);
	dis[1]=0;

	ll x=-1;
	for(ll i=0;i<n;i++){
		x=-1;
    //if loop runs nth time and a single node is relaxed at that time that means there is a negative cycle
		for(ll j=0;j<m;j++){
      int a=a[j][0],b=a[j][1],w=a[j][2];
			if(dis[b]>dis[a]+w){
				dis[b]=dis[a]+w;
        
				x=1;
			}
		}
	}

	if(x==-1){
		cout<<"No cycle detected";
	}
    
    // distance array contain the minimum distance fron source to the 'ith' node.
}
