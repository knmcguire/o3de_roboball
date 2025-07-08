# Roboball 10

and we are at the final part! let's finally get this thing being autonomous!

## Differentiate between wall and floor

Let's create some walls! Make 4 entities of the white box and make an arena around the ball.

Play the game and you'll see the ball constantly hitting the wall 

Now at the following to the ifstatement of the collision script

```lua
	else
		Debug.Log('obstacle')
```

You see now that it constantly hits the wall and detects is since it's different from the floor so it will now detect it as obstacle.

## Move from obstacles

Now we move away from the obstacles.

Add the following property:
```
		AvoidAngle = 2.4,
```

and 

Add this line to the obstacle if statement (where the debug log of thee obstacle is)

```lua
		self.ControlHeading = WrapAngle(self.ControlHeading + self.Properties.AvoidAngle )
```

Now run the game and you'll see the ball bouncing away from the walls.


Now let's add some obstacles to the scene, let's use the white box collider for it.

Play the game and see how it handles the other obtacles. 

