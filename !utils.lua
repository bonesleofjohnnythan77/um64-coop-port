--Useful romhack functions and important globals

E_MODEL_BRICK_BLOCK = smlua_model_util_get_id("brick_block_geo")
E_MODEL_BREAKABLE_BRICK = smlua_model_util_get_id("breakable_brick_geo")
E_MODEL_MESSAGE_BOX = smlua_model_util_get_id("message_box_geo")
E_MODEL_WC_PLATFORM = smlua_model_util_get_id("wc_platform_geo")
E_MODEL_NOTEBLOCK = smlua_model_util_get_id("noteblock_geo")
E_MODEL_CRYSTAL = smlua_model_util_get_id("crystal_geo")
E_MODEL_LILYPAD = smlua_model_util_get_id("lilypad_geo")
E_MODEL_CRYSTAL_PLATFORM = smlua_model_util_get_id("crystal_platform_geo")
E_MODEL_POUNDABLE_CRYSTAL = smlua_model_util_get_id("poundable_crystal_geo")

COL_POUNDABLE_CRYSTAL = smlua_collision_util_get("poundable_crystal_collision")
COL_CRYSTAL_PLATFORM = smlua_collision_util_get("crystal_platform_collision")
COL_LILYPAD = smlua_collision_util_get("lilypad_collision")
COL_BRICK_BLOCK = smlua_collision_util_get("brick_block_collision")


--get star count
function get_star_count() 
    return save_file_get_total_star_count(get_current_save_file_num() - 1, COURSE_MIN - 1, COURSE_MAX - 1)
end

function is_bubbled(m)
    return m.action == ACT_BUBBLED
end

--despawn if stars are below/above count
function despawn_if_stars_below_count(obj, count)
    if get_star_count() < count then
        obj_mark_for_deletion(obj)
    end
end

function despawn_if_stars_above_count(obj, count)
    if get_star_count() >= count then
        obj_mark_for_deletion(obj)
    end
end

--do function for each object 
function for_each_object_with_behavior(behavior, func) -- by isaac
    local o = obj_get_first_with_behavior_id(behavior)
    while o do
        func(o)
        o = obj_get_next_with_same_behavior_id(o)
    end
end

--set hitbox

--- @param obj Object
--- @param hitbox ObjectHitbox
function obj_set_hitbox(obj, hitbox)
    if not obj or not hitbox then return end
    -- Sets other hitbox values once
    if (obj.oFlags & OBJ_FLAG_30) == 0 then
        obj.oFlags = obj.oFlags | OBJ_FLAG_30

        obj.oInteractType = hitbox.interactType
        obj.oDamageOrCoinValue = hitbox.damageOrCoinValue
        obj.oHealth = hitbox.health
        obj.oNumLootCoins = hitbox.numLootCoins

        cur_obj_become_tangible()
    end

    -- Set actual hitboxes
    obj.hitboxRadius = obj.header.gfx.scale.x * hitbox.radius
    obj.hitboxHeight = obj.header.gfx.scale.y * hitbox.height
    obj.hurtboxRadius = obj.header.gfx.scale.x * hitbox.hurtboxRadius
    obj.hurtboxHeight = obj.header.gfx.scale.y * hitbox.hurtboxHeight
    obj.hitboxDownOffset = obj.header.gfx.scale.y * hitbox.downOffset
end