

# [zj]				[Q]https://zerojudge.tw/ShowProblem?problemid=g751
# [AC]

import datetime




def checkans(a):
	#





	answer_array = [4, 8, 7, 6, 3, 4, 8, 7, 6, 3,
					4, 8, 7, 6, 3, 4, 8, 7, 6, 3, 4, 8, 7, 6, 3]
	total = 0
	#獲取現在時間
	x1 = datetime.datetime.now().year
	x2 = datetime.datetime.now().month
	x3 = datetime.datetime.now().day


	def f(x: int):
		x = x % 30000
		return ((x*x)+87-int(x/3)-(x % 7)) % 48763
	def g(x: int):
		x = x % 30000
		return ((x-1)*(x+2)+(x/4)-(x % 3)) % 48763
	def q(x: int):
		x = x % 30000
		x = x+x*x+(449*x) % 48763
		return ((x % 3)+(x % 5)+(x % 7)+(x % 2)+(x % 11)+(x % 101)) % 48763
	def swap(a, b):
		return b, a
	day_lucky_number = int((f(x1)+g(x2)+q(x3)) % 48763)
	def random_swap():
		for i in range(len(answer_array)):
			seed = int((day_lucky_number+f(total)+g(total)+q(total)) % 48763)
			if (i % 3 == 0):
				seed = int(((seed+f(answer_array[i]+day_lucky_number))) % 48763)
			elif (i % 3 == 1):
				seed = int(((seed+g(answer_array[i]))) % 48763)
			elif (i % 3 == 2):
				seed = int(((seed+q(answer_array[i]))) % 48763)
			px, py = i, int((f(seed)+g(seed+day_lucky_number) +
							q(seed+day_lucky_number)) % len(answer_array))
			answer_array[px], answer_array[py] = swap(
				answer_array[px], answer_array[py])






	#
	for i in a:
		total += ord(i)
		answer_array.append(ord(i))

	total = int((f(total)+g(total)+q(total)) % 48763)
	random_swap()

	score = 0

	for i in range(len(answer_array)):
		if (i % 3 == 0):
			score = int(((score+f(answer_array[i]))) % 48763)
		elif (i % 3 == 1):
			score = int(((score+g(answer_array[i]+day_lucky_number))) % 48763)
		elif (i % 3 == 2):
			score = int(((score+q(answer_array[i]+day_lucky_number))) % 48763)

	score = round(score/487.63, 2)

	#print(f'score:{score}')
	return score


a = ""
alls=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
for i in alls:
	a=i
	if(checkans(a)>95):
		print(a)
		exit()

for i in alls:
	for j in alls:
		a=i+j
		if(checkans(a)>95):
			print(a)
			exit()


for i in alls:
	for j in alls:
		for k in alls:
			a=i+j+k
			if(checkans(a)>95):
				print(a)
				exit()




