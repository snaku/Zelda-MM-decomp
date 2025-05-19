#include "../include/MM_Audio.h"
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
        playSound(MAYBE_HEALTH_RECOVER_SOUND);
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

// FUN_80101930
bool isHealthLow()
{
    short lowHealthThreshold;

    if (gPlayerData.healthCapacity < 0x51) lowHealthThreshold = 0x10;
    else if (gPlayerData.healthCapacity < 0xa1) lowHealthThreshold = 0x18;
    else if (gPlayerData.healthCapacity < 0xf1) lowHealthThreshold = 0x20; 
    else lowHealthThreshold = 0x2c;

    return (gPlayerData.health <= lowHealthThreshold && gPlayerData.health > 0);
}

// FUN_80116088
void ModifyMagic()
{
    // TODO

    if (maybeRequestMagic)
    {
        gPlayerData.magic += 4;
        playSound(0x401f); 

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

// FUN_80115db4
bool consumeMagic(int param_1, short amount, short param_3)
{
    /* param_1 = pointer vers une structure 
    *  param_3 = ?
    */ 
    char cVar1; // ?
    bool uVar2; // undefined4 dans ghidra
    int iVar3;

    // link n'a pas encore eu la barre de magie
    if (!gPlayerData.magicAcquired)
    {
        uVar2 = false;
    }

    else
    {
        iVar3 = gPlayerData.magic;
        if (iVar3 - amount < 0)
        {
            if (gPlayerData.magicCapacity != 0)
            {
                playSound(MAYBE_ERROR_SOUND);
            }
            uVar2 = false;
        }
    }

    return uVar2;
}
