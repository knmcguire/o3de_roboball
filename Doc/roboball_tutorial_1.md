# Roboball tutorial 1

This tutorial is made with the following hardware and environments:
* Windows 11 home
* Lenovo Legion S7 laptop
* Nvidia GTX 3060 (8 gb ram)
* 24 Gb RAM

This tutorial is made for **O3DE version 25.05**, so any version that doesn't match is done at own risk.

## Getting started

If this is your first time working with O3DE make sure that you go through the following tutorials first:

* Getting started: https://www.docs.o3de.org/docs/welcome-guide/
* Editor tour: https://www.docs.o3de.org/docs/welcome-guide/tours/editor-tour/

Then do the following:
*  Create a project called "RoboBall", based on the default Project template ([O3DE tutorial on creating projects](https://www.docs.o3de.org/docs/welcome-guide/create/))
* Build the project and open up the editor of the project. .
* On the welcome screen a level, select Open... and navigate to Levels\DefaultLevel and select DefaultLevel.prefab.

You should be able to see the following level now:

![editor](images/editor.png)

> This can take up to 10-20 minutes to completely finish and all the assests to be processes. Make sure to wait until the bottom right says `Pending Jobs: 0` and no failed build/jobs.

## Create a ball asset

![hide_shaderball](images/hide_shaderball.png)

First select the shader ball and delete it from the entity editor ('rightclick' on it and Delete)


Then create a new entity called roboball

1. On the scene or Entity editor, do `right mouseclick` and select Create Entity or `Ctrl+Alt+N`
1. Select the newly created entity and rename it to 'RoboBall' in the inspector

![addmesh](images/addmesh.png)

Then let's add a sphere:

1. Click 'Add Component'
1. Add a Mesh component
1. Next to Model Assest click on the folder icon
navigate PrimativeAssets > Assets > Objects > _Primitives > _Sphere_1x1.fbx

![addtransform](images/addtransform.png)


You should now see this. As you can notice the ball is within the floor, so let's move it up.

1. Open up the transform component 
1. add '`0,5` ' meters in the z-axis

The viewport should now show this:

![sphere_asset](images/sphere_asset.png)

Jeej! You have a ball! Go to [page 2](roboball_tutorial_2.md)