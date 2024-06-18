# I have forked the cheat menu repo
This menu is a work in progress, features may be broken or crash your game. It currently only builds and runs for GTA SA.
I will add a release for the menu when I feel like it's ready.

I have disabled logging support in this menu due to it being broken.

As I learn more C++ I will be adding more to this menu. Eventually, I would like to make some sort of chaos mod too.
I have been getting the hang of the functions in GTA SA using the plugin sdk and this menu.

I would like to make my own menu and name it KCNet-SAMenu or something like that using this one as a base.

All credit goes to Grinch for the menu [user-grinch](https://github.com/user-grinch)

<p align="center">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/logo.png" width="700" height="180">
  </p>
<p align="center">  
  Press <kbd>Left Ctrl</kbd> + <kbd>M</kbd> to open the menu. Doesn't work in multiplayer.
</p>
<p align="center">  
  READ THE INSTRUCTIONS. EVERYTHING YOU NEED TO KNOW IS ALREADY HERE.
</p>

## Introduction

A mod menu for Grand Theft Auto III, Vice City & San Andreas which allows a large set of modifications/cheats to be applied enabling a much more easier & amusing gameplay. This is **NOT** intended for use in multiplayer, I won't be responsible for any form of bans. Use it at your own risk!

Get stable binaries from [here](https://github.com/user-grinch/Cheat-Menu/releases). Beta binaries are available at the discord server.

[![Discord Banner 2](https://discordapp.com/api/guilds/689515979847237649/widget.png?style=banner2)](https://discord.com/invite/ZzW7kmf)

## Installation
Only these versions of the game is supported. I highly recommand installing the menu on a fresh, non-modded game first.
- GTA SA v1.0 US Hoodlum 
- GTA VC v1.0 EN
- GTA III v1.0 EN

<details>
  <summary>Manual ( I have disabled the installer for my fork. )</summary>

1. Install [DirectX9](https://www.microsoft.com/en-us/download/details.aspx?id=35), [Visual C++ Redistributable 2022 x86](https://aka.ms/vs/17/release/vc_redist.x86.exe) & [Ultimate asi loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader/releases).
2. Download [**CheatMenuSA/VC/III.7z**](https://github.com/user-grinch/Cheat-Menu/releases) and extract everything in game root directory (NOT MODLOADER). The **CheatMenu** folder & **.asi** file must be placed in the same place.
3. Install [SilentPatch](https://gtaforums.com/topic/669045-silentpatch/) (For GTA III don't install the ddraw.dll component)
4. Install [D3D8to9 wrapper](https://github.com/crosire/d3d8to9/releases) (For III & VC) 
</details>

## Incompatible Mods
### GTA SA
1. **ENB/ SA_DirectX 2.0** 
2. **MSI Afterburner**  **FIX:**  Enable Stealth mode in rivatuner
3. **GTA Underground**

### GTA III
1. SilentPatch **ddraw.dll** component.  **FIX:**  Delete ddraw.dll file for now

Let me know if you mind more.

## Things to do on crash
1. Delete the `CheatMenuXX.toml` config file and try again.
2. If it's happening after installing a recent mod try removing it.
3. Try on a fresh installation of the game.
4. If still doesn't fix your issue, go ahead and report it.

### Crash reports/ Bug reports
Install [Crash info](https://www.mixmods.com.br/2021/06/crashinfo.html) & reproduce your crash. When reporting the crash upload the crashinfo logfile with it. Explain how to reproduce the crash in details. Also include,
- Game version
- Menu version
- List of mods installed

You can either open a issue here or directly contact me on discord (Recommended).

## Images
<details>
  <summary>Show Images</summary>
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/1.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/2.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/3.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/4.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/5.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/6.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/7.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/8.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/9.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/10.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/11.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/12.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/13.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/14.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/15.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/16.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/17.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/18.png">
  <img src="https://raw.githubusercontent.com/user-grinch/Cheat-Menu/master/images/19.png">
</details>

## Submit Translations
*How to translate Cheat Menu to another language*

The translations are loaded from `CheatMenuXX/locale/*.toml` files. Make a copy of the `English.toml` file and translate the texts there to your language. Rename the file to `your_language.toml` and make a pull request. 

If you're language isn't supported ( Appears `???` in the menu. Check [here](https://github.com/user-grinch/Cheat-Menu/tree/master/tools/subset/in.txt) for supported languages), open a [issue](https://github.com/user-grinch/Cheat-Menu/issues) asking for support.


## Required to build
1. [Build Tools 2022](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022)
2. [DirectX9 SDK](https://www.microsoft.com/en-us/download/details.aspx?id=6812)
3. [Plugin SDK](https://github.com/DK22Pac/plugin-sdk)
4. [Premake5](https://premake.github.io/) - Comes with already.

# Building the menu
## To make the solution files for this
1. Open a Command Prompt, Windows Terminal or Powershell window into the tools folder.
2. Run .\premake5.exe vs2022 (If using a different Visual Studio version, specify it here.)

## To build the menu
I need to look into how I built this, I don't remember the exact steps.
But you should be able to open the solution file in Visual Studio 2022 and build it from there.

## Debug the menu
You can use Visual Studio 2022 to debug the menu.


Here is my layout for the Debugging tab (These values should be set to where your GTA SA install is.):
* Command: "C:\Rockstar Games\GTA SA orig mod\gta_sa.exe"
* Working directory: "C:\Rockstar Games\GTA SA orig mod"

I have set this in the general tab for output directory: "C:\Rockstar Games\GTA SA orig mod\scripts".
This makes it to where it will build the menu straight to my GTA SA folder and I can launch the game using the debugger in Visual Studio 2022.

Mods helpful to have in GTA SA:
* Fast Loader (Make the game faster for debugging): [Fast Loader](https://www.gtagarage.com/mods/show.php?id=25665)
* Wide screen fix (Patch the game for proper widescreen support): [Wide screen fix](https://gtaforums.com/topic/547841-gtanfsmpother-widescreen-fixes-pack/)
* Windowed Mode (Add windowed mode support for the game.) [Windowed mode](https://github.com/ThirteenAG/III.VC.SA.WindowedMode/releases)
* Silent Patch (Fix a bunch of bugs and misc items in the game.) [Silent Patch](https://gtaforums.com/topic/669045-silentpatch/)

If using multiple monitors:
* Skip Device Selection: [Skip Device Selection](https://www.gtainside.com/en/sanandreas/mods/99791-skip-device-selection-window)

This disabled the device selection screen on startup for faster debugging.

## Projects used
1. [Cheat-Menu](https://github.com/user-grinch/Cheat-Menu)
2. [ImGui](https://github.com/ocornut/imgui)
3. [Kiero](https://github.com/Rebzzel/kiero)
4. [MinHook](https://github.com/TsudaKageyu/minhook)
5. [Plugin SDK](https://github.com/DK22Pac/plugin-sdk)

All credits are given in Menu/About tab.
