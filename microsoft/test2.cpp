/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;
int shortestPath(vector<vector<int>>& grid, int k) {
    int ans = -1, n = 0, dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}; 
    vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), -1));
    queue<array<int, 3>> q;
    q.push({0,0,k});
    while(!q.empty()){
        if(n-- == 0) { ans++; n = q.size()-1; }
        auto [x, y, objRemain] = q.front();   q.pop();
        if( x+1 == grid.size() && y+1 == grid[0].size() ) return ans;
        if( x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() )continue;
        objRemain -= grid[x][y];
        if( vis[x][y] >= objRemain ) continue;
        vis[x][y] = objRemain;
        for(auto d: dir) q.push({x + d[0], y + d[1], objRemain});
    }
    return -1;
}
vector<vector<int>> solution(int N, int M, vector<int> &X1, vector<int> &Y1, vector<int> &X2, vector<int> &Y2){
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        a[i][j]=0;
    }
    int n=X1.size();
    for(int i=0;i<n;i++){
        for(int j=X1[i];j<=X2[i];j++){
            for(int k=Y1[i];k<=Y2[j];k++){
               a[j][k]=1; 
            }
        }
    }
    
    vector<vector<int>>grid;
    for(int i=0;i<m;i++){
        vector<int> in;
        for(int j=0;j<n;j++)
        in.push_back(a[i][j]);
        grid.push_back(in);
    }
    return grid;
}
int main()
{
    //vector<int> A={2,4,1,3,4,6,2,4,1,6};
    int n,m;
    vector<int> x1,x2,y1,y2;
    x1={2,1,4};
    y1={0,1,3};
    vector<vector<int>> grid={
        {0,0,0,1,1},
        {0,0,0,1,1},
        {1,1,1,0,0},
        {1,1,1,0,0},
        {1,1,1,0,0}
    };
    int ans=shortestPath(grid,0);
    cout<<ans;
    return 0;
}