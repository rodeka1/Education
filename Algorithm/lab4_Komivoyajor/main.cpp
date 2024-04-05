#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <cstdint>

using namespace std;

int lengthPath(vector<vector<int>>& graph, vector<int>& answer){
    int length = 0;
    for(int i=0; i<answer.size(); i++){
        length+=graph[answer[i]][answer[(i+1)%answer.size()]];
    }
    return length;
}

void brute_force(vector<vector<int>>& graph, int& length, vector<int>& realAnswer, vector<int> answer=vector<int>(0), int v=0){
    answer.push_back(v);
    if(answer.size()!=graph.size()){
        for(int i=0; i<graph.size(); i++){
            if(find(answer.begin(), answer.end(), i)!=answer.end())
                continue;
            brute_force(graph, length, realAnswer, answer, i);
        }
    }
    else{
        int lengthP=lengthPath(graph, answer);
        if(length>lengthP){
            length=lengthP;
            realAnswer=answer;
        }
    }

}

void printPath(vector<int>& answer){
    for(int i=0; i<answer.size(); i++){
        printf("%d ", answer[i]);
    }
    printf("\n");
}



int main(int argc, char const *argv[])
{
    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> graph[i][j];
            if(i!=j)
                graph[i][j] = graph[i][j]==0 ? INT32_MAX/(n+1) : graph[i][j];
        }
    }
    vector<int> answer;
    int length = INT32_MAX;
    brute_force(graph, length, answer);
    for(int i=0; i<answer.size(); i++){
        printf("%d ", answer[i]);
    }
    printf("%d", length);
    printf("\nDone\n");
    return 0;
}