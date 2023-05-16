#include "congrRand.h"

/*!
Генерирует следующий случайный элемент
\return случайный элемент
*/
int congrRand::rand()
{
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % (32768);
}

/*!
Первичная генерация
\param[seed] Начальная инициализация
\return Ничего не возвращает
*/
void congrRand::srand(unsigned int seed)
{
  next = seed;
}
