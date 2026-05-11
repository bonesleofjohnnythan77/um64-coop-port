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

cur_obj_scale(2.75)

end


hook_event(HOOK_UPDATE, function()

    for_each_object_with_behavior(id_bhvExclamationBox, exclamation_box_new)
    for_each_object_with_behavior(bhvSMSRYoshiMessage, yoshi_star)
    for_each_object_with_behavior(bhvKoopaRaceEndpoint, yoshi_star)

    end)