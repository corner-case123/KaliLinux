
import sys

# Redirect standard input to read from a file
sys.stdin = open('a.in', 'r')

# Redirect standard output to write to a file
sys.stdout = open('a.out', 'w')


x = int(input())
print("hello world :",x)
