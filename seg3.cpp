struct SegTree {
    int n;
    struct Node {
        int count;   // number of elements satisfying property in segment
        int lazy;    // pending operation (custom)
        Node(int c = 0, int lz = 0): count(c), lazy(lz) {}
    };
    vector<Node> tree;

    SegTree(int size) {
        n = size;
        tree.resize(4 * n);
    }

    void build(int node, int l, int r, vector<int> &arr, int target) {
        if (l == r) {
            tree[node].count = (arr[l] == target ? 1 : 0);
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, arr, target);
        build(node * 2 + 1, mid + 1, r, arr, target);
        tree[node].count = tree[node * 2].count + tree[node * 2 + 1].count;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0) return;
        int val = tree[node].lazy;
        tree[node].lazy = 0;
        if (l != r) {
            // propagate to children
            tree[node * 2].lazy += val;
            tree[node * 2 + 1].lazy += val;
        }
        // update current node count if lazy is set operation
        // Example: for alive/dead tracking, val = -1 (remove), set count=0
        tree[node].count = (val < 0 ? 0 : tree[node].count);
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        push(node, l, r);
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            tree[node].lazy += val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);
        tree[node].count = tree[node * 2].count + tree[node * 2 + 1].count;
    }

    int queryKth(int node, int l, int r, int k) {
        push(node, l, r);
        if (tree[node].count < k) return -1;
        if (l == r) return l;
        int mid = (l + r) / 2;
        push(node * 2, l, mid);
        if (tree[node * 2].count >= k) return queryKth(node * 2, l, mid, k);
        else return queryKth(node * 2 + 1, mid + 1, r, k - tree[node * 2].count);
    }

    // Wrappers
    void build(vector<int> &arr, int target) { build(1, 0, n - 1, arr, target); }
    void update(int l, int r, int val) { update(1, 0, n - 1, l, r, val); }
    int kth(int k) { return queryKth(1, 0, n - 1, k); }
};


/*  // works for a specific target to buid a tree i.e only 1 elemnt to be trackable

    SegTree st(n);
    st.build(arr, target);

    st.kth(0,5,2) ---> index of 2nd element target in (l,r); else returns -1

    st.update(2,5,9)    ----> setssss all ele in (2,5) = 9;

    // direct answer return, no Node

    // 0-based but not kth like 3rd is 3 only

*/
