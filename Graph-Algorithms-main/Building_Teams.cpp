#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    adj->clear();
    for(int i=0;i<m;++i)
    {
        int u,v;
        cin>>u>>v;
        //undirected graph used for bipartite graph check if it is directed then it will not work for all cases
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>team(n+1,-1);
    team.clear();
    bool isBipartite=true;
    for(int i=1;i<=n;++i)
    {
        if(team[i]==-1)
        {
            queue<int>q;
            q.push(i);
            team[i]=0;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for(auto it:adj[node])
                {
                    if(team[it]==-1)//not visited
                    {
                        team[it]=1-team[node];//assigning opposite team to it
                        q.push(it);//pushing it to queue
                    }
                    else if(team[it]==team[node])//if it is already visited and it is in same team as node
                    {
                        isBipartite=false;
                        break;
                    }
                    assert(~team[it] && team[it]!=team[node]);//if it is already visited and it is in different team as node then it should be true
                }
            }
        }
    }
    if(isBipartite)
    {
        for(int i=1;i<=n;++i)
        {
            cout<<team[i]+1<<" ";//printing team of each node
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