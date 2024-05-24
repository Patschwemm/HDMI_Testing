#include <lvgl.h>
#include <iostream>
#include <widgets/image.hpp>
#include <widgets/button.hpp>

void main_menu() {
	
	// initialize main screen
	lv_obj_t* main_screen = lv_obj_create(NULL);
	
	const char* imgpath = "C:\\Users\\patrick.schwemmer\\Documents\\GitHub\\HDMI_Testing\\pics\\rotoclear_testing.bin";
	// Set background
	image_from_path(main_screen, imgpath , false);

	// Set a button
	createLabelButton(main_screen, "Settings", 10, 10);

	lv_scr_load(main_screen);
}
