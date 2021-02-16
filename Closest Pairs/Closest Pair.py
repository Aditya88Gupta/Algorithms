from collections import namedtuple
from math import sqrt


Point = namedtuple('Point', 'x y')

def Dist(first_point, second_point):
    return (first_point.x - second_point.x) ** 2 + (first_point.y - second_point.y) ** 2
    
def ClosestSplitPair(Px,Py,delta):
    Min = float('inf')
    n = len(Px)
    mid = Px[n//2].x
    tmp=[]
    for x,y in Py:
        if x in (mid-delta,mid+delta):
            tmp.append((x,y))
    for i in range(len(tmp)-1):
        for j in range(i+1,min(7,len(tmp)-i)):
            dist = Dist(tmp[i],tmp[j])
            if dist<Min:
                Min = dist
    
    return Min


def ClosestPair(Sx,Sy):
    n = len(Sx)
    if n<=4:
        Min = float('inf')
        for i in range(n-1):
            for j in range(i+1,n):
                dist = Dist(Sx[i],Sx[j])
                if dist<Min:
                    Min = dist
                    #print(Min,Sx[i],Sx[j])
        return Min            
    Left_Min = ClosestPair(Sx[:(n//2)],Sy)
    Right_Min = ClosestPair(Sx[(n//2)+1:],Sy)
    Split_Min = ClosestSplitPair(Sx,Sy,min(Left_Min,Right_Min))
    return min(Left_Min,Right_Min,Split_Min)
    
if __name__ == '__main__':
    input_n = int(input())
    input_points = []
    for _ in range(input_n):
        x, y = map(int, input().split())
        input_point = Point(x, y)
        input_points.append(input_point)    
    Sx = input_points.copy()   
    Sy = input_points.copy()
    Sx.sort(key = lambda P:P.x)
    Sy.sort(key = lambda P:P.y)
    print("{0:.9f}".format(sqrt(ClosestPair(Sx,Sy))))
   
