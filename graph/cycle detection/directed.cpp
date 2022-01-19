bool dfs(int v,vector<int> adj[],vector<int> &vis){
        vis[v]=1;
        for(auto child:adj[v]){
            if(vis[child]==0){
                if (dfs(child,adj,vis)) return true;}
                
            else 
               { if (vis[child]==1){  return true;}}
            
        }
        vis[v]=2;
        return false;
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(100001,0);
        int ok=0;
        for(int i=0;i<V;i++){
        if(vis[i]==0 and dfs(i,adj,vis)){
            // cycle detected
            ok=1; break;
        }
    }

        return ok;
    }
