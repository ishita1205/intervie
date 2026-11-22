#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
    
    void dfs(vector<vector<int>> image, vector<vector<int>> ans,int sr,int sc,int newcolor,int inicolor,int delrow[],int delcol[])
    {
        ans[sr][sc]=newcolor;
        int m=image.size();
        int n=image[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow=sr+delrow[i];
            int ncol=sc+delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && ans[nrow][ncol]!=inicolor && image[nrow][ncol]==inicolor)
            {
                dfs(image,ans,nrow,ncol,newcolor,inicolor,delrow,delcol);
            }
            
        }



    }


public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        vector<vector<int>> ans=image;
        dfs(image,ans,sr,sc,color,inicolor,delRow,delCol);
        return ans;


    }
};