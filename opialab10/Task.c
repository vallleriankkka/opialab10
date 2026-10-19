#include <locale.h>
#include <stdio.h>
#include <math.h>|
int get_duration(int start_sec, int end_sec);
int check_status(int duration_sec);
int get_full_minutes(int total_sec);
void print_time_mm_ss(int minutes, int seconds);
void process_stage(int start_sec, int end_sec);

int main()
{
	setlocale(LC_CTYPE, "");

	char sportsman;
	int start_sec, end_sec;

	for (;;)
	{
		printf("Введите однобуквенный код спортсмена\n");
		scanf(" %c", &sportsman);

		if (sportsman == '!')
			break;

		printf("Код: %c\n", sportsman);

		printf("Введите старт и финиш\n");
		scanf("%d %d", &start_sec, &end_sec);

		process_stage(start_sec, end_sec);
	}
}
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