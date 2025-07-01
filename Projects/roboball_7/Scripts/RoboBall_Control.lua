local Control = {
	Properties = {
		ImpulseSize = 1.0,
		InputEventName = ""
	}
}

function Control:OnActivate()
	self.TickNotificationBus = TickBus.Connect(self);
	local inputBusId = InputEventNotificationId(self.Properties.InputEventName)
	self.InputNotificationBus = InputEventNotificationBus.Connect(self, inputBusId)
end

function Control:OnTick(deltaTime, currentTime)
	local Rot = TransformBus.Event.GetWorldRotation(self.entityId); 
 	local ImpulseSize = self.Properties.ImpulseSize
 	local x_new = ImpulseSize * math.cos(Rot.z)
 	local y_new = ImpulseSize * math.sin(Rot.z)
	RigidBodyRequestBus.Event.ApplyLinearImpulse (self.entityId, Vector3(x_new,y_new, 0.0));
end

function Control:OnPressed(value)
	local ImpulseDirection = value * self.Properties.ImpulseSize
-- 	RigidBodyRequestBus.Event.ApplyLinearImpulse(self.entityId, Vector3(0, ImpulseDirection, 0));
	RigidBodyRequestBus.Event.ApplyAngularImpulse(self.entityId, Vector3(0.0, 0.0, ImpulseDirection));
 end


function Control:OnDeactivate()
	self.TickNotificationBus:Disconnect();
	self.InputNotificationBus:Disconnect();

end

return Control