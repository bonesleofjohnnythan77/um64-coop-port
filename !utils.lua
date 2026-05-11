--Useful romhack functions and important globals

E_MODEL_BRICK_BLOCK = smlua_model_util_get_id("brick_block_geo")
COL_BRICK_BLOCK = smlua_collision_util_get("brick_block_collision")

--get star count
function get_star_count() 
    return save_file_get_total_star_count(get_current_save_file_num() - 1, COURSE_MIN - 1, COURSE_MAX - 1)
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