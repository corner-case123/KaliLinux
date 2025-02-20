
#import sys

# # Redirect standard input to read from a file
# sys.stdin = open('a.in', 'r')

# # Redirect standard output to write to a file
# sys.stdout = open('a.out', 'w')

name = input("your name :")
text = f"hello {name},would you like to learn some python today?"
print(text)
print("below are three name formats!")
print(name.lower())
print(name.upper())
print(name.title())

print("the following your favourite quote!")
print('Oscar Wilde said,"To live is the wildest thing"')

weird_name = "\n\thasan muba\t" ;
print(weird_name) ;
print(weird_name.lstrip())  ;
print(weird_name.rstrip()) ;
print(weird_name.strip()) ;