#include "../include/MM_Actor.h"

float gDeltaTime = 0.0f;

// FUN_800b69ac
void updateActorPosition(Actor* actor)
{
    float fVar1 = actor->velocity_x * gDeltaTime;
    float fVar2 = actor->velocity_y * gDeltaTime; 
    float fVar3 = actor->velocity_z * gDeltaTime;

    actor->x = actor->x + fVar1 + actor->accel_x;
    actor->y = actor->y + fVar2 + actor->accel_y;
    actor->z = actor->z + fVar3 + actor->accel_z;
}
