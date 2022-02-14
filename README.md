
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

## Getting Started

### Prerequisites

- **Rainmeter v4.5 or newer.** Rainmeter can be installed by downloading the `.exe` file [from Rainmeter's official website.](https://www.rainmeter.net/)
- **JaxCore v40005 or newer.** JaxCore can be installed by downloading the `.rmskin` file from [JaxCore's official website.](https://jax-core.github.io/)

### Installation

Assuming you successfully downloaded and installed Rainmeter as well as JaxCore, you can now proceed to install ModularPlayers by following the steps below.

1. Download and run the `.rmskin` file for **ModularPlayers** from the official [JaxCore site](https://jax-core.github.io/) to install **ModularPlayers**.
2. Leave the installation settings at their defaults and click Install.
3. When the installation is finished, a startup pop-up should appear. Follow through the pop-up to finish installing **ModularPlayers**.

* Note:  If you find that the JaxCore option is red on the startup pop-up, please press the red button and Core will be installed automatically. Perchance this fails, you can manually install Core by downloading the `.rmskin` file from [JaxCore's official website.](https://jax-core.github.io/)

### Setting Up

To use the custom player styles, you must first install and configure **[ImageMagick](https://github.com/khanhas/MagickMeter) as well as [Spicetify](https://spicetify.app/).** If you already have **ImageMagick** and **Spicetify** setup, you can skip to choosing the presets; if not, follow the instructions below to setup **ImageMagick** and **Spicetify**.


#### Installing ImageMagick:

1. Open **[this link](https://www.imagemagick.org/script/download.php#windows)**. This link will take you to another site where you must locate and download the appropriate installer.
2. Find a suitable release under **Windows Binary Release** that corresponds to your requirements and download it. The `ImageMagick-7.1.0-19-Q16-HDRI-x64-dll.exe` executable will be used to install for this guide.
3. After the download is complete, run the installer, which in this case is `ImageMagick-7.1.0-19-Q16-HDRI-x64-dll.exe`.
4. Leave the installation settings at their defaults and follow through the installation. You can tinker around with the settings **ONLY** if you know what they do.
5. Open **[this link](https://github.com/khanhas/MagickMeter/releases)** and dowload the latest release of the **MagickMeter** skin. The `magickmeter_0.7.3.rmskin` Rainmeter skin file will be used to install for this guide. 
6. Leave the installation settings at their defaults and click Install.
7. Restart Rainmeter and your plugin will be activated.

And that is how you setup **ImageMagick**. You can now proceed to configure the player Presets.

* **Note:** An alternate approach for **Step 5** and **Step 6** is:
  - Download the [plugin DLLs](https://github.com/khanhas/MagickMeter/releases)
  - Copy the version that corresponds to your system from the zip file (x86 or x64)
  - Open Run(`Win + R`), type `%appdata%\Rainmeter\Plugins\` and press **OK**.
  - Manually paste DLL you copied in the second step.
  - Finally, restart Rainmeter and your plugin will be activated.

#### Installing Spicetify:

1. Open Powershell (Windows 10) or Windows Terminal (Windows 11) and run the commands that follow:
    ```
      Invoke-WebRequest -UseBasicParsing "https://raw.githubusercontent.com/khanhas/spicetify-cli/master/install.ps1" | Invoke-Expression

      spicetify

      spicetify config extensions webnowplaying.js
    ```
   **If you only want to install `webnowplaying.js` without the custom themes, use the following command:**
      ```
        spicetify config inject_css 0 replace_colors 0
      ```
2. And finally, run the following command to save and apply all your changes:
    ```
      spicetify backup apply
    ```

You can now proceed to choosing the presets.

#### Choosing Presets:
Follow the steps outlined below to setup custom player presets:

1. Open Core and head over to the **Desktop** section.
2. Select **ModularPlayers** from the list and proceed to the **Appearance** tab.
3. Under **Player Style** choose a preset that you like.
4. The player style will be changed if you refresh **ModularPlayers** by deactivating and activating the toggle on the bottom left.

* **Note:** The **General** and **Appearance** tabs allow you to further customize each preset as required.

## Help and Credits
- MediaPlayer plugin by [i2002](https://github.com/i2002)
- MagickMeter and ImageMagick plugins along with Spicetify by [khanhas](https://github.com/khanhas)
- Join the [Core Community Discord Server](https://discord.gg/JmgehPSDD6) for more help.
