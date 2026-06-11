#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"
#include "game/level_update.h"
#include "levels/scripts.h"
#include "actors/common1.h"
#include "make_const_nonconst.h"

#include "areas/1/custom.model.inc.h"
#include "levels/bob/header.h"
extern u8 _bob_segment_ESegmentRomStart[]; 
extern u8 _bob_segment_ESegmentRomEnd[];
const LevelScript level_bob_entry[] = {
INIT_LEVEL(),
LOAD_MIO0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd),
LOAD_RAW(0x1A, _bobSegmentRomStart, _bobSegmentRomEnd),
LOAD_RAW(0x0E, _bob_segment_ESegmentRomStart, _bob_segment_ESegmentRomEnd),
LOAD_MIO0(0xA,_clouds_skybox_mio0SegmentRomStart,_clouds_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group3_mio0SegmentRomStart,_group3_mio0SegmentRomEnd),
LOAD_RAW(12,_group3_geoSegmentRomStart,_group3_geoSegmentRomEnd),
LOAD_MIO0(6,_group14_mio0SegmentRomStart,_group14_mio0SegmentRomEnd),
LOAD_RAW(13,_group14_geoSegmentRomStart,_group14_geoSegmentRomEnd),
ALLOC_LEVEL_POOL(),
MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE,      bubbly_tree_geo),
    LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440),
    LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM,  bob_geo_000458),
    LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS,      bob_geo_000470),
