#include "analyse.h"

Analyse::Analyse(const char* data, int len)
{
    for(n=1; n<len; n<<=1);
    x = new complex<double>[n];
    for(int i=0; i<len; i++)
        x[i] = complex<double>((double)data[i]);
}

Analyse::~Analyse()
{
    delete [] x;
}

bool Analyse::fft(int on)
{
    if(abs(on) != 1)
        return false;
    reverse();

    int i, j, k;
    double _on = (double)(on << 1);
    for(i=2; i<=n; i<<=1)
    {
        complex<double> Wn(cos(_on * PI / i), sin (_on * PI / i));
        for(j=0; j<n; j+=i)
        {
            complex<double> W(1.0);
            for(k=j; k<j+(i>>1); k++)
            {
                complex<double> tmp(x[k+(i>>1)] * W);
                x[k + (i >> 1)] = x[k] - tmp;
                x[k] += tmp;
                W *= Wn;
            }
        }
    }

    //最后的部分之所以不分摊到每一次蝶形运算，是要发挥干扰放大器的作用
    if(on == -1)
        for(i=0; i<n; i++)
            x[i] /= (double)n;
    return true;
}

void Analyse::print(char* data, int len)
{
    for(int i=0; i<len; i++)
        data[i] = (char)x[i].real();
}

void Analyse::reverse()
{
    for(int i=1, j=n>>1, k; i<n-1; i++)
    {
        if(i < j)
            swap(x[i], x[j]);
        k = n >> 1;
        while(j >= k)
        {
            j -= k;
            k >>= 1;
        }
        if(j < k)
            j += k;
    }
}
