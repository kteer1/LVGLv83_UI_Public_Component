#include "page.h"
#include "../../driveconf.h"
#include "../src_type.h"

unsigned char screen_pageuser[SCREEN_PAGELIST_MAX];
lv_obj_t* screen_pagelist_t[SCREEN_PAGELIST_MAX];


// void* Get_FreePageUID(void)
// {

// }

// void* Get_PageUID(void)
// {
//     unsigned char fuid;
//     unsigned char i=0;
//     for(i=0;i<SCREEN_PAGELIST_MAX;i++)
//     {
//         if(screen_pagelist_t[fuid]==NULL)
//         {
//             return screen_pagelist_t[fuid];
//         }
//     }
//     return NULL;
    
// }

// void* Del_PageUID(void* param)
// {

// }



void kPage_Init(void* param)
{   
    // unsigned char i;
    // for(i=0;i<SCREEN_PAGELIST_MAX;i++)
    // {
    //     screen_pagelist_t[i] = lv_obj_create(NULL);
    // }
    screen_pagelist_t[kPAGE_SCREEN_0] = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen_pagelist_t[kPAGE_SCREEN_0],lv_color_make(0x0,0x0,0x0),LV_PART_MAIN);
    lv_scr_load(screen_pagelist_t[kPAGE_SCREEN_0]);/**加载屏幕 */
}

