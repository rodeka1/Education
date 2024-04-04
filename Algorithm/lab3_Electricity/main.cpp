#include <iostream>
#include <vector>

using namespace std;

struct Edge{
    int v, u; // In Out
    bool isEds = false;
    int isDirected = 0; // -1 0 1
};

struct Node{
    int v;
    vector<Edge> Edges;
};



int main(){
    freopen("test.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<Node> Nodes(n);
    vector<Edge> Edges(m);
    for(int i=0; i<m; i++){
        int v,u, d;
        bool e;
        cin >> v >> u >> e >> d; // In Out isEds isDirected
        Edges.push_back(Edge{v,u,e,d});
        Nodes[v].Edges.push_back(Edge{v,u,e,d});
        if(d!=0)
            Nodes[u].Edges.push_back(Edge{u,v,e,d==1?-1:1});
        else
            Nodes[u].Edges.push_back(Edge{u,v,e,d});
    }
    for(int i=0; i<n; i++){
        cout << i << endl;
        for(int j=0; j<Nodes[i].Edges.size(); j++){
            printf("%d %d %d %d\n", Nodes[i].Edges[j].v, Nodes[i].Edges[j].u, Nodes[i].Edges[j].isEds, Nodes[i].Edges[j].isDirected);
        }
    }
    
    return 0;
}