

rivers = {
	"Bay of Bengal" : "Bangladesh" ,
	"Ganga" : "India" ,
	"Nile" : "Egypt"
}

for river,country in rivers.items() :
	print(f"{river} runs through {country}")


fav_language = {
	"Alice" : "Python" ,
	"Bob" : "C++" ,
	"Arafat" : "JavaScript" ,
	"Hasan" : "Python" ,
	"Mohammed" : "Ruby" ,
	"Kenny" : "C++"
}

users = ["hasan","Bob","lee","evans"] 

print("\n")
for user in users :
	if user.title() not in fav_language :
		print(f"Mr {user.title()},Please take the poll!")