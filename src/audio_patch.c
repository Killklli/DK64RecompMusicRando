#include <ultra64.h>
#include "modding.h"
typedef struct SynthConfig {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    ALHeap *unk14;
    s32 unk18;
    u8 unk1C;
    u8 unk1D;
    u8 pad1E[2];
    s32 unk20;
    s32 unk24;
} SynthConfig;

typedef struct {
    u8 unk0[0xEC];
} struct_sub_8076C328;

typedef struct {
    struct_sub_8076C328 unk0[4];
} struct_8076C328;

extern struct_8076C328 D_global_asm_8076C328[];

typedef struct Struct80600D50_sp60 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Struct80600D50_sp60;

typedef struct OverlayInfoStruct {
    s32 rom_code_start;
    s32 rom_data_end;
    void *rdram_start;
    void *overlay_end;
    void *rdram_code_end;
    void *rdram_data_end;
} OverlayInfoStruct;

typedef struct SeqpConfig {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
    u8 padA[2];
    ALHeap *unkC;
    void *unk10;
    void *unk14;
    void *unk18;
    s32 unk1C;
} SeqpConfig;

typedef struct UnkConfig {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    ALHeap *unkC;
    s16 unk10;
} UnkConfig;

void func_global_asm_80737E50(ALCSPlayer *);
void func_global_asm_80737F0C(ALSeqPlayer*, s32, u8);
void func_global_asm_80738080(ALSeqPlayer*, u8, u8);
void func_global_asm_807380CC(ALSeqPlayer*, s32, u8);
void func_global_asm_80738118(ALSeqPlayer*, s32, u8);
void func_global_asm_80601A10(SynthConfig *, s32, Struct80600D50_sp60 *);
void func_global_asm_80732DEC(SeqpConfig *, s32);
void func_global_asm_80732F10(ALSeqPlayer *, SeqpConfig *);
void func_global_asm_80735AA0(UnkConfig *);
void _free(void *ptr);
void func_global_asm_8060B140(u32 arg0, void *arg1, s32 *arg2, u8 arg3, u8 arg4, u8 arg5, u8 *arg6);
void func_global_asm_80735A50(ALSeqPlayer *arg0, ALBank *arg1);
void func_global_asm_806010A0(void);
void func_global_asm_80737C20(s32 arg0);
void func_global_asm_80737CF4(s32 arg0, s32 arg1);
void func_global_asm_80601CC0(void);
extern u16 D_global_asm_8076BF30[];
extern void *D_global_asm_8076BF38[];
extern ALHeap D_global_asm_8076D1E8;
extern ALBank *D_global_asm_8076D1FC;
extern u8 D_global_asm_80770F50;
extern s32 D_global_asm_807452B0[];
extern OverlayInfoStruct gOverlayTable[];
extern ALBank *D_global_asm_8076D1F8;
extern ALSeqPlayer *D_global_asm_8076BF20[];

u8 audio_engine[0x38000];

RECOMP_FORCE_PATCH void func_global_asm_80600D50(void) {
    UnkConfig spCC;
    ALBankFile *temp_v0_2;
    ALBankFile *temp_v0_3;
    s32 spC0;
    SynthConfig sp98;
    SeqpConfig sp78;
    Struct80600D50_sp60 sp6C;
    ALSeqPlayer *player;
    void *temp_v0;
    s32 i;

    alHeapInit(&D_global_asm_8076D1E8, &D_global_asm_80770F50, 0x7BD80);
    D_global_asm_807452B0[0] = 0xD00; // Reduce allocation for bank 0
    sp98.unk0 = 0x2C;
    sp98.unk4 = 0x38;  // Increased phys voice count
    sp98.unk8 = 0x70;  // Increased max pvoice
    sp98.unkC = 1;
    sp98.unk10 = 0;
    sp98.unk1C = 6;
    sp98.unk1D = 6;
    sp98.unk18 = 0;
    sp98.unk14 = &D_global_asm_8076D1E8;
    sp6C.unk0 = 22050;
    sp6C.unk4 = 2;
    sp6C.unk8 = 0xC00;
    func_global_asm_80601A10(&sp98, 0x14, &sp6C);
    spC0 = gOverlayTable[15].rom_data_end - gOverlayTable[15].rom_code_start;
    temp_v0 = &audio_engine[0]; // @recomp: Change this to be a static address
    func_global_asm_8060B140(gOverlayTable[15].rom_code_start, temp_v0, &spC0, 0xD, 0, 2, 0);
    temp_v0_2 = alHeapDBAlloc(NULL, 0, &D_global_asm_8076D1E8, 1, spC0);
    func_global_asm_8060B140(gOverlayTable[15].rom_code_start, temp_v0_2, &spC0, 0xD, 0, 2, 0);
    alBnkfNew(temp_v0_2, (u8*)gOverlayTable[14].rom_code_start);
    D_global_asm_8076D1FC = temp_v0_2->bankArray[0];
    spC0 = gOverlayTable[16].rom_data_end - gOverlayTable[16].rom_code_start;
    func_global_asm_8060B140(gOverlayTable[16].rom_code_start, temp_v0, &spC0, 0xD, 0, 2, 0);
    _free(temp_v0);
    temp_v0_3 = alHeapDBAlloc(NULL, 0, &D_global_asm_8076D1E8, 1, spC0);
    func_global_asm_8060B140(gOverlayTable[16].rom_code_start, temp_v0_3, &spC0, 0xD, 0, 2, 0);
    alBnkfNew(temp_v0_3, (u8*)gOverlayTable[17].rom_code_start);
    D_global_asm_8076D1F8 = temp_v0_3->bankArray[0];
    sp78.unk0 = 0x2C;
    sp78.unk4 = 0x40;
    sp78.unk9 = 0;
    sp78.unk8 = 0x10;
    sp78.unkC = &D_global_asm_8076D1E8;
    func_global_asm_80732DEC(&sp78, 0x58);
    for (i = 0; i < 4; i++) {
        D_global_asm_8076BF30[i] = 0xFFFF;
        D_global_asm_8076BF38[i] = alHeapDBAlloc(NULL, 0, &D_global_asm_8076D1E8, 1, D_global_asm_807452B0[i]);
        D_global_asm_8076BF20[i] = alHeapDBAlloc(NULL, 0, &D_global_asm_8076D1E8, 1, 0x8C);
        player = D_global_asm_8076BF20[i];
        if ((!D_global_asm_8076BF38[i]) || (player = D_global_asm_8076BF20[i], !player)) {
            player = D_global_asm_8076BF20[i];
        }
        func_global_asm_80732F10(player, &sp78);
        func_global_asm_80735A50(D_global_asm_8076BF20[i], temp_v0_2->bankArray[0]);
    }
    func_global_asm_806010A0();
    spCC.unk4 = 0x40;
    spCC.unk0 = 0x40;
    spCC.unk8 = 0x14;
    spCC.unk10 = 8;
    spCC.unkC = &D_global_asm_8076D1E8;
    func_global_asm_80735AA0(&spCC);
    func_global_asm_80737C20(4);
    func_global_asm_80737CF4(0, 4);
    func_global_asm_80601CC0();
}