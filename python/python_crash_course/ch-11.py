


# testing code in python --> unittest module


import unittest # testing module

# the function we want to test
def name_format(first_name,last_name,middle_name="") :
	if middle_name :
		return f"{first_name} {middle_name} {last_name}".title()
	else :
		return f"{first_name} {last_name}".title()


class TestName(unittest.TestCase) :
# import "TestCase" class from unittest module 
	
	# test_ -->  needed to use it as a test_function 
	def test_first_last(self) :
		name = name_format("David","Jensen") 
		self.assertEqual(name,"David Jensen")

	def test_first_middle_last(self) :
		name = name_format("david","malan","j")
		self.assertEqual(name,"David J Malan")

# we can put all the test-case in one method 
	# but it is better to separate them 



# the if statement ensures code  is executed  when 
	# it is run , and not when it is imported
# by default , python runs code  while importing 
if __name__ == "__main__" :
	unittest.main()

# some assert statements in python : 
	# assertEqual(a, b)Verify that a == b
	# assertNotEqual(a, b)Verify that a != b
	# assertTrue(x)Verify that x is True
	# assertFalse(x)Verify that x is False
	# assertIn(item, list)Verify that item is in list
	# assertNotIn(item, list)Verify that item is not in list



# setUp() method : for each test_ method 
	# we need a new class instance to run test properly
# rather than making an  object inside each test_ method 
	# we can put the object making part inside setUp() func.
# setUp()  will run before each test_ method 
	# and create the object needed for each test_ method 
