#ifndef __ENCODER_H
#define __ENCODER_H
#include "sys.h"

#define ECODERA  PCin(0)
#define ECODERB  PCin(1)

void encoder_init(void);
float encoder_get_angle();
void lcd_show_encoder(float angle);
#endif