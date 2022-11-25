
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>
#include <cstdint>
#include "../include/math.h"

/////////////////////////////
// Typedefs
/////////////////////////////

// SFML types
typedef sf::Keyboard Key;
typedef sf::Sprite Sprite;

// Types
typedef uint8_t		u8;
typedef uint16_t	u16;
typedef uint32_t	u32;
typedef uint64_t	u64;
typedef u16			FontId;
typedef u16			ShaderId;
typedef u16			SoundId;
typedef u16			SoundInstanceId;
typedef u16			SpriteId;
typedef u16			TextureId;
typedef u16			BodyId;

enum class SpriteOrigin { TopLeft, Centre };
enum class QuadAlign	{ TopLeft, Centre };
enum class TextAlign	{ Left, Centre };
enum class TitlebarStyle{ None, Minimal, Full };


// General window parameters.
void SetWindowTitle(const char* title);
void SetWindowFPSLimit(u32 fps);
void SetWindowMouseCursorVisible(bool b);
void SetWindowClearColour(f4 colour);
void SetWindowIcon(const char* icon_filepath);
void SetWindowFullscreen(bool b);
void SetWindowTitlebarStyle(TitlebarStyle style);
void SetWindowAntialiased(bool b);

// Window sizing / clipping / coordinates.
void SetWindowSize(int x, int y);
void SetWindowClipRegion(f2 top_left_px, f2 size_px);
void SetWindowWorldRegion(f2 top_left_world, f2 size_world);
void ResetWindowClipRegion();
void ResetWindowWorldRegion();