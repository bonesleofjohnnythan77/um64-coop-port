LEVEL_ACT_SELECT = level_register('level_actSelect_entry', COURSE_NONE, 'Act Select', 'actSelect', 28000, 0x28, 0x28, 0x28)

local isWarping = false

local targetWarpInfo = {
    targetCourse = COURSE_BOB,
    targetLevel = LEVEL_BOB,
    targetArea = 1,
}

local MAX_ACT_NUM = 6
local COIN_STAR_ID = 6
local SPACING = 200
local STAR_POS_Y = 120
local STAR_POS_Z = -300

local selectableActs = {}

local function star_select_handler_init(o)
    hud_hide()
    spawn_non_sync_object(id_bhvActSelector, E_MODEL_NONE, 0, 999999, 0, nil) --* for mods that check for the star select

    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE

    selectableActs = {}

    local saveFile = get_current_save_file_num() - 1
    local courseId = targetWarpInfo.targetCourse - 1
    local stars = save_file_get_star_flags(saveFile, courseId)

    if (stars & (1 << COIN_STAR_ID)) ~= 0 then
        spawn_non_sync_object(id_bhvStaticObject, E_MODEL_STAR, 257, o.oPosY + (STAR_POS_Y - 502), o.oPosZ + STAR_POS_Z, function(coinStar)
            obj_scale(coinStar, 0.8)
        end)
    end

    --* get the last collected star
    local highest = -1
    for i = 0, MAX_ACT_NUM - 1 do
        if (stars & (1 << i)) ~= 0 then
            highest = i
        end
    end

    --* check for gaps in collected stars
    local noGaps = true
    for i = 0, highest - 1 do
        if (stars & (1 << i)) == 0 then
            noGaps = false
            break
        end
    end

    --* get which stars are selectable
    local limit = noGaps and math.min(highest + 1, MAX_ACT_NUM - 1) or highest

    --* get the first missing star within selectable stars
    local firstMissing = nil
    for i = 0, limit do
        if (stars & (1 << i)) == 0 then
            firstMissing = i
            break
        end
    end

    for i = 0, limit do
        if i == 0 or (stars & (1 << i)) ~= 0 or i == firstMissing then
            table.insert(selectableActs, i)
        end
    end

    local baseX = o.oPosX - ((limit) * SPACING / 2)
    for i = 0, limit do
        local x = baseX + i * SPACING
        spawn_non_sync_object(id_bhvStarSelectorStar, E_MODEL_STAR, x, o.oPosY + STAR_POS_Y, o.oPosZ + STAR_POS_Z, function(star)
            star.parentObj = o
            star.oBehParams2ndByte = i
        end)
    end

    if #selectableActs > 0 then
        o.oBehParams2ndByte = selectableActs[1]
    end

    cur_obj_set_home_once()
end

local transitionTimer = 0
local transitionTimerMax = 15

local menuHoldKeyIndex = 0
local menuHoldKeyTimer = 0

local function scroll_selectable_acts(m, o)
    local stickX = m.controller.stickX
    local pressingLeft  = stickX < -60 or (m.controller.buttonDown & L_JPAD) ~= 0
    local pressingRight = stickX >  60 or (m.controller.buttonDown & R_JPAD) ~= 0

    local amount = 0
    if pressingRight then amount = 1 end
    if pressingLeft  then amount = -1 end

    --* get current position of the selected act in the selectableActs list
    local acts = selectableActs
    local pos = 1
    for i, v in ipairs(acts) do
        if v == o.oBehParams2ndByte then
            pos = i
            break
        end
    end

    --* dsee if user is holding the same scroll direction as before
    local holdingSame = (amount == menuHoldKeyIndex)

    --* if scrolling input detected and either this is a new press or hold timer reached threshold
    if amount ~= 0 and (not holdingSame or menuHoldKeyTimer >= 10) then
        --* set new position, clamped to valid range
        local newPos = clamp(pos + amount, 1, #acts)
        if newPos ~= pos then
            o.oBehParams2ndByte = acts[newPos]
            play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource)
        end

        menuHoldKeyTimer = holdingSame and 8 or 0
    end

    if amount == 0 then
        menuHoldKeyTimer = 0
    else
        menuHoldKeyTimer = menuHoldKeyTimer + 1
    end

    --* store current scroll direction for hold detection next frame
    menuHoldKeyIndex = amount
end

