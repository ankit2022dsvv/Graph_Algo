#include<bits/stdc++.h>
using namespace std;
#define int long long
int parent[1000005],size[1000005];
vector<int>adj[1000005];
vector<int>answer;
void make_set(int v)
{
    parent[v]=v;
    size[v]=1;
}
int find_set(int v)
{
    if(v==parent[v])
    {
        return v;
    }
    return parent[v]=find_set(parent[v]);
}
void union_set(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a!=b)
    {
        if(size[a]<size[b])
        {
            swap(a,b);
        }
        parent[b]=a;
        size[a]+=size[b];
    }
}
void sol()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        make_set(i);
    }
    for(int i=0;i<m;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        union_set(u,v);
    }
    bool isBipartite=true;
    for(int i=1;i<=n;++i)
    {
        if(adj[i].size()>0)
        {
            int u=i;
            int v=adj[i][0];
            if(find_set(u)==find_set(v))
            {
                isBipartite=false;
                break;
            }
        }
    }
    if(!isBipartite)
    {
        for(int i=1;i<=n;++i)
        {
            if(size[i]==1)
            {
                answer.push_back(i);
            }
        }
        cout<<answer.size()<<"\n";
        for(auto it:answer)
        {
            cout<<it<<" ";
        }
    }
    else
    {
        cout<<"IMPOSSIBLE";
    }
}
signed main()
{
    sol();
    return 0;
}