# Moore’s Voting Method 


def majority_element_naive(elements):
    assert len(elements) <= 10 ** 5
    for e in elements:
        if elements.count(e) > len(elements) / 2:
            return 1

    return 0


def majority_element(elements):
    assert len(elements) <= 10 ** 5
    Cand = elements[0]
    count = 1
    for x in range(1,len(elements)):
        if(elements[x]==Cand):
            count+=1
        elif count==0:
            Cand = elements[x]
            count = 1
        else:
            count-=1
    if(elements.count(Cand)>len(elements)//2):
        return 1
    else:
        return 0



if __name__ == '__main__':
    input_n = int(input())
    input_elements = list(map(int, input().split()))
    assert len(input_elements) == input_n
    print(majority_element(input_elements))
