#pragma once
#include <stdint.h>

typedef enum {
	SVC_HUND_STATE_STOP = 0,
	SVC_HUND_STATE_RUN
} svc_hund_state_t;

void svc_hund_start();
void svc_hund_stop();
uint8_t svc_hund_get_hundredths();
