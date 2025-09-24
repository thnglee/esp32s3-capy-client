
#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

// 如果使用 Duplex I2S 模式，请注释下面一行
#define AUDIO_I2S_METHOD_SIMPLEX

#ifdef AUDIO_I2S_METHOD_SIMPLEX
  // === MIC INMP441 (theo dây của bạn) ===
  #define AUDIO_I2S_MIC_GPIO_WS    GPIO_NUM_2   // WS/LRCLK
  #define AUDIO_I2S_MIC_GPIO_SCK   GPIO_NUM_3   // SCK/BCLK
  #define AUDIO_I2S_MIC_GPIO_DIN   GPIO_NUM_4   // SD -> ESP

  // === LOA MAX98357A (theo dây của bạn) ===
  #define AUDIO_I2S_SPK_GPIO_DOUT  GPIO_NUM_5   // ESP -> DIN (amp)
  #define AUDIO_I2S_SPK_GPIO_BCLK  GPIO_NUM_6   // BCLK
  #define AUDIO_I2S_SPK_GPIO_LRCK  GPIO_NUM_7   // LRCLK/WS

  // (bridge macro – nhiều file codec dùng tên tổng quát)
  #define AUDIO_I2S_GPIO_BCLK  AUDIO_I2S_SPK_GPIO_BCLK
  #define AUDIO_I2S_GPIO_WS    AUDIO_I2S_SPK_GPIO_LRCK
  #define AUDIO_I2S_GPIO_DOUT  AUDIO_I2S_SPK_GPIO_DOUT
  #define AUDIO_I2S_GPIO_DIN   AUDIO_I2S_MIC_GPIO_DIN

#else
  // DUPLEX (không dùng vì bạn đang đấu 2 bộ clock khác nhau)
  #define AUDIO_I2S_GPIO_WS    GPIO_NUM_7
  #define AUDIO_I2S_GPIO_BCLK  GPIO_NUM_6
  #define AUDIO_I2S_GPIO_DIN   GPIO_NUM_4
  #define AUDIO_I2S_GPIO_DOUT  GPIO_NUM_5
#endif

/*#ifdef AUDIO_I2S_METHOD_SIMPLEX

#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_4
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_5
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_6
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_7
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_15
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_16

#else

#define AUDIO_I2S_GPIO_WS GPIO_NUM_4
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_5
#define AUDIO_I2S_GPIO_DIN  GPIO_NUM_6
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_7

#endif*/

// LED + Buttons (ESP32-S3 Super Mini)
#define BUILTIN_LED_GPIO          GPIO_NUM_12   // nếu không có LED: dùng GPIO_NUM_NC
#define BOOT_BUTTON_GPIO          GPIO_NUM_0    // nút BOOT có sẵn trên board
#define TOUCH_BUTTON_GPIO         GPIO_NUM_1    // WAKE
#define VOLUME_UP_BUTTON_GPIO     GPIO_NUM_10   // Vol+
#define VOLUME_DOWN_BUTTON_GPIO   GPIO_NUM_11   // Vol-

/*#define BUILTIN_LED_GPIO        GPIO_NUM_48
#define BOOT_BUTTON_GPIO        GPIO_NUM_0
#define TOUCH_BUTTON_GPIO       GPIO_NUM_47
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_40
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_39*/

#define DISPLAY_SDA_PIN GPIO_NUM_8
#define DISPLAY_SCL_PIN GPIO_NUM_9
#define DISPLAY_WIDTH   128

#if CONFIG_OLED_SSD1306_128X32
#define DISPLAY_HEIGHT  32
#elif CONFIG_OLED_SSD1306_128X64
#define DISPLAY_HEIGHT  64
#elif CONFIG_OLED_SH1106_128X64
#define DISPLAY_HEIGHT  64
#define SH1106
#else
#error "未选择 OLED 屏幕类型"
#endif

#define DISPLAY_MIRROR_X true
#define DISPLAY_MIRROR_Y true


// A MCP Test: Control a lamp
#define LAMP_GPIO GPIO_NUM_18

#endif // _BOARD_CONFIG_H_
