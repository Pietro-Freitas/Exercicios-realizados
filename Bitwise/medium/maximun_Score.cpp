#include<bits/stdc++.h>
using namespace std;
 
// Solução do professor, a minha esta na pasta greedy/medium
// minha complexidade: tempo: O(n × m), espaço: O(m)
// Do professor: tempo: O(n × m), espaço: O(1)

int matrixScore(vector<vector<int>> grid) {
    int n = grid.size(), m = grid[0].size();
 
    for(int i = 0 ; i < n ; i++){
        if(grid[i][0] == 0){
            for(int j = 0 ; j < m ; j++){
                grid[i][j] ^= 1;
            }
        }
    }
 
    int ans = (1<<(m-1))*n; // Ja pega a resposta da coluna 0, caso seja um matriz 3x4, ele faz 2^3 = 8, cada linha é pelo menor o numero 8 (1 ? ? ?)multiplicada 4x, contabilizando que no minimo teria 24 como resposta até essa parte
 
    for(int j = 1 ; j < m ; j++){
        int count = 0;
        for(int i = 0 ; i < n; i++){
            count += grid[i][j]; // conta quantos 1 tem na coluna j
        }
 
        ans += (1<<(m-j-1))*max(count, n - count); // utiliza a mesma lógica anterior, mas multiplica pelo numero maximo de 1 ou de 0, n - count seria o numero de linhas totais menos oo numero  de linhas com numeros 1, resultandoo na quantidade d elinhas com o numero 0.
    }
    return ans;
}