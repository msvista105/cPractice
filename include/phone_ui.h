#include "screen_ui.h"

#ifndef PHONE_UI_H
#define PHONE_UI_H


class phone_ui : public screen_ui
{
    public:
        phone_ui();
        virtual ~phone_ui();
        int re_calculate();

    protected:
        //int calculate_position();

    private:
};

#endif // PHONE_UI_H
