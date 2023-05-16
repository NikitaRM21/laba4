#ifndef RADNDOMIZER_H
#define RADNDOMIZER_H

/*!
    \brief Класс конгруэтнотого генератора
    \author Никита Романов
    \version 1.0
    \date Май 2023 года

    Содержит функцию инициализаци, функцию получения следующего случайного значения, после следующего элемента.
*/
class congrRand
{
public:
  congrRand() {}
  int rand();
  void srand(unsigned int seed);
private:
  unsigned long int next = 1;
};

#endif // RADNDOMIZER_H
