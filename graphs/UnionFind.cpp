#include<bits/stdc++.h>
using namespace std;

// used to check the number of connected components in a graph

class DisjointSet{
    public:
    vector<int> parent;
    vector<int> size;
    public:
    void DisjoinSet(int n){
        parent.resize(n+1);
        //initially the size each node is 1
        size.resize(n+1,1);
        for(int i=1;i<=n;i++){
            //initially node is parent to itself
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(node == parent[node]) return node; // the root
        int p = findParent(parent[node]);
        parent[node] = p;//path compression
        return p;
    }

    void UnionBySize(int a,int b){
        //find the boss parent of nodes a and b
        int bossA = findParent(a);
        int bossB = findParent(b);

        if(bossA == bossB) return; // already in same component.

        // compare the size's
        if(size[bossA] > size[bossB]){
            // comnain the tree rooted at b with a and update the parent of b.
            size[bossA]+=size[bossB];
            parent[bossB] = bossA;
        }
        else{
            size[bossB]+=size[bossA];
            parent[bossA] = bossB;
        }
    }
};

int main(){
    
    //create a directed graph
    // 1->2->3->1  4->5  6->7 8->9 10 11
    // number of components = 6
    int n = 11; // number of nodes
    vector<vector<int>> adj(n+1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(5);
    adj[6].push_back(7);
    adj[8].push_back(9);

    DisjointSet ds;
    ds.DisjoinSet(n);

    for(int i=1;i<n+1;i++){
        for(auto it: adj[i]){
            ds.UnionBySize(i,it);
        }
    }

    //count number of unique parent in the disjointset
    unordered_set<int> set;
    for(int i=1;i<ds.parent.size();i++){
        set.insert(ds.parent[i]);
    }

    cout<<"NUMBER OF COMPONENTS: "<<set.size()<<endl;
    
    return 0;


}