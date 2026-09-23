#include <ultra64.h>
#include "modding.h"
#include "repy_api.h"
REPY_PREINIT_ADD_NRM_TO_ALL_INTERPRETERS;
extern void *D_global_asm_8076BF38[4];

RECOMP_CALLBACK("*", recomp_on_music_bin_load) void play_music(s32 song, s32 bank, u8 *bin) {
    unsigned char *mods_folder;
    REPY_Handle song_data;
    void *new_bin;
    u32 copied;
    REPY_bool has_song_data;

    REPY_FN_SETUP;
    mods_folder = recomp_get_mod_folder_path();
    REPY_FN_SET_STR("mods_folder", (const char *) mods_folder);
    REPY_FN_SET_S32("game_song", song);
    REPY_FN_IMPORT("music_rando");
    REPY_FN_EXEC_CACHE(get_random_song, "song_data = music_rando.get_random_song_data(mods_folder, game_song)\n");
    REPY_INLINE_COMPILE_CACHE(has_song_data_check, REPY_CODE_EVAL, "song_data is not None\n");
    has_song_data = REPY_FN_EVAL_BOOL(has_song_data_check);
    if (has_song_data) {
        song_data = REPY_FN_GET("song_data");
        new_bin = recomp_alloc(0x8000);
        REPY_MemcpyFromBuffer(new_bin, 0x8000, 0, song_data);
        REPY_Release(song_data);
        D_global_asm_8076BF38[bank] = new_bin;
    }
    recomp_free(mods_folder);
    REPY_FN_CLEANUP;
}

