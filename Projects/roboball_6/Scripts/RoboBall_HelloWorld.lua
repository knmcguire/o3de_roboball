local HelloWorld = {
	Properties = {
	}
}
function HelloWorld:OnActivate()
	Debug.Log("Hello, World!")
	self.TickNotificationBus = TickBus.Connect(self);
end

function HelloWorld:OnTick(deltaTime, currentTime)
 	Debug.Log("Hello again!")
end

function HelloWorld:OnDeactivate()
	Debug.Log("Goodbye, World!")
	self.TickNotificationBus:Disconnect();
end

return HelloWorld