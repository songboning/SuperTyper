#include "decoder.h"

Decoder::Decoder()
{
    header = new Bmphead;
    codetext = NULL;
}

Decoder::~Decoder()
{
    delete header;
    if(codetext)
        delete [] codetext;
}

void Decoder::load(const char* FileName)
{
    ifstream bmpfile;
    bmpfile.open(FileName, ios::binary | ios::in);
    bmpfile.read((char*)header, sizeof Bmphead);
    header->size -= sizeof Bmphead;
    char* content = new char[header->size];
    bmpfile.read(content, header->size);
    bmpfile.close();

    int codelength, i;
    for(i=codelength=0; i<DECODER_LEN; i++)
        codelength |= (content[i] & 0x01) << i;
    if(codetext)
        delete [] codetext;
    codetext = new char[codelength + 2];
    memset(codetext, 0, codelength + 2);
    for(i=0; i<codelength<<3; i++)
        codetext[i >> 3] |= (content[i+DECODER_LEN] & 0x01) << (i & 7);
    delete [] content;

    for(i=0, cnt_Enter.clear(); codetext[i]; i++)
        if(codetext[i] == '\n')
            cnt_Enter.push_back(i);
}

char* Decoder::get_text()
{
    return codetext;
}

int Decoder::adjust(int len)
{
    if(cnt_Enter.size() <= DECODER_MAXLINE)
        return 0;
    return len < cnt_Enter[DECODER_MAXLINE] ? 0 : cnt_Enter[lower_bound(cnt_Enter.begin(), cnt_Enter.end(), len) - cnt_Enter.begin() - DECODER_MAXLINE];
}
