#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define pb push_back
#define endl '\n'
const int INF = INT_MAX;
const int MAX = 1010;
int n, m, q;

vector<int> dijkstra(vector<ii> g[MAX], vector<int> hosp){
    priority_queue<ii> pq;
    for(int amb : hosp){
        pq.push({-0, amb-1});
    }
    vector<int> dist(n, INF);
    while(!pq.empty()){
        int u = pq.top().second, w = -pq.top().first;
        pq.pop();
        if(w >= dist[u]) continue;
        dist[u] = w;
        for(auto [v, n_w] : g[u]){
            if( dist[v] > w + n_w){
                pq.push({-(w + n_w), v});
            }
        }
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    while(cin >> n >> m >> q){
        vector<int> hosp(q);
        vector<ii> g[MAX];
        for(int i = 0; i < m; i++){
            int x, y, z; cin >> x >> y >> z; x--, y--;
            g[x].pb({y, z}), g[y].pb({x, z});
        }
        for(int &i : hosp)
            cin >> i;
        vector<int> dist = dijkstra(g, hosp);
        int ans = -1;
        for(int x : dist) ans = max(ans, x);

        cout << ans << endl;
    }

    return 0;
}