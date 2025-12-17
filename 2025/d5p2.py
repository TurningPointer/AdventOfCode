l=[]
try:
    while True:
        x=input()
        l.append(x.split('-'))
except EOFError:
    pass
l.sort(key= lambda y : int(y[0]))
m=[]
for low,high in l:
    if not m or int(low)>(int(m[-1][1])+1):
        m.append([int(low),int(high)])
    else:
        m[-1][1]=max(int(high),int(m[-1][1]))
count=sum(high-low+1 for low,high in m)
print(count)