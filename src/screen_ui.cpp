#include <stdio.h>
#include <iostream>
#include "screen_ui.h"
//#include <string>

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
    cout << "~screen_ui , item_num is " << item_num << "; this :"  << this << ", tag is" << tag << endl;
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

screen_ui::overlay_background(string path){
    if(path.find("png") != string::npos){
        cout << "find png image " << endl;
    }
    return 1;
}
void screen_ui::set_tag(string t){
    tag = t;
}
