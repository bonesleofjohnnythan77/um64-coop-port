#include "custom.model.inc.h"
const GeoLayout bubbly_tree_geo[]= {
GEO_CULLING_RADIUS(800),
GEO_OPEN_NODE(),
GEO_DISPLAY_LIST(1,DL_bubbly_tree_geo_0x302e948),
GEO_CLOSE_NODE(),
GEO_END(),
};
#include "custom.model.inc.h"
const GeoLayout spiky_tree_geo[]= {
GEO_SHADOW(1,155,100),
GEO_OPEN_NODE(),
GEO_SCALE(0,16384),
GEO_OPEN_NODE(),
GEO_DISPLAY_LIST(1,DL_spiky_tree_geo_0x302f850),
GEO_DISPLAY_LIST(4,DL_spiky_tree_geo_0x302ba18),
GEO_CLOSE_NODE(),
GEO_CLOSE_NODE(),
GEO_END(),
};
#include "custom.model.inc.h"
const GeoLayout snow_tree_geo[]= {
GEO_DISPLAY_LIST(1,DL_spiky_tree_geo_0x302f850),
GEO_DISPLAY_LIST(4,DL_spiky_tree_geo_0x302ba18),
GEO_CLOSE_NODE(),
GEO_CLOSE_NODE(),
GEO_END(),
};
#include "custom.model.inc.h"
const GeoLayout palm_tree_geo[]= {
GEO_CULLING_RADIUS(800),
GEO_OPEN_NODE(),
GEO_DISPLAY_LIST(4,DL_palm_tree_geo_0x3033258),
GEO_CLOSE_NODE(),
GEO_END(),
};
