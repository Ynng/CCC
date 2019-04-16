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

def make_link(G, node1, node2):
    if node1 not in G:
        G[node1] = {}
    (G[node1])[node2] = 1
    if node2 not in G:
        G[node2] = {}
    (G[node2])[node1] = 1
    return G

def find_eulerian_tour(graph):
    G = {}
    for link in graph:
        make_link(G,link[0],link[1])
    
    currentNode = graph[0][0]
    recursion(Matrix, output, largestNode, currentNode, edgeCounts)
    print (output)
    return output

def recursion(G, output, currentNode):
    nextNode = -1
    if(G[currentNode]==0):
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

find_eulerian_tour([(0, 1), (1, 2), (2, 0), (2, 3), (3, 4), (4, 2), 
(4, 5), (5, 6), (6, 4), (6, 7), (7, 8), (8, 6), 
(8, 9), (9, 10), (10, 8), (10, 11), (11, 12), (12, 10), 
(12, 13), (13, 14), (14, 12), (14, 15), (15, 16), 
(16, 14), (16, 17), (17, 18), (18, 16), (18, 19), 
(19, 20), (20, 18), (20, 21), (21, 22), (22, 20), 
(22, 23), (23, 24), (24, 22), (24, 25), (25, 26), 
(26, 24), (26, 27), (27, 28), (28, 26), (28, 29), 
(29, 30), (30, 28), (30, 31), (31, 32), (32, 30), 
(32, 33), (33, 34), (34, 32), (34, 35), (35, 36), 
(36, 34), 
(36, 37), (37, 38), (38, 36), (38, 39), (39, 40), 
(40, 38), (40, 41), (41, 42), (42, 40), (42, 43), 
(43, 44), (44, 42), (44, 45), (45, 46), (46, 44), 
(46, 47), (47, 48), (48, 46), (48, 49), (49, 50), 
(50, 48), (50, 51), (51, 52), (52, 50), (52, 53), 
(53, 54), (54, 52), (54, 55), (55, 56), (56, 54), 
(56, 57), (57, 58), (58, 56), (58, 59), (59, 60), 
(60, 58), (60, 61), (61, 62), (62, 60), (62, 63), 
(63, 64), (64, 62), (64, 65), (65, 66), (66, 64), 
(66, 67), (67, 68), (68, 66), (68, 69), (69, 70), (70, 68),
(70, 71), (71, 72), (72, 70), (72, 73), (73, 74), (74, 72),
(74, 75), (75, 76), (76, 74), (76, 77), (77, 78), (78, 76),
(78, 79), (79, 80), (80, 78), (80, 81), (81, 82), (82, 80),
(82, 83), (83, 84), (84, 82), (84, 85), (85, 86), (86, 84),
(86, 87), (87, 88), (88, 86), (88, 89), (89, 90), (90, 88),
(90, 91), (91, 92), (92, 90), (92, 93), (93, 94), (94, 92),
(94, 95), (95, 96), (96, 94), (96, 97), (97, 98), (98, 96),
(98, 99), (99, 100), (100, 98)])

