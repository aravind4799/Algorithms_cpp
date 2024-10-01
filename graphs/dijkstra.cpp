#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<pair<int,int>>> &adj,int u,int v,int weight){
    adj[u].push_back({v,weight});
}

int main(){

    vector<vector<pair<int,int>>> adj(4);
    // dijkstra fails if we have a negative edge cycle
    // dijkstra will work sometimes even if we have negative edges, but don't have a negative cycle depending on the graph.
    addEdge(adj,0,1,-7);
    addEdge(adj,0,3,-10);
    // addEdge(adj,3,1,10);
    addEdge(adj,1,2,-9);
    addEdge(adj,2,3,-5);

    vector<int> distance(4,(int)1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//min-heap
    pq.push({0,0});
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        int wt = p.first;
        int node = p.second;

        for(auto it: adj[node]){
            int adjNode = it.first;
            int adjWt = it.second;
            if(distance[adjNode] > wt+adjWt){
                distance[adjNode]=wt+adjWt;
                pq.push({distance[adjNode],adjNode});
            }
        }

    }
    cout<<"Shortest distance to reach the destination 2: "<<distance[2];
    return 0;
}