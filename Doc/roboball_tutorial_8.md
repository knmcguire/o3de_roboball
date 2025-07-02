# Roboball 8

So if you finished section 7 you should be able to see this:

![better_camera_rig](images/better_camera_rig.gif)


Now let's work with collisions!

The ball is bouncing around and could be hitting things but it is not doing anything to it. So let's work with that.

In the Roboball_control.lua add a collision event to OnActivate()

```lua
     local event = SimulatedBody.GetOnCollisionBeginEvent(self.entityId);
```
If you run this, you will see an error that there is a nil variable on that event. This is due that the event is being accessed when the physics hasn't been enabled yet, so we've got to use onPhysicsEnabled().

Remove that last line and make this function:

```lua
function Control:OnPhysicsEnabled(entityId)
	local event = SimulatedBody.GetOnCollisionBeginEvent(self.entityId);
	self.CollisionEvent = event:Connect(
		function(_, collision)
			self:OnCollisionBegin(collision)
		end
	);
end
```

Running now will give an issuse that OnCollisionBegin doesn't exist, so let's add that function:

```lua
function Control:OnCollisionBegin(collision)
	Debug.Log('Ouch!')
end
```

And let's disconnect of the rigidbodynoticiation bus in OnDeactivate()

```lua
	self.RigidBodyNotificationBusHandler:Disconnect()
```

Run the game and you should see the folllowing in the console:
```
(Script) - Ouch!
(Script) - Ouch!
(Script) - Ouch!
(Script) - Ouch!
```
