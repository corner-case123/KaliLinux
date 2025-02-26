## local and global scope matters in python

# while(True) :
# 	text = input("insert your text :")
# 	if text == "quit" :
# 		break 
# 	print(f"{text}")


# ctrl+C to terminate 
# num = 1 
# while num <= 1 :
# 	print(num)


orders = []

print("type quit to end order")
while (True) :
	item = input("insert your item :")
	if item == "quit" :
		break 
	orders.append(item)

print("your orders are :")
for order in orders :
	print(f"{order}")

total_ticket = int(input("total ticket you want to buy : "))


total_cost =  0 # scope matters
while (total_ticket>0) :
	age = int(input(f"age of {total_ticket}-th person: "))
	if (age < 3) :
		total_cost += 0
	elif (age>=3 and age<=12) :
		total_cost += 10
	elif (age>12 and age <=17) :
		total_cost += 12
	else  :
		total_cost += 15
	total_ticket-=1
print(f"total cost :{total_cost}")




sandwiches = ["Pastrami", "Pastrami", "BLT", "Grilled Cheese", "Turkey Sandwich", "Reuben Sandwich", "Club Sandwich"]

print("Sorry Sir,We Dont have any 'Pastrami'")
while "Pastrami" in sandwiches :
	sandwiches.remove("Pastrami")

for sandwich in sandwiches :
	print(f"sandwich {sandwich} has been made")

