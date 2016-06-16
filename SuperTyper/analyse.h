#ifndef ANALYSE_H
#define ANALYSE_H

#include <math.h>
#include <complex>
#include <algorithm>

#define PI (acos(-1.0)) //用反三角函数定义圆周率

using namespace std;

class Analyse
{
public:
    Analyse(const char* data, int len);
    ~Analyse();
    bool fft(int on);   //快速傅里叶变换
    void print(char* data, int len);

private:
    int n;
    complex<double>* x; //序列
    void reverse(); //调整顺序
};

#endif // ANALYSE_H
