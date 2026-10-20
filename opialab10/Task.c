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