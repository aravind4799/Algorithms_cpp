#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 8;
    vector<vector<int>> adj(n+1);
     // Filling adjacency list
    adj[1] = {4, 6, 7};
    adj[2] = {1, 3, 5};
    adj[3] = {5};
    adj[4] = {6, 7, 8};
    adj[5] = {1, 2, 6};
    adj[6] = {4, 7};
    adj[7] = {4, 5};
    adj[8] = {3, 5, 6};

    queue<int> q;
    vector<int> vis(n+1,0);
    vis[1]=1;
    q.push(1);

    while(!q.empty()){
        int node = q.front();
        cout<<node<<" - ";
        q.pop();

        for(auto it: adj[node]){
            if(vis[it]==0){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}