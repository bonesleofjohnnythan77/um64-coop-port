const BehaviorScript bhvWigglerHead[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvWigglerHead),
LOAD_COLLISION_DATA(brick_block_collision),
OR_INT(oFlags,1),
CALL_NATIVE(bhv_brick_init),
BEGIN_LOOP(),
CALL_NATIVE(load_object_collision_model),
CALL_NATIVE(bhv_brick_update),
END_LOOP(),
}; 

const BehaviorScript bhvKoopaRaceEndpoint[] = {
BEGIN(OBJ_LIST_GENACTOR),
ID(id_bhvKoopaRaceEndpoint),
OR_INT(oFlags,8201),
LOAD_ANIMATIONS(oAnimations,yoshi_seg5_anims_05024100),
SET_INTERACT_TYPE(8388608),
DROP_TO_FLOOR(),
SET_HITBOX(160,150),
ANIMATE(0),
SET_HOME(),
BEGIN_LOOP(),
CALL_NATIVE( bhv_toad_message_loop),
END_LOOP(),
};

const BehaviorScript bhvLllHexagonalMesh[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvLllHexagonalMesh),
OR_INT(oFlags,1),
BEGIN_LOOP(),
CALL_NATIVE( Func_Custom_0x802bd158),
END_LOOP(),
};

const BehaviorScript bhv1Up[] = {
BEGIN(OBJ_LIST_LEVEL),
ID(id_bhv1Up),
OR_INT(oFlags,1),
SET_HITBOX_WITH_OFFSET(30,30,0),
SET_FLOAT(oGraphYOffset,30),
CALL_NATIVE( bhv_1up_init),
CALL_NATIVE( init_object),
BEGIN_LOOP(),
SET_INT(oIntangibleTimer,0),
CALL_NATIVE( bhv_1up_loop),
ADD_INT(oFaceAngleYaw,256),
END_LOOP(),
};

const BehaviorScript bhvWaterLevelDiamond[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvWaterLevelDiamond),
OR_INT(oFlags,1),
CALL_NATIVE( coin_spawner_init),
SET_HITBOX(70,30),
SET_FLOAT(oCollisionDistance,200),
SET_INT(oIntangibleTimer,0),
BEGIN_LOOP(),
CALL_NATIVE( coin_spawner_update),
END_LOOP(),
};
/*
const BehaviorScript bhvExclamationBox[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvExclamationBox),
OR_INT(oFlags,9),
LOAD_COLLISION_DATA(col_exclamation_box_geo_0x8025f78),
OR_INT(oFlags,1),
SET_FLOAT(oCollisionDistance,300),
SET_HOME(),
BEGIN_LOOP(),
CALL_NATIVE(exclamation_box_new),
END_LOOP(),
};
*/
const BehaviorScript bhvInSunkenShip3[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvInSunkenShip3),
OR_INT(oFlags,1),
SET_HITBOX(86,30),
SET_FLOAT(oCollisionDistance,200),
SET_INT(oIntangibleTimer,0),
BEGIN_LOOP(),
ADD_INT(oAnimState,1),
CALL_NATIVE( message_block_init),
END_LOOP(),
};

const BehaviorScript bhvWfRotatingWoodenPlatform[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvWfRotatingWoodenPlatform),
OR_INT(oFlags,1),
CALL_NATIVE( init_object),
LOAD_COLLISION_DATA(wc_platform_collision),
BEGIN_LOOP(),
CALL_NATIVE( bhv_wf_rotating_wooden_platform_loop),
CALL_NATIVE( load_object_collision_model),
END_LOOP(),
};

const BehaviorScript bhvGiantPole[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvGiantPole),
OR_INT(oUnk94,3),
SET_HOME(),
CALL_NATIVE( init_object),
LOAD_COLLISION_DATA(noteblock_collision),
BEGIN_LOOP(),
CALL_NATIVE( Func_Custom_0x802c2b4c),
CALL_NATIVE( load_object_collision_model),
END_LOOP(),
};

const BehaviorScript Bhv_Custom_0x0403c72c[] = {
BEGIN(OBJ_LIST_PUSHABLE),
ID(id_bhvNewId),
OR_INT(oFlags,8265),
LOAD_ANIMATIONS(oAnimations,flyguy_seg8_anims_08011A64),
SET_HOME(),
SET_OBJ_PHYSICS(40,65136,65486,1000,1000,0,0,0),
CALL_NATIVE( bhv_goomba_init),
BEGIN_LOOP(),
CALL_NATIVE( bhv_goomba_update),
END_LOOP(),
};

