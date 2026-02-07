// max xor of (x) among elements present in TRIE
struct Trie {
    struct Node {
        Node* nxt[2];
        int cnt;
        Node() {
            nxt[0] = nxt[1] = nullptr;
            cnt = 0;
        }
    };

    Node* root;
    Trie() { root = new Node(); }

    void insert(int x) {
        Node* cur = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (!cur->nxt[bit])
                cur->nxt[bit] = new Node();
            cur = cur->nxt[bit];
            cur->cnt++;
        }
    }

    int getMax(int x) {
        Node* cur = root;
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (cur->nxt[1 - bit]) {
                res |= (1 << i);
                cur = cur->nxt[1 - bit];
            } else if (cur->nxt[bit]) {
                cur = cur->nxt[bit];
            } else break;
        }
        return res;
    }
};
