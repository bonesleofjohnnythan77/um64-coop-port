Lights1 actSelect_dl_Grass_Example_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0x0, 0xFF, 0x0, 0x49, 0x49, 0x49);

Vtx actSelect_dl_Level_Mesh_001_mesh_layer_1_vtx_0[4] = {
	{{ {-500, 0, 500}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {500, 0, 500}, 0, {1008, 1008}, {0, 127, 0, 255} }},
	{{ {500, 0, -500}, 0, {1008, -16}, {0, 127, 0, 255} }},
	{{ {-500, 0, -500}, 0, {-16, -16}, {0, 127, 0, 255} }},
};

Gfx actSelect_dl_Level_Mesh_001_mesh_layer_1_tri_0[] = {
	gsSPVertex(actSelect_dl_Level_Mesh_001_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_actSelect_dl_Grass_Example[] = {
	gsSPSetLights1(actSelect_dl_Grass_Example_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_actSelect_dl_Grass_Example[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx actSelect_dl_Level_Mesh_001_mesh_layer_1[] = {
	gsSPDisplayList(mat_actSelect_dl_Grass_Example),
	gsSPDisplayList(actSelect_dl_Level_Mesh_001_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_actSelect_dl_Grass_Example),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

