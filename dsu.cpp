class dsuuu {
public:
    vector<int> parent, size;

    dsuuu(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            make(i);
        }
    }

    // no need to call make each time
    void make(int n) {
        parent[n] = n;
        size[n] = 1;
    }

    int find(int n) {
        if (parent[n] == n) return n;
        return parent[n] = find(parent[n]);
    }

    void uniion(int a, int b) {
        int par1 = find(a);
        int par2 = find(b);
        if (par1 != par2) {
            if (size[par1] > size[par2]) {
                parent[par2] = par1;
                size[par1] += size[par2];
            } else {
                parent[par1] = par2;
                size[par2] += size[par1];
            }
        }
    }

    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};