const BehaviorScript bhvTowerDoor[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvTowerDoor),
OR_INT(oUnk94,3),
SET_HOME(),
CALL_NATIVE( init_object),
LOAD_COLLISION_DATA(wide_noteblock_collision),
BEGIN_LOOP(),
CALL_NATIVE( Func_Custom_0x802c2b4c),
CALL_NATIVE( load_object_collision_model),
END_LOOP(),
};

const BehaviorScript Bhv_Custom_0x13000f60[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvNewId),
OR_INT(oFlags,1),
BEGIN_LOOP(),
CALL_NATIVE( Func_Custom_0x802bd1c0),
END_LOOP(),
};

const BehaviorScript bhvUkikiCage[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvUkikiCage),
OR_INT(oFlags,1),
BEGIN_LOOP(),
CALL_NATIVE( bhv_crystal_size_loop),
END_LOOP(),
};

const BehaviorScript bhvBowserSubDoor[] = {
BEGIN(OBJ_LIST_LEVEL),
ID(id_bhvBowserSubDoor)
OR_INT(oFlags,1),
LOAD_ANIMATIONS(oAnimations,seaweed_seg6_anims_0600A4D4),
ANIMATE(0),
CALL_NATIVE( bhv_seaweed_init),
CALL_NATIVE( bhv_crystal_size_loop),
BEGIN_LOOP(),
END_LOOP(),
};

const BehaviorScript bhvTTCElevator[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvTTCElevator),
OR_INT(oFlags,17),
CALL_NATIVE( init_object),
LOAD_COLLISION_DATA(dark_platform_collision),
CALL_NATIVE( bhv_ssl_moving_pyramid_wall_init),
BEGIN_LOOP(),
CALL_NATIVE( bhv_ssl_moving_pyramid_wall_loop),
CALL_NATIVE( load_object_collision_model),
END_LOOP(),
};

const BehaviorScript bhvOpenableGrill[] = {
BEGIN(OBJ_LIST_DEFAULT),
ID(id_bhvOpenableGrill),
OR_INT(oFlags,9),
BEGIN_LOOP(),
CALL_NATIVE( bhv_new_openable_grill),
END_LOOP(),
};

const BehaviorScript bhvSmallBomp[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvSmallBomp)
OR_INT(oFlags,1),
LOAD_COLLISION_DATA(col_bubbly_tree_geo_0x302ea70),
SCALE(0,200),
CALL_NATIVE( bhv_init_room),
BEGIN_LOOP(),
CALL_NATIVE( Func_Custom_0x802c2ab4),
CALL_NATIVE( load_object_collision_model),
END_LOOP(),
};

const BehaviorScript bhvKickableBoard[] = {
BEGIN(OBJ_LIST_LEVEL),
ID(id_bhvKickableBoard),
OR_INT(oFlags,1),
SET_HITBOX(100,100),
SET_INT(oIntangibleTimer,0),
SET_MODEL(24),
BEGIN_LOOP(),
CALL_NATIVE( Func_Custom_0x802b2dac),
CALL_NATIVE( bhv_yellow_coin_loop),
ADD_INT(oUnk94,1280),
END_LOOP(),
};

const BehaviorScript Bhv_Custom_0x13000f78[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvNewId),
OR_INT(oFlags,9),
CALL_NATIVE( init_object),
LOAD_COLLISION_DATA(lilypad_collision),
SET_FLOAT(oYoshiChosenHome,64),
SET_HOME(),
BEGIN_LOOP(),
CALL_NATIVE( bhv_floating_platform_loop),
CALL_NATIVE( load_object_collision_model),
END_LOOP(),
};

const BehaviorScript bhvSquarishPathMoving[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvSquarishPathMoving),
OR_INT(oFlags,1),
CALL_NATIVE( init_object),
LOAD_COLLISION_DATA(crystal_platform_collision),
SET_HOME(),
BEGIN_LOOP(),
CALL_NATIVE( bhv_squarish_path_moving_loop),
END_LOOP(),
};

const BehaviorScript bhvLllWoodPiece[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvLllWoodPiece),
OR_INT(oFlags,1),
LOAD_COLLISION_DATA(poundable_crystal_collision),
CALL_NATIVE( bhv_init_room),
BEGIN_LOOP(),
CALL_NATIVE( Func_Custom_0x802bc664),
CALL_NATIVE( load_object_collision_model),
END_LOOP(),
};

const BehaviorScript bhvChainChompGate[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvChainChompGate),
LOAD_COLLISION_DATA(poundable_switch_blue_collision),
OR_INT(oFlags,1),
CALL_NATIVE( bhv_poundable_switch_init),
BEGIN_LOOP(),
CALL_NATIVE( load_object_collision_model),
CALL_NATIVE( bhv_poundable_switch_loop),
END_LOOP(),
};

