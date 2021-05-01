import math
def distance(p, p2):
  return math.sqrt((p[0] - p2[0])**2 + (p[1] - p2[1])**2)

q = [9223372036854775807, 0]
p1 = [1, 0]
p2 = [1, 1]

print(distance(q, p1))
print(distance(q, p2))

print((distance(q, p2) - distance(q, p1)) > 0)