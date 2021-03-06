#pragma once
#include <stdint.h>

typedef struct {
	uint16_t freq;
	uint16_t duration;
} svc_melody_note_t;

extern const svc_melody_note_t *svc_melodies[];
extern const uint8_t svc_melodies_n;

void svc_melody_play(uint8_t melody);
void svc_melody_play_repeat(uint8_t melody, uint8_t rep);
void svc_melody_stop(void);
void svc_aux_timer_melody_handler(void);
