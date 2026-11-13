# Development log

## 2026-11-13 — Portable VAD

Moved the existing energy/silence detection contract into voice_core for S31 reuse. The host test uses the production source with address/undefined sanitizers; `bash tests/test_host.sh` passes. Thresholds retain the S3 baseline and require separate S31 acoustic calibration. Board validation is not implied by host tests.
