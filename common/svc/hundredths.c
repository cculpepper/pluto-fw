#include "hundredths.h"
#include "aux_timer.h"
#include "common/hal/hal.h"
#include "common/svc/svc.h"
#include <string.h>

#define N_hund 2
uint8_t svc_hund_n = N_hund;

typedef struct {
	svc_hund_state_t state;
	uint8_t min;
	uint8_t hundredths;
	uint8_t subsec;
} svc_hund_t;

static svc_hund_t hund_data;

static void svc_hund_inc() {
	hal_rtc_timedate_t td;
	hal_rtc_get(&td);
	if (hund_data.min != td.m){
		/* Then we need to go back to zero on the hundredths and start counting again. */ 
		hund_data.subsec = 0;
		hund_data.min = td.m;
		hund_data.hundredths = 0;
	}
	else {
		hund_data.subsec++;
		if(hund_data.subsec == 77) { /* 77 is pretty close to number of 1/128 seconds in 1/100 of a minute Actual is 76.8*/ 
			hund_data.subsec = 0;
			hund_data.hundredths++;
			if(hund_data.hundredths == 100) {
				hund_data.hundredths = 0;
			}
		}
	}
}

void svc_aux_timer_hund_handler(void) {
	svc_hund_inc();
	svc_aux_timer_set_call_main();
}

void svc_hund_start(void) {
	/*svc_aux_timer_set_required(SVC_AUX_TIMER_REQUIRED_HUND, 1);*/
	hal_rtc_timedate_t td;
	hal_rtc_get(&td);
	hund_data.subsec = ((td.s*100)/60);
	hund_data.min = td.m;
	hund_data.hundredths = 0;
}

void svc_hund_stop(void) {
	/* Also need to stop the aux timer */ 
	/*svc_aux_timer_set_required(SVC_AUX_TIMER_REQUIRED_HUND, 0);*/

}

uint8_t svc_hund_get_hundredths(void){
	/*return hund_data.hundredths;*/
	hal_rtc_timedate_t td;
	hal_rtc_get(&td);
	return (int)((td.s*100.0)/60.0);
}

