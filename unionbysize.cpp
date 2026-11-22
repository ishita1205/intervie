#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> parent,size;
    int findUPar(int node)
    {
        if(parent[node]==node)
        {
            return node;
        }

        return parent[node]=findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        u=findUPar(u);
        v=findUpar(v);

        if(u==v) return;
        if(size[u]<size[v])
        {
            parent[u]=v;
            size[v]=size[v]+size[u];
        }
        else{
            parent[v]=u;
            size[u]+=size[v];

        }



    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &edge : connections) {
            unionBySize(edge[0], edge[1]);
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (findUPar(i) == i)
                components++;
        }

        return components - 1;
        
    }
};