file(GLOB_RECURSE SOURCES   "."
                            "../../../../ESP_Drive/LCD_Drive/Bsp/lvgl_mini_v9p3/*.c"
                    )



set( INCLUDES       "." 
                    "../../../../ESP_Drive/LCD_Drive/Bsp/lvgl_mini_v9p3"
                    )

idf_component_register(
                        SRCS ${SOURCES} 
                        INCLUDE_DIRS ${INCLUDES}
                        # REQUIRES "log" "driver" "esp_lcd" "esp_common" "freertos"
)