local function star_select_handler_loop(o)

    local coinStar = obj_get_first_with_behavior_id(id_bhvStaticObject) --* too lazy to make a new bhv

    if coinStar and transitionTimer <= 0 then coinStar.oFaceAngleYaw = coinStar.oFaceAngleYaw + 0x800 end

    if transitionTimer > 0 then
        transitionTimer = transitionTimer + 1

        if transitionTimer >= transitionTimerMax then
            transitionTimer = 0
            camera_unfreeze()
            hud_show()
            warp_to_warpnode(targetWarpInfo.targetLevel, targetWarpInfo.targetArea, o.oBehParams2ndByte + 1, targetWarpInfo.targetNode)
        end
    end

    local m = gMarioStates[0]

    m.freeze = 1

    if transitionTimer <= 0 then
        scroll_selectable_acts(m, o)
    end
end

local function star_selector_star_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL
    o.oFaceAngleYaw = 0
    o.oStarSelectorSize = 1.3
    local isStarCollected


    local saveFileNum = get_current_save_file_num() - 1
    local courseIndex = targetWarpInfo.targetCourse - 1
    local starFlag = 1 << o.oBehParams2ndByte
    isStarCollected = save_file_get_star_flags(saveFileNum, courseIndex) & starFlag ~= 0

    if isStarCollected then
        obj_set_model_extended(o, E_MODEL_STAR)
    else
        obj_set_model_extended(o, E_MODEL_TRANSPARENT_STAR)
    end
end

local function star_selector_star_loop(o)
    local parent = o.parentObj
    local selectedAct = parent.oBehParams2ndByte

    if o.oBehParams2ndByte == selectedAct then
        if transitionTimer <= 0 then
            o.oFaceAngleYaw = o.oFaceAngleYaw + 0x800
        end
        if o.oStarSelectorSize < 1.69 then
            o.oStarSelectorSize = o.oStarSelectorSize + 0.15
        end
    else
        o.oFaceAngleYaw = 0
        if o.oStarSelectorSize > 1.3 then
            o.oStarSelectorSize = o.oStarSelectorSize - 0.15
        end
    end

    cur_obj_scale(o.oStarSelectorSize)
end

id_bhvStarSelectorStar = hook_behavior(nil, OBJ_LIST_GENACTOR, true, star_selector_star_init, star_selector_star_loop, "bhvStarSelectorStar")
id_bhvStarSelectorHandler = hook_behavior(nil, OBJ_LIST_GENACTOR, true, star_select_handler_init, star_select_handler_loop, "bhvStarSelectorHandler")

--* i couldn't find a better way to do this without breaking the music
local function before_warp(destLevel, destArea, destWarpNode, arg)
    local isMainLevel = course_is_main_course(get_level_course_num(destLevel)) or false
    local m = gMarioStates[0]

    if not isMainLevel or destLevel == gNetworkPlayers[0].currLevelNum then return end

    targetWarpInfo.targetCourse = get_level_course_num(destLevel)
    targetWarpInfo.targetLevel = destLevel
    targetWarpInfo.targetArea = destArea
    targetWarpInfo.targetNode = destWarpNode
    isWarping = true
    return {
        destLevel = gNetworkPlayers[0].currLevelNum,
        destArea = 1,
        destWarpNode = 0x0A,
    }
end

local l = gLakituState

local function mario_update(m)
    if m.playerIndex ~= 0 then return end

    if gNetworkPlayers[0].currLevelNum ~= LEVEL_ACT_SELECT then return end

    set_mario_action(m, ACT_DISAPPEARED, 0)

    local o = obj_get_first_with_behavior_id(id_bhvStarSelectorHandler)

    obj_set_model_extended(m.marioObj, E_MODEL_NONE)
    camera_freeze()

    local baseX = o.oPosX - ((MAX_ACT_NUM - 1) * SPACING / 2)
    local middleX = baseX + ((MAX_ACT_NUM - 1) * SPACING / 2)

    l.pos.x, l.pos.y, l.pos.z = middleX, -28, 926
    l.focus.x, l.focus.y, l.focus.z = middleX, o.oPosY, o.oPosZ
end

local function for_each_object_with_behavior(behavior, func_f)
    local obj = obj_get_first_with_behavior_id(behavior)
    while obj ~= nil do
        func_f(obj)
        obj = obj_get_next_with_same_behavior_id(obj)
    end
end

local function count_string_chars(str)
    local count = 0
    for _ in string.gmatch(str, ".") do
        count = count + 1
    end
    return count
end

