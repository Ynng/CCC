# Given a list of numbers, L, find a number, x, that
# minimizes the sum of the absolute value of the difference
# between each element in L and x: SUM_{i=0}^{n-1} |L[i] - x|
#
# Your code should run in Theta(n) time
#
import math


def partitioning(L, k):
    p = L[0]
    smaller = []
    larger = []
    for val in L:
        if val < p:
            smaller += [val]
        if val > p:
            larger += [val]
    print(smaller)
    print(larger)
    print(k)

    if len(larger) > k-1:
        return partitioning(larger, k)
    elif len(larger) == k-1:
        return p
    else:
        return partitioning(smaller, k-len(larger)-1)


def minimize_absolute(L):
    x = partitioning(L, math.ceil(len(L)/2.0))
    print(x)
    return x


minimize_absolute([1,2,3])
