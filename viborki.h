#ifndef VIBORKI_H
#define VIBORKI_H

#include <vector>
#include "congrRand.h"
#include "xorshift.h"
#include <iostream>
using namespace std;
/*!
    \brief Класс выборки
    \author Никита Романов
    \version 1.0
    \date Май 2023 года

    Содержит вектор данных. Функции расчёта среднего, дисперсии, стандартного отклонения, коэффициэнта кореляции,
    подсчёта размера массива, получения данных и вывода значений.
*/
class viborki
{
public:
  viborki(congrRand &randomer, const int quantity);
  viborki(xorShift &randomer, const int quantity);
  viborki(const int quatity);
  long double mean();
  long double variance();
  long double standartDeviation();
  long double coefficientOfVariation();
  unsigned int getDataSize(){
    return data.size();
  }
  vector<long double> getDataBase(){
    return data;
  }
  void show(){
    for (auto i:data){
      cout << i << " ";
    }
  }

private:
  vector<long double> data;
};

#endif // VIBORKI_H
