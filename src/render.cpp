#include <lvgl.h>
#include <Windows.h>
#include <iostream>

/**
 * Create a button with a label and react on click event.
 */
void createButton(void)
{
    std::cout << "displ " << lv_screen_active() << std::endl;

    lv_obj_t* btn = lv_button_create(lv_screen_active());     /*Add a button the current screen*/
    lv_obj_set_pos(btn, 10, 10);                            /*Set its position*/
    lv_obj_set_size(btn, 120, 50);                          /*Set its size*/

    lv_obj_t* label = lv_label_create(btn);          /*Add a label to the button*/
    lv_label_set_text(label, "Settings");                     /*Set the labels text*/
    lv_obj_center(label);
}