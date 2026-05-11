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
end

end

--exclamation block changes

function exclamation_box_new(o)

local exclamation = obj_get_nearest_object_with_behavior_id(o, id_bhvRotatingExclamationMark)

if exclamation then
    obj_mark_for_deletion(exclamation)
end

obj_scale(o, 2.75)

end

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

hook_event(HOOK_UPDATE, function()

    for_each_object_with_behavior(id_bhvExclamationBox, exclamation_box_new)
    for_each_object_with_behavior(bhvSMSRYoshiMessage, yoshi_star)
    for_each_object_with_behavior(bhvKoopaRaceEndpoint, yoshi_star)

    end)