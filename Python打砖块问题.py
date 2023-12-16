class Solution:
    def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        ans = [-1]*len(hits)
        def dfs(x, y):
            if 0 <= x < m and 0 <= y < n and grid[x][y] == 1:
                grid[x][y] = 2
                ans = 1 + dfs(x + 1, y) + dfs(x - 1, y) + dfs(x, y + 1) + dfs(x, y - 1)
                return ans
            return 0
        def is_stable(x, y):
            if x == 0: return True
            if x + 1 < m and grid[x + 1][y] == 2: return True
            if x - 1 >= 0 and grid[x - 1][y] == 2: return True
            if y + 1 < n and grid[x][y + 1] == 2: return True
            if y - 1 >= 0 and grid[x][y - 1] == 2: return True
            return False
        # 模拟最终的残局
        for x, y in hits:
            grid[x][y] -= 1
        # 标记稳定砖块。 注意不标记被打掉的砖块，因此这一步需要在“模拟最终的残局”之后
        for y in range(n):
            dfs(0, y)
        # 倒推
        for i in range(len(hits) - 1, -1,-1):
            x, y = hits[i]
            grid[x][y] += 1
            # 如果不稳定，打掉也没啥影响
            if not is_stable(x, y) or grid[x][y] == 0:
                ans[i] = 0
            else:
                # 否则 dfs 计算联通图大小，这里的联通指的是值为 1。
                # 实际指的是添加了 (x,y) 砖块之后，这些值为 1 的砖块会变成稳定砖块（我们用 2 表示）
                # 由于我们是反推，因此就是移除 (x, y) 砖块之后， 这些稳定的砖块会变成不稳定（掉落）
                ans[i] = dfs(x, y) - 1
        return ans