const BehaviorScript bhvBulletBill[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvBulletBill),
OR_INT(oFlags,1),
SET_FLOAT(oCollisionDistance,4000),
CALL_NATIVE( bhv_poundable_switch_starspawn_init),
BEGIN_LOOP(),
CALL_NATIVE( bhv_poundable_switch_starspawn_loop),
END_LOOP(),
};

const BehaviorScript bhvBubbleMaybe[] = {
BEGIN(OBJ_LIST_UNIMPORTANT),
ID(id_bhvBubbleMaybe),
OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
BILLBOARD(),
CALL_NATIVE(bhv_water_bubble_init_new),
SET_RANDOM_FLOAT(oWaterObjUnkF4, /*Minimum*/ -75, /*Range*/ 150),
SET_RANDOM_FLOAT(oWaterObjUnkF8, /*Minimum*/ -75, /*Range*/ 150),
SET_RANDOM_FLOAT(oWaterObjUnkFC, /*Minimum*/ -75, /*Range*/ 150),
SUM_FLOAT(/*Dest*/ oPosX, /*Value 1*/ oPosX, /*Value 2*/ oWaterObjUnkF4),
SUM_FLOAT(/*Dest*/ oPosZ, /*Value 1*/ oPosZ, /*Value 2*/ oWaterObjUnkF8),
SUM_FLOAT(/*Dest*/ oPosY, /*Value 1*/ oPosY, /*Value 2*/ oWaterObjUnkFC),
SET_INT(oAnimState, -1),
BEGIN_REPEAT(60),
ADD_INT(oAnimState, 1),
CALL_NATIVE(bhv_bubble_maybe_loop),
END_REPEAT(),
DEACTIVATE(),
};

const BehaviorScript bhvSunkenShipPart[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvSunkenShipPart),
OR_INT(oFlags,1),
SET_INT(oIntangibleTimer,0),
BEGIN_LOOP(),
ADD_INT(oAnimState,1),
END_LOOP(),
};

const BehaviorScript bhvLllRotatingHexagonalRing[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvLllRotatingHexagonalRing),
OR_INT(oFlags,1),
CALL_NATIVE( init_object),
LOAD_COLLISION_DATA(green_dotted_block_collision),
SET_HOME(),
BEGIN_LOOP(),
CALL_NATIVE( bhv_squarish_path_moving_loop),
END_LOOP(),
};

const BehaviorScript bhvPyramidTop[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvPyramidTop),
OR_INT(oFlags,17),
CALL_NATIVE( init_object),
LOAD_COLLISION_DATA(green_block_collision),
CALL_NATIVE( bhv_ssl_moving_pyramid_wall_init),
BEGIN_LOOP(),
CALL_NATIVE( bhv_ssl_moving_pyramid_wall_loop),
CALL_NATIVE( load_object_collision_model),
END_LOOP(),
};

const BehaviorScript bhvLllMovingOctagonalMeshPlatform[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvLllMovingOctagonalMeshPlatform),
OR_INT(oFlags,65),
SET_HOME(),
LOAD_COLLISION_DATA(green_block_collision),
BEGIN_LOOP(),
CALL_NATIVE( bhv_lll_moving_octagonal_mesh_platform_loop),
CALL_NATIVE( load_object_collision_model),
END_LOOP(),
};

const BehaviorScript Bhv_Custom_0x130017b8[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvNewId),
OR_INT(oFlags,1),
CALL_NATIVE(bhv_solid_stepblock_init),
LOAD_COLLISION_DATA(solid_stepblock_collision),
SET_HOME(),
BEGIN_LOOP(),
CALL_NATIVE( bhv_solid_stepblock_loop),
CALL_NATIVE( load_object_collision_model),
END_LOOP(),
};

const BehaviorScript Bhv_Custom_0x13002304[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvNewId),
OR_INT(oFlags,65),
SET_HOME(),
//LOAD_COLLISION_DATA(col_unk_DL_03035904_0xae7bc8),
BEGIN_LOOP(),
CALL_NATIVE( bhv_lll_moving_octagonal_mesh_platform_loop),
CALL_NATIVE( load_object_collision_model),
END_LOOP(),
};

const BehaviorScript bhvLllSinkingRockBlock[] = {
BEGIN(OBJ_LIST_SURFACE),
ID(id_bhvLllSinkingRockBlock)
OR_INT(oFlags,9),
CALL_NATIVE( init_object),
LOAD_COLLISION_DATA(metal_box_seg8_collision_08024C28),
SCALE(0,160),
SET_HOME(),
BEGIN_LOOP(),
CALL_NATIVE( bhv_lll_sinking_rock_block_loop),
CALL_NATIVE( bhv_lll_sinking_rock_block_loop),
CALL_NATIVE( load_object_collision_model),
END_LOOP(),
};