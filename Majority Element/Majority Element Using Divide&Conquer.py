

def Merge(LeftHalf,RightHalf):
    if len(RightHalf[0])!=0:
        right_majority= RightHalf[0][0]
        for val in LeftHalf[1]:
            if val==right_majority:
                RightHalf[0].append(val)
                LeftHalf[1].remove(val)
    if len(LeftHalf[0])!=0:
        left_majority= LeftHalf[0][0]
        for val in RightHalf[1]:
            if val==left_majority:
                LeftHalf[0].append(val)
                RightHalf[1].remove(val)

    if len(LeftHalf[0])==0:
        RightHalf[1]+= LeftHalf[1]
        return RightHalf
    if len(RightHalf[0])==0:
        LeftHalf[1]+= RightHalf[1]
        return LeftHalf
    if LeftHalf[0][0] == RightHalf[0][0]:
        LeftHalf[0]+=RightHalf[0]
        LeftHalf[1]+=RightHalf[1]
        return LeftHalf
    if len(LeftHalf[0])>len(RightHalf[0]):
        LeftHalf[1]+= RightHalf[0]
        LeftHalf[1]+= RightHalf[1]
        return LeftHalf
    if len(LeftHalf[0])<len(RightHalf[0]):
        RightHalf[1]+= LeftHalf[0]
        RightHalf[1]+= LeftHalf[1]
        return RightHalf

    List=[[],[]]
    List[1]+= LeftHalf[0]
    List[1]+= LeftHalf[1]
    List[1]+= RightHalf[0]
    List[1]+= RightHalf[1]
    return List



def majority_element(elements):
    if len(elements)==1:
        List=[[elements[0]],[]]
        return List
    LeftHalf= majority_element(elements[:len(elements)//2])
    RightHalf= majority_element(elements[len(elements)//2:])
    #print(LeftHalf)
    #print(RightHalf)
    return Merge(LeftHalf,RightHalf)



if __name__ == '__main__':
    input_n = int(input())
    input_elements = list(map(int, input().split()))
    assert len(input_elements) == input_n
    Res = majority_element(input_elements)
    #print(Res)
    if len(Res[0])>(input_n//2):
        print(1)
    else:
        print(0)