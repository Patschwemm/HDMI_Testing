#include <lvgl.h>
#include <render.hpp>
#include <iostream>

void init_lvgl_windows(void)
{
    lv_init();

    int32_t zoom_level = 100;
    bool allow_dpi_override = false;
    bool simulator_mode = false;
    lv_display_t* display = lv_windows_create_display(
        L"LVGL Display Window",
        800,
        480,
        zoom_level,
        allow_dpi_override,
        simulator_mode);

    if (!display) {
        std::cerr << "Failed to create display" << std::endl;
        return;
    }

    // Set display as default
    lv_disp_set_default(display);

    HWND window_handle = lv_windows_get_display_window_handle(display);
    if (!window_handle) {
        std::cerr << "Failed to get window handle" << std::endl;
        return;
    }

    lv_indev_t* pointer_indev = lv_windows_acquire_pointer_indev(display);
    if (!pointer_indev) {
        std::cerr << "Failed to acquire pointer input device" << std::endl;
        return;
    }

    lv_indev_t* keypad_indev = lv_windows_acquire_keypad_indev(display);
    if (!keypad_indev) {
        std::cerr << "Failed to acquire keypad input device" << std::endl;
        return;
    }

    lv_indev_t* encoder_indev = lv_windows_acquire_encoder_indev(display);
    if (!encoder_indev) {
        std::cerr << "Failed to acquire encoder input device" << std::endl;
        return;
    }

    // Create the main screen
    lv_obj_t* main_screen = lv_win_create(lv_scr_act());
    lv_scr_load(main_screen);

    createButton();
}
