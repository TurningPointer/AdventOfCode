from math import sqrt

def distance(p1, p2):
    return sqrt((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2 + (p1[2]-p2[2])**2)
data_input = """ """

points = [[int(x) for x in line.split(',')] for line in data_input.strip().split('\n')]
n = len(points)
circuits=n
distances = []
for i in range(n):
    for j in range(i + 1, n):
        d = distance(points[i], points[j])
        distances.append((d, i, j))
distances.sort()
parent = list(range(n))

def fboss(i):
    if parent[i] == i:
        return i
    parent[i] = fboss(parent[i]) 
    return parent[i]

def union(i, j):
    boss1 = fboss(i)
    boss2 = fboss(j)
    if boss1 != boss2:
        parent[boss1] = boss2
        return True
    return False
for k in range(len(distances)):
    dist, p1, p2 = distances[k]
    if(union(p1, p2)):
        circuits-=1
    if(circuits==1):
        break
print(points[p1][0]*points[p2][0])     