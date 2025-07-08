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

