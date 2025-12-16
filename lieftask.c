#include <stdio.h>
#include <Windows.h>
#include <math.h>

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float then;
	float now;
	printf("¬ведите стоимость базовой корзины продуктов в рубл€х в прошлом году:");
	scanf_s("%f", &then);
	printf("¬ведите стоимость базовой корзины продуктов в рубл€х в насто€щее врем€:");
	scanf_s("%f", &now);
	float ipc = (now / then) * 100 - 100;
	printf("»нфл€ци€ с прошлого года составила: %10.2f %%", ipc);
	
}