#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include "voice_core/voice_vad.h"
int main(void) {
    int16_t speech[2048], silence[24000] = {0};
    for (size_t i=0; i<2048; ++i) speech[i]=100;
    voice_vad_t v; voice_vad_reset(&v); voice_vad_observe(&v,speech,2048);
    assert(v.speech_seen && !voice_vad_should_stop(&v,false));
    voice_vad_observe(&v,silence,24000); assert(voice_vad_should_stop(&v,false));
    puts("voice VAD host tests passed"); return 0;
}
