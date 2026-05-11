#include "custom.model.inc.h"
const GeoLayout yellow_coin_geo[]= {
GEO_NODE_START(), 
GEO_OPEN_NODE(),  
GEO_SHADOW(0,180,50),
GEO_ASM(0, geo_rotate_coin),
GEO_ROTATION_NODE(LAYER_FORCE, 0, 0, 0),
GEO_OPEN_NODE(),
GEO_ANIMATED_PART(1,0,50,0,DL_yellow_coin_geo_0x30076d0),
GEO_CLOSE_NODE(),
GEO_END(),
};
#include "custom.model.inc.h"
const GeoLayout yellow_coin_no_shadow_geo[]= {
GEO_NODE_START(),    
GEO_OPEN_NODE(),
GEO_SHADOW(0,180,50),
GEO_ASM(0, geo_rotate_coin),
GEO_ROTATION_NODE(LAYER_FORCE, 0, 0, 0),
GEO_OPEN_NODE(),
GEO_ANIMATED_PART(1,0,50,0,DL_yellow_coin_geo_0x30076d0),
GEO_CLOSE_NODE(),
GEO_END(),
};

#include "custom.model.inc.h"
const GeoLayout blue_coin_geo[]= {
GEO_NODE_START(),    
GEO_OPEN_NODE(),
GEO_SHADOW(0,180,80),
GEO_ASM(0, geo_rotate_coin),
GEO_ROTATION_NODE(LAYER_FORCE, 0, 0, 0),
GEO_OPEN_NODE(),
GEO_ANIMATED_PART(1,0,50,0,DL_blue_coin_geo_0x3007720),
GEO_CLOSE_NODE(),
GEO_END(),
};
#include "custom.model.inc.h"
const GeoLayout blue_coin_no_shadow_geo[]= {
GEO_NODE_START(),    
GEO_OPEN_NODE(),
GEO_SHADOW(0,180,80),
GEO_ASM(0, geo_rotate_coin),
GEO_ROTATION_NODE(LAYER_FORCE, 0, 0, 0),
GEO_OPEN_NODE(),
GEO_ANIMATED_PART(1,0,50,0,DL_blue_coin_geo_0x3007720),
GEO_CLOSE_NODE(),
GEO_END(),
};

#include "custom.model.inc.h"
const GeoLayout red_coin_geo[]= {
GEO_NODE_START(),     
GEO_OPEN_NODE(),
GEO_SHADOW(0,180,50),
GEO_ASM(0, geo_rotate_coin),
GEO_ROTATION_NODE(LAYER_FORCE, 0, 0, 0),
GEO_OPEN_NODE(),
GEO_ANIMATED_PART(1,0,50,0,DL_red_coin_geo_0x3006c30),
GEO_CLOSE_NODE(),
GEO_END(),
};
