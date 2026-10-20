# Домашнее задание к работе 10
## Условия задания
Создайте мини-проект, реализующий программу системы хронометража на спортивных соревнованиях (например, лыжные гонки или биатлон). Программа должна принимать временные метки прохождения контрольных этапов в секундах, рассчитывать чистый результат, проверять его на соответствие правилам (контроль нарушений) и красиво выводить данные на экран. 
### Контрольный пример 1
```
Код: D
Старт и финиш: 00 20
Вывод: 00:20 Дисквалификация
```
### Контрольный пример 2
```
Код: A
Старт и финиш: 12 45
Вывод: 00:33 Рекорд
```
### Контрольный пример 3
```
Код: L
Старт и финиш: 32 103
Вывод: 01:11 Норма
```
### Контрольный пример 4
```
Код: !
Завершение программы
```
## 1. Реализация программы
Файл С
```c
#include <locale.h>
#include <stdio.h>

//Контрольный пример 1
//Код: D
//Старт и финиш: 00 20
//Вывод: 00:20 Дисквалификация

//Контрольный пример 2
//Код: A
//Старт и финиш: 12 45
//Вывод: 00:33 Рекорд

//Контрольный пример 3
//Код: L
//Старт и финиш: 32 103
//Вывод: 01:11 Норма

//Контрольный пример 4
//Код: !
//Завершение программы

int get_duration(int start_sec, int end_sec)
{
	return end_sec - start_sec;
}


int check_status(int duration_sec)
{
	if (duration_sec < 30)
	{
		return -1;
	}
	if (duration_sec < 45)
	{
		return 1;
	}
	else
		return 0;
}

int get_full_minutes(int total_sec)
{
	return total_sec / 60;
}

void print_time_mm_ss(int minutes, int seconds)
{
	printf("%02d:%02d\n", minutes, seconds);
}

void process_stage(int start_sec, int end_sec)
{
	int duration = get_duration(start_sec, end_sec);
	int status = check_status(duration);
	int minutes = get_full_minutes(duration);
	int seconds = duration % 60;
	print_time_mm_ss(minutes, seconds);
	if (status == -1)
	{
		puts("Дисквалификация");
	}
	if (status == 1)
	{
		puts("Рекорд этапа");
	}
	if (status == 0)
	{
		puts("Норма");
	}
}

int main()
{
	setlocale(LC_CTYPE, "");

	char sportsman;
	int start_sec, end_sec;

	while (1)
	{
		printf("Введите однобуквенный код спортсмена\n");
		scanf(" %c", &sportsman);

		if (sportsman == '!')
		{
			printf("Завершение программы\n");
			break;
		}


		printf("Код: %c\n", sportsman);

		printf("Введите старт и финиш\n");
		scanf("%d %d", &start_sec, &end_sec);

		process_stage(start_sec, end_sec);
	}
	return 0;
}
```
Файл заголовка
```c
#pragma once
int get_duration(int start_sec, int end_sec);
int check_status(int duration_sec);
int get_full_minutes(int total_sec);
void print_time_mm_ss(int minutes, int seconds);
void process_stage(int start_sec, int end_sec);
```
## 2. Результаты работы программы
Контрольные примеры 1-4 по порядку
```
Введите однобуквенный код спортсмена
D
Код: D
Введите старт и финиш
00 20
00:20
Дисквалификация
Введите однобуквенный код спортсмена
A
Код: A
Введите старт и финиш
12 45
00:33
Рекорд этапа
Введите однобуквенный код спортсмена
L
Код: L
Введите старт и финиш
32 103
01:11
Норма
Введите однобуквенный код спортсмена
!
Завершение программы

C:\Users\valer\source\repos\opialab10\x64\Debug\opialab10.exe (процесс 3940) завершил работу с кодом 0 (0x0).
Чтобы автоматически закрывать консоль при остановке отладки, включите параметр "Сервис" ->"Параметры" ->"Отладка" -> "Автоматически закрыть консоль при остановке отладки".
Нажмите любую клавишу, чтобы закрыть это окно:
```
## 3. Информация о разработчике
Елфимова Валерия бОТИ-261
