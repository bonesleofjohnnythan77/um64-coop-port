--Custom Behaviors
function init_object(o)
    network_init_object(o, true, nil)
end

--Progression Blocks

---@param o Object
function bhv_brick_init(o)
    obj_set_model_extended(o, E_MODEL_BRICK_BLOCK)
    network_init_object(o, true, nil)
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

--crystals

function bhv_crystal_size_loop(o)
    local scale = (o.oBehParams2ndByte * 0.0099487305) + 0.25
    o.header.gfx.scale.x = scale
    o.header.gfx.scale.y = scale
    o.header.gfx.scale.z = scale
end

--thought there was something else to this

function bhv_new_openable_grill(o)
    bhv_openable_grill_loop()
end

--poundable crystal

sBreakableBoxHitbox = {
    interactType = INTERACT_BREAKABLE,
    downOffset = 20,
    damageOrCoinValue = 0,
    health = 1,
    numLootCoins = 0,
    radius = 150,
    height = 200,
    hurtboxRadius = 150,
    hurtboxHeight = 200,
};

function breakable_box_init(o)
    o.oHiddenObjectUnkF4 = nil
    o.oAnimState = 1
    o.oHealth = 1

    local param = o.oBehParams2ndByte
    if param == 0 then
        o.oNumLootCoins = 0
    elseif param == 1 then
        o.oNumLootCoins = 3
    elseif param == 2 then
        o.oNumLootCoins = 5
    elseif param == 3 then
        cur_obj_scale(1.5)
    end
    network_init_object(o, false, {"oHealth"})
end

function Func_Custom_0x802bc664(o)
    obj_set_hitbox(o, sBreakableBoxHitbox)
    obj_set_model_extended(o, E_MODEL_POUNDABLE_CRYSTAL)

    if o.oTimer == 0 then
        breakable_box_init(o)
    end

    if cur_obj_was_attacked_or_ground_pounded() ~= 0 then
        o.oHealth = 0
        network_send_object(o, true)
    end

    if o.oHealth == 0 then
        obj_explode_and_spawn_coins(46, 1)
        create_sound_spawner(SOUND_GENERAL_BREAK_BOX)     
    end
end

--metal cap only box


function Func_Custom_0x802c2ab4(o)
    obj_set_hitbox(o, sBreakableBoxHitbox)
    obj_set_model_extended(o, E_MODEL_BUBBLY_TREE)
    local m = nearest_mario_state_to_object(o)

    if o.oTimer == 0 then
        breakable_box_init(o)
    end

    if m.flags & MARIO_METAL_CAP == 0 then
        if cur_obj_was_attacked_or_ground_pounded() ~= 0 then
            o.oHealth = 1
            network_send_object(o, true)
        end
    end

    if m.flags & MARIO_METAL_CAP ~= 0 then
        if cur_obj_was_attacked_or_ground_pounded() ~= 0 then
            o.oHealth = 0
            network_send_object(o, true)
        end
    end

    if o.oHealth == 0 then
        obj_explode_and_spawn_coins(46, 1)
        create_sound_spawner(SOUND_GENERAL_BREAK_BOX)         
    end
end

--coin spawner

function coin_spawner_init(o)
    network_init_object(o, false, {'oAction'})
end

function coin_spawner_update(o)
    local m = nearest_mario_state_to_object(o)
    if not m then return end

    if not (o.oAction > 0) then
        if obj_check_hitbox_overlap(m.marioObj, o) then
            if o.oBehParams2ndByte ~= 1 then
                spawn_sync_object(id_bhvThreeCoinsSpawn, E_MODEL_YELLOW_COIN, o.oPosX, o.oPosY, o.oPosZ, nil)
            else
                spawn_sync_object(id_bhvSingleCoinGetsSpawned, E_MODEL_YELLOW_COIN, o.oPosX, o.oPosY, o.oPosZ, nil)
            end
            o.oAction = 1
            cur_obj_become_intangible()
            network_send_object(o, true)
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

--UM64 Silver Star

function Func_Custom_0x802b2dac(o)
    local m = nearest_mario_state_to_object(o)
    o.oFaceAngleYaw = o.oFaceAngleYaw + 0x800


    if o.oTimer > 90 or (o.oMoveFlags & 1) ~= 0 then
        cur_obj_become_tangible()

        if obj_check_if_collided_with_object(o, m.marioObj) ~= 0 then
            obj_mark_for_deletion(o)
            spawn_non_sync_object(id_bhvGoldenCoinSparkles, E_MODEL_NONE, o.oPosX, o.oPosY, o.oPosZ, nil)
        end
    end
end

--UM64 Noteblock

