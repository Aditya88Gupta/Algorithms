# Fractional Knapsack, Greedy Approach


def maximum_loot_value(capacity, weights, prices):
    value=0
    temp={}
    for i in range(len(prices)):
        temp[i] = (prices[i]/weights[i])     # Per unit value of each item 

    while capacity>0:
       x = max(temp, key=temp.get)           # Choose Item of Max per unit value 
       amount = min(weights[x],capacity)      
       value+= amount*temp[x]
       capacity-=amount
       temp[x]=0
    return value


if __name__ == "__main__":
    input_capacity = eval(input())
    input_weights = list(map(eval,input().split()))
    input_prices = list(map(eval,input().split()))
    opt_value = maximum_loot_value(input_capacity, input_weights, input_prices)
    print("{:.10f}".format(opt_value))
