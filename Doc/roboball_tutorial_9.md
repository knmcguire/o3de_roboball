# Roboball 9

Make a new script based on roboball_control.lua called roboball_autonomous.lua.

Change all `Control` to `Autonomous` and add it to the script.

Now add the following line to the part where it collides with the ground:

```lua
RigidBodyRequestBus.Event.ApplyLinearImpulse (self.entityId, Vector3(0,0, 1.0));
```

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