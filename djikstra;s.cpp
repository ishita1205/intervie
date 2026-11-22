#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
vector<int> shortestPath(int n, int m,vector<vector<int>> edges)
{
    vector<pair<int,int>> adj[n+1];

    for(auto it: edges)
    {
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n+1,1e9);
    vector<int> parent(n+1);
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
    }

    while(!pq.empty())
    {
        auto it=pq.top();
        int node=it.second;
        int dist=it.first;
        pq.pop();

        for(auto it: adj[node])
        {
            int adjNode=it.first;
            int edW=it.second;
            if(dist+edW< dist[adjNode])
            {
                dist[adjNode]=dist+edW;
                pq.push({dist+edW,adjNode});
                parent[adjNode]=node;
            }
        }
        
    }




}

};

