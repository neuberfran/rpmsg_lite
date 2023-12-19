#Description: Serial Manager USB CDC; user_visible: True
include_guard(GLOBAL)
message("component_serial_manager_usb_cdc component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/fsl_component_serial_port_usb.c
    ${CMAKE_CURRENT_LIST_DIR}/usb_cdc_adapter/usb_device_descriptor.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
    ${CMAKE_CURRENT_LIST_DIR}/usb_cdc_adapter
)

#OR Logic component
if(${MCUX_DEVICE} STREQUAL "MIMXRT1166_cm4")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1166_cm7")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1052")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MK22F12810")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT633S_cm33")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1064")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC5526")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC54607")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC54S016")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC54606")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC54616")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "K32L2B31A")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC54016")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC54018")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC54628")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC5512")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MK22F51212")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1173_cm4")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1173_cm7")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC5516")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC54605")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1051")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC54618")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1021")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT555S_cm33")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC54018M")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC5514")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC55S16")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "K32L2B11A")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1062")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC54S018")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1042")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1176_cm4")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1173_cm4")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1175_cm4")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1176_cm7")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1171_cm7")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1173_cm7")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1172_cm7")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1175_cm7")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC54S018M")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MK22F25612")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "K32L2B21A")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1061")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC5528")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1165_cm4")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1165_cm7")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC55S66_cm33_core0")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC54S005")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC55S69_cm33_core0")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "K32L2A31A")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1024")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1011")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC54005")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC55S28")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT533S_cm33")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC55S14")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC55S26")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "K32L2A41A")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "LPC54608")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT685S_cm33")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT595S_cm33")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1015")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MK64F12")
    include(driver_sysmpu)
endif()
if(${MCUX_DEVICE} STREQUAL "MK63F12")
    include(driver_sysmpu)
endif()
if(${MCUX_DEVICE} STREQUAL "MK24F12")
    include(driver_sysmpu)
endif()
if(${MCUX_DEVICE} STREQUAL "MK66F18")
    include(driver_sysmpu)
endif()
if(${MCUX_DEVICE} STREQUAL "MK65F18")
    include(driver_sysmpu)
endif()
if(${MCUX_DEVICE} STREQUAL "MK26F18")
    include(driver_sysmpu)
endif()

include(driver_common)
include(middleware_usb_device_cdc_external)
