--Useful romhack functions and important globals

require("actselect")
require("bhv")
require("courses")
require("hud")
require("itembox")
require("scroll_textures")
require("moving_textures")
require("sound")
require("tweaks")
require("dialogs")
smlua_audio_utils_replace_sequence(0x01, 0x00, 90, "01_Seq_custom")

E_MODEL_BRICK_BLOCK = smlua_model_util_get_id("brick_block_geo")
E_MODEL_BREAKABLE_BRICK = smlua_model_util_get_id("breakable_brick_geo")
E_MODEL_MESSAGE_BOX = smlua_model_util_get_id("message_box_geo")
E_MODEL_WC_PLATFORM = smlua_model_util_get_id("wc_platform_geo")
E_MODEL_NOTEBLOCK = smlua_model_util_get_id("noteblock_geo")
E_MODEL_CRYSTAL = smlua_model_util_get_id("crystal_geo")
E_MODEL_LILYPAD = smlua_model_util_get_id("lilypad_geo")
E_MODEL_CRYSTAL_PLATFORM = smlua_model_util_get_id("crystal_platform_geo")
E_MODEL_POUNDABLE_CRYSTAL = smlua_model_util_get_id("poundable_crystal_geo")
E_MODEL_POUNDABLE_SWITCH_BLUE = smlua_model_util_get_id("poundable_switch_blue_geo")
E_MODEL_POUNDABLE_SWITCH_YELLOW = smlua_model_util_get_id("poundable_switch_yellow_geo")
E_MODEL_SOLID_STEPBLOCK = smlua_model_util_get_id("solid_stepblock_geo")
E_MODEL_TRANSPARENT_STEPBLOCK = smlua_model_util_get_id("transparent_stepblock_geo")
E_MODEL_RETRO_SPRITES = smlua_model_util_get_id("retro_sprites_geo")
E_MODEL_RETRO_COIN = smlua_model_util_get_id("retro_coin_geo")
E_MODEL_RETRO_FIRE_FLOWER = smlua_model_util_get_id("retro_fire_flower_geo")
E_MODEL_RETRO_STAR = smlua_model_util_get_id("retro_star_geo")
E_MODEL_GREEN_DOTTED_BLOCK = smlua_model_util_get_id("green_dotted_block_geo")
E_MODEL_DARK_PLATFORM = smlua_model_util_get_id("dark_platform_geo")
E_MODEL_WIDE_NOTEBLOCK = smlua_model_util_get_id("wide_noteblock_geo")
E_MODEL_GREEN_BLOCK = smlua_model_util_get_id("green_block_geo")
E_MODEL_YI_PLATFORM_GREEN = smlua_model_util_get_id("yi_platform_green_geo")
E_MODEL_YI_PLATFORM_PURPLE = smlua_model_util_get_id("yi_platform_purple_geo")

COL_GREEN_BLOCK = smlua_collision_util_get("green_block_collision")
COL_WIDE_NOTEBLOCK = smlua_collision_util_get("wide_noteblock_collision")
COL_DARK_PLATFORM = smlua_collision_util_get("dark_platform_collision")
COL_NOTEBLOCK = smlua_collision_util_get("noteblock_collision")
COL_SOLID_STEPBLOCK = smlua_collision_util_get("solid_stepblock_collision")
COL_POUNDABLE_SWITCH_BLUE = smlua_collision_util_get("poundable_switch_blue_collision")
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

--spawn 100 coin star in non main levels.

local levelTable = {
    [LEVEL_TOTWC] = true,
    [LEVEL_PSS] = true,
    [LEVEL_COTMC] = true
}

local prev_numCoins = 0

hook_event(HOOK_ALLOW_INTERACT, function(m, obj, inter_type)
  if inter_type == INTERACT_COIN then
    prev_numCoins = m.numCoins
  end
  return true
end)


hook_event(HOOK_ON_INTERACT, function(m, obj, inter_type, value)
    for i = 0, MAX_PLAYERS - 1 do
        --local m = gMarioStates[i]
        local np = gNetworkPlayers[i]

        if inter_type == INTERACT_COIN then
            local numcoins = m.numCoins
            local required = gLevelValues.coinsRequiredForCoinStar
            if levelTable[np.currLevelNum] then
                --djui_chat_message_create("yes spawn")
                if numcoins >= required and prev_numCoins < required then
                --if m.controller.buttonDown & X_BUTTON ~= 0 then --debug
                    bhv_spawn_star_no_level_exit(m.marioObj, 6, 1)
                end
            end
        end
    end
end)

hook_event(HOOK_MARIO_UPDATE, function (m)
    local shadeR = m.marioBodyState.shadeR
    local shadeG = m.marioBodyState.shadeG
    local shadeB = m.marioBodyState.shadeB
    if gNetworkPlayers[0].currLevelNum == LEVEL_WF then
        m.marioBodyState.shadeR = 46
        m.marioBodyState.shadeG = 28
        m.marioBodyState.shadeB = 76
    elseif gNetworkPlayers[0].currLevelNum == LEVEL_COTMC then
        m.marioBodyState.shadeR = 44
        m.marioBodyState.shadeG = 66
        m.marioBodyState.shadeB = 39        
    else
        m.marioBodyState.shadeR = shadeR
        m.marioBodyState.shadeG = shadeG
        m.marioBodyState.shadeB = shadeB
    end
end)

hook_event(HOOK_UPDATE, function ()

stop_cap_music()

end)



--[[ WONT BE USED ANYMORE
hook_event(HOOK_MARIO_UPDATE, function (inter_type)
    
    for i = 0, MAX_PLAYERS - 1 do
        local m = gMarioStates[i]
        local np = gNetworkPlayers[i] 
        if inter_type == INTERACT_COIN then
            local numcoins = m.numCoins
            local required = gLevelValues.coinsRequiredForCoinStar            
        if np.currLevelNum == LEVEL_TOTWC or np.currLevelNum == LEVEL_PSS then
        if numcoins >= required and prev_numCoins < required then    
        bhv_spawn_star_no_level_exit(m.marioObj, 6, 0)
        end
    end
end

end)
]]--