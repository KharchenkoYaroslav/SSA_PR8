# SSA_PR8

# Технології та запуск

## Як середовище розробки було обрано Docker-контейнер на базі образу `debian:bullseye-slim` з таких причин:

### Прозорість — усі початкові умови для виконання завдання задані в `Dockerfile`, що дозволяє бачити весь процес виконання, а також гарантує стабільність роботи коду.

### Швидкість відтворення початкових умов — Docker-контейнер дозволяє легко змінювати необхідні пакети та конфігурації. Усі зміни можна відкрутити назад за кілька секунд, тоді як у віртуальній машині це займає певний час. Це особливо актуально для завдань, які потребують змін або видалення файлів.

### Зручність розробки — Docker дозволяє швидко змінювати архітектуру, копіювати файли з основної машини та автоматизувати повторювані команди, що значно пришвидшує розробку.

### Варіативність — якщо щось неможливо або складно реалізувати на базі одного образу, завжди можна замінити його на інший.

#### *У завданнях, які неможливо реалізувати як задумано без використання повноцінної системи, буде застосовано `VM`*

## Запуск

### Всі необхідні команди для запуску контейнерів та виконання файлів описані в `Dockerfile`

# Звіт по завданням

## Задача 1

### Виклик count = write(fd, buffer, nbytes) може повернути в змінній count значення, відмінне від nbytes коли write не може записати весь буфер одразу

```
root@3f516114b9ea:/app# gcc -g -Wall task.c -o task -lm
root@3f516114b9ea:/app# ./task
count: 65536
```

## Задача 2

### Буде прочитано 4 байти бісля 3 байту
```
root@9fb04411942a:/app# gcc -g -Wall task.c -o task -lm
root@9fb04411942a:/app# ./task
Read 4 bytes: 2 3 3 7 
```

## Задача 3

### Дослідження, які вхідні дані є найгіршими для алгоритму швидкого сортування
```
root@f5aa935dceaa:/app# gcc -g -Wall task.c -o task -lm
root@f5aa935dceaa:/app# ./task
Test: sorted     | Size: 1000 | Time: 0.086 ms | Sorted: YES
Test: sorted     | Size: 10000 | Time: 0.815 ms | Sorted: YES
Test: sorted     | Size: 100000 | Time: 7.841 ms | Sorted: YES
Test: reversed   | Size: 1000 | Time: 0.092 ms | Sorted: YES
Test: reversed   | Size: 10000 | Time: 1.867 ms | Sorted: YES
Test: reversed   | Size: 100000 | Time: 8.114 ms | Sorted: YES
Test: constant   | Size: 1000 | Time: 0.066 ms | Sorted: YES
Test: constant   | Size: 10000 | Time: 0.727 ms | Sorted: YES
Test: constant   | Size: 100000 | Time: 8.131 ms | Sorted: YES
Test: random     | Size: 1000 | Time: 0.187 ms | Sorted: YES
Test: random     | Size: 10000 | Time: 2.211 ms | Sorted: YES
Test: random     | Size: 100000 | Time: 23.201 ms | Sorted: YES
```

## Задача 4

### Батьківський процес виводить pid дочірнього процесу, а дочірній поверне 0
```
root@81e00d3f62e8:/app# gcc -g -Wall task.c -o task -lm
root@81e00d3f62e8:/app# ./task
13
0
```

## Задача за варіантом 22

### Програма для створення дерева процесів
```
root@91db47b68670:/app# gcc -g -Wall task.c -o task -lm
root@91db47b68670:/app# ./task
Starting tree creation from PID 12
PID 12 at level 0 will create 2 children
PID 13 at level 1 will create 2 children
PID 14 at level 1 will create 2 children
PID 16 at level 2 will create 0 children
PID 15 at level 2 will create 0 children
PID 18 at level 2 will create 0 children
PID 17 at level 2 will create 0 children
Process 12 finished
```