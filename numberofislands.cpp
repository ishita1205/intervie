#include<iostream>
#include<vector>
using namespace std;
class Solution{
public: 
void bfs(int row,int col, vector<vector<char>>& grid,vector<vector<int>> vis)
{
    int m=grid.size();
    int n=grid[0].size();
    queue<pair<int,int>> q;
    q.push({row,col});
    
    int delrow[]={-1,1,0,0};
    int delcol[]={0,0,1,-1};

    while(!q.empty())
    {
        int currrow=q.front().first;
        int currcol=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nrow=currrow+delrow[i];
            int ncol=currcol+delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]=='1' && !vis[nrow][ncol])
            {
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});

            }
        }
    }

}   
    int numIslands(vector<vector<char>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }


        return cnt;

    }

};