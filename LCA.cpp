const int N = 100005; 
const int LOG = 20;   // maximum log2(N) = 20

int level[N];
int LCA[N][LOG];
vector<vector<int>> adj(N, vector<int>());


void dfs(int node, int par, int lev) {
    level[node] = lev;
    LCA[node][0] = par;     // first clm has direct par

    for (auto child : adj[node]) {
        if (child != par) {
            dfs(child, node, lev + 1);
        }
    }
}

void init(int n, int root) { 
    // set all values -1
    memset(LCA, -1, sizeof(LCA));
    memset(level, 0, sizeof(level)); 

    // initialise first clm of LCA
    dfs(root, -1, 0);

    // initialise remainig clm;
    for (int j = 1; j < LOG; j++) {  

        for (int i = 1; i <= n; i++) {  

            if (LCA[i][j - 1] != -1) {
                int par = LCA[i][j - 1];
                LCA[i][j] = LCA[par][j - 1];
            }
        }
    }
}

int getLCA(int a, int b) {

    if (a == b) return a; // already same

    // b is always depper
    if (level[a] > level[b]) swap(a, b);

    int dpt = level[b] - level[a];

    // make both EQUAL
    while (dpt > 0) {
        int jump = log2(dpt);
        b = LCA[b][jump];

        dpt -= (1LL << jump);
    }

    if (a == b) return a; // check after equalizing

    for (int i = LOG - 1; i >= 0; i--) {
        // if the 2^i th parent exist and is yes then its below LCA

        if (LCA[a][i] != -1 && LCA[a][i] != LCA[b][i]) {
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }

    // now a and b are just below LCA so return direct parent of any
    return LCA[a][0];
}
