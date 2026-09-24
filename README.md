# GAME-EDUCATIONAL-PM_Equator

Educational PM game: discover the right value of the letters and complete the equations.

## LICENSE
* GNU GPL V2

## COMPILE TOOLS
* Open Watcom C/C++ 1.9/2.0 (wcc386 + wlink + wrc)
* OS/2 Toolkit 4.5 (os2tk45 headers)
* IBM IPFC for help compilation

## AUTHORS
* Frank Sven Nestel (original 1995-2001)
* OS/2World port 2026

## LINKS
* https://www.os2world.com/games/index.php/native-games/educational/181-pm-equator

## VERSION 1.0 (2026-09-24)

### Major Features
- **Full multilingual support**: 6 languages (English, Spanish, Dutch, German, French, Italian) with translated help libraries
- **High-DPI / HD ready**: 2× graphics scale — all 35 board glyphs (digits, alphas, signs) upscaled to 50×50 / 32×32
- **Help system fixed**: Help libraries now found from `bin\hlp\` relative to EXE (uses `DosQueryModFromEIP` for reliable own-module path)
- **Compiled help**: 6 `.HLP` files built from translated `.ipf` sources via IPFC (`bin\hlp\EQUATOR_XX.HLP`)
- **Settings persistence**: Language, level, hardmode, alpha, hedgehog, save-on-exit saved to `Equator.cfg`

### Build
Run `compile-wat.cmd` on ArcaOS VM (Open Watcom + IPFC in PATH). Output in `bin\EQUATOR.EXE` with `bin\hlp\` help files.

### Controls
- Drag-and-drop digits/letters onto the board
- Double-click to enter digits via dialog (in alpha mode)
- Right-click to reset pointer
- Menu: Game → New Puzzle / Solution / High Scores / Level / Hardmode / Alpha / Hedgehog
- Options → Language (6) / Save settings on exit
- Help → Index / General / Using Help / Keys / About

### Technical Notes
- OS/2 PM 32-bit flat (LX) executable
- Bitmap resources: OS/2 BITMAPCOREHEADER 4bpp (loaded via `GpiLoadBitmap`)
- Cursors: standard `.ptr` resources (unscaled)
- Help: `WinCreateHelpInstance` with fully-qualified library path
- Threaded puzzle generation (`DosCreateThread` / `_beginthread`)