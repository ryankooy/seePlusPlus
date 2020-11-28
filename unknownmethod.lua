local object = {print=print}

function Thing(t, k)
	return function() print("you called the method") end
end

setmetatable(object, {__index=Thing})
object.print("Hi")
object.hello()
