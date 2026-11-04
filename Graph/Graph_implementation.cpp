#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:

    // Adjacency list to store graph
    // Key = Node, Value = List of its adjacent nodes
    unordered_map<int,list<int>> adj;

    void addedge(int u,int v,bool direction){

        // direction = 0 -> Undirected Graph
        // direction = 1 -> Directed Graph

        // Create an edge from node u to node v
        adj[u].push_back(v);

        // For an undirected graph, add reverse edge also
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printadjlist(){

        // Traverse each node and its adjacency list
        for(auto i : adj){

            // Print the current node
            cout << i.first << "->";

            // Print all adjacent nodes of the current node
            for(auto j : i.second){
                cout << j << ",";
            }

            cout << endl;
        }
    }
};

int main(){

    int n;
    cout << "Enter the number of nodes " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges " << endl;
    cin >> m;

    // Create a graph object
    graph g;

    // Take input for all edges
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;

        // Create an undirected edge between u and v
        g.addedge(u,v,0);
    }

    // Print the adjacency list representation
    g.printadjlist();

    return 0;
}