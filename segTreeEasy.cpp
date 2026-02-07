// easy seg tree implementation 
int n;
vector<int> t;

void build(vector<int> &a){
    n = a.size();
    t.assign(2*n, 0);

    // leaves
    for(int i = 0; i < n; i++)
        t[n+i] = a[i];

    // parents
    for(int i = n-1; i > 0; i--)
        t[i] = max(t[i<<1], t[i<<1|1]);
}

void update(int p, int v){
    p += n;
    t[p] = v;
    while(p > 1){
        p >>= 1;
        t[p] = max(t[p<<1], t[p<<1|1]);
    }
}

int query(int l, int r){
    int ans = LLONG_MIN;
    l += n;
    r += n;
    while(l <= r){
        if(l & 1) ans = max(ans, t[l++]);
        if(!(r & 1)) ans = max(ans, t[r--]);
        l >>= 1;
        r >>= 1;
    }
    return ans;
}

