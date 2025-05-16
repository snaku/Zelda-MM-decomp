#ifndef MM_PLAYER_H
#define MM_PLAYER_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

struct SavePlayerData;

bool ModifyHealth(int unused_1, short heart);
void ModifyMagic();
void addMagic(int unused_1, short amount);
int FUN_80115db4(int param_1, short param_2, short param_3);

#endif
