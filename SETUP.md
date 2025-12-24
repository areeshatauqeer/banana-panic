# Quick Setup Guide

## Your Assets Are Already Loaded!

The game is configured to use your existing assets from the project root directory.

### Current Asset Mapping

**Player (Bunny):**
- `bunny1_stand.png` - Idle animation
- `bunny1_walk1.png` & `bunny1_walk2.png` - Running animation (alternates)
- `bunny1_jump.png` - Jumping
- `bunny1_ready.png` - Sliding
- `bunny1_hurt.png` - Death

**Enemies:**
- `spikeMan_stand.png` - Default enemy
- `spikeMan_walk1.png` & `spikeMan_walk2.png` - Walking animation

**Collectibles:**
- `carrot.png` - Heart collectible
- `carrot_gold.png` - Star collectible
- `mushroom_red.png` - Candy collectible
- `coin_gold.png` - Coin collectible

**Platforms:**
- `ground_grass.png` - Main platform texture
- `ground_cake.png` - Alternative platform
- `ground_sand.png` - Alternative platform

**Backgrounds:**
- `bg_layer1.png` - Far background (parallax 0.2)
- `bg_layer2.png` - Mid background (parallax 0.4)
- `bg_layer3.png` - Near background (parallax 0.6)

**Font:**
- `Baloo2-VariableFont_wght.ttf` - Cute font for UI

**Sound:**
- `impactPlate_medium_004.ogg` - Jump sound

## Building the Game

1. **Install SFML 2.6.2**
   - Download from https://www.sfml-dev.org/download.php
   - Extract to a location (e.g., `C:\SFML`)
   - Set environment variable `SFML_DIR` to point to SFML directory

2. **Open in Visual Studio 2026**
   - Open `PlatformerGame.vcxproj`
   - Configure project properties if `SFML_DIR` is not set:
     - C/C++ → General → Additional Include Directories: `$(SFML_DIR)\include`
     - Linker → General → Additional Library Directories: `$(SFML_DIR)\lib`

3. **Build**
   - Select Debug or Release configuration
   - Build Solution (F7)

4. **Copy SFML DLLs**
   - Copy these DLLs to your output directory (where .exe is):
     - Debug: `sfml-graphics-d-2.dll`, `sfml-window-d-2.dll`, `sfml-system-d-2.dll`, `sfml-audio-d-2.dll`
     - Release: `sfml-graphics-2.dll`, `sfml-window-2.dll`, `sfml-system-2.dll`, `sfml-audio-2.dll`
   - These are in `$(SFML_DIR)\bin`

5. **Run!**
   - Make sure all asset files are in the same directory as the .exe
   - Run the game

## Controls

- **SPACE / UP / W**: Jump
- **DOWN / S**: Slide (defeats enemies!)
- **P / ESC**: Pause
- **ESC**: Exit to menu

## Gameplay Tips

- Jump over enemies or slide into them to defeat them
- Collect carrots, gold carrots, mushrooms, and coins for points
- Try to survive as long as possible!
- The game gets progressively more challenging

## Customization

You can easily customize:
- Game speed in `PlayingState.cpp` (`gameSpeed_`)
- Physics in `Player.cpp` (gravity, jump strength, etc.)
- Spawn rates in `PlayingState.cpp` (enemy and collectible timers)
- Colors and styles throughout the code

Enjoy your cute platformer game! 🐰🎮

