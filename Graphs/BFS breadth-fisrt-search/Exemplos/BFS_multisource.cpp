#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define endl '\n'
typedef long long ll;
const int MAX = 1010;

int n, m;
char M[MAX][MAX];
bool vis[MAX][MAX];
int dist[MAX][MAX];

vector<pair<int,int>> mov  = {{-1, 0}, {1,0}, {0, -1} , {0, 1}};

bool val(pair<int, int> u){
    return u.f >= 0 and u.s >= 0 and u.f < n and u.s < m
        and M[u.f][u.s] != '#' and !vis[u.f][u.s];
}

void bfs_ms(vector<pair<int, int>> ms){
    memset (vis, 0, sizeof vis);
    memset (dist, 9999999, sizeof dist);

    queue<pair<int,int>> q;
    for(auto s : ms) q.push(s), vis[s.f][s.s] = true, dist[s.f][s.s] = 0;

    while(!q.empty()){
        pair<int,int> v = q.front(); q.pop();
        for(auto u : mov){
            u.f += v.f, u.s += v.s;
            if(val(u)){
                q.push(u); vis[u.f][u.s] = 1;
                dist[u.f][u.s] = dist[v.f][v.s];
            }
        }
    }
}

int bfs(pair<int, int> s){
    memset(vis, 0, sizeof vis);

    queue<pair<int,int>> q;
    q.push(s); vis[s.f][s.s] = 1; dist[s.f][s.s] = 0;

    while(!q.empty()){
        pair<int,int> v = q.front(); q.pop();

        if(v.f == 0 or v.s == 0 or v.f == n-1 or v.s == -1){
            return dist[v.f][v.s] + 1;
        }

        for( auto u : mov){
            u.f += v.f, u.s += v.s;

            if(val(u) and dist[v.f][v.s]+1 < dist[u.f][u.s]){
                q.push(u), vis[u.f][u.s] = 1;
                dist[u.f][u.s] +=1;
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> m >> n;
        //bfs_ms(ms)
        //bfs(s)
        vector<pair<int, int>> ms;
        pair<int, int> s;

        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
            cin >> M[i][j];
            if(M[i][j] == '*') ms.pb({i, j});
            if(M[i][j] == '@') s = {i, j};
        }
        bfs_ms(ms);
        int ans = bfs(s);
        if(ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << endl;        
    }
    return 0;
}