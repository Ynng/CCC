# Find Eulerian Tour
#
# Write a function that takes in a graph
# represented as a list of tuples
# and return a list of nodes that
# you would follow on an Eulerian Tour
#
# For example, if the input graph was
# [(1, 2), (2, 3), (3, 1)]
# A possible Eulerian tour would be [1, 2, 3, 1]

import random

def find_eulerian_tour(graph):
    # your code here
    output = []
    largestNode = 0
    for i in graph:
        if (i[0]>largestNode):
            largestNode = i[0]
        if (i[1]>largestNode):
            largestNode = i[1]
    Matrix = [[False for x in range(largestNode+1)] for y in range(largestNode+1)] 
    edgeCounts = [0 for x in range(largestNode+1)]
    for i in graph:
        Matrix[i[0]][i[1]]=True
        Matrix[i[1]][i[0]]=True
        edgeCounts[i[0]]+=1
        edgeCounts[i[1]]+=1
    
    currentNode = graph[0][0]
    recursion(Matrix, output, largestNode, currentNode, edgeCounts)
    print (output)
    return output

def recursion(Matrix, output, largestNode, currentNode, edgeCounts):
    nextNode = -1
    print(currentNode)
    print(output)
    if(edgeCounts[currentNode]==0):
            output.append(currentNode)
            return
            
    for i in range(largestNode+1):
        if(Matrix[currentNode][i]==True):
            Matrix[currentNode][i]=False
            Matrix[i][currentNode]=False
            edgeCounts[i]-=1
            edgeCounts[currentNode]-=1
            nextNode = i
            break

    recursion(Matrix, output, largestNode, nextNode, edgeCounts)
    if(edgeCounts[currentNode]!=0):
        recursion(Matrix, output, largestNode, currentNode, edgeCounts)
    else: 
        output.append(currentNode)
    return

find_eulerian_tour([(0, 1), (1, 5), (1, 7), (4, 5),
(4, 8), (1, 6), (3, 7), (5, 9),
(2, 4), (0, 4), (2, 5), (3, 6), (8, 9)])

