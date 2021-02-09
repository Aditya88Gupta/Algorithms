def Dist(x1,y1,x2,y2):
    return (abs(x1-x2)+abs(y1-y2))
    
def ClosestPair(Sx):
    n = len(Sx)
    if n<=4:
        Min = float('inf')
        for i in range(n-1):
            for j in range(i+1,n):
                dist = Dist(Sx[i][0],Sx[i][1],Sx[j][0],Sx[j][1])
                if dist<Min:
                    Min = dist
                    #print(Min,Sx[i],Sx[j])
        return Min            
    Left_Min = ClosestPair(Sx[:(n//2)])
    Right_Min = ClosestPair(Sx[(n//2)+1:])
    return min(Left_Min,Right_Min)
    
num = int(input())
Points = list(map(int,input().split()))
Px = [Points[x] for x in range(0,len(Points),2)]
Py = [Points[y] for y in range(1,len(Points),2)]
Sx,Sy=([],[])
for index,x in enumerate(Px):
    Sx.append((x,Py[index]))
    Sy.append((x,Py[index]))
Sx.sort(key=lambda x:x[0])
Sy.sort(key=lambda x:x[1])
#print(Sx)
#print(Sy)
print("The smallest distance is",ClosestPair(Sx))