LOAD_MODEL_FROM_GEO(22, warp_pipe_geo),
LOAD_MODEL_FROM_GEO(23, bubbly_tree_geo),
LOAD_MODEL_FROM_GEO(24, spiky_tree_geo),
LOAD_MODEL_FROM_GEO(25, snow_tree_geo),
LOAD_MODEL_FROM_GEO(27, palm_tree_geo),
LOAD_MODEL_FROM_GEO(31, metal_door_geo),
LOAD_MODEL_FROM_GEO(32, hazy_maze_door_geo),
LOAD_MODEL_FROM_GEO(34, castle_door_0_star_geo),
LOAD_MODEL_FROM_GEO(35, castle_door_1_star_geo),
LOAD_MODEL_FROM_GEO(36, castle_door_3_stars_geo),
LOAD_MODEL_FROM_GEO(37, key_door_geo),
LOAD_MODEL_FROM_GEO(38, castle_door_geo),
// LOAD_MODEL_FROM_DL(132,0x08025f08,4),
// LOAD_MODEL_FROM_DL(158,0x0302c8a0,4),
// LOAD_MODEL_FROM_DL(159,0x0302bcd0,4),
// LOAD_MODEL_FROM_DL(161,0x0301cb00,4),
// LOAD_MODEL_FROM_DL(164,0x04032a18,4),
// LOAD_MODEL_FROM_DL(201,0x080048e0,4),
// LOAD_MODEL_FROM_DL(218,0x08024bb8,4),
LOAD_MODEL_FROM_GEO(231,brick_block_geo),
LOAD_MODEL_FROM_GEO(232,yi_platform_green_geo),
// LOAD_MODEL_FROM_GEO(233,0x03035904),
JUMP_LINK(script_func_global_1),
JUMP_LINK(script_func_global_4),
JUMP_LINK(script_func_global_15),
JUMP_LINK(local_area_bob_1_),
FREE_LEVEL_POOL(),
MARIO_POS(1,135,-6558,0,6464),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_bob_1_[] = {
AREA(1,Geo_bob_1_0x18e1700),
TERRAIN(col_bob_1_0xe0249a0),
SET_BACKGROUND_MUSIC(0,3),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_bob_1_),
JUMP_LINK(local_warps_bob_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_bob_1_[] = {
OBJECT_WITH_ACTS(0,-69,1578,-515,0,295,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(0,1382,-1247,-6372,0,-154,0,0xb0000, bhvFadingWarp,31),
OBJECT_WITH_ACTS(0,2479,-95,-6508,0,-153,0,0xc0000, bhvFadingWarp,31),
OBJECT_WITH_ACTS(0,-5813,-2906,-4336,0,107,0,0xd0000, bhvFadingWarp,31),
OBJECT_WITH_ACTS(0,2779,-3162,5633,0,-151,0,0xe0000, bhvFadingWarp,31),
OBJECT_WITH_ACTS(231,-9172,1863,-12764,3,304,3,0x0, bhvSunkenShipPart,31),
OBJECT_WITH_ACTS(231,8806,3897,-14032,0,48,0,0x0, bhvSunkenShipPart,31),
OBJECT_WITH_ACTS(231,14912,2948,-3883,0,9,0,0x0, bhvSunkenShipPart,31),
OBJECT_WITH_ACTS(231,14287,6226,4745,0,333,0,0x0, bhvSunkenShipPart,31),
OBJECT_WITH_ACTS(231,-16437,2618,-1278,0,358,0,0x20000, bhvSunkenShipPart,31),
OBJECT_WITH_ACTS(231,-10724,4778,5865,0,25,0,0x0, bhvSunkenShipPart,31),
OBJECT_WITH_ACTS(231,-2077,2828,11786,0,68,0,0x30000, bhvSunkenShipPart,31),
OBJECT_WITH_ACTS(231,7318,2498,14019,0,108,0,0x10000, bhvSunkenShipPart,31),
OBJECT_WITH_ACTS(124,931,-3430,-462,0,0,0,0x0, bhvMessagePanel,31),
OBJECT_WITH_ACTS(212,2007,-3472,-1811,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(142,-2314,-3670,-3160,0,0,0,0x0, bhvWaterMist2,31),
OBJECT_WITH_ACTS(142,-2033,-3670,-3159,0,0,0,0x0, bhvWaterMist2,31),
OBJECT_WITH_ACTS(0,-2145,-3567,-3259,0,0,0,0x0, bhvWaterfallSoundLoop,31),
OBJECT_WITH_ACTS(188,620,-3472,-2516,0,0,0,0x0, bhvBobomb,31),
OBJECT_WITH_ACTS(0,138,-3442,-1291,0,0,0,0x0, bhvHiddenRedCoinStar,31),
OBJECT_WITH_ACTS(215,795,-3171,-713,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(192,-676,-3472,-1869,0,0,0,0x20000, bhvGoomba,31),
OBJECT_WITH_ACTS(130,-5001,-3394,2143,0,0,0,0x0, bhvBreakableBoxSmall,31),
OBJECT_WITH_ACTS(232,685,1367,-1159,0,0,0,0x0, bhvSslMovingPyramidWall,31),
OBJECT_WITH_ACTS(0,-5786,-2991,-2940,0,0,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(0,-7238,-2573,-511,0,0,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(0,-6160,-2986,-460,0,0,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(0,-7203,-2753,-2455,0,0,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(0,-6738,-2807,-1452,0,0,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(0,-4292,-3474,-1502,0,0,0,0x50000, bhvBulletBill,31),
OBJECT_WITH_ACTS(231,111,2880,-12965,0,278,0,0x0, bhvSunkenShipPart,31),
OBJECT_WITH_ACTS(233,-108,1290,-1494,0,0,0,0x10000, Bhv_Custom_0x13002304,31),
RETURN()
};
const LevelScript local_warps_bob_1_[] = {
WARP_NODE(10,9,1,10,0),
WARP_NODE(11,9,1,12,0),
WARP_NODE(12,9,1,11,0),
WARP_NODE(13,9,1,14,0),
WARP_NODE(14,9,1,13,0),
WARP_NODE(240,6,1,50,0),
WARP_NODE(241,6,1,100,0),
WARP_NODE(0,9,1,10,0),
WARP_NODE(1,9,1,10,0),
WARP_NODE(2,9,1,10,0),
WARP_NODE(3,9,1,10,0),
WARP_NODE(4,9,1,10,0),
WARP_NODE(5,9,1,10,0),
WARP_NODE(6,9,1,10,0),
RETURN()
};
