# Roboball 7

If you finished [roboball 6](roboball_tutorial_6.md), you should have achieved this at least which is a controllable ball that is a bit better.

However, let's improve it a bit more here as using rotationalimpulse is not the best to control the ball. Also, it is not possible for the camera rig to follow the ball nicely so we will improve that here as well.

## rotation instead of impulse

We could try to add a constant rotation to the entity, but the physics component would be need to be disabled (but there is a script for it if interested)

Open up the roboball_control.lua in the lua editor again.

Add another propertie called RotationDirection and AngularVelocity that's a float

```lua
local Control = {
	Properties = {
		ImpulseSize = 1.0,
		InputEventName = "",
		RotationDirection = 0.0,
		AngularVelocity = 0.2
	}
}
```

and in `OnPressed()` assign the returned value of those keybindings to that property, and comment out the linear impulse and the local veriable assigning.

```lua
function Control:OnPressed(value)
	--local ImpulseDirection = value * self.Properties.ImpulseSize
	-- RigidBodyRequestBus.Event.ApplyAngularImpulse(self.entityId, Vector3(0.0, 0.0, ImpulseDirection));'
	self.Properties.RotationDirection = value
end
```

Then in OnTick add a setangularvelocity in the rigidbodyrequestbus:

```lua
	local RotVel = self.Properties.RotationDirection * self.Properties.AngularVelocity;
	RigidBodyRequestBus.Event.SetAngularVelocity (self.entityId, Vector3(0.0, 0.0, RotVel));
```

Play the game and press the keys.

You see that the ball keeps rotating. So let's null the after applying it again so it resets

```lua

self.Properties.RotationDirection = 0.0
```

play the game again. Now you notice for sure that it only rotates once when pressed. We need to change the function for the keybindings event from OnPressed to OnHeld()

```lua
function Control:OnHeld(value)
	self.Properties.RotationDirection = value
end
```

The total code should look like this:

```lua
local Control = {
	Properties = {
		ImpulseSize = 1.0,
		InputEventName = "",
		RotationDirection = 0.0,
		AngularVelocity = 0.2
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
	
	local RotVel = self.Properties.RotationDirection * self.Properties.AngularVelocity;
	RigidBodyRequestBus.Event.SetAngularVelocity (self.entityId, Vector3(0.0, 0.0, RotVel));
	self.Properties.RotationDirection = 0.0

end

function Control:OnHeld(value)
	--local ImpulseDirection = value * self.Properties.ImpulseSize
	self.Properties.RotationDirection = value
	-- RigidBodyRequestBus.Event.ApplyAngularImpulse(self.entityId, Vector3(0.0, 0.0, ImpulseDirection));
 end


function Control:OnDeactivate()
	self.TickNotificationBus:Disconnect();
	self.InputNotificationBus:Disconnect();
end

return Control
```

And the ball control should look like this

![bounce_with_rotation](images/bounce_with_rotation.gif)

## Improve the Camera rig. 

So you probably noticed that when you rotate the ball, the camera doesn't rotate around it. That is something that we gamers are not really used to so let's change that.

Let's first reposition the camera to a new transform.

* Translate: -5, 0, 2
* Rotate: 0, 0, -90

![reposition_camera](images/reposition_camera.png).

Get a quick view through the editor camera if the position is okay


Then remove the transform behavior element called 'FollowTargetFromAngle'

Then add a FollowTarget from Distance instead with the following:

* Follow distance: 5 m
* Minimum follow distance: 1
* maximum follow distance: 10

Play the game and see the difference. It still followes it, but when you rotate it seems to not face the entity. 

Let's add the `FaceTarget` element at transform behaviors.

Play again and you see that things have very much improved.

Now place a look at behavior to be a little above the ball, so namely 1.0 meters in the z

This is the full component part:

![update_camera_rig](images/update_camera_rig.png)

So if you now press play, you should see the camera rotating around the ball. You still get a bit sick but at least you know where the ball is going :)

It might be nice to decouple to z axis from the ball, but that would require some more scripting so let's leave that for another time. 

![better_camera_rig](images/better_camera_rig.gif)

Jeej! That's end of section 7. 