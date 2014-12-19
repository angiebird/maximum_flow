#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;
typedef int TYPE;
typedef pair<int,TYPE> ii;
typedef vector<ii> vii;
typedef vector<TYPE> vi;

int n = 15491;
vi chdLs[15491];
int v[15491];
int s = 15489;
int t = 15490;
int adj[15491][15491];

void addEdge(int from, int to){
    for(int i = 0; i < chdLs[from].size(); i++){
        if(chdLs[from][i] == to){
            return;
        }
    }
    chdLs[from].push_back(to);
}

int dfs(int from, TYPE& flow){
    v[from] = 1;
    if(from== t){
        return 1;
    }
    int find = 0;
    for(int i = 0; i < chdLs[from].size(); i++){
        int to = chdLs[from][i];
        if(!v[to]){
            int ww = min(flow, adj[from][to]);
            if(ww> 0 && dfs(to, ww)){
                find = 1;
                flow = ww;
                adj[from][to] -= flow;
                adj[to][from] += flow;
                break;
            }
        }
    }
    //v[from] = 0;
    return find;
}

int main(){
    int from;
    int to;
    TYPE cap;
    int i = 0;

    for(int i = 0; i < n; i++){
        v[i] = 0;
        for(int j = 0; j <n; j++){
            adj[i][j] = 0;
        }
    }

    double uu, vv, cc;

    while(scanf("%lf %lf %lf", &uu, &vv, &cc) == 3){
        from = (int)uu;
        to   = (int)vv;
        cap  = (int)cc;
        printf("%d %d %d\n", from, to, cap);
        adj[from][to] = cap;
        addEdge(from, to);
        addEdge(to, from);
    }

    int flow = INT_MAX;
    int mf = 0;
    printf("mf: %d\n", mf);
    while(dfs(s, flow)){
        mf += flow;
        //printf("mf: %d\n", mf);
        for(int i = 0; i < n; i++){
            v[i] = 0;
        }
    }
    printf("mf: %d\n", mf);
}
