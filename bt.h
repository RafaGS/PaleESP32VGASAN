#ifndef BT_H
#define BT_H

// Minimal wrapper to expose ESP-IDF Bluetooth controller APIs when building
// under Arduino-ESP32. The project previously included <bt.h> which is not
// provided by all installations. Including esp_bt.h from the ESP-IDF/Arduino
// core should provide the needed symbols such as esp_bt_controller_deinit()
// and esp_bt_controller_mem_release().

#include "esp_bt.h"

#endif // BT_H
