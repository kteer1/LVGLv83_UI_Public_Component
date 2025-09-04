#ifndef ___kDRIVECONF_H__
#define ___kDRIVECONF_H__

#include "src/src_enum.h"
#include "src/src_type.h"

#include "../../ESP_Drive/LCD_Drive/lcd_drive.h"
#include "../../ESP_Drive/LCD_Drive/Bsp/lvgl_mini_v9p3/lvgl.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

#include "esp_log.h"



#define kPrint_LOG         ESP_LOGI

/**UI DISP OPERTION */
#define UI_DISP_HOR         EXAMPLE_LCD_H_RES
#define UI_DISP_VER         LVGL_Disp_BUFF_SIZE
#define UI_BYTE_PER_PIXEL   1

#endif // DRIVE_H


