
# in python local and global doesnot matter 
# conditionals 

stock = ["veneno","countach","huracan"]
car_req = "Veneno"
if car_req.lower() in stock :
	print(f"{car_req.title()} is in stock")
else :
	print(f"{car_req.title()} is not in stock")


bike = "kawasaki"
if bike == "kawasaki" :
	print("This bike is too expensive to import")
print(bike=="bmw")

values = [10,20,30]
#print([for value in values ])

courses= ["C++","C","Python","Java","JavaScript"]
req_courses = ["Go","Php","Java","python"]

for course in req_courses :
	if course.title() in courses :
		print(f"{course} is added to thw cart!")
	else :
		print(f"sorry we dont have {course} right now")


#########

user_name = ["admin","david","pearson","louis"]
new_users = ["admin"]

for name in user_name :
	if (name=="admin") :
		print("Welcome Sir!Would you like a Status repo?")
	else :
		print(f"welcome user {name}")
for value in range(0,4) :
	user_name.pop()
	

if not user_name :
	print("Sir we need to find some users")




###############

current_users =["bRad","nAkib","turJo","hasan","aRafat"]
new_user = ["haSan","labib"]
# list comprehension 
current_users = [user.lower() for user in current_users]
for new in new_user :
	if new.lower() not in current_users :
		print(f"user name {new} is available")
	else :
		print(f"user name {new} is already present")


digits = list(range(1,10))

for digit in digits :
	print (f"{digit}-th")


	