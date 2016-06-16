#ifndef CODER_H
#define CODER_H

#pragma pack(2)

#include <fstream>
#include <string>
#include <QString>

#define CODER_LEN 32  //约定的表示加密文本长度所占用的空间

using namespace std;

struct Bmphead
{
    short type;    //记录bmp文件类型
    int size;   //记录文件大小
    char duoyu[48]; //文件头中无用的信息
};

class Coder
{
public:
    Coder();
    ~Coder();
    const char* load(const char* FileName, string codetext);   //将文本加密存储

private:
    Bmphead* header;
};

#endif // CODER_H
