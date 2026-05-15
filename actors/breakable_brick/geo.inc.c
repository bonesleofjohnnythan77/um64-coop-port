#include "custom.model.inc.h"
const GeoLayout breakable_brick_geo[]= {
GEO_CULLING_RADIUS(300),
GEO_OPEN_NODE(),
GEO_SHADOW(10,180,70),
GEO_OPEN_NODE(),
GEO_SWITCH_CASE(4, geo_switch_anim_state),
GEO_OPEN_NODE(),
GEO_DISPLAY_LIST(1,DL_unk_DL_0403bacc_0x403c5ec),
GEO_CLOSE_NODE(),
GEO_CLOSE_NODE(),
GEO_CLOSE_NODE(),
GEO_END(),
};
