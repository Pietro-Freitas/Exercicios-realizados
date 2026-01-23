#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define endl '\n'
typedef long long ll;
const int MAX = 10e4+10;
vector<int> g[MAX];
bool vis[MAX];
bool ciclo = false;

void dfs(int v, int pai){
    vis[v] = true;

    for(int w : g[v]) if(!vis[w]){
        dfs(w, v); // v é o vértice pai de w
    }else if(w != pai) ciclo = true;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int m, n; cin >> m >> n;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y; x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }

    for(int i = 0; i < m; i++){
        if(!vis[i]){
            dfs(i, -1); // -1 não existe pois i já é o pai dele msm
        }
    }

    cout << (ciclo ? "CICLO\n" : "ACICLICO\n");

    return 0;
}