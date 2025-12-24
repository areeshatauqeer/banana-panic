# Cute 2D Platformer Game

A delightful 2D platformer game built with C++ and SFML 2.6.2, featuring cute characters, colorful graphics, and smooth gameplay similar to Minion Rush.

## Features

- **Cute Art Style**: Round characters, big expressive eyes, soft colors, and playful animations
- **Player Movement**: Running, jumping, sliding, and death animations
- **Enemies**: Moving obstacles with collision detection
- **Collectibles**: Hearts, stars, candies, and coins to collect
- **Parallax Background**: Multi-layer scrolling background for depth
- **Game States**: Menu, Playing, Pause, and Game Over screens
- **HUD**: Score display with smooth animations
- **Sound Effects**: Jump, slide, collect, enemy hit, and background music

## Requirements

- **SFML 2.6.2**: Download from [SFML website](https://www.sfml-dev.org/download.php)
- **Visual Studio 2026**: 64-bit development environment
- **C++17** or later

## Setup Instructions

### 1. Install SFML

1. Download SFML 2.6.2 for Visual Studio 2026 (64-bit)
2. Extract to a location (e.g., `C:\SFML`)
3. Set the `SFML_DIR` environment variable to point to the SFML directory, or configure it in Visual Studio project properties

### 2. Configure Visual Studio Project

1. Open `PlatformerGame.vcxproj` in Visual Studio 2026
2. Go to Project Properties → C/C++ → General
3. Add `$(SFML_DIR)\include` to Additional Include Directories
4. Go to Linker → General
5. Add `$(SFML_DIR)\lib` to Additional Library Directories
6. Or set `SFML_DIR` environment variable to your SFML installation path

### 3. Asset Structure

Create the following folder structure and add your assets:

```
assets/
├── sprites/
│   ├── player_idle.png
│   ├── player_run.png
│   ├── player_jump.png
│   ├── player_slide.png
│   ├── player_death.png
│   ├── enemy.png
│   ├── collectible_heart.png
│   ├── collectible_star.png
│   ├── collectible_candy.png
│   ├── collectible_coin.png
│   └── platform.png
├── backgrounds/
│   ├── bg_layer0.png (far background - sky/clouds)
│   ├── bg_layer1.png (mid background - mountains/buildings)
│   └── bg_layer2.png (near background - trees/decorations)
├── sounds/
│   ├── jump.ogg
│   ├── slide.ogg
│   ├── collect.ogg
│   ├── enemy_hit.ogg
│   ├── death.ogg
│   └── bg_music.ogg
└── fonts/
    └── default.ttf (cute, playful font)
```

### 4. Asset Specifications

#### Player Sprites
- **Idle**: 4 frames, 64x64 pixels each
- **Run**: 6 frames, 64x64 pixels each
- **Jump**: 3 frames, 64x64 pixels each
- **Slide**: 4 frames, 64x64 pixels each
- **Death**: 5 frames, 64x64 pixels each

#### Enemy Sprites
- **Walk**: 4 frames, 64x64 pixels each

#### Collectibles
- **All types**: 4 frames, 32x32 pixels each

#### Backgrounds
- **Width**: At least 1280 pixels (wider for seamless scrolling)
- **Height**: 720 pixels
- **Format**: PNG with transparency where needed

#### Sounds
- **Format**: OGG Vorbis (recommended) or WAV
- **Sample Rate**: 44100 Hz recommended

### 5. Build and Run

1. Build the project in Visual Studio (Debug or Release)
2. Copy SFML DLLs to the output directory:
   - `sfml-graphics-d-2.dll` (Debug) or `sfml-graphics-2.dll` (Release)
   - `sfml-window-d-2.dll` (Debug) or `sfml-window-2.dll` (Release)
   - `sfml-system-d-2.dll` (Debug) or `sfml-system-2.dll` (Release)
   - `sfml-audio-d-2.dll` (Debug) or `sfml-audio-2.dll` (Release)
3. Ensure all assets are in the `assets/` folder relative to the executable
4. Run the game!

## Controls

- **SPACE / UP / W**: Jump
- **DOWN / S**: Slide
- **P / ESC**: Pause (in-game)
- **ESC**: Exit (in menu)

## Gameplay

- Run automatically and avoid enemies
- Jump over obstacles and enemies
- Slide under low obstacles and defeat enemies
- Collect items to increase your score
- Try to survive as long as possible!

## Customization

### Adjusting Game Speed
Edit `gameSpeed_` in `PlayingState.cpp` to change the overall game speed.

### Changing Physics
Modify values in `Player.cpp`:
- `gravity_`: Fall speed
- `jumpStrength_`: Jump height
- `runSpeed_`: Horizontal movement speed

### Spawn Rates
Adjust in `PlayingState.cpp`:
- `spawnTimer_` threshold: Enemy spawn frequency
- `collectibleTimer_` threshold: Collectible spawn frequency

## Troubleshooting

### Missing DLLs
If you get DLL errors, copy the required SFML DLLs to your executable directory.

### Assets Not Loading
- Check that asset paths are correct relative to the executable
- Ensure file names match exactly (case-sensitive on some systems)
- Verify file formats are supported (PNG for images, OGG/WAV for sounds)

### Font Issues
If the font doesn't load, the game will still run but text may not display. Make sure `default.ttf` exists in `assets/fonts/`.

## License

This project is provided as-is for educational and personal use.

## Notes

- The game is designed to be cute and playful with soft colors and round shapes
- All animations are frame-based and can be customized
- The parallax system creates depth with multiple background layers
- Sound effects enhance the playful atmosphere

Enjoy your cute platformer game!

