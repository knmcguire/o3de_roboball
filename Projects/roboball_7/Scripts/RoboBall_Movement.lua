local Movement = {
	Properties = {
		ImpulseSize = 1.0,
	}
}

function Movement:OnActivate()
	self.TickNotificationBus = TickBus.Connect(self);
end

function Movement:OnTick(deltaTime, currentTime)
	RigidBodyRequestBus.Event.ApplyLinearImpulse(self.entityId, Vector3(self.Properties.ImpulseSize, 0.0, 0.0));
end

function Movement:OnDeactivate()
	self.TickNotificationBus:Disconnect();
end

return Movement