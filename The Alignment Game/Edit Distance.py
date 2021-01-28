
# This Program is Case Sensitive 

def EditDistance(Str1,Str2):           # O(n*m)
    Table = []
    for i in range(len(Str1)+1):
        Table.append([0]*(len(Str2)+1))
        Table[i][0]=i
    Table[0] = list(range(0,len(Str2)+1))
    for i in range(1,len(Str1)+1):
        for j in range(1,len(Str2)+1):
            if Str1[i-1]==Str2[j-1]:
                Table[i][j] = Table[i-1][j-1]
                continue
            Table[i][j] = min(Table[i-1][j],Table[i][j-1],Table[i-1][j-1])+1
    return Table


def PrintMat(Matrix):
    for i in range(len(Matrix)):
        for j in range(len(Matrix[0])):
            print(Matrix[i][j],end=" ")
        print()    

def main():
    
    Str1,Str2 = list(map(str,input().split()))
    Matrix = EditDistance(Str1,Str2)
    PrintMat(Matrix)
    Ed = Matrix[-1][-1]
    print("Edit Distance =",Ed)


if __name__ == "__main__":
    main()