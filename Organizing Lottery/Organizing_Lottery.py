import operator


def GetCount(List,Map,num):
    Count=[0]*num
    temp=0
    for val,id in List:
        if id==1:
            temp+=1
        elif id==3:
            temp-=1
        else:
            Count[Map[val]]=temp
    return Count                

def points_cover(starts, ends, points):
    Map = {}
    for index,val in enumerate(points):
        Map[val]=index
    List=[(val,1) for val in starts]
    List+=[(val,2) for val in points]
    List+=[(val,3) for val in ends]
    List.sort(key=operator.itemgetter(0,1))
    return GetCount(List,Map,len(points))


def main():
    data = list(map(int, input().split()))
    n, m = data[0], data[1]
    input_starts=[]
    input_ends=[]
    for i in range(n):
        start,end=list(map(int, input().split()))
        input_starts.append(start)
        input_ends.append(end)
    input_points = list(map(int, input().split()))
    output = points_cover(input_starts, input_ends, input_points)
    [print(val,end=" ") for val in output] 

if __name__ == "__main__":
    main()