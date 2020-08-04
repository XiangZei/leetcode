#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+9;

int G[37][37];
long long ans[37][37];
int vis[37][37];
char chr;
long long res;
int x[4] = {0,0,-1,1};
int y[4] = {-1,1,0,0};
void dfs(int i, int j){
    if(G[i][j] == -1) {

    }
    for(int i = 1; i <= 6; i++) {
        
    }
    for(int k = 0; k < 4; k++) {

    }
}
int main()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> chr;
            if (chr == '#')
            {
                G[i][j] = -1;
            }
            else
            {
                G[i][j] = 0;
            }
        }
    }
    dfs(0,0);
    cout<<res<<endl;
    return 0;
}
