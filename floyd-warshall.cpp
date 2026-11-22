#include<iostream>
#include<vector>
using namespace std;
void floydWarshall(vector<vector<int>> &dist)
{
    int V=dist.size();
    int INF=1e8;
    for(int i=0;i<V;i++)///each intermediat vertex;
    {
        for(int j=0;j<V;j++) //pick all vertices as destinatin
        {
            for(int k=0;k<V;k++) 
            {
                if(dist[j][i]!=INF && dist[i][k]!=INF)
                {
                    dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
                }


            }
        }

    }


}