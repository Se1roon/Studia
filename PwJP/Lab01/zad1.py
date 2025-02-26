import math

print('Podaj promień okręgu definującego torus: ')
r = float(input())

print('Podaj odległość środka okręgu od osi obrotu: ')
R = float(input())

pole = 4*math.pi**2*r*R
objetosc = 2*math.pi**2*R*r**2

print(f'pole = {pole}')
print(f'objetosc = {objetosc}')
