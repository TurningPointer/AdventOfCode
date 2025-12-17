count=0
list=input().split(',')
for k in range(len(list)):
    l2=list[k].split('-')
    low=l2[0]
    high=l2[1]
    for i in range (int(low),int(high)+1):
        len1=len(str(i))
        for j in range(1,len1//2+1):
            num=len1//j
            if(str(i)[:j]*num==str(i)):
                count+=int(i)
                break
print(count)