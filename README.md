# DK64 Music Rando

DK64 Music rando lets you use packs generated at https://theballaam96.github.io/PackBuilder/ so the game can have randomized music.

This Requires the Python Library mod

## What It Does
- The mod will randomly pick a song from your pack stored at mods_data/pack.zip
- This song will persist for the length of the game running
- Next game boot WILL rotate the song chosen

## Installation
1. Download the latest `dk64_music_rando.nrm` from Releases.
2. Put the file in your DK64 Recompiled mods folder.
   - Example (Windows): `C:\Users\<YourUser>\AppData\Local\DK64Recompiled\mods`
3. Launch DK64 Recompiled and enable the mod from the mods menu.

## Build Requirements
- `clang`
- `ld.lld`
- `make`
- `RecompModTool` from [N64Recomp](https://github.com/N64Recomp/N64Recomp)

Notes:
- On macOS, Apple Clang is not enough for this target. Use an LLVM toolchain that supports MIPS and point `CC`/`LD` to it if needed.
- On Linux/macOS, ensure `zip` is installed for packaging workflows.

## Building from Source
From the repository root:

```bash
make
```

This builds `build/mod.elf`.

Then package the mod:

```bash
RecompModTool mod.toml C:/path/to/DK64Recompiled/mods
```

PowerShell example:

```powershell
.\RecompModTool.exe .\mod.toml C:\Users\<YourUser>\AppData\Local\DK64Recompiled\mods
```

The produced mod file is named `dk64_music_rando.nrm`.

## Credits
See `authors` in `mod.toml` for the full contributor list included in the mod manifest.
