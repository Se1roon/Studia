def suma(a,b):
    return a+b


def roznica(a,b):
    return a-b


PI = 3.1415

if __name__ == '__main__':
    #Tak - kod został uruchomiony jako program
    print('Skrypt uruchomiony')
    import sys 
    print(suma(int(sys.argv[1]), int(sys.argv[2])))
    print(PI)
else:
    #Nie - plik został zaimportowany jako moduł
    print('Moduł zaimportowany')

