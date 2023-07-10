#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    public:
        UnionFind(int n) : vertex(n), parent(n), below_size(n, 1) {
            for(int i = 0; i < n; i++) parent[i] = i;
        }

        int root(int x) {
            if(parent[x] == x) return x;
            return parent[x] = root(parent[x]);
        }

        void merge(int x, int y) {
            int x_root = root(x);
            int y_root = root(y);

            if(x_root == y_root) return;

            if(below_size[x_root] < below_size[y_root]) swap(x_root, y_root);

            parent[y_root] = x_root;
            below_size[x_root] += below_size[y_root]; 
        }

        bool same(int x, int y) {return (root(x) == root(y));}

        int size(int x) {return below_size[root(x)];}

        int cc() {
            vector<int> group_size(vertex, 0);
            for(int i = 0; i < vertex; i++) group_size[root(i)]++;
            int ret = 0;
            for(int i = 0; i < vertex; i++) if(group_size.size() > 0) ret++;

            return --ret;
        }

    private:
        int vertex;
        vector<int> parent;
        vector<int> below_size;
};  