physics_center_x  = 0
physics_center_y  = 0
physics_size_x    = 8
physics_size_y    = 8
physics_can_sleep = true
physics_rotation  = true

addanim('spinning_coin_gold.png',16)
playanim('spinning_coin_gold.png',false)

function step()

end

function contact(with)
  -- print('coin contact with ' .. with)
  if with == 'player' then
    killed=true
  end  
end

function onAnimEnd()
  playanim('spinning_coin_gold.png',false)
end
