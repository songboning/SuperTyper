#ifndef DECODER_H
#define DECODER_H

#pragma pack(2) //控制结构体地址对齐

#include <string.h>
#include <fstream>
#include "coder.h"
#include "analyse.h"

#define DECODER_LEN 32  //约定的表示加密文本长度所占用的空间

using namespace std;

class Decoder
{
public:
    Decoder();
    ~Decoder();
    void load(const char* FileName);    //装载指定的文件并解密
    char* get_text();

private:
    Bmphead* header;    //存放加密文件信息
    char* codetext; //解密出的字串
};

#endif // DECODER_H
