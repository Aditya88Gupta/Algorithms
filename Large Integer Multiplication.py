# This Program assumes that the integers to be multiplied have same number of digits

import sys,math
sys.setrecursionlimit(10**7) # max depth of recursion

def Fast_PMUL(n,A,B,lower_a,lower_b):
    
    #print(n)
    res = [0]*(2*n-1)
    if n==1:
        res[0] = A[lower_a] * B[lower_b]
        return res
    
    temp_1 = Fast_PMUL(n//2,A,B,lower_a,lower_b)  # D1*E1           
    for i in range(len(temp_1)):
        res[i] += temp_1[i]      
    temp_2 = Fast_PMUL(n//2,A,B,lower_a+(n//2),lower_b+(n//2)) # D0*E0     
    for i in range(len(temp_2)):
        res[n+i] += temp_2[i] 
    Temp1 = [0]*(n//2); Temp2 = [0]*(n//2)
    for i in range(n//2):
        Temp1[i] = A[lower_a+i]+A[lower_a+n//2+i]      # (D1+D0)
        Temp2[i] = B[lower_b+i]+B[lower_b+n//2+i]      # (E1+E0)   
    temp_3 = Fast_PMUL(n//2,Temp1,Temp2,0,0)    
    #print(temp_1,temp_2,temp_3)   

    for i in range(len(temp_3)):
        res[(n//2)+i] += temp_3[i]-temp_1[i]-temp_2[i]
    return res

def Wrapper(n,A,B,lower_a=0,lower_b=0):
    p = math.log(n,2)
    s = math.floor(p)
    if 2**s != n:
        for i in range(2**(s+1)-n):
            A.insert(0,0)
            B.insert(0,0)    
        temp = Fast_PMUL(2**(s+1),A,B,lower_a,lower_b)
        index=0
        for i in range(len(temp)):
            if temp[i] != 0:
                index = i
                break
        return temp[i:]    
    else:
        return Fast_PMUL(n,A,B,lower_a,lower_b)   

def ToPoly(num):
    List=[]
    while num!=0:
        List.append(num%10)
        num = num//10

    return List[::-1]

def ToInt(List):

    for i in range(len(List)-1,0,-1):
        if List[i] > 10:
            temp = (List[i] - List[i]%10)//10
            List[i] = List[i]%10
            List[i-1] += temp 
        #print(List)    
    Sum = 0
    p = len(List)-1
    for i in List:       
        Sum+= i*(10**p) 
        p-=1
    return Sum

def main():
    num1 = int(input())
    num2 = int(input())
    p1 = ToPoly(num1)
    p2 = ToPoly(num2)
    Res = Wrapper(len(p1),p1,p2)
    Res = ToInt(Res)
    print(Res)
    


if __name__ == "__main__":
    main()           