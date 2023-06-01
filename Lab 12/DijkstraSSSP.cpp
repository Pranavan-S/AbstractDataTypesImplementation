#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> dijkstra(vector<vector<int>>& graph, int src){
    int n =graph.size(); //number of vertices
    vector<int> distance(n, INT32_MAX); //list of shortest distances from source.
    vector<bool> visited(n,false); // storing visited info

    //ordering the vertices by their distance from source
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> vertexOrder;

    vertexOrder.push({0,src});
    distance[src] = 0; //distance of the source is 0.

    int u;
    while (!vertexOrder.empty()){

        u = vertexOrder.top().second;
        vertexOrder.pop();
        visited[u] = true;
        
        for (int v=0; v<n; v++){
            if (graph[u][v] !=0 && !visited[v]){

                // relaxing edge (u,v)
                if (distance[v] > distance[u] + graph[u][v]){
                    distance[v] = distance[u] + graph[u][v];
                }
                vertexOrder.push({distance[v],v});
            }
        }
    }
    return distance;
}
 int main(){
    vector<vector<int>> graph;
    // adjacency matrix.
    graph = {
            {0,10,0,0,15,5},
            {10,0,10,30,0,0},
            {0,10,0,12,5,0},
            {0,30,12,0,0,20},
            {15,0,5,0,0,0},
            {5,0,0,20,0,0}
            };

    int src = 3; // change src to change the source city.

    vector<int> dist = dijkstra(graph, src);

    //displaying outputs.
    cout<<"Source: "<<src<<endl;
    for (int i = 0; i< dist.size();i++){
        if (i==src){continue;}
        cout<<"The shortest time taken to reach city "<<i<<" from source: "<<dist[i]<<endl;
    }
    return 0;
 }
