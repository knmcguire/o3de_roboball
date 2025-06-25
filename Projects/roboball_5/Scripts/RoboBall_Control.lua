local Control = {
	Properties = {
		ImpulseSize = 1.0,
	}
}

function Control:OnActivate()
	self.TickNotificationBus = TickBus.Connect(self);
end

function Control:OnTick(deltaTime, currentTime)
	RigidBodyRequestBus.Event.ApplyLinearImpulse(self.entityId, Vector3(self.Properties.ImpulseSize, 0.0, 0.0));
end

function Control:OnDeactivate()
	self.TickNotificationBus:Disconnect();
end

return Control