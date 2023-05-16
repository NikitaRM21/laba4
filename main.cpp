#include <iostream>
#include "congrRand.h"
#include "xorshift.h"
#include "viborki.h"
#include <random>
#include <chrono>
using namespace std;

/*!
Генерирует выборку
\return Ничего не возвращает
*/
void generateVib(int q,int a) {
  if (a==1){
      xorShift lol;
      lol.srand(15);
      auto begin = std::chrono::steady_clock::now();
      for (int i=0; i<q; ++i) {
        lol.rand();
      }
      auto end = chrono::steady_clock::now();
      auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
      cout << elapsed_ms.count() << endl;
  } else if (a==2) {
      congrRand lol;
      lol.srand(15);
      auto begin = std::chrono::steady_clock::now();
      for (int i=0; i<q; ++i) {
        lol.rand();
      }
      auto end = chrono::steady_clock::now();
      auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
      cout << elapsed_ms.count() << endl;
  } else {
      srand(15);
      auto begin = std::chrono::steady_clock::now();
      for (int i=0; i<q; ++i) {
        rand();
      }
      auto end = chrono::steady_clock::now();
      auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
      cout << elapsed_ms.count() << endl;
  }
}

/*!
Расчитывает необходимое кол-во интервалов
\param[е] Начальная инициализация
\return Количество интервалов
*/
int getIntervalNumber(const double e) {
  int cur = 0;
  if (e == 1) {
    return 16;
  }
  for (int i=1;i<16;i++) {
    if (e > i/16.0){
      cur+=1;
    } else {
      break;
    }
  }
  return cur;
}


int main()
{
  //first, second arrays are vectors of 10 samples with 100 elements
  congrRand lol;
  vector<viborki> firstArray;
  for (int i=0;i<10;++i) {
      viborki cong(lol,100);
      firstArray.push_back(cong);
  }

  xorShift kek;
  vector<viborki> secondArray;
  for (int i=0;i<10;++i) {
      viborki cong1(kek,100);
      secondArray.push_back(cong1);
  }

  vector<viborki> thirdArray;
  for (int i=0;i<10;++i) {
      viborki cong(100);
      thirdArray.push_back(cong);
  }

  cout << "---------------------" << endl;
  for (int i=0;i<firstArray.size();i++) {
      cout << firstArray[i].mean() << " " << firstArray[i].variance() << " " << firstArray[i].coefficientOfVariation() << " " << firstArray[i].standartDeviation() << " " << endl;
  }
  cout << "---------------------" << endl;

  for (int i=0;i<secondArray.size();i++) {
      cout << secondArray[i].mean() << " " << secondArray[i].variance() << " " << secondArray[i].coefficientOfVariation() << " " << secondArray[i].standartDeviation() << " " << endl;
  }
  cout << "---------------------" << endl;

  for (int i=0;i<thirdArray.size();i++) {
      cout << thirdArray[i].mean() << " " << thirdArray[i].variance() << " " << thirdArray[i].coefficientOfVariation() << " " << thirdArray[i].standartDeviation() << " " << endl;
  }
  cout << "---------------------" << endl;


  //хи квадрат 16 интервалов для 100 элементов по закону Стерджейса
  cout << "хи квадрат конгруэнтный" << endl;
  for (auto i: firstArray) {
    vector<int> n(16);
    for (auto j: i.getDataBase()) {
      n[getIntervalNumber(j)]+=1;
    }
    double sum = 0;
    for (auto i: n) {
      sum += (i*i / (1/16.0));
    }
    cout << sum/100 - 100 << endl;
  }
  cout << "хи квадрат xorshift" << endl;
  for (auto i: secondArray) {
    vector<int> n(16);
    for (auto j: i.getDataBase()) {
      n[getIntervalNumber(j)]+=1;
    }
    double sum = 0;
    for (auto i: n) {
      sum += (i*i / (1/16.0));
    }
    cout << sum/100 - 100 << endl;
  }

  cout << "хи квадрат rand" << endl;
  for (auto i: thirdArray) {
    vector<int> n(16);
    for (auto j: i.getDataBase()) {
      n[getIntervalNumber(j)]+=1;
    }
    double sum = 0;
    for (auto i: n) {
      sum += (i*i / (1/16.0));
    }
    cout << sum/100 - 100 << endl;
  }


  //measure time for a generation 1-congr 2-xorShift 3-rand
  cout << "=========" << endl;
  generateVib(100,1);
  generateVib(1000,1);
  generateVib(10000,1);
  generateVib(100000,1);
  generateVib(1000000,1);
  cout << "=========" << endl;
  generateVib(100,2);
  generateVib(1000,2);
  generateVib(10000,2);
  generateVib(100000,2);
  generateVib(1000000,2);
  cout << "=========" << endl;
  generateVib(100,3);
  generateVib(1000,3);
  generateVib(10000,3);
  generateVib(100000,3);
  generateVib(1000000,3);

  return 0;
}
