#ifndef DECODER_H
#define DECODER_H

#pragma pack(2) //控制结构体地址对齐

#include <string.h>
#include <fstream>
#include <vector>
#include <algorithm>

#define DECODER_LEN 32  //约定的表示加密文本长度所占用的空间
#define DECODER_MAXLINE 20  //动态显示的最大行数

using namespace std;

struct Bmphead
{
    short type;    //记录bmp文件类型
    int size;   //记录文件大小
    char duoyu[48]; //文件头中无用的信息
};

class Decoder
{
public:
    Decoder();
    ~Decoder();
    void load(const char* FileName);    //装载指定的文件并解密
    char* get_text();
    int adjust(int len);

private:
    Bmphead* header;    //存放加密文件信息
    char* codetext; //解密出的字串
    vector<int> cnt_Enter;  //记录每一个回车的位置
};

#endif // DECODER_H
