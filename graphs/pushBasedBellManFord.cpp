#include <iostream>
#include <vector>
#include <climits>  // for INT_MAX

using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

void pushBasedBellmanFord(int N, vector<Edge>& edges, int source, int target) {
    vector<int> dist(N, INT_MAX);  // Distance array
    vector<int> successor(N, -1);  // Successor array
    vector<bool> updated(N, false);  // Tracks which nodes were updated in the previous iteration

    dist[target] = 0;  // Initialize the target node distance to 0
    updated[target] = true;  // Mark target as updated

    // Perform N-1 iterations, as in Bellman-Ford
    for (int i = 1; i <= N - 1; ++i) {
        bool madeUpdate = false;  // Track if any update is made in this iteration
        vector<bool> nextUpdated(N, false);  // Track updates for this iteration

        // Process all edges
        for (auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int weight = edge.weight;

            // Only consider edges where the destination node was updated in the last iteration
            if (updated[v] && dist[u] > dist[v] + weight) {
                dist[u] = dist[v] + weight;
                successor[u] = v;  // Update the successor
                nextUpdated[u] = true;  // Mark this node as updated
                madeUpdate = true;  // Update occurred
            }
        }

        // Early termination if no updates were made
        if (!madeUpdate) {
            break;
        }

        // Move current updates to the next iteration
        updated = nextUpdated;
    }

    // Output the result
    for (int i = 0; i < N; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "Node " << i << " is unreachable from target." << endl;
        } else {
            cout << "Shortest distance to node " << i << " from target: " << dist[i] << endl;
            cout << "Successor of node " << i << ": " << successor[i] << endl;
        }
    }
}

int main() {
    int n = 6;  // Number of nodes
    vector<Edge> edges;
    
    // Define the edges (u, v, weight)
    edges.push_back(Edge(3, 2, 6));
    edges.push_back(Edge(5, 3, 1));
    edges.push_back(Edge(0, 1, 5));
    edges.push_back(Edge(1, 5, -3));
    edges.push_back(Edge(1, 2, -2));
    edges.push_back(Edge(3, 4, -2));
    edges.push_back(Edge(2, 4, 3));

    int source = 0;
    int target = 4;

    pushBasedBellmanFord(n, edges, source, target);
    
    return 0;
}
