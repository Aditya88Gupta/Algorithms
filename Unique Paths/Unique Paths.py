
# https://leetcode.com/problems/unique-paths/


def PrintMat(Matrix):
    for i in range(len(Matrix)):
        for j in range(len(Matrix[0])):
            print(Matrix[i][j],end=" ")
        print()

def UniquePaths(m,n):
    Table = [[0]*n]*m
    Table[0] = [1]*n
    for i in range(1,m):
        Table[i][0]=1
    for i in range(1,m):
        for j in range(1,n):
            Table[i][j]=Table[i-1][j]+Table[i][j-1] 
    #PrintMat(Table)               
    return Table[m-1][n-1]

def main():
    
    m = int(input())
    n = int(input())
    print(UniquePaths(m,n))

if __name__ == "__main__":
    main()        