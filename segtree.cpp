struct Node {
    int sum = 0;
    int maxi = LLONG_MIN;
    int mini = LLONG_MAX;
};

class Segtree {
public:
    int n;
    vector<Node> tree;
    vector<int> lazyAdd, lazySet;
    vector<bool> isSet;

    Segtree(int size) {
        n = size;
        tree.resize(4 * n);
        lazyAdd.assign(4 * n, 0);
        lazySet.assign(4 * n, 0);
        isSet.assign(4 * n, false);
    }

    void build(const vector<int>& a, int v = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        if (tl == tr) {
            tree[v].sum = tree[v].maxi = tree[v].mini = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        pull(v);
    }

    void push(int v, int tl, int tr) {
        if (isSet[v]) {
            applySet(v, lazySet[v], tl, tr);
            if (tl != tr) {
                isSet[2 * v] = isSet[2 * v + 1] = true;
                lazySet[2 * v] = lazySet[2 * v + 1] = lazySet[v];
                lazyAdd[2 * v] = lazyAdd[2 * v + 1] = 0; // clear add
            }
            isSet[v] = false;
        }
        if (lazyAdd[v] != 0) {
            applyAdd(v, lazyAdd[v], tl, tr);
            if (tl != tr) {
                lazyAdd[2 * v] += lazyAdd[v];
                lazyAdd[2 * v + 1] += lazyAdd[v];
            }
            lazyAdd[v] = 0;
        }
    }

    void applySet(int v, int val, int tl, int tr) {
        tree[v].sum = val * (tr - tl + 1);
        tree[v].maxi = tree[v].mini = val;
        lazyAdd[v] = 0; // reset addition
    }

    void applyAdd(int v, int add, int tl, int tr) {
        tree[v].sum += add * (tr - tl + 1);
        tree[v].maxi += add;
        tree[v].mini += add;
    }

    void pull(int v) {
        tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
        tree[v].maxi = max(tree[2 * v].maxi, tree[2 * v + 1].maxi);
        tree[v].mini = min(tree[2 * v].mini, tree[2 * v + 1].mini);
    }

    void rangeAdd(int l, int r, int add, int v = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        push(v, tl, tr);
        if (r < tl || tr < l) return;
        if (l <= tl && tr <= r) {
            lazyAdd[v] += add;
            push(v, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        rangeAdd(l, r, add, 2 * v, tl, tm);
        rangeAdd(l, r, add, 2 * v + 1, tm + 1, tr);
        pull(v);
    }

    void rangeAssign(int l, int r, int val, int v = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        push(v, tl, tr);
        if (r < tl || tr < l) return;
        if (l <= tl && tr <= r) {
            isSet[v] = true;
            lazySet[v] = val;
            lazyAdd[v] = 0; // clear add
            push(v, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        rangeAssign(l, r, val, 2 * v, tl, tm);
        rangeAssign(l, r, val, 2 * v + 1, tm + 1, tr);
        pull(v);
    }

    Node query(int l, int r, int v = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        push(v, tl, tr);
        if (r < tl || tr < l) return {0, LLONG_MIN, LLONG_MAX};
        if (l <= tl && tr <= r) return tree[v];
        int tm = (tl + tr) / 2;
        Node left = query(l, r, 2 * v, tl, tm);
        Node right = query(l, r, 2 * v + 1, tm + 1, tr);
        return {
            left.sum + right.sum,
            max(left.maxi, right.maxi),
            min(left.mini, right.mini)
        };
    }

/*
    segtree st(N);

    st.build(arr);

    st.rangeAdd(1, 3, 10)    --> adds
    st.rangeAssign(2, 5, 9)  --> assign

    Node ans = st.query(4, 8);

    maximum = ans.maxi
    minimum = ans.mini
    sum     = ans.sum
 */

};
