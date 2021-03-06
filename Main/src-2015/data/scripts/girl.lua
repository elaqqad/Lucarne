physics_center_x  =  0
physics_center_y  =  0
physics_size_x    = 15
physics_size_y    = 48
physics_can_sleep = false
physics_rotation  = false

addanim('G_standstill-left.png',40)
addanim('G_walk-left.png',40)
addanim('G_jump-left.png',40)
addanim('G_standstill-right.png',40)
addanim('G_walk-right.png',40)
addanim('G_jump-right.png',40)
addanim('G_turn-left.png', 40)
addanim('G_turn-right.png', 40)

playanim('G_standstill-left.png', true)
stopanim()

-- define a state variable which can be: 
-- 'wait_left', 'wait_right'
-- 'walk_left', 'walk_right'
-- 'turn_left', 'turn_right'

state = 'wait_left'

function step()

  -- update state
  if state == 'wait_left' or state == 'wait_right' then
    if Key_j then
	  if state == 'wait_left'then 
	    -- already in the correct orientation, just walk!
	    state = 'walk_left'
	    playanim('G_walk-left.png',true)
	  else
	    -- uho, need to turn left
	    state = 'turn_left'
	    playanim('G_turn-left.png',false)
		--playanim('G_standstill-left.png', false)
	  end
    elseif Key_l then
	  if state == 'wait_right' then 
	    -- already in the correct orientation, just walk!
	    state = 'walk_right'
	    playanim('G_walk-right.png',true)
	  else
	    -- uho, need to turn right
	    state = 'turn_right'
	    playanim('G_turn-right.png',false)
		--playanim('G_standstill-right.png', false)
	  end
	end
  else
    if not Key_j and state == 'walk_left' then
	  state = 'wait_left'
	  stopanim()
	  playanim('G_standstill-left.png', false)
    elseif not Key_l and state == 'walk_right' then
	  state = 'wait_right'
	  stopanim()
	  playanim('G_standstill-right.png', false)
	end
  end

  if Key_i then
    if state == 'wait_left' then
	  set_jump(0, 7)
	  state = 'jump_left'
      playanim('G_jump-left.png',false)
	end
    if state == 'wait_right' then
	  set_jump(0, 7)
	  state = 'jump_right'
      playanim('G_jump-right.png',false)
	end
	if state == 'walk_left' then
	  set_jump(-1.5, 6)
	  state = 'jump_left'
	  playanim('G_jump-left.png', false)
	end
	if state == 'walk_right' then
	  set_jump(1.5, 6)
	  state = 'jump_right'
	  playanim('G_jump-right.png', false)
	end
  end

  -- walk if state is 'walk_*'
  if state == 'walk_left' then
    set_walk(-1.2)
  elseif state == 'walk_right' then
    set_walk(1.2)
  end

end

function contact(with)
  
end

function onAnimEnd()
  if state == 'turn_left' then
    state = 'walk_left'
	playanim('G_walk-left.png',true)
  end
  if state == 'jump_left' then
    state = 'wait_left'
	playanim('G_standstill-left.png', false)
  end
  if state == 'turn_right' then
    state = 'walk_right'
	playanim('G_walk-right.png',true)
  end
  if state == 'jump_right' then
    state = 'wait_right'
	playanim('G_standstill-right.png', false)
  end
end
