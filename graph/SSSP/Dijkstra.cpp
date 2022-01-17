#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define pb push_back
vector<vector<pair<int,int>>> adj(10000);
void dijkstra(){
    int m,n;
    cin>>n>>m;
    vector<int>dis(n+1,inf), parent(n+1,-1);
    
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({b,c});
        adj[b].pb({a,c});
    }
    set<pair<int,int>> pq;
    //each element has weight,node in set 
    
    pq.insert({0,1});
    dis[1]=0;
    
    while(!pq.empty()){
        int curr=pq.begin()->second;
        int d=pq.begin()->first;
        pq.erase(pq.begin());
        
        for(auto child:adj[curr]){
            if(d+child.second<dis[child.first]){
                pq.erase({dis[child.first],child.first});
                dis[child.first]=d+child.second;
                parent[child.first]=curr;
                pq.insert({dis[child.first],child.first});
            }
        }
        
    }
     // way from node-1 to node-n
    vector<int> ans;
    if (dis[n]==inf){
        cout << -1; return;
    }
    while(n!=-1){
        ans.pb(n);
        n=parent[n];
    }
    reverse(ans.begin(),ans.end());
    
    
    // 'ans' vector contain path from node-1 to node-n
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}
int main(){
    dijkstra();
    return 0;
    
}
