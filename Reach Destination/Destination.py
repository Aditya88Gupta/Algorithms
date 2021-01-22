import math

def solution(List):
    
    Res = {}
    Sum = 0
    for index,val in enumerate(List):
        
        D = (1*2)-(4*1*(-val*2))
        n = (-1 + math.sqrt(abs(D)))//(2 * 1)
        Sum = n*(n+1)//2
        if Sum == val:
             Res[val] = (int(n))
        elif ((Sum+n+1)-val)==1:
            Res[val] = int(n+1+1)
        else:    
            Res[val]=(int(n)+1)  
            
    return Res         
    
Cases = int(input())
List = []
for i in range(Cases):
    List.append(int(input()))
Res = solution(List)
#print(Res)
for val in List:
    print(Res[val])