#ifndef SCREEN_UI_H
#define SCREEN_UI_H

extern int item_num;
class screen_ui
{

    public:
        screen_ui();
        screen_ui(int item_num);
        virtual ~screen_ui();
        int show_ui();

    protected:

    private:
        int show_menu();
};

#endif // SCREEN_UI_H
