idf_component_register(SRCS "voice_core.c" "voice_mcp_json.c" "voice_vad.c"
                       INCLUDE_DIRS "include" PRIV_REQUIRES cjson)
