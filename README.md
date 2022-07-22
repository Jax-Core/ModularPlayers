
<br />
<div align="center">
  <a href="https://github.com/Jax-Core/ModularPlayers">
    <img src="https://i.imgur.com/EjekXps.png" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">ModularPlayers</h3>

  <p align="center">
    Media Controls with gesture control and a multitude of features.
    <br />
    <a href="https://www.deviantart.com/jaxoriginals/art/ModularPlayers-Adaptive-music-widget-886577256"><strong>More Info »</strong></a>
    <br />
    <br />
    <a href="https://discord.gg/JmgehPSDD6">Report Bugs & Request Features </a>
  </p>
</div>


<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about">About</a>
    </li>
    <li>
      <a href="#Features">Features</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
        <li><a href="#setting-up">Styles Setup</a>
          <ul>
           <li><a href="#installing-imagemagick">Installing ImageMagick</a></li>
        <li><a href="#installing-spicetify">Installing Spicetify</a></li>
        <li><a href="#choosing-presets">Choosing Presets</a></li>
          </ul>
        </li>
      </ul>
    </li>
    <li> <a href="#help-and-credits">Help & Credits</a></li>

  </ol>
</details>


## About

![ModularPlayers](https://images-wixmp-ed30a86b8c4ca887773594c2.wixmp.com/i/97bfd084-7ef0-496f-a835-3c41f482d38c/denufe0-a4a5dad3-3428-44da-a4e9-2acfc51592a7.png/v1/fill/w_1192,h_670,q_70,strp/modularplayers___adaptive_music_widget_by_jaxoriginals_denufe0-pre.jpg)

ModularPlayers is a Rainmeter skin that includes a gallery of hand-crafted media controllers, a preview option, and an efficient settings menu.


## Features

* 10 Player Presets
* Animated Styles
* Gesture Driven Media Controls

<!-- INSTALLATION AND SETUP -->
## Getting Started

### Prerequisites
- **Windows 10** or above
- For older systems, **Powershell v5.1 or newer** is required. Upgrade powershell **[here](https://docs.microsoft.com/en-us/powershell/scripting/windows-powershell/install/installing-windows-powershell?view=powershell-7.2#upgrading-existing-windows-powershell)**!

### Installation 
**By Powershell CLI:**
Run the following command in Powershell (`win + r` -> `powershell.exe` / search)
```
$installSkin="ModularPlayers";Invoke-WebRequest -UseBasicParsing "https://raw.githubusercontent.com/Jax-Core/JaxCore/master/CoreInstaller.ps1" | Invoke-Expression
```
**By legacy [Rainmeter](https://www.rainmeter.net/) .rmskin installer:**
Download and run the `.rmskin` file from the latest release **[here](https://github.com/Jax-Core/ValliStart/releases/latest)**.
> Note:  If you find that the JaxCore option is red on the startup pop-up, please press the red button and Core will be installed automatically. Perchance this fails, you can manually install Core by downloading the `.rmskin` file from [JaxCore's official website.](https://jax-core.github.io/)
<br />
<br />

## Additional requisites
### ImageMagick (Blur generation)
#### 1. Download ImageMagick: https://www.imagemagick.org/script/download.php#windows

![Download](https://i.imgur.com/gfjRZxh.png)

#### 2. Install ImageMagick. You must check `Add application directory to your system path`:

![InstallStep](https://i.imgur.com/6TbBlTo.png)
  
#### 3. Restart Rainmeter by `Right Click (Anything JaxCore) -> Developer options -> Reload Rainmeter`

Guide from [MagickMeter](https://github.com/khanhas/MagickMeter) by Khanhas

### Spicetify (Full Spotify support)

#### 1. Open Powershell, copy the following commands, paste and press enter:
    ```
      Invoke-WebRequest -UseBasicParsing "https://raw.githubusercontent.com/khanhas/spicetify-cli/master/install.ps1" | Invoke-Expression

      spicetify

      spicetify config extensions webnowplaying.js
    ```
   **If aren't using Spicetify for theming, run the following command**
      ```
        spicetify config inject_css 0 replace_colors 0
      ```
#### 2. And finally, run the following command to save and apply all your changes:
    ```
      spicetify backup apply
    ```
    
#### 3. Restart Rainmeter by `Right Click (Anything JaxCore) -> Developer options -> Reload Rainmeter`

## Help and Credits
- MediaPlayer plugin by [i2002](https://github.com/i2002)
- MagickMeter and ImageMagick plugins along with Spicetify by [khanhas](https://github.com/khanhas)
- Join the [Core Community Discord Server](https://discord.gg/JmgehPSDD6) for more help.
