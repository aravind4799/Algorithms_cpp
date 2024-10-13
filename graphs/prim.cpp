#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=4;
    vector<vector<pair<int,int>>> adj(n);
    //{wt,node}
    adj[0].push_back({1,1});
    adj[0].push_back({3,3});
    adj[1].push_back({1,0});
    adj[1].push_back({1,3});
    adj[1].push_back({2,2});
    adj[2].push_back({2,1});
    adj[2].push_back({4,3});
    adj[3].push_back({4,2});
    adj[3].push_back({1,1});
    adj[3].push_back({3,0});

    vector<int> visited(n,0);
    priority_queue <pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,-1}});

    int mstSum=0;
    vector<pair<int,int>> mstGraph;
    //(wt,node)

    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();

        int wt = p.first;
        int node = p.second.first;
        int parent = p.second.second;

        if(visited[node]==1) continue;

        visited[node]=1;
        mstSum+=wt;
        if(parent!=-1) mstGraph.push_back({parent,node});
        
        for(auto& [adjWeight,adjNode]: adj[node]){
            if(visited[adjNode]==0) pq.push({adjWeight,{adjNode,node}});
        }
    }

    cout<<"MST SUM: "<<mstSum<<endl;

    cout<<"MST CONTAINS THESE EDGES:"<<endl;
    for(auto it: mstGraph){
        cout<<it.first<<"-"<<it.second<<" ";
    }

    

    return 0;
}