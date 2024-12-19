#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int>adj[100001];
vector<bool>visited(100001,false);
vector<int>head;//head of the connected components of the graph
void dfs(int node)
{
    visited[node]=true;
    for(auto child:adj[node])
    {
        if(!visited[child])
        {
            dfs(child);
        }
    }
}
void sol()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;++i)
    {
        //if the node is not visited then it is the head of the connected component of the graph
        if(!visited[i])
        {
            head.push_back(i);
            dfs(i);
        }
    }
    cout<<head.size()-1<<endl;
    for(int i=0;i<head.size()-1;++i)
    {
        cout<<head[i]<<" "<<head[i+1]<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}