import random
import string

def generate_random_password(length, use_letters, use_numbers, use_symbols):
    characters = ''
    if use_letters:
        characters += string.ascii_letters
    if use_numbers:
        characters += string.digits
    if use_symbols:
        characters += string.punctuation

    password = ''.join(random.choice(characters) for i in range(length))
    return password

if __name__ == "__main__":
    length = int(input("Insira o comprimento da senha: "))
    use_letters = input("Usar letras? (sim/não): ") == 'sim'
    use_numbers = input("Usar números? (sim/não): ") == 'sim'
    use_symbols = input("Usar símbolos? (sim/não): ") == 'sim'

    password = generate_random_password(length, use_letters, use_numbers, use_symbols)
    print(f"Senha Gerada: {password}")
