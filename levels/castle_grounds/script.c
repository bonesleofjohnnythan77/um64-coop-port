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
#include "levels/castle_grounds/header.h"
extern u8 _castle_grounds_segment_ESegmentRomStart[]; 
extern u8 _castle_grounds_segment_ESegmentRomEnd[];
const LevelScript level_castle_grounds_entry[] = {
INIT_LEVEL(),
LOAD_MIO0(0x07, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd),
LOAD_RAW(0x1A, _castle_groundsSegmentRomStart, _castle_groundsSegmentRomEnd),
LOAD_RAW(0x0E, _castle_grounds_segment_ESegmentRomStart, _castle_grounds_segment_ESegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group10_mio0SegmentRomStart,_group10_mio0SegmentRomEnd),
LOAD_RAW(12,_group10_geoSegmentRomStart,_group10_geoSegmentRomEnd),
LOAD_MIO0(6,_group15_mio0SegmentRomStart,_group15_mio0SegmentRomEnd),
LOAD_RAW(13,_group15_geoSegmentRomStart,_group15_geoSegmentRomEnd),
ALLOC_LEVEL_POOL(),
MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03,           castle_grounds_geo_0006F4),
    LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_BUBBLY_TREE,  bubbly_tree_geo),
    LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE,    warp_pipe_geo),
    LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CASTLE_DOOR,  castle_door_geo),
    LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_METAL_DOOR,   metal_door_geo),
    LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_VCUTM_GRILL,  castle_grounds_geo_00070C),
    LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_FLAG,         castle_grounds_geo_000660),
    LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CANNON_GRILL, castle_grounds_geo_000724),
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
LOAD_MODEL_FROM_GEO(41, metal_door_geo),
// LOAD_MODEL_FROM_DL(132,0x08025f08,4),
// LOAD_MODEL_FROM_DL(158,0x0302c8a0,4),
// LOAD_MODEL_FROM_DL(159,0x0302bcd0,4),
// LOAD_MODEL_FROM_DL(161,0x0301cb00,4),
// LOAD_MODEL_FROM_DL(164,0x04032a18,4),
// LOAD_MODEL_FROM_DL(201,0x080048e0,4),
// LOAD_MODEL_FROM_DL(218,0x08024bb8,4),
// LOAD_MODEL_FROM_GEO(236,0x03031ffc),
JUMP_LINK(script_func_global_1),
JUMP_LINK(script_func_global_11),
JUMP_LINK(script_func_global_16),
JUMP_LINK(local_area_castle_grounds_1_),
FREE_LEVEL_POOL(),
MARIO_POS(1,135,-545,2010,-370),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_castle_grounds_1_[] = {
AREA(1,Geo_castle_grounds_1_0x2281700),
TERRAIN(col_castle_grounds_1_0xe00aff8),
SET_BACKGROUND_MUSIC(0,39),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_castle_grounds_1_),
JUMP_LINK(local_warps_castle_grounds_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_castle_grounds_1_[] = {
OBJECT_WITH_ACTS(0,-545,2010,-370,0,0,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(22,1415,1510,-27,0,0,0,0x50000, bhvWarpPipe,31),
OBJECT_WITH_ACTS(221,1796,1510,-1239,0,287,0,0x28000000, bhvToadMessage,31),
//OBJECT_WITH_ACTS(0,521,1766,87,0,0,0,0x0, bhvIgloo,31),
OBJECT_WITH_ACTS(221,969,1510,192,0,216,0,0x12000000, bhvToadMessage,31),
OBJECT_WITH_ACTS(124,560,1510,-631,0,280,0,0x0, bhvMessagePanel,31),
OBJECT_WITH_ACTS(22,-187,1510,-45,0,0,0,0x70000, bhvWarpPipe,31),
OBJECT_WITH_ACTS(221,78,1510,-1318,0,310,0,0x13000000, bhvToadMessage,31),
OBJECT_WITH_ACTS(22,1042,1510,-1405,0,0,0,0x60000, bhvWarpPipe,31),
OBJECT_WITH_ACTS(0,359,1718,-1230,0,0,0,0x640000, bhvDeathWarp,31),
OBJECT_WITH_ACTS(0,448,2552,-792,0,0,0,0x320000, bhvAirborneStarCollectWarp,31),
OBJECT_WITH_ACTS(0,946,1510,-494,0,0,0,0x1f0000, bhvInstantActiveWarp,31),
OBJECT_WITH_ACTS(85,1828,1510,-564,0,280,0,0x10000, bhvSMSRYoshiMessage,31),
OBJECT_WITH_ACTS(236,-184,1834,-52,0,0,0,0x8000000, bhvWigglerHead,31),
OBJECT_WITH_ACTS(236,1038,1835,-1404,0,0,0,0x1000000, bhvWigglerHead,31),
//OBJECT_WITH_ACTS(0,-567,1680,-831,0,0,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(85,24,1510,-1105,0,171,0,0x0, bhvKoopaRaceEndpoint,31),
OBJECT_WITH_ACTS(85,698,1510,23,0,59,0,0x0, bhvKoopaRaceEndpoint,31),
RETURN()
};
const LevelScript local_warps_castle_grounds_1_[] = {
WARP_NODE(50,16,1,50,0),
WARP_NODE(100,16,1,100,0),
WARP_NODE(1,6,1,1,0),
WARP_NODE(31,16,1,31,0),
WARP_NODE(1,16,1,1,0),
WARP_NODE(2,16,1,2,0),
WARP_NODE(5,29,1,10,0),
WARP_NODE(10,16,1,10,0),
WARP_NODE(1,6,1,0,0),
WARP_NODE(8,27,1,10,0),
WARP_NODE(10,16,1,10,0),
WARP_NODE(4,16,1,10,0),
WARP_NODE(6,24,1,10,0),
WARP_NODE(7,27,1,10,0),
RETURN()
};
