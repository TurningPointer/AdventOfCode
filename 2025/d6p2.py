l=[]
with open("/home/santoshc/Python/d6w.txt", "r") as f:
    l=f.readlines()
w=max(len(line) for line in l)
grid=[]
for line in l:
    grid.append(line.ljust(w))
cols=[]
for i in range(len(grid[0])):
    if all(line[i]==' ' for line in grid):
        continue
    else:
        col=list(line[i] for line in grid)
        cols.append(col)
buffer=[]
result=0
del(cols[-1])
for col in reversed(cols):
    buffer.append("".join(col[:-1]))
    if(col[-1]=='*'):
        ans=1
        for buff in buffer:
            ans*=int(buff)
        result+=ans
        buffer=[]
    elif(col[-1]=='+'):
        result+=sum(int(buffer[i]) for i in range(len(buffer)))
        buffer=[]
print(result) 