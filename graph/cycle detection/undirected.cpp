bool helper(int v,vector<int> adj[],vector<int> &vis,int par){
        vis[v]=1;
        for(auto child:adj[v]){
            if(vis[child]==0){
                if(helper(child,adj,vis,v)) return true;
            }
            else {if(vis[child]==1 and child!=par) return true;}
        }
        vis[v]=2;
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(100000,0);
        for (int i=0;i<V;i++){
	        if(vis[i]==0){
	            bool h=helper(i,adj,vis,-1);
	            if(h==true) return true;
	        }
	    }
	    return false;
        
    }
