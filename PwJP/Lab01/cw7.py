import math

k = int(input('Podaj k = '))

suma = 0
for v in range(1, k + 1):
    if v**2/2 - v >= k:
        print(f'v={v}')
        suma += v

print(f'suma = {suma}')

