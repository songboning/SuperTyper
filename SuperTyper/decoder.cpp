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

/*for(int i=0; i<30; i++)printf("%d ", content[DECODER_LEN+i]);puts("");
    Analyse sf(content+DECODER_LEN, header->size-DECODER_LEN);
    sf.fft(1);
    sf.fft(-1);
    sf.print(content+DECODER_LEN, header->size-DECODER_LEN);
for(int i=0; i<30; i++)printf("%d ", content[DECODER_LEN+i]);puts("");
*/


    int codelength, i;
    for(i=codelength=0; i<DECODER_LEN; i++)
    {
        codelength |= (content[i] & 0x01) << i;
    }

    Analyse sf(content+DECODER_LEN, codelength<<3);
    sf.fft(1);
    sf.fft(-1);
    sf.print(content+DECODER_LEN, codelength<<3);

    if(codetext)
        delete [] codetext;
    codetext = new char[codelength + 2];
    memset(codetext, 0, codelength + 2);
    for(i=0; i<codelength<<3; i++)
        codetext[i >> 3] |= (content[i+DECODER_LEN] & 0x01) << (i & 7);
    delete [] content;
}

char* Decoder::get_text()
{
    return codetext;
}
