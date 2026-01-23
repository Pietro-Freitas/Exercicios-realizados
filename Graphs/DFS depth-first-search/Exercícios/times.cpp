#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define endl '\n'
typedef long long ll;
const int MAX = 10e5 + 10;
vector<int> g[MAX];
bool vis[MAX];

void dfs(int v){
    vis[v] = true;

    for(int w : g[v]) if(!vis[w]){
        dfs(w);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y; x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }

    int times = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i);
            times++;
        }
    }
    
    cout << times << endl;

    return 0;
}