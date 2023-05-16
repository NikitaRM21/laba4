#include "xorshift.h"

/*!
Генерирует следующий случайный элемент
\return случайный элемент
*/
int xorShift::rand() {
  next ^= next << 13;
  next ^= next >> 17;
  next ^= next << 5;
  return static_cast<unsigned>(next)%32768;
}

/*!
Первичная генерация
\param[seed] Начальная инициализация
\return Ничего не возвращает
*/
void xorShift::srand(unsigned int seed) {
  next = seed;
}
