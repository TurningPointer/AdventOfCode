l=[]
with open("/home/santoshc/Python/d6w.txt", "r") as f:
	for line in f.readlines():
		l.append(line.split())
	op=l[-1]
	sum=0
	for i in range(len(l[0])):
		if(l[-1][i])=='*':
			ans=1
			for j in range(len(l)-1):
				ans*=int(l[j][i])
		else:
			ans=0
			for j in range(len(l)-1):
				ans+=int(l[j][i])
		sum+=ans
	print(sum) 