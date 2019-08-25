#include <iostream>
#include <algorithm>

#define valid(i, j) ( 0 <= i && i < H && 0 <= j && j < L)
#define MAXH 200
#define MAXL 200
#define INFINITE 0x3F3F3F3F

using namespace std;

int grid[MAXH][MAXL];
int H, L;
bool visited[MAXH][MAXL];

int dfs(int x, int y, int v) {
    int weight = 1;
    int directions[][2] = { {0, 1},
                           {1, 0},
                           {0, -1},
                           {-1, 0} };

    visited[x][y] = true;

    for(int i=0; i<4; i++) {
        int k = x + directions[i][0];
        int l = y + directions[i][1];

        if(valid(k, l) && grid[k][l] == v && !visited[k][l])
            weight += dfs(k, l, v);
    }
    
    return weight;
}

int main() {
    int ans = INFINITE;

    // reading input
    cin >> H >> L;
    for(int i=0; i<H; i++)
        for(int j=0; j<L; j++)
            cin >> grid[i][j];
    
    // dfs in all grid
    for(int i=0; i<H; i++)
        for(int j=0; j<L; j++)
            if(!visited[i][j])
                ans =  min(ans, dfs(i, j, grid[i][j]));
    
    cout << ans << endl;

    return 0;
}