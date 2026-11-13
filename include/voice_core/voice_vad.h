#pragma once
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
typedef struct { size_t captured_samples, silence_samples, speech_candidate_samples; bool speech_seen; } voice_vad_t;
void voice_vad_reset(voice_vad_t *vad);
void voice_vad_observe(voice_vad_t *vad, const int16_t *samples, size_t count);
bool voice_vad_should_stop(const voice_vad_t *vad, bool queued_capture);
