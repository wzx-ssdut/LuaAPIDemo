
-- add function
add = function(a, b)
	return a + b
end

local data = {
	[1] = {
		name = "Kitty",
		level = 10,
	},
	[2] = {
		name = "Jack",
		level = 22,
	},
	[3] = {
		name = "Mouse",
		level = 31,
	},
	[4] = {
		name = "Jerry",
		level = 9,
	},
}
gettable = function(index)
	return data[index]
end


getmultivalue = function()
	return 3, "xxxx", {1,2,3}
end