text = input('Wprowadź tekst: ')
znak = input('Wprowadź znak: ')

index = text.rfind(znak)

print(f'{text[0:index] + text[index + 1:]}')
