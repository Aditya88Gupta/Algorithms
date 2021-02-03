# Discrete Knapsack with repetitions allowed


def maximum_loot_value(capacity, weights, prices):
    Values=[0]*(capacity+1)
    for i in range(1,capacity+1):
        val=0
        for index,weight in enumerate(weights):
            if weight<=i:
                val=Values[i-weight]+prices[index]
            if val>Values[i]:
                Values[i]=val
    Max=Values[capacity]          
    items=[]            
    for index,weight in enumerate(weights):
        if prices[index]+Values[capacity-weight]==Max:
            items.append((weight,prices[index]))
    print(items)
    return Max                


if __name__ == "__main__":
    input_capacity = eval(input())
    input_weights = list(map(eval,input().split()))
    input_prices = list(map(eval,input().split()))
    opt_value = maximum_loot_value(input_capacity, input_weights, input_prices)
    print("{:.2f}".format(opt_value))
