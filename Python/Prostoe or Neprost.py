def is_prime(num):
    if num <= 1:
        return False
    elif num == 2:
        return True
    elif num % 2 == 0:
        return False
    else:
        for i in range(3, int(num**0.5) + 1, 2):
            if num % i == 0:
                return False
        return True
num = int(input("Введите число: "))
if is_prime(num):
    print(f"{num} - простое число.")
else:
    print(f"{num} - не является простым числом.")
