# Roboball Tutorial 3

If you completed [part 3 of the roboball tutorial](roboball_tutorial_3.md) you should have a bouncy ball like this. If not, please complete it first or start with the project in /Projects/roboball_2. 

![full_bounce](images/full_bounce.gif)


## Add a Lua script

So the ball bounces away and that's nice, but that get's boring after a while. Let's give it a Lua script for more complex behavior.

![add_lua_component](images/add_lua_component.png)

1. Select the RoboBall Entity
1. Click `Add Component`
1. Select `Lua Script`
1. Open the Lua editor with the symbol next to the empty field

![lua_editor](images/lua_editor.png)


Let's make a simple lua script

1. Go to File > New
1. Make a new folder called Scripts
1. In that folder, call the file RoboBall_HelloWorld.lua
1. Go back to the editor
1. In the Lua script component let's add this Lua script

![add_lua_script](images/add_lua_script.png)

## Hello World!

Now back in the Lua Editor in the RoboBall_HelloWorld.lua enter the following:
```lua
local HelloWorld = {
	Properties = {
	}
}
function HelloWorld:OnActivate()
	Debug.Log("Hello, World!")
end

function HelloWorld:OnTick(deltaTime, currentTime)
end

function HelloWorld:OnDeactivate()
	Debug.Log("Goodbye, World!")
end

return HelloWorld
```

The console in the O3DE editor now should say

```
Entered game mode
(Script) - Hello, World!
(Spawnables) - Entities from new root spawnable 'Root.spawnable' are ready (generation: 0).
(Script) - Goodbye, World!
Exited game mode
```

So `OnActivate` is started when the game is activated, and `onDeactivate` is activated when the game is ended (when you press `esc`).

## Hello, Again!

Now I'd like it the ball to talk to me all the time! So let's add a tick notification bus to it.

Connect to the tick notification bus in OnActivate
```lua
	self.TickNotificationBus = TickBus.Connect(self);
```

Add a new function OnTick()

```lua
function HelloWorld:OnTick(deltaTime, currentTime)
 	Debug.Log("Hello again!")
end
```

And disconnect from the bus when the game ends in DeActivate()
```lua
	self.TickNotificationBus:Disconnect();
```

The full script should like like this:


```lua
local HelloWorld = {
	Properties = {
	}
}
function HelloWorld:OnActivate()
	Debug.Log("Hello, World!")
	self.TickNotificationBus = TickBus.Connect(self);
end

function HelloWorld:OnTick(deltaTime, currentTime)
 	Debug.Log("Hello again!")
end

function HelloWorld:OnDeactivate()
	Debug.Log("Goodbye, World!")
	self.TickNotificationBus:Disconnect();
end

return HelloWorld

```

When running the came you should see this in the console:

```
Entered game mode
(Script) - Hello, World!
(Spawnables) - Entities from new root spawnable 'Root.spawnable' are ready (generation: 0).
(Script) - Hello again!
(Script) - Hello again!
(Script) - Hello again!
(Script) - Hello again!
...
(Script) - Hello again!
(Script) - Hello again!
(Script) - Hello again!
(Script) - Hello again!
(Script) - Goodbye, World!
Exited game mode

```

## Go to the next part

You've added a Lua script! Let's go to the next part to do something with the physics in that script

`