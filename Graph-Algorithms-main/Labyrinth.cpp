#include<bits/stdc++.h>
using namespace std;
#define int long long

class MazeSolver
{
private:
    int n,m;
    vector<char>path;
    vector<vector<char>>*grid;
    vector<vector<char>>*check;
    vector<vector<bool>>*visited;

    bool valid(int x,int y)
    {
        if(x<0 || x>=n || y<0 || y>=m)
        {
            return false;
        }
        if((*grid)[x][y]=='#' || (*visited)[x][y])
        {
            return false;
        }
        return true;
    }
    bool bfs(int x,int y)
    {
        queue<pair<int,int>>q;
        q.push(make_pair(x,y));
        (*visited)[x][y]=true;
        while(!q.empty())
        {
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            if((*grid)[a][b]=='B')
            {
                while(1)
                {
                    path.push_back((*check)[a][b]);
                    if(path.back()=='L')
                    {
                        b++;
                    }
                    else if(path.back()=='R')
                    {
                        b--;
                    }
                    else if(path.back()=='U')
                    {
                        a++;
                    }
                    else if(path.back()=='D')
                    {
                        a--;
                    }
                    if(a==x && b==y)
                    {
                        break;
                    }
                }
                return true;
            }
            int dx[4]={0,0,-1,1};
            int dy[4]={-1,1,0,0};
            char direction[4]={'L','R','U','D'};
            for(int i=0;i<4;++i)
            {
                int nx=a+dx[i];
                int ny=b+dy[i];
                if(valid(nx,ny))
                {
                    (*check)[nx][ny]=direction[i];
                    q.push(make_pair(nx,ny));
                    (*visited)[nx][ny]=true;
                }
            }
        }
        return false;
    }
public:
    MazeSolver(int row,int col):n(row),m(col)//constructor
    {
        grid=new vector<vector<char>>(row,vector<char>(col));
        check=new vector<vector<char>>(row,vector<char>(col,' '));
        visited=new vector<vector<bool>>(row,vector<bool>(col,false));
    }
    ~MazeSolver()//destructor
    {
        delete grid;
        delete check;
        delete visited;
    }
    void ReadMaze()
    {
        int x=0,y=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                cin>>(*grid)[i][j];
                if((*grid)[i][j]=='A')
                {
                    x=i;
                    y=j;
                }
            }
        }
        if(bfs(x,y))
        {
            cout<<"YES"<<endl;
            cout<<path.size()<<endl;
            while(!path.empty())
            {
                cout<<path.back();
                path.pop_back();
            }
        }
        else
        {
            cout<<"NO";
        }
    }
};

signed main()
{
    int n,m;
    cin>>n>>m;
    MazeSolver* maze=new MazeSolver(n,m);//dynamic memory allocation
    maze->ReadMaze();
    delete maze;
    return 0;
}