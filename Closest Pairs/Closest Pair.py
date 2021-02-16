from collections import namedtuple
from math import sqrt
from itertools import combinations


Point = namedtuple('Point', 'x y')

def Dist(first_point, second_point):
    return (first_point.x - second_point.x) ** 2 + (first_point.y - second_point.y) ** 2


def minimum_distance_squared_naive(points):
    min_distance_squared = float("inf")

    for p, q in combinations(points, 2):
        min_distance_squared = min(min_distance_squared,
                                   Dist(p, q))

    return min_distance_squared


def ClosestSplitPair(Px,delta):
    Min = delta
    n = len(Px)
    mid = Px[n//2].x
    tmp=[]
    for p in Px:
        if mid-delta<p.x and p.x<mid+delta:
            tmp.append(p)
    tmp.sort(key = lambda P:P.y)  
    if len(tmp)<8:
        return minimum_distance_squared_naive(tmp)    
    for i in range(len(tmp)-7):
        dist = minimum_distance_squared_naive(tmp[i:i+7])
        if dist<Min:
            Min = dist 

    return Min


def ClosestPair(Sx):
    n = len(Sx)
    if n<4:
        return minimum_distance_squared_naive(Sx)          
    Left_Min = ClosestPair(Sx[:(n//2)])
    Right_Min = ClosestPair(Sx[(n//2):])
    Split_Min = ClosestSplitPair(Sx,min(Left_Min,Right_Min))
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
    #Sy.sort(key = lambda P:P.y)
    print("{0:.9f}".format(sqrt(ClosestPair(Sx))))
   
