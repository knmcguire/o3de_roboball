# RoboBall Tutorial 5

In [RoboBall Tutorial Part 4](roboball_tutorial_4.md), you should have a forward bouncing ball with a camera rig like this:

![follow_ball](images/follow_ball.gif)

If not, please complete it first or start with the project in `/Projects/roboball_4`. 

In this tutorial, we will add keybindings to the project and read/react to them in the Lua script.

## Make Keyboard Input Bindings

Here we will show how to make keyboard bindings:

![add_input_component](images/add_input_component.png)

1. Select the `RoboBall` entity and go to the Inspector
1. Click on **Add Component** and add the `Input` component 
1. Click on the **Open Asset Editor** next to the `Input to Event Bindings`

![keyboard_bindings](images/keyboard_bindings.png)

1. Go to `File > New > Input Bindings` or `Save as...` (if there is already one generated)
1. Go to Scripts and save it as `keyboard.inputbindings`
1. Call the event name `Control`
1. Next to **Event Generators**, click the `+` button
1. Add a class of the type `InputEventMap`
1. Put this in the fields:
    * Input Device: `Keyboard`
    * Input Name: `keyboard_key_navigation_arrow_right`
    * Event Value: `-1.0`
    * Dead Zone: `0.0`
1. Add another class of the type `InputEventMap`
1. Put this in the fields:
    * Input Device: `Keyboard`
    * Input Name: `keyboard_key_navigation_arrow_left`
    * Event Value: `1.0`
    * Dead Zone: `0.0`
1. Save the input binding

![keyboard_binding_component.png](images/keyboard_binding_component.png)

Then let's add the keybindings to the Input component:

1. Click the folder button next to the `Input to Event Bindings` field
1. Navigate to `roboball > Scripts`
1. Select `keyboard.inputbindings` and press **OK**

You should now see keyboard in the Input component.

## Add Event Bus to Lua Script

Open up the Lua editor and start a new script called `RoboBall_Control.lua`. Input the following:

```lua
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
```

Add the new script to the Lua Script component:

![add_control_script](images/add_control_script.png)

Now add the following to properties:

```lua
		InputEventName = ""
```

And these two lines to `OnActivate()`:

```lua
	local inputBusId = InputEventNotificationId(self.Properties.InputEventName)
	self.InputNotificationBus = InputEventNotificationBus.Connect(self, inputBusId)
```

And the bus disconnect in `OnDeactivate()`:

```lua
	 self.InputNotificationBus:Disconnect();
```

Now add the function that will react when either of the 2 arrow buttons are being held:

```lua
function Control:OnPressed(value)
 	local ImpulseDirection = value * self.Properties.ImpulseSize
	RigidBodyRequestBus.Event.ApplyLinearImpulse(self.entityId, Vector3(0, ImpulseDirection, 0));
end
```

In the script component, there is a field now called `InputEventName`. Fill in `Control`.

Now you should be able to control the ball somewhat with the arrow keys, which should result in this with ImpulseSize being `5.0`.

See the resulting script here:

```lua
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
	RigidBodyRequestBus.Event.ApplyLinearImpulse(self.entityId, Vector3(self.Properties.ImpulseSize, 0.0, 0.0));
end

function Control:OnPressed(value)
	local ImpulseDirection = value * self.Properties.ImpulseSize
	RigidBodyRequestBus.Event.ApplyLinearImpulse(self.entityId, Vector3(0, ImpulseDirection, 0));
end

function Control:OnDeactivate()
	self.TickNotificationBus:Disconnect();
	self.InputNotificationBus:Disconnect();
end

return Control
```

Now you can control your ball!

![ball_controll](images/ball_control.gif)

We are not done here yet, so go ahead to [Part 6](roboball_tutorial_6.md)!