#ifndef MM_ITEM_H
#define MM_ITEM_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum Items
{
    ARROW_ITEM,
    BOMB_ITEM,
    DEKU_STICK_ITEM
} Items;

void changeItemAmmo(short item, short amount);

#endif