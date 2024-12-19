#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<vector<char>>grid;
vector<vector<bool>>visited;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool isValid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
    {
        return false;
    }
    if(visited[x][y]==true || grid[x][y]=='#' || ~grid[x][y]=='.')
    {
        return false;
    }
    return true;
}
void dfs(int x,int y)
{
    visited[x][y]=true;
    for(int i=0;i<4;++i)
    {
        if(isValid(x+dx[i],y+dy[i]))
        dfs(x+dx[i],y+dy[i]);
    }
}
void sol()
{
    cin>>n>>m;
    grid.resize(n,vector<char>(m));
    visited.resize(n,vector<bool>(m,false));
    int count_rooms=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(grid[i][j]=='.' && visited[i][j]==false && isValid(i,j))
            {
                dfs(i,j);
                count_rooms++;
            }
        }
    }
    cout<<count_rooms<<endl;
}
signed main()
{
    sol();
    return 0;
}