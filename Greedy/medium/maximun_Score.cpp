/*
Algoritmo do professor na pasta bitwise/medium
minha complexidade: tempo: O(n × m), espaço: O(m)
Do professor: tempo: O(n × m), espaço: O(1)
*/
#include<bits/stdc++.h>
using namespace std;

int convertToDecimal(string number){
    int result = 0;
    for (char c : number) {
        result = result * 2 + (c - '0');
    }
    return result;
}

int matrixScore(vector<vector<int>> grid) {
    int cont = 0;
    for(int i = 0; i < grid.size(); i++){
        int first = grid[i][0];
        if(first == 0){
            for(int j= 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1) grid[i][j] = 0;
                else grid[i][j] = 1;
            }
        }
    }
    for(int j = 0; j < grid[0].size(); j++){
        int cont1 = 0; 
        int cont0 = 0;
        for(int i = 0; i < grid.size(); i++){
            cont1 += (grid[i][j] == 1 ? 1 : 0);
            cont0 += (grid[i][j] == 0 ? 1 : 0);
        }
        if(cont0 > cont1){
            for(int i = 0; i < grid.size(); i++){
                if(grid[i][j]) grid[i][j] = 0;
                else grid[i][j] = 1;
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < grid.size(); i++){
        string number = "";
        for(int j = 0; j < grid[i].size(); j++){
            number += grid[i][j] + '0';
        }
        int temp = convertToDecimal(number); // em c++ main recente é melhor int valor = stoi(number, 0, 2);, que tranforma em base binária
        ans += temp;
    }
    cout << ans << endl;
    return ans;
}

int main(){
    vector<vector<int>> grid = { {0,0,1,1}, {1,0,1,0}, {1,1,0,0} };
    
    cout << matrixScore(grid) << endl;

    return 0;
}