#include <iostream>
#include <algorithm>
#include <stack>
#include <utility>

#define valid(i, j) ( 0 <= i && i < H && 0 <= j && j < L)
#define MAXH 200
#define MAXL 200
#define INFINITE 0x3F3F3F3F
#define mk(a, b) make_pair(a, b)

using namespace std;

typedef pair<int, int> pii;

int grid[MAXH][MAXL];
int H, L;
bool visited[MAXH][MAXL];

int dfs(int x, int y, int v) {
    stack<pii> stack;
    int weight = 0;
    int directions[][2] = { {0, 1},
                           {1, 0},
                           {0, -1},
                           {-1, 0} };

    stack.push(mk(x, y));

    while(!stack.empty() ) {
        pii pair = stack.top();
        stack.pop();
        x = pair.first;
        y = pair.second;

        if(!visited[x][y]) {
            visited[x][y] = true;

            for(int i=0; i<4; i++) {
                int k = x + directions[i][0];
                int l = y + directions[i][1];

                if(valid(k, l) && grid[k][l] == v && !visited[k][l])
                    stack.push(mk(k, l));
            }

            weight++;
        }
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