// sieve for prime factors (Spf)
const int N = 1e7;
int spf[N + 1];

void sieve() {
    for (int i = 1; i <= N; i++) spf[i] = i;
    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) { // prime
            for (int j = i * i; j <= N; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
}

// factorize k using SPF
vector<pair<int, int>> factorize(int k) {
    vector<pair<int, int>> factors;
    while (k > 1) {
        int p = spf[k];
        int cnt = 0;
        while (k % p == 0) {
            k /= p;
            cnt++;
        }
        factors.push_back({p, cnt});
    }
    return factors;
}

// TC = NloglogN build up,  log(k) each query
// ML = O(N)
// n = 2e5 --> maximum 6 prime factors lol!!
