

places  = ["hanoi","bahmas","lake baikal","taj-mahal"]
for place in places :
	print(place) 
print("I want to visit all of these places!")


#range function 
l = 2 
r = 12
jump = 2 
numbers = list(range(l,r+1,jump)) 
print(numbers)

## list comprehension 
cubes = [value**3 for value in range(1,11)]
print(cubes)

## slicing list
print(places[0:2]) # list[l:r+1]
print(places[1:]) # index 1 to end 
print(places[:3]) # index 0 to (3-1)
print(places[-3:])
print(places[:-1]) # last index excluded 

## copying by reference and by value

my_drink = ["mojo","power","speed","hulk"]
friend_drink1 = my_drink[:] # copy by value 
friend_drink2 = my_drink  # copy by reference

my_drink.append("braver")
friend_drink1.append("laban")
print(my_drink)
print(friend_drink1)
print(friend_drink2) 
