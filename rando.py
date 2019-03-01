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
    print(largestNode)
    for i in graph:
        Matrix[i[0]][i[1]]=True
        Matrix[i[1]][i[0]]=True
    
    mostEdgeNode=0
    mostEdge = 0
    for i in range(largestNode+1):
        counter = 0
        for edge in Matrix[i]:
            if(edge==True):
                counter+=1
        if (counter>mostEdge):
            mostEdge = counter
            mostEdgeNode = i

    print ("mostEdgeNode:")
    print (mostEdgeNode)

    output.append(mostEdgeNode)
    # Matrix[graph[0][0]-1][graph[0][1]-1]=False
    # Matrix[graph[0][1]-1][graph[0][0]-1]=False
    lastNode = mostEdgeNode

    for c in range(len(graph)):
        mostEdge = 0
        mostEdgeNode = 0
        for i in range(largestNode+1):
            if(Matrix[lastNode][i]==True):
                counter = 0
                for edge in Matrix[i]:
                    if(edge==True):
                        counter+=1
                if (counter>mostEdge):
                    mostEdge = counter
                    mostEdgeNode = i
        Matrix[lastNode][mostEdgeNode]=False
        Matrix[mostEdgeNode][lastNode]=False
        output.append(mostEdgeNode)
        lastNode = mostEdgeNode
            
    
    print(Matrix)
    print(output)
    return output

find_eulerian_tour([(0, 1), (1, 5), (1, 7), (4, 5),
(4, 8), (1, 6), (3, 7), (5, 9),
(2, 4), (0, 4), (2, 5), (3, 6), (8, 9)])