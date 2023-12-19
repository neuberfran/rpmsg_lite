#Description: Driver mdio-enet-qos; user_visible: True
include_guard(GLOBAL)
message("driver_mdio-enet-qos component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/fsl_enet_qos_mdio.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)


include(driver_enet_qos)
include(driver_mdio-common)
