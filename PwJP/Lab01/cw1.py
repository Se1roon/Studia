import math

print("Podaj x: ")
x = float(input())
print("Podaj z: ")
z = float(input())
print("Podaj i: ")
i = int(input())
print("Podaj j: ")
j = int(input())

w = pow((x+2)/i, 1/3)*pow(math.sin(x**2 + z**2), j)
v = (math.log(x**2) + 2*x**2 + pow(z, -2))/((x + z)*i) + i/j

print(f'w = {w}')
print(f'v = {v}')
