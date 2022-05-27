using System;
using System.Linq;
using System.Collections.Generic;
public class Solution
{
    public int CountNegatives(int[][] grid)
    {
        int cnt = 0;
        int n = grid.Length;
        int m = grid[0].Length;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if(grid[i][j] < 0)++cnt;
        return cnt;
    }
}