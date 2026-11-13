idf_component_register(SRCS "src/voice_core.c" "src/voice_mcp_json.c" "src/voice_vad.c"
                       INCLUDE_DIRS "include" PRIV_REQUIRES cjson)
