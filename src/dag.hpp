#include <bits/stdc++.h>
using namespace std;

vector<int> tplsort(const vector<vector<int>> &G) {
    int N = G.size() - 1;

    vector<int> indeg(N + 1, 0);
    for(int i = 1; i <= N; i++) for(int x : G[i]) indeg[x]++;

    queue<int> que;
    for(int i = 1; i <= N; i++) if(indeg[i] == 0) que.push(i);

    vector<int> ret;
    while(!que.empty()) {
        int v = que.front(); que.pop();
        ret.emplace_back(v);
        for(int nv : G[v]) if(!--indeg[nv]) que.push(nv);
    }

    return ret;
}

bool isdag(const vector<vector<int>> &G) {return (G.size() - 1 == tplsort(G).size());}