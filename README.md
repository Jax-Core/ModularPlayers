<h1 align="center">
  Modular Players
</h1>

<h4 align="center">Download Now!</h4>

A gallery of hand-crafted rainmeter music players with built in preview and settings menu. Download rainmeter [here](https://www.rainmeter.net/).

## Gesture actions
For some of the styles there would be only one button for play pause. By swiping left or right on the skin you can play the previous or next song.

## Styles
<p float="left" align="center">
  <img src="https://github.com/EnhancedJax/ModularPlayers/blob/main/%40Resources/Images/Preview/Simple.png"/>
  <img src="https://github.com/EnhancedJax/ModularPlayers/blob/main/%40Resources/Images/Preview/Neumorphism.png"/>
  <img src="https://github.com/EnhancedJax/ModularPlayers/blob/main/%40Resources/Images/Preview/Blur.png"/>
</p>
<p float="left" align="center">
  <img src="https://github.com/EnhancedJax/ModularPlayers/blob/main/%40Resources/Images/Preview/MIUI.png"/>
  <img src="https://github.com/EnhancedJax/ModularPlayers/blob/main/%40Resources/Images/Preview/Side.png"/>
  <img src="https://github.com/EnhancedJax/ModularPlayers/blob/main/%40Resources/Images/Preview/Card.png"/>
</p>
<p float="left" align="center">
  <img src="https://github.com/EnhancedJax/ModularPlayers/blob/main/%40Resources/Images/Preview/Fortnite.png"/>
  <img src="https://github.com/EnhancedJax/ModularPlayers/blob/main/%40Resources/Images/Preview/BigCirc.png"/>
  <img src="https://github.com/EnhancedJax/ModularPlayers/blob/main/%40Resources/Images/Preview/Android.png"/>
</p>

# Installation
### Requirements
Rainmeter 4.4 beta or newer: [Download here](https://www.rainmeter.net/)
Spicetify-cli for Spotify to function.

### Installation Instructions
1. Install rainmeter
1. Download the latest release
1. Open the .rmskin package 
1. Leave the installation settings default, and press install

**You'll also have to install ImageMagick for the skin to function. Follow [THIS](https://github.com/khanhas/MagickMeter#how-to-install) guide.**
**Installing this skin would update your Core version, if core is missing, it would be automatically installed.**
  
## Contact me
via Discord: **Jax#1090**

## Special thanks to
[@khanhas](https://github.com/khanhas) for the MagickMeter plugin

# How to install Spicetify-cli

Follow this guide here to basic installation: https://github.com/khanhas/spicetify-cli/wiki/Guide-for-Rainmeter-user

If spotify is blank after installation, follow the following guide:
***
- uninstall spotify
- delete both spicetify folders in your user folder (.spicetify, and spicetify-cli)
- delete your spotify folder in ```%appdata%\local```
- delete everything in ```%temp%```

- install this ver of spotify https://spotify.en.uptodown.com/windows/download/3882445
- then create a folder in ```%appdata%local/spotify```
call it `Update`

- and set the user group permissions so that trusted installer and system have permissions blocked

- open powershell and paste this into it 
`Invoke-WebRequest -UseBasicParsing "https://raw.githubusercontent.com/khanhas/spicetify-cli/master/install.ps1" | Invoke-Expression`

- type `spicetify` and hit enter once

- run this ```spicetify backup apply enable-devtool```

- close spotify


Now you can do your themes and extensions
here is an example:
```
spicetify config inject_css 0 replace_colors 0
spicetify config extensions webnowplaying.js
spicetify apply
```
