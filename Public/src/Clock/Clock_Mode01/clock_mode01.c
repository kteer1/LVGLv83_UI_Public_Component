#include "clock_mode01.h"

#include "clock_mode01_conf.h"
#include <stddef.h>


typedef struct{
    lv_coord_t w;
    lv_coord_t h;
}clockmode01_boxsize_t;

typedef struct{
    lv_obj_t* label_obj;
    lv_obj_t* label_text;

    lv_obj_t* label_text_load;

    lv_anim_t label_anim;

    int32_t label_anim_postion;
    int32_t label_anim_postion_01;
    int32_t label_anim_postion_max;
}lv_objlabe_t;

typedef struct {
    lv_obj_t* srceen;
    lv_obj_t* class;
    lv_objlabe_t label01;/**hour */
    lv_objlabe_t label02;
    lv_objlabe_t label03;/**colorn */
    lv_objlabe_t label04;/**min */
    lv_objlabe_t label05;
}clockmode01_lv_conf_t;

typedef struct{
    uint8_t falign;
    void* fbase;
    void* fobj;
    lv_style_t* fbox_style;
    lv_style_t* ffont_style;
    clockmode01_boxsize_t box_size;
}clockmode01_create_box_t;


#define CLOCK_TIME_FONT_01  clock_time_font_48
LV_FONT_DECLARE(CLOCK_TIME_FONT_01);

#define CLOCK_TIME_FONT_02  clock_time_font_24
LV_FONT_DECLARE(CLOCK_TIME_FONT_02);
lv_font_t* clock_font01_t_ = &CLOCK_TIME_FONT_01;
lv_font_t* clock_font02_t_ = &CLOCK_TIME_FONT_02;
lv_style_t clock_box_style01_t;
lv_style_t clock_font_style01_t;
lv_style_t clock_font_style02_t;
#define CLOCK_BOX_STYLE01_COLOR         lv_color_make(0x0,0x0,0x0)
#define CLOCK_FONT_STYLE01_COLOR        lv_color_make(0xFF,0xFF,0xFF)
// #define CLOCK_FONT_STYLE01_COLOR        ~(CLOCK_BOX_STYLE01_COLOR)

clockmode01_lv_conf_t  clockmode01_struct_t;
clockmode01_time_s clockmode01_time_t = CLOCKMODE01_Deflaut(0,0,0,12);
static void ClockMode01_AnimStart(void* param);
static void ClockMode01_CreateBox(void* param,void* fbase,void* fobj,uint8_t falign,lv_style_t * fbox_style,lv_style_t * ffont_style);
static void ClockMode01_BoxUpData(void* param,uint8_t fvalue_new,uint8_t fvalue_last);

void ClockMode01_StyleInit(void)
{
    /**样式初始化 */
    static uint8_t s_sle_init_t=0;
    if(s_sle_init_t)
    {
        return;
    }

    lv_style_init(&clock_box_style01_t);
    lv_style_set_pad_top(&clock_box_style01_t,0);
    lv_style_set_pad_bottom(&clock_box_style01_t,0);
    lv_style_set_pad_left(&clock_box_style01_t,0);
    lv_style_set_pad_right(&clock_box_style01_t,0);
    lv_style_set_bg_color(&clock_box_style01_t,CLOCK_BOX_STYLE01_COLOR);
    // lv_style_set_border_opa(&clock_box_style01_t,LV_OPA_0);

    lv_style_init(&clock_font_style01_t);
    lv_style_set_text_font(&clock_font_style01_t,clock_font01_t_);
    lv_style_set_text_color(&clock_font_style01_t,CLOCK_FONT_STYLE01_COLOR);
    lv_style_set_pad_top(&clock_font_style01_t,0);
    lv_style_set_pad_bottom(&clock_font_style01_t,0);
    lv_style_set_pad_left(&clock_font_style01_t,0);
    lv_style_set_pad_right(&clock_font_style01_t,0);

    lv_style_init(&clock_font_style02_t);
    lv_style_set_text_font(&clock_font_style02_t,clock_font02_t_);
    lv_style_set_text_color(&clock_font_style02_t,CLOCK_FONT_STYLE01_COLOR);
    lv_style_set_pad_top(&clock_font_style02_t,0);
    lv_style_set_pad_bottom(&clock_font_style02_t,0);
    lv_style_set_pad_left(&clock_font_style02_t,0);
    lv_style_set_pad_right(&clock_font_style02_t,0);

    s_sle_init_t=1;
}


