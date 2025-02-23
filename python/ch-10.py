


# # how to open and read from a file 
# # open() assigns the object to file_object
# # read() reads the data from file_object and stores it in content
# with open("sample.txt") as file_object :
# 	content = file_object.read()

# print(content)

# # for file path both relative or absolute file path can be used 

# # reading line by line 

# # use rstrip() to remove extra new-lines for each line 
# with open("sample.txt") as file_object :
# 	for line in file_object :
# 		print(line.rstrip())


# # creating a list of lines from file 


# with open("sample.txt") as file_object :
# 	lines = file_object.readlines() # read lines into a list


# for line in lines :
# 	print(line.rstrip())


# # creating a string from file content 

# text = ""

# # splitting line by line in a list 
# with open("sample.txt") as file_object :
# 	lines = file_object.readlines()

# for line in lines :
# 	text += line.rstrip()

# print(text)  # string created from the file content 

# pi_value = ""
# with open("pi.txt") as file_object :
# 	lines = file_object.readlines()

# for line in lines :
# 	pi_value += line.strip() # to remove white-space an new-line

# print(pi_value[:12])  # only 10 digit after decimal point 

# # python string matching 
# if "12" in pi_value :
# 	print("my birth date is in pi-value :)")
# else :
# 	print("my birth date is not there :(")



# filename = "output.txt"


# # read mode  --> "r"
# #  write mode --> "w"
# # append --> "a"
# # read and write "r+"
# # write mode deletes the content
# 	# it creates the file if it does not exist (write)
# # in write mode "\n" should be explicitly added 

# with open(filename,"w") as file_object :
# 	file_object.write("very hot.\n")
# 	file_object.write("summar day.\n")


# ## task 

# def login():

# 	user_name = input("Enter Your User_Name :")
# 	password = input("Enter Your Password :")
# 	with open("output.txt","a") as file_object :
# 		file_object.write(f"user name : {user_name}\n")
# 		file_object.write(f"password  : {password}\n")

# login() ;  # store user info in a file 


# # Error handling 

# try :
# 	# contains only the code that is risky 
# 	value = 5/1
# except ZeroDivisionError :
# 	# what to do if we encounter a particular error
# 	print("You cant Divide by Zero!")
# else :
# 	print(f"{value}")
# 	# what to do if try block runs without error 
# 	# it contains the code that is safe 

# # handling missing file : FileNotFoundError
# 	# use try-except block 

# # text.split() --> splits into a list by whitespace 
# text = "desi king-mindu arafat"
# text_list = text.split()
# print(text_list)

# # use looping to deal with many files together 



# # task 
# def cal() :
# 	try :
# 		# shorthand syntax of python 
# 		a,b = int(input("First Num :")),int(input("Second Num :"))
# 	except ValueError:
# 		print("Invalid Input")
# 		cal() # keep calling cal() until valid input given
# 	else :
# 		print(f"sum of numbers :{a+b}")
# cal() 


# def find_cnt(file_name,word) :
# 	with open(file_name) as f :
# 		content = f.read()
# 	# convert to same case for comparison 
# 	print(f"the word '{word}' appears {content.lower().count(word.lower())}")

# find_cnt("sample.txt","The ")


# storing and using data using json

import json  # import the module 
numbers = [1,2,3,4,5] # data to store 
with open("text.json","w") as f :
	json.dump(numbers,f) # use json.dump() to store 

with open("text.json") as f :
	num = json.load(f) # using json.load() to extract info
	print(num) # print to check
