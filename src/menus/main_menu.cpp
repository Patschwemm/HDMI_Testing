#include <lvgl.h>
#include <iostream>
#include <widgets/image.hpp>
#include <widgets/button.hpp>

void main_menu() {
	
	// init lv png decoder
	
	// initialize main screen
	lv_obj_t* main_screen = lv_obj_create(NULL);
	
	const char* imgpath = "D:\\VisualStudio\\Repositories\\HDMI_Testing\\pics\\rotoclear_testing.bin";
	// Set background
	image_from_path(main_screen, imgpath , true, 0.5);

	// Set a button
	createLabelButton(main_screen, "Settings", 10, 10);

	 lv_scr_load(main_screen);
}
