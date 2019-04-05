n = int(input())
m = 0
G = {}
for pageNum in range(n):
    m=input()
    print(m)
    for choices in range(m):
        makeLink(G,pageNum,choices)

print (G)


def makeLink(G, v1, v2):
    if v1 not in G:
        G[v1] = {}
    G[v1][v2]=True