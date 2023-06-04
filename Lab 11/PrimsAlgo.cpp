#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void prim(vector<vector<int>> graph, int src){

    int n = graph.size(); //number of vertices.

    //give more priority to edges with low cost.
    priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> edge_order;
    
    //track the visited vertices.
    vector<bool> visited(n,false);

    //number of visited vertices.
    int visited_count = 0;

    int edge_cost;

    int cost = 0;//MST cost
    

    int u = src;

    vector<int> min_edge; // temporary container for minimum cost edge.

    while(visited_count<n){
        //adding the edges of current vertex to the priority queue
        //so we can find minimum weighted edge.
        for (int i=0;i<n;i++){
            if (graph[u][i]!=0 && !visited[i] ){
                edge_order.push({graph[u][i],{u,i}}); 
            }
        }

        //set visited flag for the finished vertex
        visited[u] = true;
        visited_count++;
        
        //edge with minimum weight.
        min_edge = edge_order.top().second;
        u = min_edge[1];
        edge_order.pop(); 

        //adding cost and printing predecessor
        if (!visited[min_edge[1]]){

            edge_cost = graph[min_edge[0]][min_edge[1]];
            cost += graph[min_edge[0]][min_edge[1]];

            cout<<min_edge[0]<<" -> "<<min_edge[1]<<" = "<<edge_cost<<endl;
        }
             
    }
    cout<<"Cost of the Minimum spanning tree: "<<cost<<endl;
}

int main(){
    vector<vector<int>> graph;
    //graph representation using adjacency matrix.
    graph = {
            {0,3,0,0,0,1},
            {3,0,2,1,10,0},
            {0,2,0,3,0,5},
            {0,1,3,0,5,0},
            {0,10,0,5,0,4},
            {1,0,5,0,4,0}
            };

    //source vertex.        
    int src = 0;
    prim(graph,src);
    return 0;
}