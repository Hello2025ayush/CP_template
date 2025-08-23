int nodes = 1;
int max_nodes = 1000005;
int arr[max_nodes][26]; // each node has a map of 26 words which stores 
                        // next node it should point to like for 'a' --> 't'
                        //                                           --> 'r'
                        //                        [a][t] stores address to 't' ka map
                        //                        [a][r] stores address to 'r' ka map
                        // for any string to start root = 0;


void init() {
    for (int i = 0; i < max_nodes; i++) {
        for (int j = 0; j < 26; j++) arr[i][j] = -1;
    }
}

void build(string &s){
    int idk = 0;
    for(auto ch : s){
        int it = ch - 'a';

        if(arr[idk][it] == -1){
            arr[idk][it] = nodes++;
            idk = arr[idk][it];
        }
        else{
            idk = arr[idk][it];
        }
    }
}

int lcp(string &s){
    int len = 0;

    int i = 0;
    for(auto ch : s){
        int it = ch - 'a';

        if(arr[i][it] == -1){
            break;
        }
        else{
            i = arr[i][it];
            len++;
        }
    }

    return len;
}
/*
    for each test case

    for(int i = 0; i <= nodes; i++){
        for(int j = 0; j < 26; j++) arr[i][j] = -1;
    }

    nodes = 1;
    
*/
