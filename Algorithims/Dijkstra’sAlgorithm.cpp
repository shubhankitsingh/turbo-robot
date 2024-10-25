#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF=1e9; // A large value representing infinity
// Function to perform Dijkstra's algorithm
void dijkstra(int src,vector<vector<pair<int,int>>>&adj,vector<int>&dist){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dist[src]=0; // Distance to source is 0
    pq.push({0,src}); // Push the source vertex with distance 0

    while(!pq.empty()){
        int u=pq.top().second;
        int d=pq.top().first;
        pq.pop();

        if(d>dist[u]) // If the current distance is not better, continue
            continue;
        // Traverse all adjacent nodes of u
        for(auto edge:adj[u]){
            int v=edge.first;
            int weight=edge.second;

            // If there's a shorter path to v through u
            if(dist[u]+weight<dist[v]){
                dist[v]=dist[u]+weight;
                pq.push({dist[v],v}); // Push updated distance of v
            }
        }
    }
  }
int main(){
    int n=5; // Number of nodes
    vector<vector<pair<int,int>>>adj(n); // Adjacency list (node, weight)
    // Adding edges (u, v, weight)
    adj[0].push_back({1,10});
    adj[0].push_back({4,5});
    adj[1].push_back({2,1});
    adj[2].push_back({3,4});
    adj[4].push_back({1,3});
    adj[4].push_back({2,9});
    adj[4].push_back({3,2});

    vector<int>dist(n,INF); // Distance array initialized to infinity
    int src=0; // Source node

    dijkstra(src,adj,dist); // Perform Dijkstra's algorithm

    // Output shortest distances from the source
    for(int i=0;i<n;i++){
        if(dist[i]==INF)
            cout<<"Distance from node "<<src<<" to node "<<i<<": INF"<<endl;
        else
            cout<<"Distance from node "<<src<<" to node "<<i<<": "<<dist[i]<<endl;
    }

    return 0;
}
