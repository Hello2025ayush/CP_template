// implicit / Dynamic segtree.  query = 1e5 but values upto 1e9/1e12..

struct Seg {
    struct Node {
        int v;
        Node *l, *r;
        Node() : v(-inf), l(nullptr), r(nullptr) {}
    };

    Node* root = nullptr;
    const int L = 1, R = 2000000000;

    void upd(Node* &t, int l, int r, int pos, int val) {
        if (!t) t = new Node();
        if (l == r) {
            t->v = val;
            return;
        }
        int m = (l + r) >> 1;
        if (pos <= m) upd(t->l, l, m, pos, val);
        else upd(t->r, m + 1, r, pos, val);
        t->v = max(t->l ? t->l->v : -inf,
                   t->r ? t->r->v : -inf);
    }

    int qry(Node* t, int l, int r, int ql, int qr) {
        if (!t || qr < l || r < ql) return -inf;
        if (ql <= l && r <= qr) return t->v;
        int m = (l + r) >> 1;
        return max(qry(t->l, l, m, ql, qr),
                   qry(t->r, m + 1, r, ql, qr));
    }

    // use these shit for functionality...
    void update(int pos, int val) {
        upd(root, L, R, pos, val);
    }

    int query(int l, int r) {
        return qry(root, L, R, l, r);
    }
};

/*
    Seg st;

    change R = max_range like 1e9, 1e12 etc...

    update --> log(R);
    query  --> log(R);
*/
