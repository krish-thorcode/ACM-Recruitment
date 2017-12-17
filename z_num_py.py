test_cases = int(input())
flag1 = 0
flag2 = 0
terms = []
div = 10000000009
limit = 1000000000

if 1<test_cases<10000:
	flag1 = 1
	for i in range(0,test_cases):
		a,b,n = map(int,raw_input().split())

		if a<limit and b<limit and n<limit:
			flag2 = 1
			for j in range(0,n-1):
				c = (b + (2*a))%div
				a=b
				b=c
			terms.append(b)


if (flag1 != 0) and (flag2 != 0):
	for i in range(0,test_cases):
		print(terms[i]%div)