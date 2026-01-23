#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define f first
#define s second
typedef pair<int, int> ii;
typedef long long ll;
const int INF = INT_MAX;
const int MAX = 1500;
char M[MAX][MAX];
bool vis[MAX][MAX];
vector<ii> mov = {{-1, 0}, {1, 0},{0,-1},{0,1}};
int n, m;

bool val(ii v){
    return v.f >= 0 and v.s >= 0 and v.f < n and v.s < m and !vis[v.f][v.s];
}

void bfs(ii s){
    queue<ii> q; q.push(s);
    vis[s.f][s.s] = true;
    ii v;
    while(!q.empty()){
        v = q.front(); q.pop();
        ii esq = v, dir = v, u = v;
        esq.s -= 1;
        dir.s += 1;
        u.f += 1;
        if(M[u.f][u.s] == '#'){
            M[esq.f][esq.s] = 'o';
            M[dir.f][dir.s] = 'o';
            if(val(esq)){
                q.push(esq);
                vis[esq.f][esq.s] = true;
            }
            if(val(dir)){
                q.push(dir);
                vis[dir.f][dir.s] = true;
            }
        }else{
            M[u.f][u.s] = 'o';
            if(val(u)){
                q.push(u);
                vis[u.f][u.s] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> M[i][j];

    for(int j = 0; j < m; j++) if(M[0][j] == 'o') bfs({0, j});

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cout << M[i][j];
            if(j == m-1) cout << endl;
    }

    return 0;
}