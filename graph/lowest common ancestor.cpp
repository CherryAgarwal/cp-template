#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj(100001);
int n,maxN;
vector<vector<int>> lca( 100001 , vector<int> (16, -1));
vector<int> level(100001);

void dfs(int node,int lvl,int par){
    level[node]=lvl;
    lca[node][0]=par;
    for(auto child:adj[node]){
        if(child!=par){
            dfs(child,lvl+1,node);
        }
    }
}
void init(int n,int maxN){
    dfs(0,0,-1);
    for(int j=1;j<=maxN;j++){
        for(int i=0;i<n;i++){
            if(lca[i][j-1]!=-1){
                int par=lca[i][j-1];
                lca[i][j]=lca[par][j-1];
            }
        }
    }
}

int lowestans(int a,int b){
    if(level[a]>level[b]) swap(a,b);
    int d=level[b]-level[a];
    while(d>0){
        int i=log2(d);
        b=lca[b][i];
        d-=(1<<i);
    }
    if(a==b) return a;
    for(int i=maxN;i>=0;i--){
        if(lca[a][i]!=-1 && lca[a][i]!=lca[b][i])
            a=lca[a][i],b=lca[b][i];
    }
    return lca[a][0];
}

int main(){
    
    int m;
    cin>>n;
    maxN=log2(n);
    
    for(int i=1;i<n;i++){
        int a;
        cin>>a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    init(n,maxN);

    cin>>m;
    int lca;
    int x,y;
    cin>>x>>y;
    lca=lowestans(x, y);
    m=m-2;
    while(m--){
        int a;
        cin>>a;
        lca=lowestans(a, lca);    
    }
    cout<<lca;
    return 0;
}
