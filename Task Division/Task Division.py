
def GetPartition(Max,n):
    Total = n-1
    Case1 = (n-Max)-1
    Case2 = (n-Max)-1
    Case3 = (n-2*Max)-1
    if Case3<0:
        Case3=0
    Total = Total - (Case1+Case2-Case3)    
    return Total

def GetCount(val):
    Max = val-2
    flag = True
    if val<=3:
        flag=False
    count=0
    while flag and val>2:
        if (val-Max)>=Max:
            count+=(GetPartition(Max-1,val-Max))*3
        else:
            count+= ((val-Max)-1)*3
        #print(Max,val-Max,count)    
        Max-=1
        if (val-Max)%2==0:
            if Max<=(val-Max)//2:
                flag = False
        else:
            if Max<=((val-Max)//2+1):
                flag = False

    return count        

def main():
    
    Cases=int(input())
    Res=[]
    for i in range(Cases):
        n = int(input())
        count = GetCount(n)
        Res.append(count)
    for val in Res:
        print(val)        

if __name__ == "__main__":
    main()    