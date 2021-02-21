
# https://leetcode.com/problems/unique-paths-ii/

def PrintMat(Matrix):
    for i in range(len(Matrix)):
        for j in range(len(Matrix[0])):
            print(Matrix[i][j],end=" ")
        print()

def UniquePaths2(InputGrid,m,n):
    for i in range(0,m):
        for j in range(0,n):
            if i==0 or j==0:
                if InputGrid[i][j]!=1:
                    if i==0 and j==0:
                        InputGrid[i][j]=1
                    elif i==0:
                        InputGrid[i][j]=InputGrid[i][j-1]    
                    elif j==0:
                        InputGrid[i][j]=InputGrid[i-1][j] 
                else:
                    InputGrid[i][j]=-1
            elif InputGrid[i][j]==1:
                InputGrid[i][j]=-1
    for i in range(1,m):
            for j in range(1,n):
                if InputGrid[i][j]!=-1:  
                    InputGrid[i][j]=InputGrid[i-1][j]+InputGrid[i][j-1]
                    if InputGrid[i-1][j]==-1:
                        InputGrid[i][j]+=1   
                    if InputGrid[i][j-1]==-1:
                        InputGrid[i][j]+=1              
                else: 
                    InputGrid[i][j]=0           
    #PrintMat(InputGrid)        
    if InputGrid[m-1][n-1]==-1:
        return 0                                                                                  
    return InputGrid[m-1][n-1]

def main():
    InputGrid = [[1,0]]
    m = len(InputGrid)
    n = len(InputGrid[0])
    print(UniquePaths2(InputGrid,m,n))

if __name__ == "__main__":
    main()