
## negative indexing can only be used for accessing / finding
## it cannot be used for inserting 
motorcycle = [] 
motorcycle.append("henda")
motorcycle.append("yamaha")
motorcycle.append("suzuki")

motorcycle[0] = "honda" #modify
print(f"first bought bike is {motorcycle[0]}") 
print(f"last bought bike is {motorcycle[2]}")

motorcycle.insert(3,"ducati") 
print(motorcycle)
print(f"the bike which is  very expensive :{motorcycle.pop()}")
print (f"it removes the second element :{motorcycle.pop(1)}")

motorcycle.remove("honda") #removes first occ of honda 

print("\n\n")
print(20*"#")
print("\n\n")

guest = ["nakib","turjo","arafat"]

print(f"dear {guest[0]},you are invited to the dinner")
print(f"dear {guest[1]},you are invited to the dinner")
print(f"dear {guest[2]},you are invited to the dinner")

guest.pop()

guest.append("king-min-doo")
print(f"sir {guest[-1]},you are invited to the party")


guest.append("new-user1")
guest.append("new-user2")
guest.append("new-user3")


print(f"the first guest is {guest[0]}") 
print(f"the last guest is {guest[-1]}") 
print(f"sorry sir we cannot have you :  {guest.pop(-1)}")



