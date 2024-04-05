#include <stdlib.h>
#include <stdio.h>


int voltageCount=0, resistorCount=0;
int nodeCount=0;

typedef struct {
    char type;
    int high;
    int low;
    double value;
} Component; 

Component** parseFile(char* fileName){
    FILE* file;
    file = fopen(fileName, "r");
    int count;
    fscanf(file, "%d\n", &count);
    Component** components=malloc(count*sizeof(Component*));

    char type;
    int high, low;
    float value;
    for(int i=0; i<count; i++){
        components[i]=malloc(sizeof(Component*));
        fscanf(file, "%c %d %d %f\n", &type, &high, &low, &value);
        if(nodeCount<high || nodeCount <low){
            nodeCount = high>low?high:low;
        }
        components[i]->type = type;
        components[i]->high = high;
        components[i]->low = low;
        components[i]->value = value;
        if(type=='V')
            voltageCount+=1;
        if(type=='R')
            resistorCount+=1;
    }
    return components;
}

typedef struct
{
    int i;
    int j;
    double** M;
} Matrix;

Matrix* initMatrix(int size_i, int size_j){
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->i=size_i;
    matrix->j=size_j;
    matrix->M=malloc(size_i*sizeof(double*));
    for(int i=0; i<size_i; i++){
        matrix->M[i]=malloc(size_j*sizeof(double));
        for(int j=0; j<size_j; j++){
            matrix->M[i][j]=0.0;
        }
    }
    return matrix;
}

void printMatrix(Matrix* A){
    for(int i=0; i< A->i; i++){
        for(int j=0; j< A->j; j++){
            printf("%.3f ", A->M[i][j]);
        }
        printf("\n");
    }
    return;
}


Matrix** calculateMatrices(Component** components, int nodeCount){
    Matrix** answer = malloc(2*sizeof(Matrix*));
    int g2Count = voltageCount;
    int matrixSize = nodeCount+g2Count;
    printf("g2:%d\nmatrix:%d\n", g2Count, matrixSize);
    Matrix* A = initMatrix(matrixSize, matrixSize);
    Matrix* b = initMatrix(matrixSize, 1);
    int g2Index = matrixSize-g2Count;
    for(int i=0; i<nodeCount; i++){
        int high = components[i]->high;
        int low = components[i]->low;
        double value = components[i]->value;
        if(components[i]->type=='R'){
            if(high!=0)
                A->M[high-1][high-1]+= 1/value;
            if(low!=0)
                A->M[low-1][low-1]+= 1/value;
            
            if(high!=0 && low!=0){
                A->M[high-1][low-1]-= 1/value;
                A->M[low-1][high-1]-= 1/value;
            }
        }
        if(components[i]->type=='V'){
            if(high!=0){
                A->M[high-1][g2Index]+=1;
                A->M[g2Index][high-1]+=1;
            }
            if(low!=0){
                A->M[low-1][g2Index]-=1;
                A->M[g2Index][low-1]-=1;
            }
            b->M[g2Index][0]=value;
            g2Index+=1;
        }
    }
    answer[0]=A;
    answer[1]=b;
    return answer;
}

void freeAll(Component** components, ){
}

void printSLAU(Matrix* A, Matrix* b){
    printMatrix(A);
    int size = A->i;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(A->M[i][j]!=0.0)
                printf("%.3f*p%d + ", A->M[i][j], j);
        }
        printf("= %.3f\n", b->M[i][0]);
    }
}


int main(){
    Component** components;
    components = parseFile("test.txt");
    printf("ParseDone\n");
    int count = voltageCount + resistorCount;
    Matrix** answer;
    answer= calculateMatrices(components, nodeCount);
    printSLAU(answer[0], answer[1]);
    return 0;
}