class DisjointSet {
public:
    vector<int> size, parent;
    DisjointSet(int n) {
        size.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }
    int findupar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findupar(parent[node]);
    }
    void unionbysize(int u, int v) {
        int upar_u = findupar(u);
        int upar_v = findupar(v);
        if (upar_u == upar_v)
            return;
        if (size[upar_u] < size[upar_v]) {
            parent[upar_u] = upar_v;
            size[upar_v] += size[upar_u];
        } else {
            parent[upar_v] = upar_u;
            size[upar_u] += size[upar_v];
        }
    }
};