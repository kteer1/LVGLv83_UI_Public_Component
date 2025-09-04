file(GLOB_RECURSE SOURCES   "."
                            "../*.c"
                    )



set( INCLUDES       "." 
                    "../"
                    )

idf_component_register(
                        SRCS ${SOURCES} 
                        INCLUDE_DIRS ${INCLUDES}
                        # REQUIRES "log" "driver" "esp_lcd" "esp_common" "freertos"
)