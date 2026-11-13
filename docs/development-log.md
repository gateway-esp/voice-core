# Development log

## 2026-11-13 — Source layout

Implementation is now under src/, public headers remain include/voice_core/. Updated component and host test paths including the S31 integration test. Full host suite and S3 gateway build pass. No API or runtime changes.

## 2026-11-13 — Portable VAD

Moved the existing energy/silence detection contract into voice_core for S31 reuse. The host test uses the production source with address/undefined sanitizers; `bash tests/test_host.sh` passes. Thresholds retain the S3 baseline and require separate S31 acoustic calibration. Board validation is not implied by host tests.
