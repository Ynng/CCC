#
# Given a list of numbers, L, find a number, x, that
# minimizes the sum of the square of the difference
# between each element in L and x: SUM_{i=0}^{n-1} (L[i] - x)^2
# 
# Your code should run in Theta(n) time
# 
import math


def partitioning(L, k):
    p = L[0]
    smaller = []
    larger = []
    p_count = 0
    for val in L:
        if val < p:
            smaller += [val]
        if val > p:
            larger += [val]
        if val == p:
            p_count+=1
    print(smaller)
    print(larger)
    print(p_count)
    print(k)

    if len(larger)>k-1: return partitioning(larger, k)

    elif len(larger) + p_count > k-1:
        return p
    else:
        return partitioning(smaller, k-len(larger)-p_count)


def minimize_square(L):
    x = partitioning(L, math.ceil(len(L)/2.0))
    print(x)
    return x


minimize_square([2,2,3,4])
