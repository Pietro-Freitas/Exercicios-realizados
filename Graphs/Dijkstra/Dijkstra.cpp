#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

// grafo[v] = lista de {vizinho, peso}
vector<pair<int,int>> grafo[MAX];
int distanciaMinima[MAX];
bool visitado[MAX];

void dijkstra(int verticeInicial){
    // Começamos com todas as distâncias "infinitas"
    for(int i = 0; i < MAX; i++){
        distanciaMinima[i] = INT_MAX;
    }

    // Distância até o início é zero
    distanciaMinima[verticeInicial] = 0;

    // Fila de prioridade que guarda {distanciaAtual, vertice} pelo menor caminho possível
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila;

    fila.push({-0, verticeInicial});

    while(!fila.empty()){
        auto atual = fila.top();
        fila.pop();

        int distanciaAtual = atual.first;
        int vertice = atual.second;

        if(visitado[vertice]) continue;
        visitado[vertice] = true;

        // Para cada vizinho
        for(auto aresta : grafo[vertice]){
            int vizinho = aresta.first;
            int peso = aresta.second;

            // Relaxamento
            if(distanciaAtual + peso < distanciaMinima[vizinho]){
                distanciaMinima[vizinho] = distanciaAtual + peso;
                fila.push({distanciaMinima[vizinho], vizinho});
            }
        }
    }
}

int main(){
    int numeroDeVertices, numeroDeLigacoes;
    cin >> numeroDeVertices >> numeroDeLigacoes;

    for(int i = 0; i < numeroDeLigacoes; i++){
        int vertice1, vertice2, peso; 
        cin >> vertice1 >> vertice2 >> peso;

        vertice1--; vertice2--; // base 0

        grafo[vertice1].push_back({vertice2, peso});
        grafo[vertice2].push_back({vertice1, peso}); 
        // Se for direcionado, apague a linha acima
    }

    int inicio; 
    cin >> inicio;
    inicio--;
    dijkstra(inicio);
    // Mostrando resultado
    for(int i = 0; i < numeroDeVertices; i++){
        if(distanciaMinima[i] == INT_MAX){
            cout << "Distância até " << i+1 << ": inatingível" << "\n";
        } else {
            cout << "Distância até " << i+1 << ": " << distanciaMinima[i] << "\n";
        }
    }
}
