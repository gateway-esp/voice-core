#include "voice_core/voice_vad.h"
void voice_vad_reset(voice_vad_t *v) { if (v) *v = (voice_vad_t){0}; }
void voice_vad_observe(voice_vad_t *v, const int16_t *p, size_t n) {
    if (!v || (!p && n) || !n) return;
    uint64_t e = 0; for (size_t i=0; i<n; ++i) { int64_t s=p[i]; e += (uint64_t)(s*s); }
    v->captured_samples += n;
    if (e/n > 24U*24U) { v->speech_candidate_samples += n; if (v->speech_candidate_samples >= 2048) v->speech_seen=true; v->silence_samples=0; }
    else { v->speech_candidate_samples=0; if (v->speech_seen) v->silence_samples += n; }
}
bool voice_vad_should_stop(const voice_vad_t *v, bool queued) {
    return v && v->speech_seen && v->captured_samples > (queued ? 32000U : 24000U) && v->silence_samples >= (queued ? 12800U : 16000U);
}
