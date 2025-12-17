sum=0
def maxi(l,start,end):
    l2=l[start:end+1]
    return max(l2),l.index(max(l2),start,end+1)

try:
    while True:
        num=int(input())
        l1=[int(n) for n in str(num)]
        idx=-1
        num1=0
        for i in range(12,0,-1):
            d,idx=maxi(l1,idx+1,len(l1)-i)
            num1=num1*10+d
            print(d,"\n")
        sum+=num1
except EOFError:
    pass
print(sum)