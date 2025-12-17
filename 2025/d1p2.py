count=0
ptr=50
try:
    while True:
        x=input()
        count+=int(x[1:])//100
        r=int(x[1:])%100
        if(x[0]=='L'):
            if ptr!=0 and (ptr-r)<=0:
                count+=1
            ptr=(ptr-r)%100
        else:
            if(ptr+r)>99:
                count+=1
            ptr=(ptr+r)%100 
except EOFError:
    pass
print(count)