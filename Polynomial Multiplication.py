
import sys,math
sys.setrecursionlimit(10**7) # max depth of recursion

def Naive_PMUL(n,p1,p2):
    res = [0]*(2*n-1)
    for i in range(len(p1)):
        for j in range(len(p2)):
            res[i+j] = res[i+j] + p1[i]*p2[j]
    return res 


# A(x) = D1(x)*(x^(n/2)) + D0(x)
# B(x) = E1(x)*(x^(n/2)) + E0(x)
# A(x)*B(x) = (D1*E1)*(x^n) + (D1*E0 +E1*D0)*(x^(n/2)) + D0*E0
def Naive_PMUL2(n,A,B,lower_a,lower_b):
    
    #print(n)
    res = [0]*(2*n-1)
    if n==1:
        res[0] = A[lower_a] * B[lower_b]
        return res
    
    temp_1 = Naive_PMUL2(n//2,A,B,lower_a,lower_b)  # D1*E1           
    for i in range(len(temp_1)):
        res[i] += temp_1[i]      
    temp_2 = Naive_PMUL2(n//2,A,B,lower_a+(n//2),lower_b+(n//2)) # D0*E0     
    for i in range(len(temp_2)):
        res[n+i] += temp_2[i] 
    temp_3 = Naive_PMUL2(n//2,A,B,lower_a+(n//2),lower_b) # D0*E1     
    temp_4 = Naive_PMUL2(n//2,A,B,lower_a,lower_b+(n//2)) # D1*E0
    for i in range(len(temp_3)):
        res[(n//2)+i] += temp_3[i] + temp_4[i]
    return res    

# A(x)*B(x) = (D1*E1)*(x^n) + ((D1+D0)*(E1+E0)-D1*E1-D0*E0)*(x^(n/2)) + D0*E0
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

def main():
    n = int(input())
    p1 = list(map(int,input().split()))
    p2 = list(map(int,input().split()))
    print(Naive_PMUL(n,p1,p2))
    print(Wrapper(n,p1,p2))
    


if __name__ == "__main__":
    main()           