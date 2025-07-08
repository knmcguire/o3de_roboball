# Roboball 9

Make a new script based on roboball_control.lua called roboball_autonomous.lua.

Change all `Control` to `Autonomous` and add it to the script.

Now add the following line to the part where it collides with the ground:

```lua
RigidBodyRequestBus.Event.ApplyLinearImpulse (self.entityId, Vector3(0,0, 1.0));
```

Make sure to comment out the ApplyLinearImpulse and ApplyRotatationalVelocity in onticks

And change the material back to rubber.

> Play the game and see what happens

It goes back down again, the impulse is too small.

Let's add the following to the script:

```lua
		local velocity = RigidBodyRequestBus.Event.GetLinearVelocity (self.entityId);
		local mass = RigidBodyRequestBus.Event.GetMass(self.entityId);
		local BounceImpulse = mass * (6 - velocity.z)
		RigidBodyRequestBus.Event.ApplyLinearImpulse (self.entityId, Vector3(0,0,BounceImpulse));
```

Now there should be an even bounce

Now copy the forward impulse from tick to the collision function

```lua
		local Rot = TransformBus.Event.GetWorldRotation(self.entityId); 
		local ImpulseSize = self.Properties.ImpulseSize
		local x_new = ImpulseSize * math.cos(Rot.z)
		local y_new = ImpulseSize * math.sin(Rot.z)
		RigidBodyRequestBus.Event.ApplyLinearImpulse (self.entityId, Vector3(x_new,y_new,BounceImpulse));
```
Impulse size needs to be a lot larger though (try 1000)

If you play the game now, you see that the rig needs to be adjusted. 

Turn the 'take targets rotation' off. Then you can follow the ball again.

## Fix the rotation

Uncomment apply rotation on ticks, you see that that holds it agains rotating, which does not seem very naturaly. 

Instead, start a new global variable called Control heading in onactivate
```lua
	self.ControlHeading = 0.0
```

Add this on onHeld:

```lua
		self.ControlHeading = self.ControlHeading + value*self.Properties.AngularVelocity
		Debug.Log(tostring(self.ControlHeading))
```

and change  the following on collision:
```lua
		local ImpulseSize = self.Properties.ImpulseSize
		local x_new = ImpulseSize * math.cos(self.ControlHeading)
		local y_new = ImpulseSize * math.sin(self.ControlHeading)
		RigidBodyRequestBus.Event.ApplyLinearImpulse (self.entityId, Vector3(x_new,y_new,BounceImpulse));
```

Play the game and press the game play

The heading goes very fast so change onheld back to onpressed and add a wrap function to the script:

```lua
function WrapAngle(angle)
    return (angle + math.pi) % (2 * math.pi) - math.pi
end
```

and apply this to the control heading

```lua
		self.ControlHeading = WrapAngle(self.ControlHeading + value*self.Properties.AngularVelocity)
```

## Control the forward speed and clean up the code

It will go faster everytime so let's see if we can control that speed.

Add the following to oncollision to change the impulse size accordingly:

```lua
		local ForwardVelocity = velocity.x * math.cos(self.ControlHeading) + velocity.y * math.sin(self.ControlHeading);
		Debug.Log(tostring(ForwardVelocity))
		local ForwardImpulse = mass*(6-ForwardVelocity)
		local ImpulseSize = ForwardImpulse

```

Now let's clean up the code since there is a lot of legacy stuff in there. It should look like this:

```lua
local Autonomous = {
	Properties = {
		ForwardRef = 6.0,
		BounceRef = 6.0,
		RotationDiff = 0.2,
		InputEventName = "",
		AngularVelocity = 0.2,
		GroundId = EntityId(),
	}
}

function WrapAngle(angle)
    return (angle + math.pi) % (2 * math.pi) - math.pi
end

function Autonomous:OnActivate()
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
	if collision:GetBody2EntityId() == self.Properties.GroundId then
		local velocity = RigidBodyRequestBus.Event.GetLinearVelocity (self.entityId);
		local mass = RigidBodyRequestBus.Event.GetMass(self.entityId);
		local BounceImpulse = mass * (self.Properties.BounceRef - velocity.z)
		
		local ForwardVelocity = velocity.x * math.cos(self.ControlHeading) + velocity.y * math.sin(self.ControlHeading);
		local ForwardImpulse = mass*(self.Properties.ForwardRef-ForwardVelocity)
		local x_new = ForwardImpulse * math.cos(self.ControlHeading)
		local y_new = ForwardImpulse * math.sin(self.ControlHeading)
		RigidBodyRequestBus.Event.ApplyLinearImpulse (self.entityId, Vector3(x_new,y_new,BounceImpulse));
	end
end


function Autonomous:OnPressed(value)
	self.ControlHeading = WrapAngle(self.ControlHeading + value*self.Properties.AngularVelocity)
 end


function Autonomous:OnDeactivate()
	self.InputNotificationBus:Disconnect();
	self.RigidBodyNotificationBusHandler:Disconnect()
end

return Autonomous
```

It's almost autonomous. Let's get rid of the arrow control in the next part.