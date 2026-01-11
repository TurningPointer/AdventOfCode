from math import sqrt

def distance(p1, p2):
    return sqrt((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2 + (p1[2]-p2[2])**2)

inp = """"""

points = [[int(x) for x in line.split(',')] for line in inp.strip().split('\n')]
n = len(points)
distances = []
for i in range(n):
    for j in range(i + 1, n):
        d=distance(points[i], points[j])
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

for k in range(1000):
    dist, i1, i2 = distances[k]
    union(i1, i2)
dict={}

for i in range(n):
    boss = fboss(i)
    if boss in dict:
        dict[boss]+=1
    else:
        dict[boss]=1

sizes=sorted(dict.values(), reverse=True)
print(sizes[0]*sizes[1]*sizes[2])