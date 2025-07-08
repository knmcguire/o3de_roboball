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

```
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

