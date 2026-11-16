#!/bin/bash

# функция для сортировки чисел (пузырек)
sort_nums() {
    arr=("$@")
    n=${#arr[@]}

    for (( i=0; i < n; i++ )); do
        for (( j=0; j < n-i-1; j++ )); do
            if [ ${arr[j]} -gt ${arr[j+1]} ]; then
                tmp=${arr[j]}
                arr[j]=${arr[j+1]}
                arr[j+1]=$tmp
            fi
        done
    done

    echo ${arr[@]}
}

# проверка что аргументы переданы
if [ $# -eq 0 ]; then
    echo "Введите числа через аргументы"
    echo "Пример: $0 3 1 4 2"
    exit 1
fi

echo "Было: $*"

sorted=$(sort_nums "$@")

echo "Стало: $sorted"
