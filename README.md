# O3DE RoboBall Tutorial Project

> **⚠️ EXPERIMENTAL PROJECT** - This is an unofficial, experimental tutorial project. There is limited support and you might need to fix some bugs yourself

A comprehensive tutorial series for learning **Open 3D Engine (O3DE)** through building an autonomous bouncing ball game. This project teaches fundamental O3DE concepts including physics, Lua scripting, input handling, materials, and AI behaviors.

![RoboBall Demo](Doc/images/roboball_chasing_respawned_goal.gif)

## Overview

RoboBall is a step-by-step tutorial project that guides you through creating a physics-based bouncing ball that evolves from a simple static object to an autonomous  capable of:

- **Physics-based movement** with realistic bouncing
- **Player control** through keyboard input
- **Autonomous navigation** towards goals
- **Obstacle avoidance** behaviors
- **Dynamic goal respawning** in a confined arena

## Prerequisites

- **O3DE Version 25.05** (other versions not guaranteed to work)
- Basic understanding of game development concepts
- Completed O3DE welcome guide tutorials:
  - [Getting Started](https://www.docs.o3de.org/docs/welcome-guide/)
  - [Editor Tour](https://www.docs.o3de.org/docs/welcome-guide/tours/editor-tour/)

## System Requirements

This tutorial was developed and tested on:
- Windows 11 Home
- Lenovo Legion S7 laptop
- Nvidia GTX 3060 (8 GB RAM)
- 24 GB RAM

## Tutorial Series

The project is divided into 10 progressive tutorials, each building upon the previous:

### [Tutorial 1: Getting Started](Doc/roboball_tutorial_01.md)
- Project setup and basic entity creation
- Adding mesh components and transforms
- Creating your first sphere asset

### [Tutorial 2: Physics Basics](Doc/roboball_tutorial_02.md)
- Adding PhysX components for realistic physics
- Configuring colliders and rigid bodies
- Creating custom bouncy materials

### [Tutorial 3: Lua Scripting Introduction](Doc/roboball_tutorial_03.md)
- Setting up Lua script components
- Understanding O3DE's Lua API
- Creating your first "Hello World" script

### [Tutorial 4: Movement and Camera](Doc/roboball_tutorial_04.md)
- Implementing linear impulses for movement
- Adding script properties for customization
- Setting up camera rigs to follow the ball

### [Tutorial 5: Input Handling](Doc/roboball_tutorial_05.md)
- Creating keyboard input bindings
- Connecting input events to Lua scripts
- Implementing player control systems

### [Tutorial 6: Visual Polish](Doc/roboball_tutorial_06.md)
- Adding textures and materials to objects
- Implementing rotation with angular impulses
- Coordinating visual feedback with physics

### [Tutorial 7: Advanced Control](Doc/roboball_tutorial_07.md)
- Replacing impulses with direct angular velocity control
- Improving camera rig behaviors
- Creating more responsive player controls

### [Tutorial 8: Collision Detection](Doc/roboball_tutorial_08.md)
- Setting up collision event handling
- Differentiating between collision types
- Using entity IDs for collision filtering

### [Tutorial 9: Autonomous Behaviors](Doc/roboball_tutorial_09.md)
- Creating realistic bounce mechanics with scripted actuators
- Implementing forward speed control
- Building autonomous movement patterns

### [Tutorial 10: Obsstacle Avoidance and Goal-Seeking](Doc/roboball_tutorial_10.md)
- Creating arena boundaries with walls
- Implementing obstacle avoidance
- Adding goal-seeking behaviors
- Dynamic goal respawning system

## Video Walkthroughs

Watch the development process live! These YouTube videos show the actual creation of this tutorial series:

### 📺 YouTube Series
* **[O3DE Roboball Simulation - Making a Bouncy Ball Asset](https://www.youtube.com/watch?v=qON_ox6lvYs)** *(Covers Tutorials 1-2)*
* **[O3DE Roboball Simulation - Lua scripting, Forces & Simple Camera Rig](https://www.youtube.com/watch?v=NntJrInIV6k)** *(Covers Tutorials 3-4)*
* **[O3DE Roboball Simulation - Key bindings and Force Control](https://www.youtube.com/watch?v=68C_hKMx7hg)** *(Covers Tutorial 5)*
* **[O3DE Roboball Simulation - Improving Heading Control](https://www.youtube.com/watch?v=ON2Ij8iYeks)** *(Covers Tutorials 6-7)*
* **[O3DE Roboball Simulation - Working with Collisions and Realistic bouncing (Stream Clip)](https://www.youtube.com/watch?v=6jUnmfD0jzs)** *(Covers Tutorials 8-9)*
* **[O3DE Roboball Simulation - Obstacle Avoidance and Goal Seeking](https://www.youtube.com/watch?v=l3ZbGZEtiuU)** *(Covers Tutorial 10)*

### 📡 Follow for More Content
- **YouTube Channel**: [@indierobot](https://www.youtube.com/@indierobot)
- **Twitch Channel**: [indierobot](https://www.twitch.tv/indierobot)

## Project Structure

```
o3de_roboball/
├── Doc/                          # Tutorial documentation
│   ├── images/                   # Tutorial screenshots and GIFs
│   └── roboball_tutorial_XX.md   # Individual tutorial files
├── Projects/                     # O3DE project files
│   ├── roboball_1/              # Tutorial 1 starting point
│   ├── roboball_2/              # Tutorial 2 starting point
│   ├── ...                      # Additional tutorial checkpoints
│   └── roboball_10_2/           # Final complete project
├── Gems/                        # Custom O3DE gems (if any)
└── Templates/                   # Project templates
```

## Key Learning Concepts

Through this tutorial series, you'll learn:

### **O3DE Fundamentals**
- Entity-component system architecture
- Asset pipeline and material creation
- Transform and physics systems

### **Physics Programming**
- PhysX integration and configuration
- Collision detection and response
- Custom material properties

### **Lua Scripting**
- O3DE Lua API usage
- Event bus communication
- Property systems and UI integration

### **Input Systems**
- Input binding configuration
- Event-driven input handling
- Real-time control systems

### **AI Behaviors**
- Goal-seeking algorithms
- Obstacle avoidance patterns
- Autonomous agent decision making

## Getting Started

1. **Clone this repository**
   ```bash
   git clone https://github.com/knmcguire/o3de_roboball.git
   ```

2. **Set up O3DE 25.05** following the [official installation guide](https://www.docs.o3de.org/docs/welcome-guide/)

3. **Start with Tutorial 1** at [Doc/roboball_tutorial_01.md](Doc/roboball_tutorial_01.md)

4. **Follow the tutorials sequentially** - each builds upon the previous

5. **Use the project checkpoints** in `/Projects/roboball_X/` if you need to jump to a specific tutorial

## Usage Tips

- **Take your time** - Each tutorial introduces important concepts
- **Experiment** - Try modifying values and properties to understand their effects
- **Debug actively** - Use the console output to understand what's happening
- **Save frequently** - O3DE projects can take time to rebuild

## Contributing

This is an educational project. If you find issues or have suggestions for improvements:
1. Check existing issues first
2. Create detailed bug reports with screenshots
3. Suggest enhancements that improve the learning experience

## License

See [LICENSE](LICENSE) file for details.

## Acknowledgments

- Built for the **Open 3D Engine (O3DE)** community
- Designed to teach practical game development skills
- Inspired by classic autonomous agent programming challenges

### Authorship Notes
- **Tutorials**: Written entirely by [@knmcguire](https://github.com/knmcguire) (check the commit history!)
- **Tutorial Review**: Edited and double-checked for consistency and spelling by Claude Sonnet 4.5
- **README**: Generated by GitHub Copilot (Claude Sonnet 4) to organize and present the tutorial content

---

**Happy Learning!** 🎮🤖

Start your journey with [Tutorial 1: Getting Started](Doc/roboball_tutorial_01.md)