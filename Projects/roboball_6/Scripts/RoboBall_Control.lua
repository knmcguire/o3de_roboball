local Control = {
	Properties = {
		ImpulseSize = 1.0,
		InputEventName = ""
	}
}

function Control:OnActivate()
	self.TickNotificationBus = TickBus.Connect(self);
end

function Control:OnTick(deltaTime, currentTime)
	local inputBusId = InputEventNotificationId(self.Properties.InputEventName)
	self.InputNotificationBus = InputEventNotificationBus.Connect(self, inputBusId)
	local Rot = TransformBus.Event.GetWorldRotation(self.entityId); 
 	local theta = Rot.z
 	local impulseSize = self.Properties.ImpulseSize
 	local x_new = impulseSize * math.cos(theta)
 	local y_new = impulseSize * math.sin(theta)
	RigidBodyRequestBus.Event.ApplyLinearImpulse(self.entityId, Vector3(x_new, y_new, 0.0));
end

function Control:OnPressed (value)
	local ImpulseDirection = value * self.Properties.ImpulseSize / 20
-- 	RigidBodyRequestBus.Event.ApplyLinearImpulse(self.entityId, Vector3(0, ImpulseDirection, 0));
	RigidBodyRequestBus.Event.ApplyAngularImpulse(self.entityId, Vector3(0.0, 0.0, ImpulseDirection));

 end


function Control:OnDeactivate()
	self.TickNotificationBus:Disconnect();
	self.InputNotificationBus:Disconnect();

end

return Control