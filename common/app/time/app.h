#include "common/app/app.h"
#include "common/app/apps.h"
#include "common/svc/svc.h"
#include "common/svc/hundredths.h"
#include "common/hal/hal.h"
#include "common/hal/lcd_segments.h"
typedef enum {
	BASE_DEC = 0,
	BASE_HEX,
	BASE_BIN,
	BASE_HUND,
} base_t;

typedef struct {
	APP_PRIV_COMMON
	base_t *base;
	svc_lang_t *lang;
	svc_menu_state_t conf_state;
	uint8_t display_date;
	uint8_t needs_clear;
	hal_rtc_timedate_t td_last;
} priv_t;

#define PRIV(a) ((priv_t*)((a)->priv))

void app_app_time_display_main(uint8_t view, const app_t *app, svc_main_proc_event_t event);
void app_app_time_display_enter(uint8_t view, const app_t *app);
