#include <stdio.h>
#include <stdint.h>
#include <math.h>

typedef struct Actor
{
    char pad0[0x24];
    float x; /* 0x24 */
    float y; /* 0x28 */
    float z; /* 0x2c */
    char pad1[0x38];
    float velocity_x; /* 0x64 */
    float velocity_y; /* 0x68 */
    float velocity_z; /* 0x6c */
    char pad2[0x38];
    float accel_x; /* 0xa4 */
    float accel_y; /* 0xa8 */
    float accel_z; /* 0xac */
} Actor;

extern float gDeltaTime;

void updateActorPosition(Actor* actor);