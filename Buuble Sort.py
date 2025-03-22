import random
import time
import matplotlib.pyplot as plt


def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break
    return arr


def main():
    min_size = 5000
    max_size = 10000
    step = 1000
    array_sizes = list(range(min_size, max_size + 1, step))
    bubble_times = []


    for size in array_sizes:
        print(f"Тестируем размер: {size}")
        arr = [random.randint(0, 10000) for _ in range(size)]

        # Сортировка пузырьком
        arr_copy = arr.copy()
        start = time.time()
        bubble_sort(arr_copy)
        end = time.time()
        bubble_time = end - start
        bubble_times.append(bubble_time)
        print(f"Время выполнения: {bubble_time:.2f} сек\n")

    # Построение графика
    plt.figure(figsize=(12, 8))
    plt.plot(array_sizes, bubble_times, label='Пузырьковая сортировка ', marker='o', linestyle='--')
    plt.xlabel('Размер массива')
    plt.ylabel('Время (секунды)')
    plt.title('Производительность пузырьковой сортировки')
    plt.legend()
    plt.grid(True)
    plt.savefig('bubble_sort_performance.png')
    plt.show()


if __name__ == "__main__":
    main()