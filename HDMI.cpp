// HDMI.cpp : Defines the entry point for the application.
#include <lvgl.h>
#include <Windows.h>
#include <iostream>
#include <render.hpp>
#include <init.hpp>

int main()
{
    init_lvgl_windows();
    createButton();

    // Main loop to handle LVGL tasks
    while (1)
    {
        uint32_t time_till_next = lv_timer_handler();
        Sleep(time_till_next);
    }

    return 0;
}