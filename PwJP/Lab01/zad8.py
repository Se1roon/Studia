liczba = int(input("Podaj liczbę: "))

for i in range(2, liczba):
    if (liczba % i == 0):
        print("Nie jest pierwsza")
        break;
else:
    print("Pierwsza")
