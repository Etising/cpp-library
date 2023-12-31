#include <bits/stdc++.h>
using namespace std;

using graph = vector<vector<int>>;
#define affix(v, a, b) v[a].emplace_back(b)
using Graph = vector<vector<pair<int, int>>>;
#define Affix(v, a, b, c) v[a].emplace_back(make_pair(c, b))

vector<int> mi4 = {0, -1, 0, 1}, mj4 = {1, 0, -1, 0};
vector<int> mi8 = {-1, 0, 1, 1, 1, 0, -1, -1}, mj8 = {1, 1, 1, 0, -1, -1, -1, 0};
vector<int> mx4 = {1, 0, -1, 0}, my4 = {0, -1, 0, 1};
vector<int> mx8 = {1, 1, 1, 0, -1, -1, -1, 0}, my8 = {1, 0, -1, -1, -1, 0, 1, 1};

//2次元グリッドを隣接リストに変換 - O(Grid.size())
template<class T> graph grid_to_adlist(const vector<vector<T>> &Grid, int si, int sj, int ei, int ej, const vector<int> &mi, const vector<int> &mj, T restrict) {
    assert(mi.size() == mj.size());
    graph ret((ei + 1) * (ej + 1));
    rep1(i, si, ei) {
        rep1(j, sj, ej) {
            if(Grid[i][j] == restrict) continue;
            int v = (i * (ej + 1)) + j;
            rep(m, mi.size()) {
                int ni = i + mi[m], nj = j + mj[m];
                if(!(bwe(si, ni, ei) && bwe(sj, nj, ej))) continue;
                if(Grid[ni][nj] != restrict) {
                    int next = (ni * (ej + 1)) + nj;
                    ret[v].eb(next);
                }
            }
        }
    }
    return ret;
}

//辺の重みが1の時のstartから各点への距離を求める - O(N + M)
vector<int> BFS(int start, const graph &G) {
    vector<int> dist(G.size(), -1);
    queue<int> bfs;
    dist[start] = 0;
    bfs.push(start);
    while(!bfs.empty()) {
        int v = bfs.front(); bfs.pop();
        for(int next : G[v]) {
            if(dist[next] != -1)
            continue;
            dist[next] = dist[v] + 1;
            bfs.push(next);
        }
    }
    return dist;
}

vector<int> dij(int start, const Graph &G) {
    int N = G.size();
    vector<bool> hold(N, false);
    vector<int> dist(N, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push(make_pair(dist[start], start));
    while(!que.empty()) {
        int v = que.top().second; que.pop();
        if(hold[v]) continue;
        hold[v] = true;
        for(auto next : G[v]) {
            int nv = next.second;
            int cost = next.first;
            if(chmin(dist[nv], dist[v] + cost)) 
            que.push(make_pair(dist[nv], nv));
        }
    }

    for(int i = 0; i < N; i++) if(dist[i] == INF) dist[i] = -1;
    
    return dist;
}