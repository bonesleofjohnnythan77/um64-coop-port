#include "custom.model.inc.h"
ALIGNED8 u8 unk_DL_040526dc__texture_04053F80[] = {
#include "actors/seaweed/unk_DL_040526dc_0x4053f80_custom.rgba16.inc.c"
};
ALIGNED8 u8 unk_DL_040526dc__texture_04053780[] = {
#include "actors/seaweed/unk_DL_040526dc_0x4053780_custom.rgba16.inc.c"
};
ALIGNED8 u8 unk_DL_040526dc__texture_04052F80[] = {
#include "actors/seaweed/unk_DL_040526dc_0x4052f80_custom.rgba16.inc.c"
};
ALIGNED8 u8 unk_DL_040526dc__texture_04052780[] = {
#include "actors/seaweed/unk_DL_040526dc_0x4052780_custom.rgba16.inc.c"
};

Vtx VB_unk_DL_040526dc_0x4054780[] = {
{{{ 232, 2, -76 }, 0, { -30, -12 }, { 0, 127, 0, 255}}},
{{{ -1, 2, 77 }, 0, { 990, 990 }, { 0, 127, 0, 255}}},
{{{ 232, 2, 77 }, 0, { 992, -12 }, { 0, 127, 0, 255}}},
{{{ -1, 2, -76 }, 0, { 0, 990 }, { 0, 127, 0, 255}}},
};

Vtx VB_unk_DL_040526dc_0x4054878[] = {
{{{ 311, 2, -76 }, 0, { 0, 0 }, { 0, 127, 0, 255}}},
{{{ -1, 2, -76 }, 0, { 0, 990 }, { 0, 127, 0, 255}}},
{{{ -1, 2, 77 }, 0, { 990, 990 }, { 0, 127, 0, 255}}},
{{{ 311, 2, 77 }, 0, { 990, 0 }, { 0, 127, 0, 255}}},
};

Vtx VB_unk_DL_040526dc_0x4054970[] = {
{{{ 314, 2, -76 }, 0, { 0, -20 }, { 0, 127, 0, 255}}},
{{{ -1, 2, 77 }, 0, { 990, 990 }, { 0, 127, 0, 255}}},
{{{ 314, 2, 77 }, 0, { 990, -20 }, { 0, 127, 0, 255}}},
{{{ -1, 2, -76 }, 0, { 0, 990 }, { 0, 127, 0, 255}}},
};

Vtx VB_unk_DL_040526dc_0x4054a68[] = {
{{{ 236, 2, -76 }, 0, { 0, 0 }, { 0, 127, 0, 255}}},
{{{ 0, 2, 77 }, 0, { 990, 990 }, { 0, 127, 0, 255}}},
{{{ 236, 2, 77 }, 0, { 990, 0 }, { 0, 127, 0, 255}}},
{{{ 0, 2, -76 }, 0, { 0, 990 }, { 0, 127, 0, 255}}},
};

Light_t Light_unk_DL_040526dc_0x4052770 = {
{ 255, 255, 255}, 0, { 255, 255, 255}, 0, { 40, 40, 40}, 0
};

Ambient_t Light_unk_DL_040526dc_0x4052768 = {
{63, 63, 63}, 0, {63, 63, 63}, 0
};

Gfx DL_unk_DL_040526dc_0x4054af0[] = {
gsDPPipeSync(),
gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
gsSPGeometryMode(G_CULL_BACK|G_SHADING_SMOOTH, 0),
gsDPSetTile(0, 2, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0),
gsSPTexture(65535, 65535, 0, 0, 1),
gsDPTileSync(),
gsDPSetTile(0, 2, 8, 0, 0, 0, 2, 5, 0, 2, 5, 0),
gsDPSetTileSize(0, 0, 0, 124, 124),
gsSPDisplayList(DL_unk_DL_040526dc_0x4054aa8),
gsSPTexture(65535, 65535, 0, 0, 0),
gsDPPipeSync(),
gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
gsSPGeometryMode(0, G_CULL_BACK|G_SHADING_SMOOTH),
gsSPEndDisplayList(),
};

Gfx DL_unk_DL_040526dc_0x4054aa8[] = {
gsDPSetTextureImage(0, 2, 1, unk_DL_040526dc__texture_04053F80),
gsDPLoadSync(),
gsDPLoadBlock(7, 0, 0, 1023, 256),
gsSPLight(&Light_unk_DL_040526dc_0x4052770.col, 1),
gsSPLight(&Light_unk_DL_040526dc_0x4052768.col, 2),
gsSPVertex(VB_unk_DL_040526dc_0x4054a68, 4, 0),
gsSP2Triangles(0, 1, 2, 0,0, 3, 1, 0),
gsSPEndDisplayList(),
};

