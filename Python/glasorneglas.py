def count_vowels(input_str):
    return sum(1 for char in input_str if char.lower() in "аеёиоуыэюяaeiou")
input_str = input("Введите строку: ")
vowel_count = count_vowels(input_str)
print(f"Количество гласных в строке: {vowel_count}")
