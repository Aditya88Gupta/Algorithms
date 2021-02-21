
# https://leetcode.com/problems/merge-intervals/

def Merge(intervals):
        intervals.sort(key=lambda x:x[0])
        Res=[]
        i=0
        start,end=(intervals[0][0],intervals[0][1])
        while i<len(intervals)-1:
            if end>=intervals[i+1][0]:
                if end<intervals[i+1][1]:
                    end=intervals[i+1][1] 
            else:
                Res.append(list((start,end)))
                start,end=(intervals[i+1][0],intervals[i+1][1])
            i+=1  

        Res.append(list((start,end)))    
        return Res

def main():
    
    Input=[[1,3],[2,6],[8,10],[15,18]]
    print(Merge(Input))

if __name__ == "__main__":
    main()        

