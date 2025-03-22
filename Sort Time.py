import random
import time
import matplotlib.pyplot as plt



def radix_sort(arr):
    if not arr:
        return arr
    max_num = max(arr)
    exp = 1
    while max_num // exp > 0:
        counting_sort(arr, exp)
        exp *= 10
    return arr


def counting_sort(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0] * 10

    for i in range(n):
        digit = (arr[i] // exp) % 10
        count[digit] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = n - 1
    while i >= 0:
        digit = (arr[i] // exp) % 10
        output[count[digit] - 1] = arr[i]
        count[digit] -= 1
        i -= 1

    for i in range(n):
        arr[i] = output[i]


def quick_sort_inplace(arr):
    def partition(low, high):
        pivot = arr[high]
        i = low - 1
        for j in range(low, high):
            if arr[j] <= pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1

    stack = [(0, len(arr) - 1)]
    while stack:
        low, high = stack.pop()
        if low < high:
            pi = partition(low, high)
            stack.append((low, pi - 1))
            stack.append((pi + 1, high))
    return arr


def main():
    min_size = 100000
    max_size = 500000
    step = 25000
    array_sizes = list(range(min_size, max_size + 1, step))

    bubble_times = []
    radix_times = []
    quick_times = []

    for size in array_sizes:
        print(f"\nТестируем размер: {size}")
        arr = [random.randint(0, 10000) for _ in range(size)]


        # Поразрядная сортировка
        arr_radix = arr.copy()
        start = time.time()
        radix_sort(arr_radix)
        end = time.time()
        radix_time = end - start
        radix_times.append(radix_time)
        print(f"Поразрядная: {radix_time:.2f} сек")

        # Быстрая сортировка
        arr_quick = arr.copy()
        start = time.time()
        quick_sort_inplace(arr_quick)
        end = time.time()
        quick_time = end - start
        quick_times.append(quick_time)
        print(f"Быстрая: {quick_time:.2f} сек")

    # Построение графика
    plt.figure(figsize=(12, 8))
    plt.plot(array_sizes, radix_times, label='Поразрядная', marker='s')
    plt.plot(array_sizes, quick_times, label='Быстрая', marker='^')
    plt.xlabel('Размер массива')
    plt.ylabel('Время (секунды)')
    plt.title('Сравнение времени сортировки')
    plt.legend()
    plt.grid(True)
    plt.savefig('sorting_performance.png')
    plt.show()


if __name__ == "__main__":
    main()

