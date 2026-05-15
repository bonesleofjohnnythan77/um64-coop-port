custom_hud = true -- Togglable setting in game to turn on/off the HUD with "/custom-hud". On by default
currHUD = 1 -- Required check for the custom power meter table to work. Also used to check which HUD to pick from in a multi-HUD pack


-- These are the built in functions you can change in here to affect how the HUD appears in game

appendZero = false -- Internal trigger to enable/disable zeroes in front of single digit numbers
newTimer = false --  Internal trigger to enable/disable the new timer layout
stationaryPowerMeter = false --Forces the power meter to stay in place on the screen (always visible, doesn't move when taking damage or healing)


-- This first section is to get the HUD icons that'll be used. It checks for any Character Select icons and overrides the vanilla icons if needed, or returns the vanilla icons.

-- Checks for Character Select
local charSelectOn = false
hook_event(HOOK_ON_MODS_LOADED, function(m)
    charSelectOn = _G.charSelectExists
end)

-- Vanilla life icon set up
local life_icons = {
    [CT_MARIO] = gTextures.mario_head,
    [CT_LUIGI] = gTextures.luigi_head,
    [CT_TOAD] = gTextures.toad_head,
    [CT_WALUIGI] = gTextures.waluigi_head,
    [CT_WARIO] = gTextures.wario_head,
}


-- Template table to use custom power meter textures without overriding the main power meter textures
-- Since a lot of CS packs will include their own custom power meters, and a lot of hacks will just completely override the vanilla textures, this isn't frequently used
-- However, it does let you add multiple power meters to the table below for packs of custom HUDs, or for the sake of not overriding the vanilla texture altogether

--[[local powerMeters = {
    ["left"] = {
        [1] = get_texture_info("*left power meter side texture*")
    },
    ["right"] = {
        [1] = get_texture_info("*right power meter side texture*")
    },
    [1] = {
        [1] = get_texture_info("*slice 1*")
    },
    [2] = {
        [1] = get_texture_info(*slice 2*")
    },
    [3] = {
        [1] = get_texture_info("*slice 3*")
    },
    [4] = {
        [1] = get_texture_info("*slice 4*")
    },
    [5] = {
        [1] = get_texture_info("*slice 5*")
    },
    [6] = {
        [1] = get_texture_info("*slice 6*")
    },
    [7] = {
        [1] = get_texture_info("*slice 7*")
    },
    [8] = {
        [1] = get_texture_info("*slice 8*")
    }
}]]


-- This section handles the lives, coins, and star sections separately, to make it easier to deal with the HUD layouts (only needing to plug in numbers once rather than for each element)
-- Each of these functions gets rendered later on when the actual HUD layout is called. If you want to change the spacing or content of the functions themselves, do it here. For simple placement, do it in the HUD rendering function
-- Note, in the event the parameter only asks for 4 inputs instead of 5, the horizontal scale (scaleW) becomes the single value for the scale (notable for rendering text or the CS icons)

function render_lives_segment(x, y, scaleW, scaleH) -- Lives
    if appendZero then
        lives = tostring(string.format("%02d", hud_get_value(HUD_DISPLAY_LIVES))):gsub("-", "M")
    else
        lives = tostring(string.format(hud_get_value(HUD_DISPLAY_LIVES))):gsub("-", "M")
    end

    --render_custom_char_icon(x, y, scaleW, scaleH)  -- Gets the star icon from the earlier functions, in the event of a Character Select override
    if charSelectOn then
        _G.charSelect.character_render_life_icon(0, x, y, 1)
    else
        djui_hud_render_texture(life_icons[gMarioStates[0].character.type], x, y, 1, 1)
    end
    djui_hud_print_text("@", x + 16, y, scaleW)
    djui_hud_print_text(lives, x + 32, y, scaleW)
end

function render_coins_segment(x, y, scaleW, scaleH) -- Coins
    if appendZero then
        coins = tostring(string.format("%02d", hud_get_value(HUD_DISPLAY_COINS))):gsub("-", "M")
    else
        coins = tostring(string.format(hud_get_value(HUD_DISPLAY_COINS))):gsub("-", "M")
    end

    if gNetworkPlayers[0].currLevelNum ~= LEVEL_CASTLE_GROUNDS and gNetworkPlayers[0].currLevelNum ~= LEVEL_CASTLE_COURTYARD and gNetworkPlayers[0].currLevelNum ~= LEVEL_CASTLE then     -- Hides coin display in certain areas
        djui_hud_render_texture(gTextures.coin, x, y, scaleW, scaleH) -- Coin texture
        djui_hud_print_text("@", x + 16, y, scaleW) -- The X
        djui_hud_print_text(coins, x + 30, y, scaleW)
    end
end

function render_stars_segment(x, y, scaleW, scaleH) -- Stars
    if appendZero then
        stars = tostring(string.format("%02d", hud_get_value(HUD_DISPLAY_STARS))):gsub("-", "M")
    else
        stars = tostring(string.format(hud_get_value(HUD_DISPLAY_STARS))):gsub("-", "M")
    end

    --render_custom_star_icon(x, y, scaleW, scaleH) -- Gets the star icon from the earlier functions, in the event of a Character Select override
    if charSelectOn then
        _G.charSelect.character_render_star_icon(0, x, y, 1)
    else
        djui_hud_render_texture(gTextures.star, x, y, 1, 1)
    end
    if gMarioStates[0].numStars < 100 then  -- Renders the X if you have less than 100 stars
        djui_hud_print_text("@", x + 16, y, scaleW) -- The X
        djui_hud_print_text(stars, x + 30, y, scaleW)  -- The counter itself
    else
        djui_hud_print_text(stars, x + 16, y, scaleW)
    end
end


-- Power meter handling
local pmTimer = 0
local ascendValue = 0
local doOnce = true
function render_power_meter(x, y, scaleW, scaleH)
    local health = math.ceil(gMarioStates[0].health / 256) - 1

    local renderPowerMeter = health < 8 or gMarioStates[0].action & ACT_GROUP_MASK == ACT_GROUP_SUBMERGED or stationaryPowerMeter
    if not stationaryPowerMeter then
        if pmTimer > 0 then
            pmTimer = pmTimer - 1
        elseif renderPowerMeter then
            if ascendValue < -1 then
                ascendValue = 35
            end
            if ascendValue >= 31 then ascendValue = ascendValue - 5
            elseif ascendValue >= 21 then ascendValue = ascendValue - 3
            elseif ascendValue >= 10 then ascendValue = ascendValue - 2
            elseif ascendValue >= 0 then ascendValue = ascendValue - 1 end
        else
            if ascendValue == -1 and not doOnce then
                pmTimer = 90
                doOnce = true
            end
            if ascendValue > 0 - 100 and pmTimer == 0 then
                ascendValue = ascendValue - 20
                doOnce = false
            end
        end
    end

    djui_hud_set_color(255, 255, 255, 255)
    -- DEFAULT POWER-METER RENDER (use these if you're not adding multiple power meters)
    --hud_render_power_meter(gMarioStates[0].health, x, y + ascendValue, scaleW, scaleH)
    hud_render_power_meter_interpolated(gMarioStates[0].health, x, y + ascendValue, scaleW, scaleH, x, y + ascendValue, scaleW, scaleH) -- Interpolated version of the above function

    -- CUSTOM POWER-METER SUPPORT
    --[[djui_hud_render_texture(powerMeters["left"][currHUD], x, y + ascendValue, scaleW, scaleH)
    djui_hud_render_texture(powerMeters["right"][currHUD], x + 32, y + ascendValue, scaleW, scaleH)
    if health > 0 then
        djui_hud_render_texture(powerMeters[health][currHUD], (x + 16), (y + 16) + ascendValue, scaleW, scaleH)
    end]]

end

-- Cap Timer handling
function render_cap_timer(timer, x, y)
    local m = gMarioStates[0]
    local metal = get_texture_info("metal")
    local vanish = get_texture_info("vanish")
    local wing = get_texture_info("wing")
	local wmcap = get_texture_info("wmcap")
	local vmcap = get_texture_info("vmcap")
	local wvcap = get_texture_info("wvcap")
    local threecap = get_texture_info("threecap")
    local hasWing = m.flags & MARIO_WING_CAP ~= 0
    local hasMetal = m.flags & MARIO_METAL_CAP ~= 0
    local hasVanish = m.flags & MARIO_VANISH_CAP ~= 0
    local curCap = hasWing and hasMetal and hasVanish and threecap or hasWing and
    hasMetal and wmcap or hasWing and hasVanish and wvcap or hasVanish and
    hasMetal and vmcap or hasWing and wing or hasMetal and metal or hasVanish and vanish
    if not (hasWing or hasMetal or hasVanish) then return end
    djui_hud_print_text("@", x + 16, y, 1)
    djui_hud_print_text(tostring(timer), x + 32, y, 1)
    djui_hud_render_texture(curCap, x, y, 1, 1)
end


-- Timer handling
minutes = 0
seconds = 0
milliseconds = 0
function render_timer(timer, x, y)
    djui_hud_set_color(255, 255, 255, 255)

    
    if hud_get_value(HUD_DISPLAY_FLAGS) & HUD_DISPLAY_FLAGS_TIMER ~= 0 then
        if newTimer then  -- New Timer, separate because it accounts for spacing issues when appending zeroes
            minutes = math.floor(timer/30/60%60)
            seconds = math.floor(timer/30)%60
            milliseconds = math.floor(timer/30%1 * 100)

            djui_hud_print_text("TIME", x - 47, y, 1)
            djui_hud_print_text(string.format("%02d", minutes), x + 12, y, 1)
            djui_hud_print_text("'", x + 36, y - 7, 1)
            djui_hud_print_text(string.format("%02d", seconds), x + 47, y, 1)
            djui_hud_print_text('"', x + 73, y - 7, 1)
            djui_hud_print_text(string.format("%02d", milliseconds), x + 87, y, 1)

        elseif not newTimer then  --Old Timer, recreation of base-game's for use with custom HUDs
            minutes = math.floor(timer/30/60%60)
            seconds = math.floor(timer/30)%60
            milliseconds = math.floor(timer/30%1 * 10)

            djui_hud_print_text("TIME", x - 47, y, 1)
            djui_hud_print_text(string.format("%d", minutes), x + 12, y, 1)
            djui_hud_print_text("'", x + 22, y - 7, 1)
            djui_hud_print_text(string.format("%02d", seconds), x + 32, y, 1)
            djui_hud_print_text('"', x + 57, y - 7, 1)
            djui_hud_print_text(string.format("%d", milliseconds), x + 66, y, 1)
        end
    end
end


-- Camera handling
local is_camera_cdown = false
function render_camera(x, y, scaleW, scaleH)
    local m = gMarioStates[0]
    local c = m.area and m.area.camera or nil
    if not c then return end
    local camText = nil
    if c.cutscene ~= 0 or (m.controller.buttonDown & R_TRIG ~= 0 and cam_select_alt_mode(0) == CAM_SELECTION_FIXED) or camera_is_frozen() then
        camText = gTextures.no_camera
    elseif set_cam_angle(0) == CAM_ANGLE_MARIO then
        camText = gTextures.mario_head
    else
        camText = gTextures.lakitu
    end
    if camText == gTextures.mario_head then --Determines whether or not to render out the custom character icon or the standard icon
        if charSelectOn then
            _G.charSelect.character_render_life_icon(0, x, y, 1)
        else
            djui_hud_render_texture(life_icons[gMarioStates[0].character.type], x, y, 1, 1)
        end
    else
        djui_hud_render_texture(camText, x, y, scaleW, scaleH)
    end
    djui_hud_render_texture(gTextures.camera, x - 16, y, scaleW, scaleH)
    if c.mode == CAMERA_MODE_C_UP then
        djui_hud_render_texture(gTextures.arrow_up, x - 12, y - 8, scaleW, scaleH)
    end
    if c.cutscene == 0 and (c.mode ~= CAMERA_MODE_C_UP and c.mode ~= CAMERA_MODE_BEHIND_MARIO) then
        if m.controller.buttonPressed & D_CBUTTONS ~= 0 then
            is_camera_cdown = true
        elseif m.controller.buttonPressed & U_CBUTTONS ~= 0 then
            is_camera_cdown = false
        end
    end
    if is_camera_cdown then
        djui_hud_render_texture(gTextures.arrow_down, x - 12, y + 16, scaleW, scaleH)
    end
end



-- This section actually renders out the HUD layouts
-- If you want to change the placement of the power meter, coin/star/life counters, camera icon, and timer, do it here
-- If you want to hide something indefinitely, either remove it or comment it out with "--" at the start of the line

local function on_hud_render() -- Handles the HUD layouts 
    if not custom_hud then return end

    hud_hide()  -- Hides base HUD
    if obj_get_first_with_behavior_id(id_bhvActSelector) ~= nil then return end  -- Hides HUD during star select
    if gNetworkPlayers[0].currActNum == 99 then return end  -- Hides HUD during Act 99, aka the credits
    djui_hud_set_resolution(RESOLUTION_N64)  -- Sets resolution to N64
    djui_hud_set_color(255, 255, 255, 255) -- Sets colors to default, fixes weird HUD render quirks
    screenWidth = djui_hud_get_screen_width()  -- Width of the screen
    screenHeight = djui_hud_get_screen_height()  -- Height of the screen
    halfScreenWidth = djui_hud_get_screen_width() / 2  -- Half the width of the screen
    halfScreenHeight = djui_hud_get_screen_height() / 2  -- Half the height of the screen
    djui_hud_set_font(FONT_HUD)


    -- This is what renders the HUDS. First is horizontal placement, second is vertical placement, third is horizontal scale, fourth is vertical scale
    if custom_hud then -- HUD layout
        render_lives_segment(22, 210, 1, 1) -- Lives Segment positioning
        render_coins_segment(screenWidth - 76, 210, 1, 1) -- Coins Segment positioning
        render_stars_segment(22, 15, 1, 1) -- Stars Segment positioning
        render_power_meter(halfScreenWidth - 51, 9, 65, 65) -- scale 65 for default power meter, though you might need to change it to a scale of 1 for custom textures
        render_cap_timer(math.ceil(gMarioStates[0].capTimer/30), 22, 35) -- Cap Timer positioning
        if newTimer then
            render_timer(hud_get_value(HUD_DISPLAY_TIMER), halfScreenWidth - 47, screenHeight * 0.85) -- New Timer positioning
        else
            render_timer(hud_get_value(HUD_DISPLAY_TIMER), halfScreenWidth + 54, 39) -- Vanilla Timer positioning
        end
        --render_camera(screenWidth - 38, screenHeight - 35, 1, 1) -- Camera mode icon positioning
    end
end

hook_event(HOOK_ON_HUD_RENDER_BEHIND, on_hud_render)



-- Chat commands
hook_chat_command("custom-hud", "to toggle between custom and vanilla HUDs, /custom-hud [hide/show] to hide or show the HUD altogether",
function (msg)
    
    if msg == "hide" then --Hides hud
        play_sound(SOUND_MENU_CLICK_FILE_SELECT, gMarioStates[0].pos)
        hud_hide()
        custom_hud = false
        return true

    elseif msg == "unhide" or msg == "show" then --Reveals hud in it's current state
        play_sound(SOUND_MENU_CLICK_FILE_SELECT, gMarioStates[0].pos)
        if currHUD ~= 0 then
            custom_hud = true 
        else
            hud_show()
        end
        return true

    elseif msg == "base" or msg == "vanilla" or msg == "off" then --Toggles hud off and shows it, even if hidden
        play_sound(SOUND_MENU_CLICK_FILE_SELECT, gMarioStates[0].pos)
        custom_hud = false 
        hud_show()
        return true

    else --Toggles hud on if off or hidden, off if on
        custom_hud = not custom_hud
        play_sound(SOUND_MENU_CLICK_FILE_SELECT, gMarioStates[0].pos)
        hud_show()
        return true
    end
    return true
end)