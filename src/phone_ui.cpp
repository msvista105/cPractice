#include "phone_ui.h"
#include <iostream>


phone_ui::phone_ui()
{
    //ctor
}

phone_ui::~phone_ui()
{
    //dtor
}

screen_ui::calculate_position(){
    std::cout << "calculate position !!" << std::endl;
    return 1;
}

phone_ui::re_calculate(){
    return calculate_position();
}

/**< phone_ui::calculate_position(){
    std::cout << "calculate position !!" << std::endl;
    return 1;
}
 */
