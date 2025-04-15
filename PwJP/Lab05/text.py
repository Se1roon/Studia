def left(text: str, width: int):
    spaces = width - len(text)
    print(text + ' ' * spaces)

def right(text: str, width: int):
    spaces = width - len(text)
    print(' ' * spaces + text)

def center(text: str, width: int):
    spaces = int((width - len(text)) / 2)
    print(' ' * spaces + text + ' ' * spaces)


if __name__ == '__main__':
    print('Moduł "text" definiuje funkcje center, left, right i służy do:')
    left("Wypisania tekstu wyrównanego do lewej,", 80)
    right("do prawej,", 80)
    center("Lub wycentrowanego.", 80)

    print(f'Dodatkowo ten moduł zawiera: {dir()}')

