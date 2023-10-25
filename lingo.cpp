#include <iostream>
#include <vector>
#include <algorithm>

int fun(std::vector<std::vector<int>>& v, int i, int j, std::vector<std::vector<int>>& dp) {
    if (i < 0 || i >= v.size() || j >= v[i].size())
        return 0;
    
    if (dp[i][j] != -1)
        return dp[i][j];
    
    int a = 0, b = 0, c = 0;
    
    if (j < v[i].size() - 1 && v[i][j] < v[i][j + 1])
        a = 1 + fun(v, i, j + 1, dp);
    if (i > 0 && j < v[i].size() - 1 && v[i][j] < v[i - 1][j + 1])
        b = 1 + fun(v, i - 1, j + 1, dp);
    if (i < v.size() - 1 && j < v[i].size() - 1 && v[i][j] < v[i + 1][j + 1])
        c = 1 + fun(v, i + 1, j + 1, dp);
    
    dp[i][j] = std::max({a, b, c});
    return dp[i][j];
}

int main() {
    std::vector<std::vector<int>> grid = {
        {3,2,4},
        { 2,1,9},{1,1,7},
        };

    int rows = grid.size();
    int cols = grid[0].size();
    
    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, -1));
    
    int longestPath = 0;
    
    for (int i = 0; i < rows; i++) {
        int j=0;
            longestPath = std::max(longestPath, fun(grid, i, j, dp));
        
    }

    std::cout << "Length of the longest path: " << longestPath << std::endl;

    return 0;
}