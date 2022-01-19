vector<vi> adj(100000+1);
vi top(100000+1,0),vis(100000+1,0),in(100000+1,0);
void topsort(int v){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(in[i]==0) q.push(i);
	}
	while(!q.empty()){
		int curr=q.front();		
		top.push_back(curr);
		q.pop();
		for(auto child:adj[curr]){
			in[child]--;
			if(in[child]==0) q.push(child);
		}
	}
}
void solve(){
    int m,n;
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        // adj[b].pb(a);
        in[b]++;

    }
    topsort(n);
}

//use priority queue for sorted order
