#ifndef XORSHIFT_H
#define XORSHIFT_H

/*!
    \brief Класс рандомного генератора на основе операции исключающее или
    \author Никита Романов
    \version 1.0
    \date Май 2023 года

    Содержит Содержит функцию инициализаци, функцию получения следующего случайного значения, после следующего элемента.
*/
class xorShift
{
public:
  xorShift() {}
  int rand();
  void srand(unsigned int seed);
private:
  unsigned long int next = 1;
};

#endif // XORSHIFT_H
