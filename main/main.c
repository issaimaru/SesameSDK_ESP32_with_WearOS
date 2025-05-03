#include "secrets.h"
#include "blecent.h"
#include "nvs_flash.h"
#include "ssm_cmd.h"

static const char * TAG = "main.c";

static void ssm_action_handle(sesame * ssm) {
    ESP_LOGI(TAG, "[ssm_action_handle][ssm status: %s]", SSM_STATUS_STR(ssm->device_status));
    if (ssm->device_status == SSM_UNLOCKED) {
        ssm_lock(NULL, 0);
    }
}

void app_main(void) {
    ESP_LOGI(TAG, "SesameSDK_ESP32 [11/24][087]");
    nvs_flash_init();
    ssm_init(ssm_action_handle);
    memcpy(p_ssms_env->ssm.addr, SSM_ADDR , 6);
    memcpy(p_ssms_env->ssm.device_secret, SSM_SECRET, 16);
    esp_ble_init();
}
