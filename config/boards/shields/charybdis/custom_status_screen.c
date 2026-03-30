#include <zmk/display/status_screen.h>
#include <lvgl.h>
#include <zmk/events/battery_state_changed.h>
#include <zmk/ble.h>
#include <zmk/endpoints.h>

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen, lv_color_black(), 0);

    // 1. 中心显示当前层级 (Layer)
    lv_obj_t *layer_label = lv_label_create(screen);
    lv_label_set_text(layer_label, "LAYER 0");
    lv_obj_align(layer_label, LV_ALIGN_CENTER, 0, -20);
    lv_obj_set_style_text_color(layer_label, lv_palette_main(LV_PALETTE_ORANGE), 0);
    lv_obj_set_style_text_font(layer_label, &lv_font_montserrat_24, 0);

    // 2. 顶部显示电池图标和百分比
    lv_obj_t *bat_label = lv_label_create(screen);
    lv_label_set_text(bat_label, LV_SYMBOL_BATTERY " 100%");
    lv_obj_align(bat_label, LV_ALIGN_TOP_MID, 0, 40);

    // 3. 底部显示蓝牙状态
    lv_obj_t *conn_label = lv_label_create(screen);
    lv_label_set_text(conn_label, LV_SYMBOL_BLUETOOTH " ACTIVE");
    lv_obj_align(conn_label, LV_ALIGN_BOTTOM_MID, 0, -40);
    lv_obj_set_style_text_color(conn_label, lv_palette_main(LV_PALETTE_BLUE), 0);

    return screen;
}
