arr = []
size,no_of_operations = map(int,raw_input().split())
#no_of_operations = int(input())
# print size
for i in range(0,size):
	arr.append(0)
# print(arr)
for i in range(0,no_of_operations):
	a,b,k = map(int,raw_input().split())
	for j in range(a,b+1):
		arr.insert(j-1,(arr[j-1]+k))
		#arr[j-1] += k

maxx = max(arr)

if(maxx<1000000007):
	print maxx
else:
	print maxx%1000000007




