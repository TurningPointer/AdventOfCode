count=0
ptr=50
try:
    while True:
        x=input()
        if(x[0]=='L'):
            ptr=(ptr-int(x[1:])+100)%100
        else:
            ptr=(ptr+int(x[1:]))%100    
        if(ptr==0):
            count+=1
except EOFError:
    pass
print(count)

