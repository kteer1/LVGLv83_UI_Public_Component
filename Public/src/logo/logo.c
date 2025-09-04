#include "logo.h"
#include "../../driveconf.h"


static char* TAG="Logo";



lv_obj_t* klogo_obj_t;
lv_anim_t klogo_obj_anim_t;
void LogoAnim_EventCallBack(void *fanim, int32_t fvar)
{
    lv_obj_set_style_text_opa((lv_obj_t*)fanim,(lv_opa_t)fvar,LV_PART_MAIN);
    if((lv_opa_t)fvar == LV_OPA_100)
    {
        ui_message_t* fui_struct = (ui_message_t*)lv_obj_get_user_data((lv_obj_t*)fanim);
        fui_struct->state|=UI_STATE_FINSHIN;
        lv_anim_del(&klogo_obj_anim_t,NULL);
    }
}



void kLogo_TaskHandle(void* param)
{
    klogo_obj_t = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(klogo_obj_t,lv_color_make(0x0,0x0,0x0),LV_PART_MAIN);


    lv_obj_t * label = lv_label_create(klogo_obj_t);
    lv_obj_set_user_data(label,param);
    lv_label_set_text(label, "Hello word!");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_color(label,lv_color_make(0xff,0xff,0xff),LV_PART_MAIN);
    lv_obj_set_style_text_opa(label,LV_OPA_0,LV_PART_MAIN);

    /**创建一个动画 */
    lv_anim_init(&klogo_obj_anim_t);
    lv_anim_set_var(&klogo_obj_anim_t, label);
    lv_anim_set_values(&klogo_obj_anim_t, LV_OPA_0, LV_OPA_100);
    lv_anim_set_time(&klogo_obj_anim_t, 500);
    /*Set the "animator" function*/
    lv_anim_set_exec_cb(&klogo_obj_anim_t, (lv_anim_exec_xcb_t) LogoAnim_EventCallBack);
    lv_anim_set_path_cb(&klogo_obj_anim_t, lv_anim_path_linear);
    lv_anim_start(&klogo_obj_anim_t);
    // lv_screen_load(klogo_obj_t);/**加载屏幕 */ 
    lv_scr_load_anim(klogo_obj_t,LV_SCR_LOAD_ANIM_NONE,0,0,true);
}