Gfx DL_unk_DL_040526dc_0x40549f8[] = {
gsDPPipeSync(),
gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
gsSPGeometryMode(G_CULL_BACK|G_SHADING_SMOOTH, 0),
gsDPSetTile(0, 2, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0),
gsSPTexture(65535, 65535, 0, 0, 1),
gsDPTileSync(),
gsDPSetTile(0, 2, 8, 0, 0, 0, 2, 5, 0, 2, 5, 0),
gsDPSetTileSize(0, 0, 0, 124, 124),
gsSPDisplayList(DL_unk_DL_040526dc_0x40549b0),
gsSPTexture(65535, 65535, 0, 0, 0),
gsDPPipeSync(),
gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
gsSPGeometryMode(0, G_CULL_BACK|G_SHADING_SMOOTH),
gsSPEndDisplayList(),
};

Gfx DL_unk_DL_040526dc_0x40549b0[] = {
gsDPSetTextureImage(0, 2, 1, unk_DL_040526dc__texture_04053780),
gsDPLoadSync(),
gsDPLoadBlock(7, 0, 0, 1023, 256),
gsSPLight(&Light_unk_DL_040526dc_0x4052770.col, 1),
gsSPLight(&Light_unk_DL_040526dc_0x4052768.col, 2),
gsSPVertex(VB_unk_DL_040526dc_0x4054970, 4, 0),
gsSP2Triangles(0, 1, 2, 0,0, 3, 1, 0),
gsSPEndDisplayList(),
};

Gfx DL_unk_DL_040526dc_0x4054900[] = {
gsDPPipeSync(),
gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
gsSPGeometryMode(G_CULL_BACK|G_SHADING_SMOOTH, 0),
gsDPSetTile(0, 2, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0),
gsSPTexture(65535, 65535, 0, 0, 1),
gsDPTileSync(),
gsDPSetTile(0, 2, 8, 0, 0, 0, 2, 5, 0, 2, 5, 0),
gsDPSetTileSize(0, 0, 0, 124, 124),
gsSPDisplayList(DL_unk_DL_040526dc_0x40548b8),
gsSPTexture(65535, 65535, 0, 0, 0),
gsDPPipeSync(),
gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
gsSPGeometryMode(0, G_CULL_BACK|G_SHADING_SMOOTH),
gsSPEndDisplayList(),
};

Gfx DL_unk_DL_040526dc_0x40548b8[] = {
gsDPSetTextureImage(0, 2, 1, unk_DL_040526dc__texture_04052F80),
gsDPLoadSync(),
gsDPLoadBlock(7, 0, 0, 1023, 256),
gsSPLight(&Light_unk_DL_040526dc_0x4052770.col, 1),
gsSPLight(&Light_unk_DL_040526dc_0x4052768.col, 2),
gsSPVertex(VB_unk_DL_040526dc_0x4054878, 4, 0),
gsSP2Triangles(0, 1, 2, 0,0, 2, 3, 0),
gsSPEndDisplayList(),
};

Gfx DL_unk_DL_040526dc_0x4054808[] = {
gsDPPipeSync(),
gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
gsSPGeometryMode(G_CULL_BACK|G_SHADING_SMOOTH, 0),
gsDPSetTile(0, 2, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0),
gsSPTexture(65535, 65535, 0, 0, 1),
gsDPTileSync(),
gsDPSetTile(0, 2, 8, 0, 0, 0, 2, 5, 0, 2, 5, 0),
gsDPSetTileSize(0, 0, 0, 124, 124),
gsSPDisplayList(DL_unk_DL_040526dc_0x40547c0),
gsSPTexture(65535, 65535, 0, 0, 0),
gsDPPipeSync(),
gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
gsSPGeometryMode(0, G_CULL_BACK|G_SHADING_SMOOTH),
gsSPEndDisplayList(),
};

Gfx DL_unk_DL_040526dc_0x40547c0[] = {
gsDPSetTextureImage(0, 2, 1, unk_DL_040526dc__texture_04052780),
gsDPLoadSync(),
gsDPLoadBlock(7, 0, 0, 1023, 256),
gsSPLight(&Light_unk_DL_040526dc_0x4052770.col, 1),
gsSPLight(&Light_unk_DL_040526dc_0x4052768.col, 2),
gsSPVertex(VB_unk_DL_040526dc_0x4054780, 4, 0),
gsSP2Triangles(0, 1, 2, 0,0, 3, 1, 0),
gsSPEndDisplayList(),
};

