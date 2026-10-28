idf_component_register(
    SRCS "app_main.cpp" "box_show.cpp"
    INCLUDE_DIRS "."
    REQUIRES
        espressif__esp_matter
        espressif__led_strip
        nvs_flash
        esp_timer
        driver
)

set_property(TARGET ${COMPONENT_LIB} PROPERTY CXX_STANDARD 17)
target_compile_options(${COMPONENT_LIB} PRIVATE "-DCHIP_HAVE_CONFIG_H")
