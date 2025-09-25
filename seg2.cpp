struct SegTree {
    struct Node {
        int mn, mx, lazy;
        Node(int v = 0): mn(v), mx(v), lazy(0) {}
    };

    int n;
    vector<Node> tree;

    SegTree(vector<int> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, arr);
    }

    void build(int node, int l, int r, vector<int> &arr) {
        if (l == r) {
            tree[node] = Node(arr[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, arr);
        build(node * 2 + 1, mid + 1, r, arr);
        pull(node);
    }

    void apply(int node, int val) {
        tree[node].mn += val;
        tree[node].mx += val;
        tree[node].lazy += val;
    }

    void push(int node) {
        if (tree[node].lazy != 0) {
            apply(node * 2, tree[node].lazy);
            apply(node * 2 + 1, tree[node].lazy);
            tree[node].lazy = 0;
        }
    }

    void pull(int node) {
        tree[node].mn = min(tree[node * 2].mn, tree[node * 2 + 1].mn);
        tree[node].mx = max(tree[node * 2].mx, tree[node * 2 + 1].mx);
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(node, val);
            return;
        }
        push(node);
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);
        pull(node);
    }


    int queryFirst(int node, int l, int r, int ql, int qr, int x) {
        if (qr < l || r < ql) return -1;
        if (tree[node].mx < x) return -1; // no candidate here
        if (l == r) return l;             // leaf found
        push(node);
        int mid = (l + r) / 2;
        int left = queryFirst(node * 2, l, mid, ql, qr, x);
        if (left != -1) return left;
        return queryFirst(node * 2 + 1, mid + 1, r, ql, qr, x);
    }

    // wrappers
    void update(int l, int r, int val) { update(1, 0, n - 1, l, r, val); }
    int queryFirst(int l, int r, int x) { return queryFirst(1, 0, n - 1, l, r, x); }
};


/*
    SegTree st(arr);

    st.queryFirst(0,5,4) ---> index of first ele >= 4 in (l,r) else -1

    st.update(2,5,9)    ----> adds +9 to range (2,5);

    // direct answer return, no Node

*/
