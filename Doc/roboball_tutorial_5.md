# Roboball Tutorial 5


In [Roboball tutorial part 4](roboball_tutorial_4.md) you should have a forward bouncing ball with a camera rig like this:

![follow_ball](images/follow_ball.gif)

If not, please complete it first or start with the project in /Projects/roboball_4. 

In this tutorial, we will add keybindings to the project and read/react to them in the Lua script


## Make keyboard input bindings

Here we will show how to make keyboard ba

![add_input_component](images/add_input_component.png)

1. Select the `RoboBall` entity and go to the Inspector
1. Click on add component and add the `Input` componenent 
1. Click on the Open Assest Editor next to the `Input to Event Bindings`

![keyboard_bindings](images/keyboard_bindings.png)

1. Go to File > New > Inputbindings or Save as ... (if there is already one generated)
1. Go to Scripts and save it as `keyboard.inputbindings`
1. Call the eventname `Control`
1. Next to event generators click the `+ button`
1. Add 1 classes of the type `EventInputMap`
1. Put this in the fields:
    * input Device: Keyboard
    * Input Name: keyboard_key_navigation_arrow_right
    * Event Value: 1,0
    * Dead zone: 0,0
1. Add another class of the type `EventInputMap`
1. Put this in the fields:
    * input Device: Keyboard
    * Input Name: keyboard_key_navigation_arrow_left
    * Event Value: -1,0
    * Dead zone: 0,0
1. Save the input binding


![keyboard_binding_component.png](images/keyboard_binding_component.png)

Then let's add the keybindings to the input component

1. Push the folder button next to the `Input to Event Bindings` field
1. Navigate to `roboball > Scripts`
1. Select `keyboard.inputbindings` and press `OK`

You should now see keyboard in the input component


