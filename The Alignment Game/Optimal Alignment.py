
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


def OptimalAlignment(Str1,Str2,Matrix):
    String1,String2=("","")
    Subsquence=0
    i,j = len(Str1),len(Str2)
    while i>0 and j>0:
        if Str1[i-1]==Str2[j-1]:
            String1=Str1[i-1]+String1
            String2=Str2[j-1]+String2
            i-=1
            j-=1
            Subsquence+=1
            continue
        Min = min(Matrix[i-1][j],Matrix[i][j-1],Matrix[i-1][j-1])
        if Min==Matrix[i-1][j-1]:
            String1=Str1[i-1]+String1
            String2=Str2[j-1]+String2
            i-=1
            j-=1
        elif Min==Matrix[i][j-1]:
            String2=Str2[j-1]+String2
            String1="-"+String1
            j-=1
        else:  
            String1=Str1[i-1]+String1
            String2="-"+String2
            i-=1
    if(i!=0):
        while i>0:
            String1=Str1[i-1]+String1
            String2="-"+String2
            i-=1
    if(j!=0):
        while j>0:
            String1=Str1[i-1]+String1
            String2="-"+String2
            i-=1        
    print(String1)
    print(String2)
    return Subsquence 

def main():
    
    Str1,Str2 = list(map(str,input().split()))
    Matrix = EditDistance(Str1,Str2)
    #PrintMat(Matrix)
    num = OptimalAlignment(Str1,Str2,Matrix)
    print("Longest Common Subsequence =",num)


if __name__ == "__main__":
    main()