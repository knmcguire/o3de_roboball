local HelloWorld = {
	Properties = {
	}
}
function HelloWorld:OnActivate()
	Debug.Log("Hello, World!")
end

function HelloWorld:OnDeactivate()
	Debug.Log("Goodbye, World!")
end

return HelloWorld