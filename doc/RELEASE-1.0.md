# PM Equator 1.0 — Release Notes

**Date:** 2026-09-24  
**Platform:** OS/2 (ArcaOS / Warp 4.52)  
**Toolchain:** Open Watcom 1.9/2.0 + OS/2 Toolkit 4.5 + IBM IPFC

---

## Overview
PM Equator is a number puzzle game for OS/2 Presentation Manager. The goal is to assign digits to letters (A–J) so that all displayed equations are satisfied. The game includes multiple difficulty levels, high-score tracking, and full multilingual help.

---

## Changes in 1.0

### 1. Help System Overhaul
| Item | Before | After |
|------|--------|-------|
| Help files | None compiled | 6 compiled `.HLP` in `bin\hlp\` |
| Languages | German only (resource string) | EN, ES, NL, DE, FR, IT |
| Runtime lookup | Bare name (`EQUATOR_DE.HLP`) | Fully-qualified path `bin\hlp\EQUATOR_XX.HLP` |
| IPF sources | Original `pmeq1.ipf` (DE) | 6 translated `.ipf` in `help\` |
| Compilation | N/A | `makefile.wat` → `ipfc` per language |

**Runtime fix:** `pmhelp.cc:BuildHelpLibraryPath()` now uses `DosQueryModFromEIP(&hmod, …, (ULONG)&BuildHelpLibraryPath)` → `DosQueryModuleName(hmod, …)` instead of the unreliable `DosQueryModuleName(NULLHANDLE, …)`. This guarantees the EXE directory is found on all OS/2 versions.

### 2. 2× Graphics Scale (HD / High-DPI)
All board glyph bitmaps upscaled 2× via nearest-neighbour:

| Asset group | Original | 2× |
|-------------|----------|-----|
| Digits `nr0-9.bmp` | 25×25 | 50×50 |
| Alpha `al0-9.bmp` | 25×25 | 50×50 |
| Alt alpha `ala0-9.bmp` | 25×25 | 50×50 |
| Signs `plus/minus/mal/durch/gleich.bmp` | 16×16 | 32×32 |

**Layout constants doubled in `pmmnwin.cc`:**
```c
PRESKIP   3 → 6
SIGNSHIFT 4 → 8
SIGNDELTA 1 → 2
lineskip  14 → 28
```
All pixel offsets in `MainPaint()`, `InitMainWin()`, `ShowHiScore()`, `window_hi()` updated accordingly. Window auto-sizes from `BigBmpData.cx/cy` so no manual window size changes needed.

### 3. Multilingual Support
- `lang.h`: `LANG_COUNT=6`, indices EN=0, ES=1, NL=2, DE=3, FR=4, IT=5
- `pmmnwin.cc:set_language()` updates all menu texts at runtime
- `pmhelp.cc:helpFiles[]` array maps language → `EQUATOR_XX.HLP`
- Default language English; persists in `Equator.cfg`

### 4. Artwork Paths Fixed
All 6 `.ipf` files: `:artwork name='E:\0MEINS\EQUATOR\...'` → `name='help\...'`
Missing 18 bitmaps copied from `src\` to `help\` (all 29 refs resolve).

### 5. English IPF Byte Integrity
Two `0x81` (ü) bytes in `pmeq_en.ipf` ("Obere Büch 24") restored after ASCII rewrite.

---

## Build Instructions

### On ArcaOS VM
```cmd
compile-wat.cmd
```
Requires:
- Open Watcom in PATH (`wcc386`, `wlink`, `wrc`)
- IBM IPFC in PATH (`ipfc` or `wipfc`)

Output:
- `bin\EQUATOR.EXE`
- `bin\hlp\EQUATOR_EN.HLP` … `EQUATOR_IT.HLP`

### Host (cross-check only)
```bash
# probe BMP headers
python3 probe_bmp.py src/
# scale 2x
python3 scale2x.py src/nr0.bmp ...
```

---

## Files Modified (since legacy)

| File | Change |
|------|--------|
| `src\pmhelp.cc` | `BuildHelpLibraryPath`: `DosQueryModFromEIP` + `DosQueryModuleName`; `INCL_DOSERRORS` added |
| `src\pmmnwin.cc` | All layout constants 2×; `InitMainWin`, `MainPaint`, `ShowHiScore`, `window_hi`, `WSetPos` |
| `src\*.bmp` (35 files) | Pixel-doubled 2× (OS/2 BITMAPCOREHEADER 4bpp) |
| `help\pmeq_*.ipf` (6) | Artwork paths → `help\`; EN `0x81` restored |
| `makefile.wat` | `HLPSRC`, `HLPDIR`, `HELPFILES`, 6 IPFC rules, clean targets |
| `src\EQUATOR.RC` | `IDS_HELPLIBRARYNAME` = `EQUATOR_DE.HLP` |
| `README.md` | Updated with 1.0 features, build, controls |

---

## Known Limitations / Future
- Cursor `.ptr` files not scaled (OS cursor size)
- `igel3.bmp` (hedgehog) and `pmwin.bmp` (icon) not upscaled — not used in main board
- No 1.5×/3× scale option (only 1× legacy / 2× current)
- Help index panel mapping is minimal (all menus → `PANEL_MAIN`)

---

## License
GNU GPL v2 (see `legacy/gpl-license.html`). Original author Frank Sven Nestel 1995-2001.