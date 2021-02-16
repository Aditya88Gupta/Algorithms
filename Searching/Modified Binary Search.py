# Modified Binary Search 
# Returns the first occurence of the key 


def GetStart(List,start,end,key,res):
    if start>end:
        if res==-1:
            return end+1
        return res
    mid=(start+end)//2
    if List[mid]==key:
        res=mid
        return GetStart(List,start,mid-1,key,res)      # If key is found, then search in the left half for first occurence  
    elif List[mid]>key:
        return GetStart(List,start,mid-1,key,res)
    return GetStart(List,mid+1,end,key,res)



def main():
    N=int(input())
    List=list(map(int,input().split()))
    key=int(input())
    Start=GetStart(List,0,N-1,key,-1)
    End=GetStart(List,0,N-1,key+1,-1)-1
    print("First Occurrence="+str(Start))
    print("Last Occurrence="+str(End))


if __name__ == "__main__":
    main()