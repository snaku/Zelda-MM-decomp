#include "../include/MM_Save.h"

// FUN_80115908
bool ModifyHealth(int unused_1, short healthChange)
{
    if (healthChange < 0 && gPlayerData.doubleDefense)
    {
        healthChange >>= 1; // division par 2
    }
    else if (healthChange > 0)
    {
        // FUN_8019f0c8(0x480b); // playSound ?
    }

    gPlayerData.health += healthChange;

    if (gPlayerData.healthCapacity < gPlayerData.health)
    {
        gPlayerData.health = gPlayerData.healthCapacity;
    }
    
    if (gPlayerData.health <= 0)
    {
        gPlayerData.health = 0;
        return false; // mort
    }
    
    return true; // vivant
}
