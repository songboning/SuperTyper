#include "coder.h"
#include "analyse.h"

Coder::Coder()
{
    header = new Bmphead;
}

Coder::~Coder()
{
    delete header;
}

const char* Coder::load(const char* FileName, string codetext)
{
    codetext += '\0';
    int codelength = codetext.length();
    ifstream bmpfile;
    bmpfile.open(FileName, ios::binary | ios::in);
    bmpfile.read((char*)header, sizeof Bmphead);
    header->size -= sizeof Bmphead;
    if(header->size < codelength << 3)
    {
        bmpfile.close();
        return "Error\nText too long!";
    }
    char* content = new char[header->size];
    bmpfile.read(content, header->size);
    bmpfile.close();

    int i, j;
    for(i=j=0; i<CODER_LEN; i++)
    {
        if(codelength >> i & 1)
            content[i] |= 0x01;
        else
            content[i] &= 0xfe;
    }

    while(i<header->size && j<codelength)
    {
        if(codetext[j] >> (i & 7) & 1)
            content[i] |= 0x01;
        else
            content[i] &= 0xfe;
        if(!(++i & 7))
            j++;
    }

    ofstream bmpfile2;
    bmpfile2.open(FileName, ios::binary | ios::out);
    bmpfile2.write((const char*)header, sizeof Bmphead);
    bmpfile2.write((const char*)content, header->size);
    bmpfile2.close();
    delete [] content;
    return "Successful!\nThe left show how your code strong.";
}
