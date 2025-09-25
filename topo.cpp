vector<int> ans;
bool kahn(int n){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0) q.push(i);
    }

    while(q.size() != 0){
        int node = q.front();
        q.pop();

        ans.pb(node);

        for(auto it : adj[node]){
            indeg[it]--;
            if(indeg[it] == 0) q.push(it);
        }
    }

    return (ans.size() == n);
}
