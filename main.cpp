#include <cstdlib>
#include <functional>
#include <string>
#include <map>
// czy nie lepiej uzyc gotowej kolejki?
//#include <queue>
#include "bitmap.h"
#include "improc.hpp"
//Gabriel Zinkiewicz

std:: function<void(int, int, Hentai&)> neg =neapolitan_love_slide;
std:: function<void(int, int, Hentai&)> filter = fisting;
struct operation
{
    std::string img_root = R"(D:\image_processor__skeleton\imgs\)";
    std::string input_filename ="lena.bmp" ;
    std::string output_filename = "out.bmp";
// Ta matoda jest nie potrzebna
//    Hentai All(Hentai & image)
//    {
//        image = prostating(image, neg );
//        image = prostating(image, filter);
//        return image;
//    }
};
int main() {
//    operation data;
// to ma przyjmować pola struktury w nazwach
    Hentai image_array = load_bitmap(R"(D:\image_processor__skeleton\imgs\lena_128.bmp)");
    std::map<int,std:: function<void(int, int, Hentai&)>> queue;
    queue[1] = neg;
    queue[2] = filter;
    for (auto& i: queue)
   {
       prostating(image_array, i.second);
   }
    save_bitmap(R"(D:\image_processor__skeleton\imgs\out.bmp)", image_array);

    return EXIT_SUCCESS;
}
