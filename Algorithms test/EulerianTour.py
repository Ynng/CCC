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
        G[node1] = set()
    (G[node1]).add(node2)
    if node2 not in G:
        G[node2] = set()
    (G[node2]).add(node1)
    return G

def find_eulerian_tour(graph):
    G = {}
    output = []
    for link in graph:
        make_link(G,link[0],link[1])

    # Making sure an eulerean tour exists
    for node in G:
        if(len(G[node])%2!=0):
            return

    recursion(G,output,graph[0][0])
    print (output)
    return output

def recursion(G, output, currentNode):
    if(len(G[currentNode])==0):
        output.append(currentNode)
        print(output)
        return

    neighborNode = random.sample(G[currentNode],1)[0]
    G[currentNode].remove(neighborNode)
    G[neighborNode].remove(currentNode)

    recursion(G,output,neighborNode)
    if(len(G[currentNode])==0):
        output.append(currentNode)
        print(output)
    else:
        recursion(G, output, currentNode)
    return

use_harder_tests = True

find_eulerian_tour([(0, 1), (1, 5), (1, 7), (4, 5),(4, 8), (1, 6), (3, 7), (5, 9),(2, 4), (0, 4), (2, 5), (3, 6), (8, 9)])