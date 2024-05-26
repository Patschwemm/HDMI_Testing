#include <lvgl.h>
#include <lv_examples.h>
#include <iostream>


static void settingOnClick(lv_event_t* e) {
    lv_obj_t* btn = lv_event_get_target_obj(e);


}

void createLabelButton(lv_obj_t* screen, const char* labeltext, int xpos, int ypos)
{   
    // Add button to current screen
    lv_obj_t* btn = lv_button_create(screen);     
    // Set size and position
    lv_obj_set_pos(btn, xpos, ypos);                           
    lv_obj_set_size(btn, 120, 50);
    // Add label and set label text - center label
    lv_obj_t* label = lv_label_create(btn);          
    lv_label_set_text(label, labeltext);                     
    // Add event
    lv_obj_add_event_cb(btn, settingOnClick, LV_EVENT_CLICKED, NULL);

    lv_obj_center(label);

}
