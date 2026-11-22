#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            adj[i]=graph[i];
        }
        queue<int> q;
        q.push(0);
       
        int color[V];
        for(int i=0;i<V;i++)
        {
            color[i]=-1;
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it: adj[node])
            {
                if(color[it]!=-1) //if node has not been colored, give the opposite color of the existing node
                {
                    color[it]=!color[node];
                    q.push(it);
                }
                
                    else if(color[it]==color[node])
                    {
                        return false;

                    }
                
                        
                }

            }




        }


        return true;

    }
};