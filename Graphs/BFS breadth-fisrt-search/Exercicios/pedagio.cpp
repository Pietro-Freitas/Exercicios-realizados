#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define endl '\n'
typedef long long ll;
const int MAX = 2510;
vector<int> g[MAX];
bool vis[MAX];
set<int> cidadesPossiveis;

void bfs(int inicio, int limite) {
    queue<int> fila;
    vector<int> dist(MAX, -1);

    fila.push(inicio);
    dist[inicio] = 0;
    vis[inicio] = true;
    cidadesPossiveis.insert(inicio);

    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();

        cidadesPossiveis.insert(atual);
        if (dist[atual] == limite) continue;
        for (int w : g[atual]) {
            if (!vis[w]) {
                vis[w] = true;
                dist[w] = dist[atual] + 1;
                cidadesPossiveis.insert(w);
                if (dist[w] <= limite) {
                    fila.push(w);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int c, e, l, p;
    int testes = 1;
    while(cin >> c >> e >> l >> p){
        if(c == 0 && p == 0 && e == 0 && l == 0) break;
        for(int i = 0; i < e; i++){
            int x, y; cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        //processamento
        bfs(l, p);

        //output
        cout<< "Teste " << testes << endl;
        for(int i : cidadesPossiveis) if(i != l) cout << i << ' ';
        cout << endl;
        cidadesPossiveis.clear();
        memset(vis, false, sizeof vis);
        memset(g, 0, sizeof g);
        testes++;
    }
    

    return 0;
}