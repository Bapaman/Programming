def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)
num = int(input("Введите число: "))
if num < 0:
    print("Факториал не определен для отрицательных чисел.")
else:
    result = factorial(num)
    print(f"Факториал {num} равен {result}")
