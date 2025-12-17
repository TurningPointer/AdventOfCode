sum=0
try:
    while True:
        num=int(input())
        l1=[int(n) for n in str(num)]
        l11=l1[0:len(l1)-1]
        d1=max(l11)
        idx1=l1.index(d1)
        l2=l1[(idx1+1):]
        d2=max(l2)
        nn=d2+d1*10
        sum+=nn
except EOFError:
    pass
print(sum)