Texture solid_stepblock__0700CF08_rgba16[] = {
	#include "actors/solid_stepblock/_0700CF08.rgba16.inc.c"
};

Vtx solid_stepblock_000_displaylist_mesh_layer_1_vtx_0[24] = {
	{{{280, 14, -14}, 0, {-353, -353}, {0x6E, 0xD3, 0x2D, 0xFF}}},
	{{{280, 265, -265}, 0, {2985, 2985}, {0x6F, 0x2B, 0xD5, 0xFF}}},
	{{{280, 265, -14}, 0, {-353, 2985}, {0x6F, 0x2B, 0x2D, 0xFF}}},
	{{{280, 14, -265}, 0, {2985, -353}, {0x6F, 0xD3, 0xD5, 0xFF}}},
	{{{265, 0, -14}, 0, {-353, -545}, {0x2A, 0x90, 0x2C, 0xFF}}},
	{{{265, 14, 0}, 0, {-544, -353}, {0x2A, 0xD4, 0x70, 0xFF}}},
	{{{265, 265, 0}, 0, {-544, 2985}, {0x2A, 0x2A, 0x70, 0xFF}}},
	{{{265, 280, -14}, 0, {-353, 3178}, {0x2B, 0x6F, 0x2D, 0xFF}}},
	{{{265, 280, -265}, 0, {2985, 3178}, {0x2B, 0x6F, 0xD5, 0xFF}}},
	{{{265, 265, -280}, 0, {3178, 2985}, {0x2B, 0x2B, 0x91, 0xFF}}},
	{{{265, 14, -280}, 0, {3178, -353}, {0x2B, 0xD3, 0x91, 0xFF}}},
	{{{265, 0, -265}, 0, {2985, -545}, {0x2A, 0x90, 0xD6, 0xFF}}},
	{{{14, 0, -265}, 0, {2985, -545}, {0xD4, 0x90, 0xD6, 0xFF}}},
	{{{14, 0, -14}, 0, {-353, -545}, {0xD5, 0x91, 0x2B, 0xFF}}},
	{{{14, 14, 0}, 0, {-544, -353}, {0xD5, 0xD5, 0x6F, 0xFF}}},
	{{{14, 265, 0}, 0, {-544, 2985}, {0xD4, 0x2A, 0x70, 0xFF}}},
	{{{14, 280, -14}, 0, {-353, 3178}, {0xD3, 0x6E, 0x2D, 0xFF}}},
	{{{14, 280, -265}, 0, {2985, 3178}, {0xD3, 0x6F, 0xD5, 0xFF}}},
	{{{14, 265, -280}, 0, {3178, 2985}, {0xD3, 0x2B, 0x91, 0xFF}}},
	{{{14, 14, -280}, 0, {3178, -353}, {0xD3, 0xD3, 0x92, 0xFF}}},
	{{{0, 14, -265}, 0, {2985, -353}, {0x90, 0xD4, 0xD6, 0xFF}}},
	{{{0, 14, -14}, 0, {-353, -353}, {0x91, 0xD5, 0x2B, 0xFF}}},
	{{{0, 265, -14}, 0, {-353, 2985}, {0x90, 0x2A, 0x2C, 0xFF}}},
	{{{0, 265, -265}, 0, {2985, 2985}, {0x90, 0x2A, 0xD6, 0xFF}}},
};

Gfx solid_stepblock_000_displaylist_mesh_layer_1_tri_0[] = {
	gsSPVertex(solid_stepblock_000_displaylist_mesh_layer_1_vtx_0 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
	gsSP2Triangles(4, 3, 0, 0, 5, 4, 0, 0),
	gsSP2Triangles(2, 5, 0, 0, 5, 2, 6, 0),
	gsSP2Triangles(2, 7, 6, 0, 1, 7, 2, 0),
	gsSP2Triangles(7, 1, 8, 0, 9, 8, 1, 0),
	gsSP2Triangles(3, 9, 1, 0, 9, 3, 10, 0),
	gsSP2Triangles(10, 3, 11, 0, 3, 4, 11, 0),
	gsSP2Triangles(4, 12, 11, 0, 12, 4, 13, 0),
	gsSP2Triangles(4, 14, 13, 0, 14, 4, 5, 0),
	gsSP2Triangles(6, 14, 5, 0, 14, 6, 15, 0),
	gsSP2Triangles(6, 16, 15, 0, 16, 6, 7, 0),
	gsSP2Triangles(7, 17, 16, 0, 17, 7, 8, 0),
	gsSP2Triangles(8, 18, 17, 0, 18, 8, 9, 0),
	gsSP2Triangles(10, 18, 9, 0, 18, 10, 19, 0),
	gsSP2Triangles(11, 19, 10, 0, 19, 11, 12, 0),
	gsSP2Triangles(19, 12, 20, 0, 13, 20, 12, 0),
	gsSP2Triangles(20, 13, 21, 0, 13, 14, 21, 0),
	gsSP2Triangles(15, 21, 14, 0, 21, 15, 22, 0),
	gsSP2Triangles(22, 15, 16, 0, 17, 22, 16, 0),
	gsSP2Triangles(22, 17, 23, 0, 18, 23, 17, 0),
	gsSP2Triangles(19, 23, 18, 0, 23, 19, 20, 0),
	gsSP2Triangles(20, 22, 23, 0, 22, 20, 21, 0),
	gsSPEndDisplayList(),
};


Gfx mat_solid_stepblock_solid[] = {
	gsSPSetGeometryMode(G_TEXTURE_GEN),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT, 0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(1984, 1984, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, solid_stepblock__0700CF08_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_solid_stepblock_solid[] = {
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx solid_stepblock_000_displaylist_mesh_layer_1[] = {
	gsSPDisplayList(mat_solid_stepblock_solid),
	gsSPDisplayList(solid_stepblock_000_displaylist_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_solid_stepblock_solid),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

