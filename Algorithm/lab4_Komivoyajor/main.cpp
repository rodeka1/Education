#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

vector<int> brute_force(vector<vector<int>>& graph, vector<int> answer){
    if(answer.size() + 1)
    brute_force(graph, answer);
}



int main(int argc, char const *argv[])
{
    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> graph[i][j];
            graph[i][j] = graph[i][j]==0 ? INT32_MAX : graph[i][j];
        }
    }
    vector<int> answer(1, 0);
    brute_force(graph, answer);
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << ' ';
    }
    return 0;
}