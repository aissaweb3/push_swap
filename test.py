import random, os



good=[]
bad=[]

def tester(min, max):
	numbers = []
	while(len(numbers) <= max):
		i = random.randint(-1000000, 5000000) 
		if(i not in numbers):
			numbers.append(i)
	p = ' '.join(map(str, numbers))
	out = int(os.popen(f"./push_swap {p} | wc -l ").read())
	if out < 5500:
		good.append(out)
	else:
		bad.append(out)
	print(out, len(bad) / (len(good)+len(bad)) * 100, "%")
while 1:
	tester(0,499)