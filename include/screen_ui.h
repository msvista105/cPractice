#include <string>

#ifndef SCREEN_UI_H
#define SCREEN_UI_H

extern int item_num;
//int tag = -1;
class screen_ui
{

    public:
        std::string tag;
        screen_ui();
        screen_ui(int item_num);
        virtual ~screen_ui();
        int show_ui();
        int overlay_background(std::string path);
        void set_tag(std::string tag);
        static void print(std::string msg);
    protected:
        int calculate_position();


    private:
        int show_menu();
};

#endif // SCREEN_UI_H
