#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj,vector<int>& vis,int start,stack<int>& st){
    vis[start]=0;//mark as visited
    for(auto adjNode: adj[start]){
        if(vis[adjNode]==-1){
            dfs(adj,vis,adjNode,st);
        }
    }
    // after dfs call -> push the node onto stack
    st.push(start);
}
void method1(vector<vector<int>>& adj,int n){
    //create visited array
    vector<int> vis(n,-1);
    // need a stack
    stack<int> st;
    dfs(adj,vis,0,st);
    // now pop from stack => topological ordering
    cout<<"TOPOLOGICAL ORDERING: "<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
void method2(vector<vector<int>>& adj,int n){
    int count=0;
    vector<int> inDegree(n,0);
    for(int i=0;i<adj.size();i++){
        for(auto it: adj[i]){
            inDegree[it]++;
        }
    }
    // push the node whose indegree is 0
    cout<<"TOPOLOGICAL ORDERING BY KAHN'S ALGO: "<<endl;
    queue<int> q;

    for(int i=0;i<n;i++){
        if(inDegree[i]==0){
            q.push(i);
        } 
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;
        cout<<node<<" ";

        for(auto adjNode: adj[node]){
            inDegree[adjNode]--;
            if(inDegree[adjNode]==0){
                //push the node into q if indegree becomes 0
                q.push(adjNode);
            }
        }

    }
    cout<<endl;

    if(count!=n){
        cout<<"THERE EXIST A CYCLE IN THE DIRECTED GRAPH!"<<endl;
    }
    else{
        cout<<"THERE IS NO CYCLE IN THE GIVEN DIRECTED GRAPH"<<endl;
    }


}
int main(){
    int n = 7;
    vector<vector<int>> adj(n);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(5);
    // adj[2].push_back(1);//cycle
    // adj[3].push_back(2);//cycle
    adj[3].push_back(4);
    adj[4].push_back(6);


    //method 1 :
    // using dfs -> while backtracking push the node onto stack
    // pop from stack and print => topological order

    method1(adj,n);
    

    //method 2: kahn's algo
    // 1. find indegree of each node
    // 2. push the node onto q whose indegee is 0
    // 3 .process the adj nodes and reduce indegree , if indegree becomes 0 add to the topological ordering

   // if topological ordering does not has all the n nodes - then there is cycle in the graph

    method2(adj,n);


    return 0;
}