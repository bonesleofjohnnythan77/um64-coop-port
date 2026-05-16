--Custom Behaviors

--Progression Blocks

---@param o Object
function bhv_brick_init(o)
obj_set_model_extended(o, E_MODEL_BRICK_BLOCK)
end

---@param o Object
function bhv_brick_update(o)
despawn_if_stars_above_count(o, (o.oBehParams >> 24))
end

--100% yoshis
function yoshi_star(o)

    despawn_if_stars_below_count(o, 16)

end

--fuckass tree leaf spawner



function Func_Custom_0x802bd158(o)


local spawnInterval = o.oBehParams2ndByte * math.random(2, 3)

if o.oTimer == nil then
    o.oTimer = 0
end

o.oTimer = o.oTimer + 1
--djui_chat_message_create("Printing" .. o.oTimer)

if o.oTimer >= spawnInterval then

    spawn_non_sync_object(id_bhvTreeLeaf, E_MODEL_LEAVES, o.oPosX, o.oPosY, o.oPosZ, nil)
    o.oTimer = 0
    cur_obj_become_intangible()
end

end

--bubble spawner

function Func_Custom_0x802bd1c0(o)
     local spawnInterval = o.oBehParams2ndByte or 60

    if o.oTimer == nil then
        o.oTimer = 0
    end

    o.oTimer = o.oTimer + 1

    if o.oTimer >= spawnInterval then
        spawn_non_sync_object(id_bhvBubbleMaybe, E_MODEL_WHITE_PARTICLE_SMALL, o.oPosX, o.oPosY, o.oPosZ, nil)
        o.oTimer = 0
        cur_obj_become_intangible()
    end   
end

function bhv_water_bubble_init_new(o)
    o.oWaterObjUnkFC  = 0x800 + (math.random() * 2048)
    o.oWaterObjUnk100 = 0x800 + (math.random() * 2048)
end


--exclamation block changes
local sExclamationBoxActions = {
    [0] = 0,  -- Initialize
    [1] = 1,  -- Idle
    [2] = 2,  -- Bounce when Mario near
    [3] = 3,  -- Pop open
    [4] = 4,  -- Spawning content
    [5] = 5,  -- Wait after popping
    [6] = 6,  -- Cleanup/despawn
}



--[[
function exclamation_box_new(o)

local exclamation = obj_get_nearest_object_with_behavior_id(o, id_bhvRotatingExclamationMark)

if exclamation then
    obj_mark_for_deletion(exclamation)
end


cur_obj_scale(2.75)
bhv_exclamation_box_loop()

end
]]--
--coin spawner

function coin_spawner_update(o)

    local m = nearest_mario_state_to_object(o)

    if not (o.oAction > 0) then
        

        if obj_check_hitbox_overlap(m.marioObj, o) then
            if o.oBehParams2ndByte ~= 1 then
                spawn_non_sync_object(id_bhvThreeCoinsSpawn, E_MODEL_YELLOW_COIN, o.oPosX, o.oPosY, o.oPosZ, nil)
                
            else
                spawn_non_sync_object(id_bhvSingleCoinGetsSpawned, E_MODEL_YELLOW_COIN, o.oPosX, o.oPosY, o.oPosZ, nil)
            end
            o.oAction = 1
              
        end
    end
end

--message block
function message_block_init(o)
    local m = gMarioStates[0]
    local collide = obj_check_if_collided_with_object(o, m.marioObj)
    if not m then return end
    
    if collide ~= 0 then
        create_dialog_box(o.oBehParams2ndByte)
    end
    obj_set_model_extended(o, E_MODEL_MESSAGE_BOX)

end


--UM64 Noteblock

function Func_Custom_0x802c2b4c(o)
    local m = nearest_mario_state_to_object(o)
    local strength = o.oBehParams2ndByte
    local speed = 64

    if cur_obj_is_mario_on_platform() == 1 and not is_bubbled(m) then

        set_mario_action(m, ACT_DOUBLE_JUMP, 1)
        m.vel.y = speed + 12


        if (m.controller.buttonDown & A_BUTTON) ~= 0 then
            spawn_non_sync_object(
                id_bhvHorStarParticleSpawner,
                E_MODEL_NONE,
                m.pos.x, m.pos.y, m.pos.z,
                nil
            )
            create_sound_spawner(SOUND_GENERAL_BOING1)
            m.vel.y = speed + strength
        end


        
    end    


end


hook_event(HOOK_UPDATE, function()

    for_each_object_with_behavior(bhvSMSRYoshiMessage, yoshi_star)
    for_each_object_with_behavior(bhvKoopaRaceEndpoint, yoshi_star)

    end)