#ifndef IMAGE_PROCESSOR_IMPROC_HPP
#define IMAGE_PROCESSOR_IMPROC_HPP
//Gabriel Zinkiewicz
#include "bitmap.h"

#include <string>
#include <vector>
#include <functional>
#define black 0
#include <cstring>
#define mask_size 3

template <typename T>
class Matrix
{
    size_t h, w;
    std::vector < std::vector < T >> m;
public:
    Matrix(size_t X, size_t Y,T val) : w(X), h(Y){

        for(int i = 0; i < X; i++) {
            std::vector<T> v(Y);
            for (int j = 0; j < Y; j++)
                v[j] = val;
            m.push_back(v);
        }
    }
    std::vector<T>& operator[](size_t idx){return m[idx];}
    auto begin(){return m.begin();}
    auto size(){return m.size();}
    auto end(){return m.end();}
    size_t X() { return w; }
    size_t Y() { return h; }
};

using Gimp_Mask = Matrix<double>;

class Hentai: public Matrix<byte>
{
    BITMAPFILEHEADER header;
    BITMAPINFO* BitmapInfo;
public:

    Hentai(BITMAPFILEHEADER  head, BITMAPINFO* BMP_I, size_t x, size_t y) : Matrix<byte>(x, y, 0), header(head) {
        size_t bitmap_info_size = header.bfOffBits - sizeof(BITMAPFILEHEADER);
        BitmapInfo = (BITMAPINFO *) malloc(bitmap_info_size);
        std::memcpy(BitmapInfo, BMP_I, bitmap_info_size);}
//    Hentai(const Hentai&) = delete;

    BITMAPFILEHEADER give_header(){return header;}
    BITMAPINFO* give_Bmp_I() {return  BitmapInfo;}
    ~Hentai()
    {
        free(BitmapInfo);
    }
//Tu ma być konstruktor kopiujący
};
extern void fisting(int i, int j, Hentai& img);

extern void neapolitan_love_slide (int i, int j, Hentai& pix);

extern Hentai load_bitmap(const std::string &filename);

extern int save_bitmap(const std::string &filename, Hentai &image_array);

extern Hentai& prostating(Hentai& img, std::function<void(int, int, Hentai&)> fun);

extern Gimp_Mask gimp_mask (size_t s);

#endif //IMAGE_PROCESSOR_IMPROC_HPP