function Func_Custom_0x802c2b4c(o)
    local m = nearest_mario_state_to_object(o)
    local strength = o.oBehParams2ndByte
    local speed = 64
    if not m then return end

    if cur_obj_is_mario_on_platform() == 1 and not is_bubbled(m) then
        set_mario_action(m, ACT_DOUBLE_JUMP, 1)
        m.vel.y = speed


        if (m.controller.buttonDown & A_BUTTON) ~= 0 then
            spawn_sync_object(
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

--Poundable Switch: There's three in total but i should make it so it can be any mount. A star spawns after all switches have been ground pounded.

local star_spawned = false

hook_event(HOOK_ON_LEVEL_INIT, function ()
    star_spawned = false
end)


function bhv_poundable_switch_init(o)
    obj_set_model_extended(o, E_MODEL_POUNDABLE_SWITCH_BLUE)
    network_init_object(o, false, { "oAction", })
end

function bhv_poundable_switch_loop(o)
    local m = nearest_mario_state_to_object(o)

    if o.oAction == 0 then
        if m and cur_obj_was_attacked_or_ground_pounded() ~= 0 then
            o.oAction = 1
            create_sound_spawner(SOUND_GENERAL2_PURPLE_SWITCH)
            network_send_object(o, true)
        end
    end

    if o.oAction == 1 then
        obj_set_model_extended(o, E_MODEL_POUNDABLE_SWITCH_YELLOW)
    end
end




function bhv_solid_stepblock_init(o)
    o.oAction = 0
    o.oTimer = 0
    obj_set_model_extended(o, E_MODEL_TRANSPARENT_STEPBLOCK)
    network_init_object(o, false, {"oAction", "oTimer"})
end

function bhv_solid_stepblock_loop(o)

  
    --djui_chat_message_create("oTimer:" .. o.oTimer)
    --djui_chat_message_create("oAction:" .. o.oAction)

    if star_spawned == true then
        o.oAction = 2
        o.oTimer = 0
        if o.oAction == 2 then
            obj_set_model_extended(o, E_MODEL_SOLID_STEPBLOCK)
        end
        network_send_object(o, true)
    else
        if o.oAction == 0 then
            obj_set_model_extended(o, E_MODEL_TRANSPARENT_STEPBLOCK)
            o.oTimer = 0
            if cur_obj_is_any_player_on_platform() ~= 0 and not is_bubbled(gMarioStates[0]) then
                create_sound_spawner(SOUND_GENERAL2_PURPLE_SWITCH)
                o.oAction = 1
                network_send_object(o, true)
            end
        elseif o.oAction == 1 then
            obj_set_model_extended(o, E_MODEL_SOLID_STEPBLOCK)
            o.oTimer = o.oTimer + 1
            network_send_object(o, true)
            if o.oTimer >= 1200 then
                o.oAction = 0
                create_sound_spawner(SOUND_GENERAL2_PURPLE_SWITCH)
                network_send_object(o, true)
            end
        end
    end




end

function set_model(o)
    obj_set_model_extended(o, E_MODEL_CRYSTAL_PLATFORM)
end

--Poundable Switch Star Spawn (borrowed from MOPs a bit here)

---@param o Object
function bhv_poundable_switch_starspawn_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.oHealth = 0
end

function bhv_poundable_switch_starspawn_loop(o)
    local switch_amount = obj_count_objects_with_behavior_id(id_bhvChainChompGate)
    local switch = obj_get_first_with_behavior_id(id_bhvChainChompGate)

    if o.oBehParams2ndByte == 10 then
    switch_amount = obj_count_objects_with_behavior_id(Bhv_Custom_0x130017b8)
    switch = obj_get_first_with_behavior_id(Bhv_Custom_0x130017b8)
    --djui_chat_message_create("work")
    end

    if switch_amount > o.oHealth or o.oHealth == 0 then
        o.oHealth = switch_amount
        return
    end

    o.oHiddenStarTriggerCounter = 0
    



    while switch do
        if switch.oAction == 1 then
           o.oHiddenStarTriggerCounter = o.oHiddenStarTriggerCounter + 1
           network_send_object(o, true)
        end
        switch = obj_get_next_with_same_behavior_id(switch)
    end

    if o.oHiddenStarTriggerCounter == o.oHealth and not star_spawned then
        spawn_red_coin_cutscene_star(o.oPosX, o.oPosY, o.oPosZ)
        star_spawned = true
        obj_mark_for_deletion(o)
    end
    --djui_chat_message_create("spawner:" .. o.oHiddenStarTriggerCounter)
end

hook_event(HOOK_ON_OBJECT_UNLOAD,
---@param o Object
function (o)
    -- Force spawn star for newly entering players
    if obj_has_behavior_id(o, id_bhvBulletBill) == 1 and o.oHiddenStarTriggerCounter ~= o.oHealth and not star_spawned then
        star_spawned = true
        --djui_chat_message_create("test")
    end
end)


hook_event(HOOK_UPDATE, function()
    for_each_object_with_behavior(bhvSMSRYoshiMessage, yoshi_star)
    for_each_object_with_behavior(bhvKoopaRaceEndpoint, yoshi_star)
    for_each_object_with_behavior(id_bhvSquarishPathMoving, set_model)
    for_each_object_with_behavior(id_bhvSunkenShipPart, function (o)
       o.header.gfx.skipInViewCheck = true
    end)
end)