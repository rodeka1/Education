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

void tsp(vector<vector<int>>& graph, int& length, vector<int>& realAnswer){
    int s = (1<<(graph.size()-1))-1;
    vector<vector<int>> path(s);
    vector<vector<int>> local_sum(s);
    for(int i=0; i<s; i++){
        path[i]=vector<int>(graph.size()-1, 0);
        local_sum[i]=vector<int>(graph.size()-1, -1);
    }

    int sum_path=INT32_MAX;
    for(int i; i<graph.size()-1; i++){
        int index = 1 << i;
        if (s&index != 0){
            int sum_temp=tsp_next(graph, path, local_sum, s^index, i) + graph[i][0];
            if(sum_temp < sum_path){
                sum_path=sum_temp;
                path[0][0] = i;
            }
        }
    }
    local_sum[0][0]=sum_path;

}

int tsp_next(vector<vector<int>>& graph, vector<vector<int>> path, vector<vector<int>> local_sum, int s, int v){
    if(local_sum[s][v]!=-1)
        return local_sum[s][v];
    if(s==0)
        return graph[0][v];
    int sum_path=INT32_MAX;
    for(int i=0; i<graph.size(); i++){
        int index = 1 << i;
        if(s&index!=0){
            int sum_temp=tsp_next(graph, path, local_sum, s^index, i) + graph[i][v];
            if(sum_temp < sum_path){
                sum_path=sum_temp;
                path[s][v] = i;
            }
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