#include <stdio.h>
#include <iostream>
#include "screen_ui.h"

using namespace std;

//int item_num = 5;
screen_ui::screen_ui()
{
    //ctor
}
screen_ui::screen_ui(int i)
{
    item_num = i;
}
screen_ui::~screen_ui()
{
    //dtor
}

screen_ui::show_menu(){
    cout << "---- show_menu item_num:" << item_num << " ----" << endl;
    return 1;
}

screen_ui::show_ui(){
    cout<<"---- show UI ----"<<endl;
    show_menu();
    return 1;
}
