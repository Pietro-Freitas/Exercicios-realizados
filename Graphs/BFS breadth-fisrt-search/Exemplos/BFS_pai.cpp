#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define endl '\n'
typedef long long ll;
const int MAX = 1e5 +10;
vector<int> g[MAX];
bool vis[MAX];
vector<int> pai(MAX, -1);

void bfs(int s){
    queue<int> q;
    q.push(s), vis[s] = true;

    pai[s] = s;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : g[v]) if(!vis[u]){
            q.push(u), vis[u] = true;
            pai[u] = v;
        }
    }
}

vector<int> path(int v){
    vector<int> ret;
    if(!vis[v]) return ret;

    ret.pb(v);
    while(pai[v] != v){ // v != s
        v = pai[v];
        ret.pb(v);
    }

    reverse(ret.begin(), ret.end()); // inverte o vector;

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n, m; cin >> n >> m;
    
    for(int i =0; i < m; i++){
        int x, y; cin >> x >> y; x--, y--;
        g[x].pb(y), g[y].pb(x);
    }

    bfs(0);
    vector<int> ans = path(n-1);

    if(ans.size() == 0) cout << "IMPOSSIBLE";
    else{
        cout << ans.size() << endl;
        for(auto u : ans) cout << u+1 << " ";
    }

    return 0;
}