local function hud_render()
    local starSelectHandler = obj_get_first_with_behavior_id(id_bhvStarSelectorHandler)

    if not starSelectHandler then return end

    djui_hud_set_resolution(RESOLUTION_N64)
    djui_hud_set_font(FONT_TINY)

    local sWidth = djui_hud_get_screen_width()
    local sHeight = djui_hud_get_screen_height()

    djui_hud_set_color(0, 0, 0, 255)

    local pos
    local out

    --act numbers

    for_each_object_with_behavior(id_bhvStarSelectorStar, function (o)
        pos = { x = o.oPosX, y = o.oPosY, z = o.oPosZ }
        out = { x = 0, y = 0, z = 0 }

        djui_hud_world_pos_to_screen_pos(pos, out)

        djui_hud_print_text(""..o.oBehParams2ndByte + 1, out.x - 3, out.y - 50, 0.9)
    end)

    local actName = get_star_name(targetWarpInfo.targetCourse, starSelectHandler.oBehParams2ndByte + 1):upper()

    local actNamePosX = (sWidth - djui_hud_measure_text(actName)) * 0.5
    local actNamePosY = (sHeight - 50)
    djui_hud_set_font(FONT_TINY)
    djui_hud_print_text(actName, actNamePosX, actNamePosY, 1)

    local scoreText = "SCORE"
    djui_hud_set_font(FONT_TINY)
    local scoreWidth = djui_hud_measure_text(scoreText)

    local coinScoreText = tostring(save_file_get_course_coin_score(get_current_save_file_num() - 1, targetWarpInfo.targetCourse - 1))
    --local coinScoreWidth = djui_hud_measure_text(coinScoreText)

    local totalWidth = scoreWidth + 105
    local centerX = (sWidth - totalWidth) * 0.5
    local scoreY = actNamePosY + 25

    djui_hud_set_font(FONT_TINY)
    djui_hud_print_text(scoreText, centerX, scoreY, 1)

    djui_hud_set_color(255, 255, 255, 255)

    djui_hud_set_font(FONT_HUD)
    djui_hud_print_text("$", centerX + 40, scoreY, 1)
    djui_hud_print_text("@", centerX + 56, scoreY, 1)
    djui_hud_print_text(coinScoreText, centerX + 73, scoreY, 1)

    local courseText = "COURSE"
    local courseTextWidth = djui_hud_measure_text(courseText)
    local courseTextX = (sWidth * 0.5) - (courseTextWidth* 0.5)
    local courseTextY = out.y + 40
    djui_hud_set_font(FONT_HUD)
    djui_hud_print_text(courseText, courseTextX, courseTextY, 1)


    --local coursePlatePosX = (sWidth * 0.5) - (courseTextureTop.width * 0.5)
    local coursePlateTopPosY = (scoreY * 0.75)
    local coursePlateBottomPosY =  coursePlateTopPosY

    djui_hud_set_filter(FILTER_LINEAR)
    --djui_hud_render_texture(courseTextureTop, coursePlatePosX, coursePlateTopPosY, 1, 1)
    --djui_hud_render_texture(courseTextureBottom, coursePlatePosX, coursePlateBottomPosY, 1, 1)
    djui_hud_set_filter(FILTER_NEAREST)

    local courseNumX = (sWidth * 0.5)
    local courseNumY = courseTextY + 19
    local courseNumChars = count_string_chars(""..targetWarpInfo.targetCourse)

    djui_hud_print_text(""..targetWarpInfo.targetCourse, courseNumX - (7 * courseNumChars), courseNumY, 1)

    djui_hud_set_font(FONT_TINY)
    djui_hud_set_color(0, 0, 0, 255)

    local levelName = get_level_name(targetWarpInfo.targetCourse, targetWarpInfo.targetLevel, targetWarpInfo.targetArea):upper()
    local levelNameWidth = djui_hud_measure_text(levelName)
    local levelNameX = (sWidth * 0.5) - (levelNameWidth * 0.5)
    local levelNameY = 20

    djui_hud_print_text(levelName, levelNameX, levelNameY, 1)
end

local function update()
    if isWarping and not is_transition_playing() then
        warp_to_level(LEVEL_ACT_SELECT, 1, network_global_index_from_local(0))
        isWarping = false
    end
end

local function before_mario_update(m)
    if m.playerIndex ~= 0 then return end

    if gNetworkPlayers[0].currLevelNum == LEVEL_ACT_SELECT then
        if transitionTimer <= 0 then

            local transColor = {r = 255, g = 239, b = 238}

            if m.controller.buttonPressed & (A_BUTTON | START_BUTTON) ~= 0 then
                play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource)
                play_character_sound(m, CHAR_SOUND_LETS_A_GO)
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, transitionTimerMax, transColor.r, transColor.g, transColor.b)
                transitionTimer = 1
            end
        elseif transitionTimer > 0 then
            m.controller.buttonPressed = m.controller.buttonPressed & ~(A_BUTTON | START_BUTTON)
        end
    end
end

hook_event(HOOK_BEFORE_MARIO_UPDATE, before_mario_update)
hook_event(HOOK_ON_HUD_RENDER_BEHIND, hud_render)
hook_event(HOOK_USE_ACT_SELECT, function () return false end)
hook_event(HOOK_MARIO_UPDATE, mario_update)
hook_event(HOOK_UPDATE, update)
hook_event(HOOK_BEFORE_WARP, before_warp)