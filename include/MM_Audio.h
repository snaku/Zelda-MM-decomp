#ifndef MM_AUDIO_H
#define MM_AUDIO_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// macros temporaires
#define MAYBE_HEALTH_RECOVER_SOUND 0x480b
#define MAYBE_ERROR_SOUND 0x4806

void playSound(int audioID);

#endif