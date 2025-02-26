m = int(input('Podaj numer miesiąca: '))

if 1 <= m <= 2 or m == 12:
    print("Zima")
elif 2 < m <= 6:
    print("Wiosna")
elif 6 < m <= 8:
    print("Lato")
elif 8 < m <= 11:
    print("Jesień")
else:
    print("????")
