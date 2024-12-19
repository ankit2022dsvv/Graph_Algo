#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
approach:
    1. use bfs to find the shortest path from 1 to n
    2. use previous array to find the path
    3. if visited[n-1]==0 then there is no path from 1 to n
    4. else print the path
*/
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>visited(n,0),previous(n,-1);
    visited[0]=1;
    queue<int>que;
    que.push(0);
    while(que.size())
    {
        int current=que.front();
        que.pop();
        for(auto& it:adj[current])
        {
            if(visited[it]==1)
            {
                continue;
            }
            que.push(it);
            visited[it]=1;
            // cout<<"print\n";
            // cout<<it<<" "<<visited[0]<<"\n";//1
            previous[it]=current;
        }
    }
    if(visited[n-1]==0)
    {
        cout<<"IMPOSSIBLE\n";
        return;
    }
    vector<int>path;
    int current=n-1;
    while(~current)
    {
        path.push_back(current);
        current=previous[current];//previous[current] is -1 if current is 0
    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<"\n";
    for(auto& it:path)
    {
        cout<<it+1<<" ";
    }
}
signed main()
{
    sol();
    return 0;
}