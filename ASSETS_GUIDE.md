# Assets Guide

This document describes the required assets for the Cute Platformer Game.

## Folder Structure

Create the following folder structure in your project root:

```
assets/
├── sprites/
├── backgrounds/
├── sounds/
└── fonts/
```

## Required Assets

### Sprites (PNG format recommended)

#### Player Sprites
All player sprites should be sprite sheets with frames arranged horizontally.

1. **player_idle.png**
   - Size: 256x64 pixels (4 frames × 64x64)
   - Frames: 4
   - Animation: Idle standing animation

2. **player_run.png**
   - Size: 384x64 pixels (6 frames × 64x64)
   - Frames: 6
   - Animation: Running animation

3. **player_jump.png**
   - Size: 192x64 pixels (3 frames × 64x64)
   - Frames: 3
   - Animation: Jumping animation

4. **player_slide.png**
   - Size: 256x64 pixels (4 frames × 64x64)
   - Frames: 4
   - Animation: Sliding animation

5. **player_death.png**
   - Size: 320x64 pixels (5 frames × 64x64)
   - Frames: 5
   - Animation: Death animation (non-looping)

#### Enemy Sprite
1. **enemy.png**
   - Size: 256x64 pixels (4 frames × 64x64)
   - Frames: 4
   - Animation: Walking animation

#### Collectible Sprites
All collectibles should be 32x32 pixels per frame.

1. **collectible_heart.png**
   - Size: 128x32 pixels (4 frames × 32x32)
   - Frames: 4
   - Animation: Pulsing/spinning heart

2. **collectible_star.png**
   - Size: 128x32 pixels (4 frames × 32x32)
   - Frames: 4
   - Animation: Rotating star

3. **collectible_candy.png**
   - Size: 128x32 pixels (4 frames × 32x32)
   - Frames: 4
   - Animation: Bouncing candy

4. **collectible_coin.png**
   - Size: 128x32 pixels (4 frames × 32x32)
   - Frames: 4
   - Animation: Spinning coin

#### Platform Sprite
1. **platform.png**
   - Size: Any (will be tiled)
   - Format: Tileable texture
   - Style: Cute, colorful platform texture

### Backgrounds (PNG format)

All backgrounds should be at least 1280 pixels wide (wider for seamless scrolling) and 720 pixels tall.

1. **bg_layer0.png** (Far Background)
   - Parallax Factor: 0.2 (slowest)
   - Content: Sky, clouds, distant mountains
   - Style: Soft, pastel colors

2. **bg_layer1.png** (Mid Background)
   - Parallax Factor: 0.4
   - Content: Mountains, buildings, trees in distance
   - Style: Medium detail

3. **bg_layer2.png** (Near Background)
   - Parallax Factor: 0.6
   - Content: Trees, decorations, foreground elements
   - Style: More detailed, closer to camera

### Sounds (OGG Vorbis or WAV format)

1. **jump.ogg** - Jump sound effect
   - Style: Light, bouncy, cheerful
   - Duration: ~0.2-0.5 seconds

2. **slide.ogg** - Slide sound effect
   - Style: Whoosh, smooth
   - Duration: ~0.3-0.6 seconds

3. **collect.ogg** - Collectible pickup sound
   - Style: Happy chime, bell, or sparkle
   - Duration: ~0.2-0.4 seconds

4. **enemy_hit.ogg** - Enemy defeat sound
   - Style: Pop, squish, or bounce
   - Duration: ~0.2-0.4 seconds

5. **death.ogg** - Player death sound
   - Style: Soft, not too harsh
   - Duration: ~0.5-1.0 seconds

6. **bg_music.ogg** - Background music
   - Style: Upbeat, cheerful, playful
   - Format: Should loop seamlessly
   - Duration: 1-3 minutes (will loop)

### Fonts (TTF format)

1. **default.ttf**
   - Style: Cute, rounded, playful
   - Recommended: Comic Sans MS alternative, or any friendly rounded font
   - Size: Should support sizes 30-80

## Art Style Guidelines

### Colors
- Use soft, pastel colors
- Avoid harsh contrasts
- Bright and cheerful palette
- Examples: Light blues, pinks, yellows, greens

### Character Design
- Round shapes
- Big expressive eyes
- Exaggerated animations
- Soft outlines (optional)
- Cute, friendly appearance

### Overall Feel
- Playful and fun
- Non-threatening enemies
- Happy, cheerful atmosphere
- Smooth, bouncy animations

## Notes

- All sprites should have transparent backgrounds (PNG with alpha channel)
- Sound effects should be light and not too loud
- Background music should be subtle and loopable
- If assets are missing, the game will still run but with limited visuals
- The game uses graceful fallbacks (colored shapes) if textures aren't found

## Testing Without Assets

The game will run even without all assets:
- Missing textures: Will use colored rectangles/shapes
- Missing sounds: Will silently skip sound playback
- Missing font: Text may not display, but game will run
- Missing backgrounds: Will use gradient backgrounds

You can develop and test the game mechanics before adding all assets!

