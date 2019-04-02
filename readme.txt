
Test Mode: 2/5
 - There's not enough here, partially because your game doesn't have a lot to test.  Inventory tests would make sense, but since the system isn't working, it's hard to suggest.  Tests for graphics features could have worked as well.

Game Programming Requirements (30%):

 7% - Game rules/Physics     - 7/7
 - Excellent, raycasting and joints are put to great use.
 3% - Audio                  - 3/3
 - Audio and sound cues are good, but the way you handle multiple channels can be improved.  If all sound channels are full, you would throw away the newest sound rather than stopping the oldest, quietest or furthest away.
 3% - Saved game             - 3/3
 - Works well, but be careful with your error checking:  If the volume fails for any reason, you delete the root, then keep going and try to use it from map survived.
    if(cJSON_AddNumberToObject(jroot, "Volume", m_CurrentSelectedVolume) == NULL)
	{
        cJSON_Delete(jroot);
	}
    if (cJSON_AddNumberToObject(jroot, "Map1 Survived", m_pSceneManager->GetScene("GameScene_Level1")->GetPlayer()->m_Survived) == NULL)

 4% - Scene management       - 4/4
 3% - Tweening               - 3/3
10% - Polish                 - 6/10
 - Excellent work, mouse control works well, but it doesn't unlock when you go into options in game.  You have a decent start on some you interactibles and inventory system, but it needs more work.  Overall, this project is looking great.

Graphics Requirements (30%):

10% - Lighting               - 10/10
 - Lights look great, and the code for it is well implemented.
 5% - Rendering to a texture - 5/5
 - Poison effect is simple, but it work well and swapping one shader for the other for the post process works well.
 5% - Cubemaps               - 3/5
 - Skybox is good, but you didn't attempt reflective surfaces.
10% - Polish                 - 10/10
 - You have a lot here, Text rendering, particles, spot light, light helpers function.

 Overall, you guys have a really solid start for a game, with a bit more time you could finish up the inventory system and add more mechanics, the base is fairly solid.  Great job!


Team members:
    - Hao Shi
    - Shih Chao Lin

Game Description:
    - Survival game. Goal: Survive as long as possible.



*****************************
  Controls:

   - "Esc" to go back to last scene.
   Menus:
	- Up/Down to navigate between menu items.
        - Space to select.
	- Left/Right to toggle.
   GameScene:
        - WASD to move.
        - 'I' to open inventory.
        - 'O' to open in-game menu.
        - 'P' to open imGui window.
		- 'F' to turn on/off flashlight
		- 'E' to grab stuff (mushroom,apple), and break tree
*****************************


Game Programming Requirements (40%):

 7% - Game rules/Physics
    - Hunger system (for some reason, my textrenderer will interfere with my game scene, so I didn't draw the HUD texts)
    - Collect things (pick up, small blue cubes are apples, green cubes are mushrooms), Break stuff (trees are breakable), both inherited from Interactable, using raycast to detect them within a certain reach.
    - bullet physic engine two feature: Two Point Two Constraint, Ray Test
    - Joints (bridge)
    - Player character only moves to the direction of the camera.

  
 3% - Audio
    - Audio queues
    - Looping sounds
    - One-time sounds

 3% - Saved game
    - Save survived time
    - Save volume
    - Automatically save while closing game.

 4% - Scene management
    - HUD will be drawn with game scene.
    - Total of 7 scenes working, dead scene not working~ will break for some reason, so we didn't put it in.
 
 3% - Tweening
    - Menu items

10% - Polish
    - FPS counter
    - Mouse control(turn camera around)
    - Inventory part 1 (logic)
    - Randomly generated world
    - Interactable things (nice hierarchy: GameObject->Interactable->Pickup/Breakable->Concrete Pickups/Breakables) using raytest
  
     
Graphics Requirements (35%):

10% - Lighting
    - Multiple lighting, share functions between shaders, on and off functionality 
  
 5% - Rendering to a texture
    - working
  
 5% - Cubemaps
    - 2 cube maps for 2 levels
  
10% - Polish
    - Add fog effect.
    - Rendering to a texture for each scene, so postprocessing won't affect scenes other than game scenes
    - Text rendering
    - Particles
    - debug draw set up, but not done
    - Inventory part 2 (displaying apple and mushroom upon picking up)


Testing: 5%
    - ImGui - testing the poisonous condition
