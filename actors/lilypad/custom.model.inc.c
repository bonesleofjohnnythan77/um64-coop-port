#include "custom.model.inc.h"
Vtx VB_unk_DL_04054e6c_0x4055e9c[] = {
{{{ 425, 0, 425 }, 0, { 903, 177 }, { 204, 204, 204, 255}}},
{{{ 425, 0, -425 }, 0, { 903, 1806 }, { 255, 255, 255, 255}}},
{{{ -425, 0, -425 }, 0, { 88, 1806 }, { 255, 255, 255, 255}}},
{{{ -425, 0, 425 }, 0, { 88, 177 }, { 204, 204, 204, 255}}},
{{{ 425, 0, 425 }, 0, { 903, 177 }, { 204, 204, 204, 255}}},
{{{ -425, 0, -425 }, 0, { 88, 1806 }, { 255, 255, 255, 255}}},
{{{ 0, 0, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255}}},
{{{ 0, 0, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255}}},
{{{ 0, 0, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255}}},
{{{ 0, 0, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255}}},
{{{ 0, 0, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255}}},
{{{ 0, 0, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255}}},
{{{ 0, 0, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255}}},
{{{ 0, 0, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255}}},
{{{ 0, 0, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255}}},
};

Light_t Light_unk_DL_04054e6c_0x4054e8c = {
{ 255, 255, 255}, 0, { 255, 255, 255}, 0, { 127, 127, 127}, 0
};

Ambient_t Light_unk_DL_04054e6c_0x4054e94 = {
{127, 127, 127}, 0, {127, 127, 127}, 0
};

Gfx DL_unk_DL_04054e6c_0x4055f8c[] = {
gsDPPipeSync(),
gsSPGeometryMode(0, 0),
gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, SHADE, TEXEL0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, SHADE, TEXEL0),
gsSPTexture(65535, 65535, 0, 0, 1),
gsDPTileSync(),
gsDPLoadSync(),
gsSPLight(&Light_unk_DL_04054e6c_0x4054e8c.col, 1),
gsSPLight(&Light_unk_DL_04054e6c_0x4054e94.col, 2),
gsSPGeometryMode(G_CULL_BACK|G_LIGHTING, 0),
gsDPSetTextureImage(0, 2, 1, unk_DL_04054e6c__texture_04054E9C),
gsDPSetTile(0, 2, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0),
gsDPLoadSync(),
gsDPLoadBlock(7, 0, 0, 2047, 256),
gsDPPipeSync(),
gsDPSetTile(0, 2, 8, 0, 0, 0, 0, 6, 0, 0, 5, 0),
gsDPSetTileSize(0, 0, 0, 124, 252),
gsSPVertex(VB_unk_DL_04054e6c_0x4055e9c, 15, 0),
gsSP2Triangles(0, 1, 2, 0,3, 4, 5, 0),
gsSP2Triangles(6, 7, 8, 0,9, 10, 11, 0),
gsSP1Triangle(12, 13, 14, 0),
gsDPPipeSync(),
gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE),
gsSPTexture(65535, 65535, 0, 0, 0),
gsSPGeometryMode(0, G_CULL_BACK|G_LIGHTING),
gsSPEndDisplayList(),
};

