frase = input("Frase: ")
vogais = ['a', 'e', 'i', 'o', 'u']

for i in range(5):
    frase = frase.replace(vogais[i], str(i + 1))
    
print(frase)
