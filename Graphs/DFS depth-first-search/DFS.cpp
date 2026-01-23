#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+10;
vector<int> grafo[MAX];
bool visitado[MAX];

void dfs(int vertice){
    visitado[vertice] = true;
    for(auto vizinho : grafo[vertice]){
        if(visitado[vizinho] == false){
            dfs(vizinho);
        }
    }
}

int main(){
    int numeroDeVertices, numeroDeLigações; cin >> numeroDeVertices >> numeroDeLigações;
    for(int i = 0; i < numeroDeLigações; i++){
        int  vertice1, vertice2; cin >> vertice1 >> vertice2;
        vertice1--;vertice2--; //coloca indices na base 0
        grafo[vertice1].push_back(vertice2);
        grafo[vertice2].push_back(vertice1);
    }

    int conexões = 0;
    for(int i = 0; i < numeroDeVertices; i++){
        if(visitado[i] == false){
            dfs(i);
            conexões++;
        }
    }
}