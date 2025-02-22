

# creating a class and class function 

# self is used to attach any variable with the class
# every function of the class must have it 
class Dog :
	def __init__(self,name,age) : # called when object is created
		"""initialize name and age"""  # doc-string
		self.name = name 
		self.age = age 
	def sit(self) :
		print(f"{self.name} is now sitting!")
	def roll_over(self) :
		print(f"{self.name} rolled over!")


# making object or class-instance 
my_dog  = Dog("tommy",21)

# accessing class variables --> dot notation 
print(f"my dog's name is {my_dog.name}")
print(f"{my_dog.name}'s age is {my_dog.age}")

# accessing methods / functions 
my_dog.roll_over() ;
my_dog.sit() ;

# task 

class Restaurant :

	def __init__(self,name,cuisine_type) :
		self.name = name 
		self.cuisine_type = cuisine_type
		self.open = False   # default value

	def describe(self) :
		print(f"Restaurant's name is {self.name}")
		print(f"{self.name}'s cuisine is {self.cuisine_type}")


new_restaurant = Restaurant("Dolphine's Dine","Tuna Curry")

new_restaurant.describe() ;

#######

class Car :

	def __init__(self,brand,model,year) :
	 	self.brand = brand  
	 	self.model = model 
	 	self.year = year
	 	self.miles = 0  # default 

	def describe(self) :
		print(f"brand : {self.brand}")
		print(f"model : {self.model}")
		print(f"year :  {self.year}")
		print(f"miles : {self.miles}")

	def set_milage(self,miles) :
		self.miles = miles

	def fuel_tank_status() :
		print(f"It has 0 fuel")


new_car = Car("bmw","M4",2003) 
new_car.describe()

# modification 
new_car.miles = 20
new_car.set_milage(20)
new_car.miles += 20 

new_car.describe()

class Manual :
	def __init__(self) :
		pass   # placeholder to avoid error !
	def printManual(self) :
		print("only manual is be careful")

# inheritance 

class EV(Car,Manual) :  # class that has to be inherited 

	def __init__(self,brand,model,year) :

		# passing the arg. to parent class 
		# implicit calling does not require "self"
		super().__init__(brand,model,year)

		# manually calling parent class initiator 
		# explicit calling requires "self" as parameter
		Manual.__init__(self)

		self.battery_size  = 75 # child class variable 

		# making another class an attribute 
		# if it taken no arg. --> pass empty parenthesis
		self.manual = Manual() 


	# making child class method
	def describe_battery(self) :
		print(f"It'sa battery size is {self.battery_size}")

	# overriding parent class method 
	def fuel_tank_status(self) :
		print("EV does not have a fuel tank")

my_tesla = EV("tesla","R9","2020")
print(my_tesla.describe()) # call parent methods 
my_tesla.describe_battery() # calling child class method
my_tesla.fuel_tank_status()

my_tesla.manual.printManual() # nested method calling 

# there are advantage of using super(), without explicitly 
# 	calling parent class  


# we can import class same way we did with func.

# import Car
# import Car as car
# from Car import *



# task 


from random import randint 
from random import choice 

class Dice :
	def __init__(self,side=6) :
		self.side = side  
	def roll_die(self) :
		self.side = randint(1,6)

	def show_side(self) :
		print(f"the side is {self.side}")

dice = Dice(1)

dice.show_side()
dice.roll_die()
dice.show_side()


# lottery 


tickets = ["00101","00111","00011","00110","00001"]

class SelectWinner :
	def __init__(self,tickets) :
		self.tickets = tickets 
	def winner(self) :
		print(f"The winner is {choice(self.tickets)}")
	def find_count(self,ticket) :
		cnt = 0 
		while choice(self.tickets) != ticket :
			cnt += 1 
		print(f"I had to try {cnt+1} times to win")


lucky_ticket = SelectWinner(tickets[:]) # pass by value 

lucky_ticket.winner()
lucky_ticket.find_count("00001")

# how many times till i win

