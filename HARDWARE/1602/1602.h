#ifndef __1602_H
#define __1602_H
#include "sys.h"

#define LCDRS 	PCout(2)
#define LCDRW	PCout(3)
#define LCDEN	PCout(4)
void lcd1602_init();
void lcd1602_wc(u8 arr);
void lcd1602_wd(u8 data);
void lcd1602_show(float angle);
#endif