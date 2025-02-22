
def  describe_pet(pet_type,pet_name) :
	"""describes a pet"""  # doc-string
	print(f"my {pet_type}'s name is {pet_name}")

# position arguments - order matters
describe_pet("cat","harry") 

# keyword arguments - order does not matter --> explicit
describe_pet(pet_name="harry",pet_type="cat")


#default value --> must be defined in right side
def describe_pet(pet_name,pet_type="dog") :
	print(f"my {pet_type}'s name is {pet_name}")

describe_pet("willie") # positional argument

#dont mix positional and keyword argument 


# optional argument 
# optional value --> string : "" , int : None 
def full_name(first_name,last_name,middle_name="",age=None) :
	if middle_name :
		print(f"{first_name} {middle_name} {last_name}")
	else :
		print(f"{first_name} {last_name}")

full_name("John","Wick") # middle_name optional 



# task

def make_player(player_name,strong_foot,age,nation="") :
	player = {
		"player name":player_name ,
		"strong foot":strong_foot ,
		"age":age , 
	}
	if nation :
		player["nation"] = nation 
	return player

print(make_player("Hasan","Right","21"))


# immutable : int , float , str , tuple (pass by value)
# mutable : list , dict  , set  (passa by ref.)

# each time --> we change value of immutable 
# 	--> a new object is created 
# 	--> we can verify by  : print(id(variable))



# for mutable obj. we can send a copy by --> var_name[:]
# it wont mod. the original one 


orders = ["football","baseball","socks","pad"]
completed_orders = []

def handle_order(orders,completed_orders) :
	while orders :
		completed_orders.append(orders.pop())


handle_order(orders[:],completed_orders) # pass by value
print(f"completed orders : {completed_orders}")
print(f"pending orders :{orders}")

print("\n")

handle_order(orders,completed_orders) # pass by ref.
print(f"pending orders :{orders}")


## func. call with any number of arguments 

# *variable_name --> create an empty "Tuple"
# **variable_name --> create an empty "Dict"


# *variable_name --> packs all value in a tuple 
def make_pizza(*toppings) :
	print("the list of toppings for your pizza :")
	print(toppings)

make_pizza("mushroom","cheese","onion")


# mix of positional and arbitrary argument 
# arbitrary must be to the right 


print("\n")
def make_pizza(size,*toppings) :
	print(f"size of the pizza is {size}")
	print("the toppings for your pizza :")
	for topping in toppings :
		print(f"-{topping}")

make_pizza(12,"mushroom","cheese","onion")


# **variable_name --> packs name-value pair in a "dict"
def build_profile(id,**user_info) :
	user_info["id"] = id ; 
	print(user_info)

build_profile(123,name="hasan",age="21",country="BD")



## task 

def make_car(brand,model_name,**details) :
	details["brand"] = brand  
	details["model_name"] = model_name
	return details

car = make_car("subaru","outback",color="black",ev=True)
print(car)


# multiple files / modules and importing 


#importing entire module 
	# for pizza.py --> import pizza 
	# we have to use dot_notaton --> 
		# pizza.make_pizza(12,"mushroom","cheese","onion")


# importing speicific functions from a module 
	# for pizza.py -> from pizza import func_0,func_1,func_2
	# we dont need dot_notation here --> 
		# make_pizza(12,"mushroom","cheese","onion")



# importing a func. with a diff. name 
	# from pizza import make_pizza as mp

# importing a module with diff. name 
	# for pizza.py --> import pizza as p
	# have to use dont notation tho 


# to avoid using dot_notation 
	# from pizza import * 


# caution : 
	# there can be function with naming conflict 
	# its best to use dot_notation or rename the function
