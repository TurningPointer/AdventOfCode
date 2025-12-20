import time 
start_time = time.perf_counter()
l=[]
with open("/home/santoshc/AdventOfCode/2025/d7inp.txt") as f:
    for line in f.readlines():
        l.append(list(line.strip('\n')))
    for i in range(len(l[0])):
        l[-1][i]=0 
for i in range(len(l)):
    for j in range(len(l[0])):
        if(l[i][j]=='S'):
            l[-1][j]=1
        if(l[i][j]=='^'):
            l[-1][j+1]+=l[-1][j]
            l[-1][j-1]+=l[-1][j]
            l[-1][j]=0
print(sum(l[-1][j] for j in range(len(l[0]))))
end_time = time.perf_counter()
execution_time = end_time - start_time
print(f"Execution time: {execution_time:.6f} seconds")