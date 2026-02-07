// has better ~~O(1)  query runtime than NOrmal segTree
struct Node {
    int sum = 0;
    int maxi = LLONG_MIN;
    int mini = LLONG_MAX;
};
class Segtree {
public:
    int n, LOG;
    vector<vector<int>> mx, mn;
    vector<vector<long long>> sm;
    vector<int> lg;

    Segtree(int size) {
        n = size;
        LOG = 32 - __builtin_clz(n);
        mx.assign(LOG, vector<int>(n));
        mn.assign(LOG, vector<int>(n));
        sm.assign(LOG, vector<long long>(n));
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;
    }

    void build(const vector<int>& a) {
        for (int i = 0; i < n; i++) {
            mx[0][i] = mn[0][i] = a[i];
            sm[0][i] = a[i];
        }

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                mx[k][i] = max(mx[k - 1][i], mx[k - 1][i + (1 << (k - 1))]);
                mn[k][i] = min(mn[k - 1][i], mn[k - 1][i + (1 << (k - 1))]);
                sm[k][i] = sm[k - 1][i] + sm[k - 1][i + (1 << (k - 1))];
            }
        }
    }

    Node query(int l, int r) {
        if (l > r) return {0, LLONG_MIN, LLONG_MAX};

        int len = r - l + 1;
        int k = lg[len];

        int maximum = max(mx[k][l], mx[k][r - (1 << k) + 1]);
        int minimum = min(mn[k][l], mn[k][r - (1 << k) + 1]);

        long long sum = 0;
        while (l <= r) {
            int p = lg[r - l + 1];
            sum += sm[p][l];
            l += (1 << p);
        }

        return {sum, maximum, minimum};
    }
};

/*
    Segtree st(n);
    st.build(a);

    Node idk = st.query(l, r)   ----> 0-based

    idk.sum              ---> O(logn)

    idk.maxi/.mini    ---> O(1)   yes!!


    this shit has better runtime than that segtree template;

*/
