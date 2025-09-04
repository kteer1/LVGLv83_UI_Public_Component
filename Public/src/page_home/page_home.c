#include "page_home.h"

#include "../../driveconf.h"

lv_obj_t* khome_t;


static void example_Anim_StartCallBack(void *fanim, int32_t fvar);

void kPageHome_Create(void* param)
{
    khome_t = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(khome_t,lv_color_make(0x0,0x0,0x0),LV_PART_MAIN);


    // lv_obj_t* khome_bnt_t = lv_btn_create(khome_t);
    // lv_obj_set_size(khome_bnt_t, 200, 120);
    // lv_obj_align(khome_bnt_t, LV_ALIGN_CENTER, 0, 0);
    // lv_obj_clear_flag(khome_bnt_t,LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_update_layout(khome_bnt_t);


    // lv_obj_t * label = lv_label_create(khome_bnt_t);
    // lv_obj_set_user_data(label,param);
    // lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    // lv_obj_set_style_text_color(label,lv_color_make(0,0,0),LV_PART_MAIN);
    // lv_label_set_text_fmt(label, "x:%u y:%u",lv_obj_get_x(khome_bnt_t),lv_obj_get_y(khome_bnt_t));



    // lv_anim_t khome_anim_start_t;
    // /**创建一个动画 */
    // lv_anim_init(&khome_anim_start_t);
    // lv_anim_set_var(&khome_anim_start_t, label);

    // /**从下到上 */

    // lv_anim_set_values(&khome_anim_start_t, LV_OPA_0, LV_OPA_100);
    // lv_anim_set_time(&khome_anim_start_t, 500);
    // /*Set the "animator" function*/
    // lv_anim_set_exec_cb(&khome_anim_start_t, (lv_anim_exec_xcb_t) example_Anim_StartCallBack);
    // lv_anim_set_path_cb(&khome_anim_start_t, lv_anim_path_linear);
    // lv_anim_start(&khome_anim_start_t);

    /**加载屏幕 */
    lv_scr_load_anim(khome_t,LV_SCR_LOAD_ANIM_NONE,0,0,true);
}



// static void example_Anim_StartCallBack(void *fanim, int32_t fvar)
// {
//     lv_obj_set_style_text_opa((lv_obj_t*)fanim,(lv_opa_t)fvar,LV_PART_MAIN);
//     if((lv_opa_t)fvar == LV_OPA_100)
//     {
//         ui_message_t* fui_struct = (ui_message_t*)lv_obj_get_user_data((lv_obj_t*)fanim);
//         fui_struct->state|=UI_STATE_FINSHIN;
        // lv_anim_del(&klogo_obj_anim_t,NULL);
//     }
// }
