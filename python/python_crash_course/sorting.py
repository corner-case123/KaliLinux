

cars = ["mclaren","bmw","audi","bugatti","lamborghini"]

print(sorted(cars)) #does not modify list 
print(sorted(cars,reverse=True)) #does not modify list 

#these modifies the original list
cars.sort() 
print(cars)
cars.sort(reverse=True)
print(cars)
cars.reverse() 
print(len(cars))


