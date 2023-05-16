#include "viborki.h"
#include <math.h>

viborki::viborki(congrRand &randomer, const int quantity) {
  for (int i=0;i<quantity;++i) {
    data.push_back(static_cast<long double>(randomer.rand())/32768);
  }
}
viborki::viborki(xorShift &randomer, const int quantity) {
  for (int i=0;i<quantity;++i) {
    data.push_back(static_cast<long double>(randomer.rand())/32768);
  }
}

viborki::viborki(const int quantity) {
  for (int i=0;i<quantity;++i) {
    data.push_back((double)rand()/RAND_MAX);
  }
}

/*!
Расчёт матожидания
\return значение матожидания
*/
long double viborki::mean() {
  long double ret = 0;
  for (auto i: data) {
    ret += i;
  }
  return ret/data.size();
}

/*!
Расчёт дисперсии
\return Значение дисперсии
*/
long double viborki::variance() {
  long double ret = 0;
  for (auto i: data) {
    ret += ( i-this->mean() ) * ( i-this->mean() );
  }
  return ret/data.size();
}

/*!
Расчёт стандартного отклонения
\return Значение стандартного отклонения
*/
long double viborki::standartDeviation() {
  return sqrt(this->variance());
}

/*!
Коэффициент вариации
\return Значение коэффициента вариации
*/
long double viborki::coefficientOfVariation() {
  return this->standartDeviation()/this->mean();
}
