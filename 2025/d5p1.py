L1=[]
L2=[]

try:
    while True:
        x=input()
        if(x==''):
            break  
        else:  
            L1.append(x)
    while True:
        y=input()
        L2.append(y)
except EOFError:
    pass
count=0
for n in L2:
    for i in L1:
        if int(n)>=int(i.split('-')[0]) and int(n)<=int(i.split('-')[1]):
            count+=1
            break
print(count)
