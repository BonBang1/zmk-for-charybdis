#include <lvgl.h>
#include <zmk/display/status_screen.h>
#include <zmk/display/widgets/output_status.h>
#include <zmk/display/widgets/battery_status.h>
#include <zmk/display/widgets/layer_status.h>
#include <zmk/display/widgets/wpm_status.h>
/* 声明 ZMK 内置的部件变量 */
static struct zmk_widget_output_status output_status_widget;
static struct zmk_widget_layer_status layer_status_widget;
static struct zmk_widget_battery_status battery_status_widget;
static struct zmk_widget_wpm_status wpm_status_widget;
/* 自定义布局初始化函数 */
lv_obj_t * zmk_display_status_screen() {
/* 创建一个全屏的基础透明容器 */
lv_obj_t * screen = lv_obj_create(NULL);
/* * 1. 电池状态 (Battery)
* 放在顶部居中，Y轴下移 30 像素，避开屏幕顶部的弧形切边
*/
zmk_widget_battery_status_init(&battery_status_widget, 
screen);
lv_obj_align(zmk_widget_battery_status_obj(&battery_status_widget)
, LV_ALIGN_TOP_MID, 0, 30);
/* * 2. 输出状态 (Output / 蓝牙 / USB)
* 放在电池下方，Y轴下移 70 像素
*/
zmk_widget_output_status_init(&output_status_widget, screen);
lv_obj_align(zmk_widget_output_status_obj(&output_status_widget), 
LV_ALIGN_TOP_MID, 0, 70);
/* * 3. 层级状态 (Layer)
* 作为核心信息，放置在屏幕绝对正中心
*/
zmk_widget_layer_status_init(&layer_status_widget, screen);
lv_obj_align(zmk_widget_layer_status_obj(&layer_status_widget), 
LV_ALIGN_CENTER, 0, 0);
/* * 4. 打字速度 (WPM)
* 放在底部居中，Y轴上移 30 像素，避开屏幕底部的弧形切边
*/
zmk_widget_wpm_status_init(&wpm_status_widget, screen);
lv_obj_align(zmk_widget_wpm_status_obj(&wpm_status_widget), 
LV_ALIGN_BOTTOM_MID, 0, -30);
return screen;
}