void ClockMode01_Create(void* param)
{
    lv_obj_t* lv_clock_t;
    ClockMode01_StyleInit();
    lv_clock_t = lv_obj_create((lv_obj_t*)param);
    lv_obj_set_size(lv_clock_t, CLOCKMODE01_BOX_With, CLOCKMODE01_BOX_HEEIGHT_0+0);
    lv_obj_align(lv_clock_t, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_bg_color(lv_clock_t,lv_color_make(0xff,0xff,0xff),LV_PART_MAIN);

    lv_obj_set_style_pad_top(lv_clock_t,0,LV_PART_MAIN);
    lv_obj_set_style_pad_bottom(lv_clock_t,0,LV_PART_MAIN);
    lv_obj_set_style_pad_left(lv_clock_t,0,LV_PART_MAIN);
    lv_obj_set_style_pad_right(lv_clock_t,0,LV_PART_MAIN);
    /** 透明的设置*/
    lv_obj_set_style_bg_opa(lv_clock_t,LV_OPA_0,LV_PART_MAIN);/**bg */
    lv_obj_clear_flag(lv_clock_t, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_opa(lv_clock_t, LV_OPA_0, LV_PART_SCROLLBAR);
  
   
    /**储存 */
    clockmode01_struct_t.srceen = (lv_obj_t*)param;
    clockmode01_struct_t.class = lv_clock_t;
    ClockMode01_CreateBox(&clockmode01_struct_t.label01,clockmode01_struct_t.class,clockmode01_struct_t.class,LV_ALIGN_LEFT_MID,&clock_box_style01_t,&clock_font_style01_t);

    ClockMode01_CreateBox(&clockmode01_struct_t.label02,clockmode01_struct_t.class,clockmode01_struct_t.label01.label_obj,LV_ALIGN_OUT_RIGHT_MID,&clock_box_style01_t,&clock_font_style01_t);

    lv_obj_t* lv_clock_colon_t;
    lv_clock_colon_t = lv_obj_create((lv_obj_t*)lv_clock_t);
    lv_obj_set_size(lv_clock_colon_t, CLOCKMODE01_BOX_With_1, CLOCKMODE01_BOX_HEEIGHT_0);
    lv_obj_align_to(lv_clock_colon_t,clockmode01_struct_t.label02.label_obj, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
    lv_obj_add_style(lv_clock_colon_t,&clock_box_style01_t,LV_PART_MAIN);

    lv_obj_t * lv_clock_colon_label_t = lv_label_create(lv_clock_colon_t);
    lv_label_set_text_fmt(lv_clock_colon_label_t, ":");
    lv_obj_add_style(lv_clock_colon_label_t,&clock_font_style01_t,LV_PART_MAIN);
    lv_obj_align(lv_clock_colon_label_t, LV_ALIGN_CENTER, CLOCKMODE01_COLON_TEXT_OFFSET_X+0, CLOCKMODE01_COLON_TEXT_OFFSET_Y+0);

    clockmode01_struct_t.label03.label_obj = lv_clock_colon_t;

    ClockMode01_CreateBox(&clockmode01_struct_t.label04,clockmode01_struct_t.class,clockmode01_struct_t.label03.label_obj,LV_ALIGN_OUT_RIGHT_MID,&clock_box_style01_t,&clock_font_style01_t);

    ClockMode01_CreateBox(&clockmode01_struct_t.label05,clockmode01_struct_t.class,clockmode01_struct_t.label04.label_obj,LV_ALIGN_OUT_RIGHT_MID,&clock_box_style01_t,&clock_font_style01_t);
}


void ClockMode01_SetTick(uint32_t ftick)
{

}


void ClockMode01_UpData(void* param)
{
    clockmode01_time_s* ftime_s = (clockmode01_time_s*)param;

    if(clockmode01_time_t.hour != ftime_s->hour)
    {
        if((clockmode01_time_t.hour%10)!=(ftime_s->hour%10))
        {
            ClockMode01_BoxUpData(&clockmode01_struct_t.label02,(ftime_s->hour%10),(clockmode01_time_t.hour%10));
        }
        if((clockmode01_time_t.hour/10)!=(ftime_s->hour/10))
        {
            ClockMode01_BoxUpData(&clockmode01_struct_t.label01,(ftime_s->hour/10),(clockmode01_time_t.hour/10));
        }
        clockmode01_time_t.hour = ftime_s->hour;
    }

    if(clockmode01_time_t.min != ftime_s->min)
    {
        if((clockmode01_time_t.min%10)!=(ftime_s->min%10))
        {
            ClockMode01_BoxUpData(&clockmode01_struct_t.label05,(ftime_s->min%10),(clockmode01_time_t.min%10));
        }
        if((clockmode01_time_t.min/10)!=(ftime_s->min/10))
        {
            ClockMode01_BoxUpData(&clockmode01_struct_t.label04,(ftime_s->min/10),(clockmode01_time_t.min/10));
        }
        clockmode01_time_t.min = ftime_s->min;
    }

}

/**====================================================== */
static void ClockMode01_CreateBox(void* param,void* fbase,void* fobj,uint8_t falign,lv_style_t * fbox_style,lv_style_t * ffont_style)
{
    lv_objlabe_t* fstruct = (lv_objlabe_t*)param;

    fstruct->label_obj = lv_obj_create((lv_obj_t*)fbase);
    lv_obj_add_style(fstruct->label_obj,fbox_style,LV_PART_MAIN);
    lv_obj_set_size(fstruct->label_obj, CLOCKMODE01_BOX_With_0, CLOCKMODE01_BOX_HEEIGHT_0);

    lv_obj_clear_flag(fstruct->label_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_opa(fstruct->label_obj, LV_OPA_0, LV_PART_SCROLLBAR);

    if(fobj != NULL)
    {
        lv_obj_align_to(fstruct->label_obj,(lv_obj_t*)fobj, falign, 0, 0);
    }
    else{
        lv_obj_align(fstruct->label_obj, falign, 0, 0);
    }
    
    lv_obj_update_layout(fstruct->label_obj);

    fstruct->label_text = lv_label_create(fstruct->label_obj);
    lv_label_set_text_fmt(fstruct->label_text,"%d",0);
    lv_obj_add_style(fstruct->label_text,ffont_style,LV_PART_MAIN);
    lv_obj_align(fstruct->label_text, LV_ALIGN_CENTER, 0, 0);
    lv_obj_update_layout(fstruct->label_text);

    // lv_coord_t foffset;
    // foffset = lv_obj_get_y(fstruct->label_text);
    // lv_obj_align(fstruct->label_text, LV_ALIGN_TOP_MID, 0, foffset);
    // lv_obj_update_layout(fstruct->label_text);

    ESP_LOGI("CLOCKMODE01","Create lv_obj_get_y(fstruct->label_text) : %d",lv_obj_get_y(fstruct->label_text));

    fstruct->label_text_load = lv_label_create(fstruct->label_obj);
    lv_obj_add_style(fstruct->label_text_load,&clock_font_style01_t,LV_PART_MAIN);
    lv_label_set_text_fmt(fstruct->label_text_load,"%d",0);
    lv_obj_align_to(fstruct->label_text_load,fstruct->label_text, LV_ALIGN_OUT_BOTTOM_MID, 0, lv_obj_get_height(fstruct->label_obj)-37);
}

static void ClockMode01_BoxUpData(void* param,uint8_t fvalue_new,uint8_t fvalue_last)
{
    lv_objlabe_t* fstruct = (lv_objlabe_t*)param;

    lv_label_set_text_fmt(fstruct->label_text, "%d",fvalue_last);

    lv_obj_update_layout(fstruct->label_text);

    ESP_LOGI("CLOCKMODE01","lv_obj_get_y(fstruct->label_text) : %d",lv_obj_get_y(fstruct->label_text));

    lv_label_set_text_fmt(fstruct->label_text_load, "%d",fvalue_new);
    lv_obj_align_to(fstruct->label_text_load,fstruct->label_text, LV_ALIGN_OUT_BOTTOM_MID, 0, lv_obj_get_height(fstruct->label_obj)-37);
    lv_obj_update_layout(fstruct->label_text_load);
    ClockMode01_AnimStart(fstruct);
}

static void ClockMode01_AnimCallBack_Text(void * param, int32_t fvalue)
{
    lv_objlabe_t* flabe_s = (lv_objlabe_t*)param;
    lv_obj_t* ftemp;
    lv_obj_set_y(flabe_s->label_text,(lv_coord_t)(-fvalue));
    // lv_obj_set_y(flabe_s->label_text,(lv_coord_t)(flabe_s->label_anim_postion-fvalue));
    lv_obj_set_y(flabe_s->label_text_load,(lv_coord_t)(flabe_s->label_anim_postion_01-fvalue));
    lv_obj_update_layout(flabe_s->label_text);
    lv_obj_update_layout(flabe_s->label_text_load);
    ESP_LOGI("CLOCKMODE01","Anim fvalue : %ld",fvalue);

    ESP_LOGI("CLOCKMODE01","Anim lv_obj_get_y(flabe_s->label_text) : %d",(lv_coord_t)lv_obj_get_y(flabe_s->label_text));
    ESP_LOGI("CLOCKMODE01","Anim lv_obj_get_y(flabe_s->label_text_load) : %d",(lv_coord_t)lv_obj_get_y(flabe_s->label_text_load));

    if(fvalue == flabe_s->label_anim_postion_max)
    {
        ftemp = flabe_s->label_text;
        flabe_s->label_text = flabe_s->label_text_load;
        flabe_s->label_text_load = ftemp;

        lv_obj_align(flabe_s->label_text, LV_ALIGN_CENTER, 0, 0);
        lv_obj_align_to(flabe_s->label_text_load,flabe_s->label_text, LV_ALIGN_OUT_BOTTOM_MID, 0, lv_obj_get_height(flabe_s->label_obj)-37);
        ESP_LOGI("CLOCKMODE01","Anim Del");
        lv_anim_del(&flabe_s->label_anim,NULL);
    }

}

static void ClockMode01_AnimStart(void* param)
{
    /**
     * param :  lv_objlabe_t
     * 启动动画
     * */
    lv_objlabe_t* flabe_s = (lv_objlabe_t*)param;
    lv_obj_update_layout(flabe_s->label_text);
    lv_obj_update_layout(flabe_s->label_text_load);
    flabe_s->label_anim_postion = lv_obj_get_y(flabe_s->label_text);
    flabe_s->label_anim_postion_01 = lv_obj_get_y(flabe_s->label_text_load);
    flabe_s->label_anim_postion_max = lv_obj_get_height(flabe_s->label_obj);
    ESP_LOGI("CLOCKMODE01","flabe_s->label_anim_postion = %ld",flabe_s->label_anim_postion);
    ESP_LOGI("CLOCKMODE01","flabe_s->label_anim_postion_01 = %ld",flabe_s->label_anim_postion_01);
    ESP_LOGI("CLOCKMODE01","flabe_s->label_anim_postion_max = %ld",flabe_s->label_anim_postion_max);
    lv_anim_init(&flabe_s->label_anim);
    lv_anim_set_var(&flabe_s->label_anim, flabe_s);
    lv_anim_set_values(&flabe_s->label_anim, 0, flabe_s->label_anim_postion_max);/**设置数值 */
    lv_anim_set_time(&flabe_s->label_anim, 1000);/**设置动画时间 */
    lv_anim_set_exec_cb(&flabe_s->label_anim, ClockMode01_AnimCallBack_Text);
    lv_anim_set_path_cb(&flabe_s->label_anim, lv_anim_path_linear);
    lv_anim_start(&flabe_s->label_anim);
    

}

