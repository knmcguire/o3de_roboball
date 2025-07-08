local Autonomous = {
	Properties = {
		ImpulseSize = 1.0,
		InputEventName = "",
		RotationDirection = 0.0,
		AngularVelocity = 0.2,
		GroundId = EntityId(),
	}
}

function WrapAngle(angle)
    return (angle + math.pi) % (2 * math.pi) - math.pi
end

function Autonomous:OnActivate()
	self.TickNotificationBus = TickBus.Connect(self);
	local inputBusId = InputEventNotificationId(self.Properties.InputEventName)
	self.InputNotificationBus = InputEventNotificationBus.Connect(self, inputBusId)
	self.RigidBodyNotificationBusHandler = RigidBodyNotificationBus.Connect(self, self.entityId)
	self.first_run = false
	self.ControlHeading = 0.0
end

function Autonomous:OnPhysicsEnabled(entityId)
	local event = SimulatedBody.GetOnCollisionBeginEvent(self.entityId);
	self.CollisionEvent = event:Connect(
		function(_, collision)
			self:OnCollisionBegin(collision)
		end
	);
end

function Autonomous:OnCollisionBegin(collision)
	-- Debug.Log('Ouch!')
	if self.first_run==false then
		--self.Properties.GroundId = collision:GetBody2EntityId()
		self.first_run = true
	end
	if collision:GetBody2EntityId() == self.Properties.GroundId then
		local velocity = RigidBodyRequestBus.Event.GetLinearVelocity (self.entityId);
		local mass = RigidBodyRequestBus.Event.GetMass(self.entityId);
		local BounceImpulse = mass * (6 - velocity.z)
		
		local ForwardVelocity = velocity.x * math.cos(self.ControlHeading) + velocity.y * math.sin(self.ControlHeading);
		Debug.Log(tostring(ForwardVelocity))
		local ForwardImpulse = mass*(6-ForwardVelocity)
		local ImpulseSize = ForwardImpulse--self.Properties.ImpulseSize
		local x_new = ImpulseSize * math.cos(self.ControlHeading)
		local y_new = ImpulseSize * math.sin(self.ControlHeading)
		RigidBodyRequestBus.Event.ApplyLinearImpulse (self.entityId, Vector3(x_new,y_new,BounceImpulse));

		Debug.Log(' Floor');
		Debug.Log(tostring(BounceImpulse));
		 
	end
end



function Autonomous:OnTick(deltaTime, currentTime)
	local Rot = TransformBus.Event.GetWorldRotation(self.entityId); 
	local ImpulseSize = self.Properties.ImpulseSize
	
	
	local x_new = ImpulseSize * math.cos(self.ControlHeading)
	local y_new = ImpulseSize * math.sin(self.ControlHeading)
	--RigidBodyRequestBus.Event.ApplyLinearImpulse (self.entityId, Vector3(x_new,y_new, 0.0));
	
	local RotVel = self.Properties.RotationDirection * self.Properties.AngularVelocity;
	--RigidBodyRequestBus.Event.SetAngularVelocity (self.entityId, Vector3(0.0, 0.0, RotVel));
	self.Properties.RotationDirection = 0.0

end

function Autonomous:OnPressed(value)
	self.Properties.RotationDirection = value
		Debug.Log(' button pressed');
		self.ControlHeading = WrapAngle(self.ControlHeading + value*self.Properties.AngularVelocity)
		Debug.Log(tostring(self.ControlHeading))
		

 end


function Autonomous:OnDeactivate()
	self.TickNotificationBus:Disconnect();
	self.InputNotificationBus:Disconnect();
	self.RigidBodyNotificationBusHandler:Disconnect()
end

return Autonomous