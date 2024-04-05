#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    int size;
    int** M;
} Graph;

Graph* initGraph(char* fileName){
    Graph* graph = malloc(sizeof(Graph));
    int size;
    FILE* file = fopen(fileName, "r");
    fscanf(file, "%d\n", &size);
    graph->size=size;

    graph->M=malloc(size*sizeof(int*));
    for(int i=0; i<size; i++){
        graph->M[i]=malloc(size*sizeof(int));
        for(int j=0; j<size; j++){
            fscanf(file, "%d ", &graph->M[i][j]);
            if(graph->M[i][j]==0 && i!=j){
                graph->M[i][j]=__INT32_MAX__/(size+1); // INF
            }
        }
    }
    return graph;
}

void printGraph(Graph* graph){
    for(int i=0; i<graph->size; i++){
        for(int j=0; j<graph->size; j++){
            printf("%d ", graph->M[i][j]);
        }
        printf("\n");
    }
}

typedef struct
{
    int size;
    int i;
    int* M;
    int length;
} Path;

Path* initPath(int size){
    Path* path = malloc(sizeof(Path));
    path->size=size;
    path->M=malloc(size*sizeof(int));
    for(int i=0; i<size; i++){
        path->M[i]=-1;
    }
    path->i=0;
    path->length=0;
    return path;
}

void addPointPath(Graph* graph, Path* path, int point){
    path->M[path->i]=point;
    if(path->i!=0)
        path->length+=graph->M[path->M[path->i-1]][path->M[path->i]];
    path->i++;
}

void copyPath(Path* from, Path* to){
    for(int i=0; i<from->size; i++){
        to->M[i]=from->M[i];
    }
    to->i=from->i;
    to->length=from->length;
}

void freePath(Path* path){
    free(path->M);
    free(path);
}

void printPath(Path* path){
    for(int i=0; i<path->size; i++){
        printf("%d ", path->M[i]);
    }
    printf("\nlength: %d\ni: %d\n", path->length, path->i);
}

Path* bruteForce(Graph* graph, unsigned int mask, ...){
    Path* path;
    Path* answer;
    if(mask==0){
        answer = initPath(graph->size+1);
        answer->length=__INT32_MAX__;
        path = initPath(graph->size+1);
    }
    else{
        va_list args;
        va_start(args, mask);
        path = va_arg(args, Path*);
        answer = va_arg(args, Path*);
        va_end(args);
    }
    if(path->i==graph->size){
        addPointPath(graph, path, path->M[0]); 
        if(answer->length > path->length){
            copyPath(path, answer);
        }
    }
    else {
        for(int i=0; i<graph->size; i++){
            if((mask >> i) & 1)
                continue;
            Path* newpath=initPath(path->size);
            copyPath(path, newpath);
            addPointPath(graph, newpath, i);
            unsigned int newmask = mask | (1<<i);
            bruteForce(graph, newmask, newpath, answer);
        }
    }
    freePath(path);
    return answer;
}

void freeAll(Graph* graph, Path* path){
    for(int i=0;i<graph->size; i++){
        free(graph->M[i]);
    }
    free(graph->M);
    free(graph);
    freePath(path);
}


int main(){
    Graph* graph;
    graph = initGraph("test.txt");
    printGraph(graph);
    Path* ans = bruteForce(graph, 0);
    printPath(ans);
    freeAll(graph, ans);
    return 0;
}