
## make , access , add  ,  modify , delete/remove
## keys() , values() retuns a list 
## set() , sorted() to organize data 
## use sorted() at last , bcz other operations may change order 
## note : comma may or may not be used after last element
person= { # make
	"first name" : "arafat" ,
	"last name" : "ullah" ,
	"city" : "dhaka" ,
	"height" : "5'4" ,
	"age" : 21  ,
}
fav_language = {
	"Alice" : "Python" ,
	"Bob" : "C++" ,
	"Arafat" : "JavaScript" ,
	"Hasan" : "Python" ,
	"Mohammed" : "Ruby" ,
	"Kenny" : "C++" 
}

person["age"] = 20  # modify
person["blood group"] = "B+" # add 
del person["city"]

print(person["first name"]) # access
print(person["last name"]) 
print(person["age"])

print(person.get("height","Not found")) # no error if not found


## looping
print("\n")
for attribute in person : # by default returns key
	print(f"{attribute}:{person[attribute]}") # without items()

print("\n")
for attribute,value in person.items() : # using items()
	print(f"{attribute}:{value}") 

if "height" in person : # search for key : without keys()
	print("this attribute is present")

print("\n")
for attribute in sorted(person) : # sorted copy 
	print(f"{attribute}")

## to get values 
print("\n")

for key in person : # normal way 
	print(f"{person[key]}") 

print("\n")

for value in person.values() : # using values()
	print(f"{value}")



## remove duplicate 
print("\n")
# sort unique languages
for language in sorted(set(fav_language.values())) :
	print(f"{language}")


##