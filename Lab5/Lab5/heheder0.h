#pragma once

#include <string>
#include <iostream>
using namespace std;


typedef struct {
    int8_t id[2];
    int32_t filesize;
    int16_t reserved[2];
    int32_t headersize;
    int32_t infoSize;
    int32_t width;
    int32_t depth;
    int16_t biPlanes;
    int16_t bits;
    int32_t biCompression;
    int32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    int32_t biClrUsed;
    int32_t biClrImportant;
} BMPHEAD;

typedef struct {
public:
    int8_t redComponent;
    int8_t greenComponent;
    int8_t blueComponent;
} RGBQUAD;

class picture {
    
    BMPHEAD header;
    RGBQUAD  **array;
    
public:
    picture() {};
    void writePicture();
};

void picture::writePicture()
{
    string line; line = "";  // путь к файлу для записи
    
    const char *file = line;
    
    FILE *fp2 = fopen(file, "wb");
    
    int32_t headerDepthOld = header.depth; // размеры исходника
    int32_t headerWidthOld = header.width;
    
    header.depth = int(header.depth * factor);
    header.width = int(header.width * factor); // NEW EDIT
    

}
