count=0
l=input().split(',')
for k in range(len(l)):
        l2=l[k].split('-')
        low=l2[0]
        high=l2[1]
        for i in range (int(low),int(high)+1):
            l1=len(str(i))//2
            if(str(i)[:l1]==str(i)[l1:]):
                count+=int(i)
print(count)