#include<bits/stdc++.h>
using namespace std;
vector<int> par(100001,-1);
vector<int> _rank(10001,1);
struct edge{
    int a,b,w;
};

int find(int a){
    if(par[a]<0) return a;
    return par[a]=find(par[a]);
}

bool compareweight(edge a,edge b){
    return (a.w<b.w);
}
void _union(int a,int b){
    a=find(a),b=find(b);
    if(a==b) return;
    if(_rank[a]>=_rank[b]){
        swap(a,b);
    }
    _rank[b]+=_rank[a];
    par[a]=b;
    return;
}
void clearDsu(int n){
    for(int i=0;i<=n;i++){
        par[i]=-1;
        _rank[i]=1;
    }
}
void kruskal(){
	int n,m;
    cin>>n>>m;
    vector<edge> adj;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj.push_back({a,b,w});
    }
    par.resize(n+1);
    _rank.resize(n+1);
    clearDsu(n);
    sort(adj.begin(), adj.end() ,compareweight);
    vector<vector<int>> mst;
    int sum=0;
    for(int i=0;i<m;i++){
        int a=find(adj[i].a),b=find(adj[i].b);
        if(a!=b){
            _union(a,b);
            sum+=adj[i].w;
            mst.push_back({adj[i].a,adj[i].b,adj[i].w});
        }
        else continue;
    }
    cout<<sum;
}
int main(){
	kruskal();
    return 0;

}
