#ifndef MM_SAVE_H
#define MM_SAVE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// 0x801ef6a2
typedef struct SavePlayerData
{
    char pad0[0x08];
    char playerName[8]; /* 0x08 */
    short healthCapacity; /* 0x10 */
    short health; /* 0x12 */
    int8_t magicCapacity; /* 0x14 */
    int8_t magic; /* 0x15 */
    short rupees; /* 0x16 */
    char pad1[0x1e];
    bool doubleDefense; /* 0x1e */
} SavePlayerData;

extern SavePlayerData gPlayerData;

bool ModifyHealth(int unused_1, short heart);

#endif