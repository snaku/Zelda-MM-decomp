#include "../include/MM_Save.h"
#include "../include/MM_Player.h"

SavePlayerData gPlayerData;
short magicAmount = 0;
bool maybeRequestMagic = false;

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

// FUN_80116088
void ModifyMagic()
{
    // TODO

    if (maybeRequestMagic)
    {
        gPlayerData.magic += 4;
        // FUN_8019f0c8(0x401f); playSound

        if (gPlayerData.magic >= gPlayerData.magicCapacity)
        {
            gPlayerData.magic = gPlayerData.magicCapacity;
            if ((magicAmount + -4) < 0)
            {
                
            }
        }

        magicAmount = 0;
        maybeRequestMagic = false;
    }
}

// FUN_80115d14
void addMagic(int unused_1, short amount)
{
    if (gPlayerData.magic < gPlayerData.magicCapacity)
    {
        maybeRequestMagic = true;
        magicAmount += amount;
    }
}


int FUN_80115db4(int param_1, short param_2, short param_3)
{
    // TODO

    int uVar2;
    int iVar3;

    if (!gPlayerData.magicAcquired)
    {
        uVar2 = 0;
    }
    else
    {
        iVar3 = gPlayerData.magic;
        if (iVar3 - param_2 < 0)
        {
            if (gPlayerData.magicCapacity != 0)
            {
                // playSound(0x4806);
            }
            uVar2 = 0;
        }
    }

    return uVar2;
}
