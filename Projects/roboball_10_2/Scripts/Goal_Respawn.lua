local GoalRespawn = {
	Properties = {
		AreaSize = 18.0,
	}
}

function GoalRespawn:OnActivate()
	self.RigidBodyNotificationBusHandler = RigidBodyNotificationBus.Connect(self, self.entityId)
end

function GoalRespawn:OnPhysicsEnabled(entityId)
	local event = SimulatedBody.GetOnCollisionBeginEvent(self.entityId);
	self.CollisionEvent = event:Connect(
		function(_, collision)
			self:OnCollisionBegin(collision)
		end
	);
end

function GoalRespawn:OnCollisionBegin(collision)
	Debug.Log('Goal hit! Respawning...')
	
	local halfSize = self.Properties.AreaSize / 2;
	local randomX = (math.random() - 0.5) * self.Properties.AreaSize; 
	local randomY = (math.random() - 0.5) * self.Properties.AreaSize; 
	local currentPos = TransformBus.Event.GetWorldTranslation(self.entityId);
	local newPos = Vector3(randomX, randomY, currentPos.z);
	TransformBus.Event.SetWorldTranslation(self.entityId, newPos);
	
	Debug.Log('Goal moved to: ' .. tostring(newPos.x) .. ', ' .. tostring(newPos.y))
end

function GoalRespawn:OnDeactivate()
	self.RigidBodyNotificationBusHandler:Disconnect()
	self.CollisionEvent:Disconnect()
end

return GoalRespawn