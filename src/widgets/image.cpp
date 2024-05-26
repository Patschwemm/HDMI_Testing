#include <lvgl.h>

void image_from_path(lv_obj_t * screen, const char* path, bool background, double sizescale) {
	// Declare the image
	lv_obj_t* img = lv_img_create(screen);
	// Get IMG from path
	lv_img_set_src(img, path);

	// Set size
	lv_obj_set_size(img, lv_disp_get_hor_res(NULL), lv_disp_get_ver_res(NULL));
	// LVGL image scale corresponds to 256 = 100% and 512 = 200%
	lv_img_set_zoom(img, 256 * sizescale);

	if (background) {
		lv_obj_move_background(img);
	}
	lv_obj_center(img);

	lv_obj_update_layout(screen);
}

