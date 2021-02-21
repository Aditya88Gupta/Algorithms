
# https://leetcode.com/problems/minimum-path-sum/

def PrintMat(Matrix):
    for i in range(len(Matrix)):
        for j in range(len(Matrix[0])):
            print(Matrix[i][j], end=" ")
        print()


def minPathSum(self, grid: List[List[int]]) -> int:
    n, m = (len(grid[0]), len(grid))
    for i in range(0, m):
        for j in range(0, n):
            if i == 0 and j == 0:
                continue
            elif i == 0:
                grid[i][j] += grid[i][j-1]
            elif j == 0:
                grid[i][j] += grid[i-1][j]
            else:
                if grid[i-1][j] < grid[i][j-1]:
                    grid[i][j] += grid[i-1][j]
                else:
                    grid[i][j] += grid[i][j-1]
    PrintMat(grid)                
    return grid[m-1][n-1]


def main():

    Input = [[1, 1]]
    print(minPathSum(Input))


if __name__ == "__main__":
    main()
