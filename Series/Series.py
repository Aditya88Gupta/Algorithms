
def generate(n,p,q):
    diff = q-p
    Min = 2
    while diff>Min:
        if diff%Min == 0 and diff/Min<n:
            break
        Min+=1
    List = [q]
    switch = True;
    for i in range(1,n):
        if List[i-1]-Min>=1 and switch:
            List.append(List[i-1]-Min)
        else:
            switch = False
            List.append(q+Min)
            q += Min 
    return List        
            
        
    
    
n = int(input())
p = int(input())
q = int(input())
List = generate(n,p,q)
List.sort()
for val in List:
    print(val,end=" ")