# Given an array A[] of size n, you need to find the maximum and minimum element present in the array.  
# Algorithm should make the minimum number of comparisons.

def Tournament(List):
    if len(List)==1:
        return(List[0],List[0])
    mid = len(List)//2
    LMin,LMax = Tournament(List[0:mid])
    RMin,RMax = Tournament(List[mid:len(List)])
    Min = min(LMin,RMin)
    Max = max(LMax,RMax)
    return (Min,Max)

def main():
    List = list(map(eval,input().split()))
    Min,Max = Tournament(List)
    print("Minimum element is",Min)
    print("Maximum element is",Max)

if __name__ == "__main__":
    main()