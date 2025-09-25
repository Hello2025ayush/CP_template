void dfs(int node, int par){
    vis[node] = 1;
    intime[node] = lowtime[node] = timer;
    timer++;

    for(auto it : adj[node]){
        if(it == par) continue;

        if(vis[it] == 1){
            // back edge, child is a ancesstor 
            lowtime[node] = min(lowtime[node], intime[it]);
        }
        else{
            dfs(it, node);

            //exiting this edge verify 
            lowtime[node] = min(lowtime[node], lowtime[it]);

            if(lowtime[it] > intime[node]){
                // (node, it) is a bridge
                
            }
        }
    }
}
