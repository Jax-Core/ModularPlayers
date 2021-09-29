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

Open Powershell, run following commands, one by one:

```
Invoke-WebRequest -UseBasicParsing "https://raw.githubusercontent.com/khanhas/spicetify-cli/master/install.ps1" | Invoke-Expression
spicetify
spicetify config extensions webnowplaying.js
```

If you just want WebNowPlaying without changing UI color, CSS, run this:
```
spicetify config inject_css 0 replace_colors 0
```
Finally, run:
```
spicetify backup apply
```

Above guide provided by spicetify: https://github.com/khanhas/spicetify-cli/wiki/Guide-for-Rainmeter-user

If spotify is blank after installation, or the player doesn't work despite following all the steps, follow the following guide:
***
- Uninstall Spotify.
- Delete your spotify folder in `%localappdata%`.(Type it in your explorer address bar.)
- Delete everything in `%temp%`

- Install [Spotify v1.1.66.580](https://spotify.en.uptodown.com/windows/download/3882445)

- Open Command Prompt as Administrator and do the following:
```cmd
rm %localappdata%\Spotify\Update

mkdir %localappdata%\Spotify\Update

icacls %localappdata%\Spotify\Update /deny "%username%":D

icacls %localappdata%\Spotify\Update /deny "%username%":R
```

> For the curious, it blocks access of Spotify to this folder, so that it can't download and install updates.

- Open powershell and run this `spicetify backup apply`

- After it shows the following, close Powershell, now Spotify info should show up in your skins.
```poweshell
PS C:\Users\username> spicetify backup apply
spicetify v2.6.2
Backing up app files:
OK
Extracting:
OK
Preprocessing:
info Fetching remote CSS map for newer compatible tag version: master
OK
OK
success Everything is ready, you can start applying now!
Err
Copying raw assets:
OK
Overwriting themed assets:
OK
Transferring user.css:
OK
Applying additional modifications:
OK
Transferring extensions:
OK
success Spotify is spiced up!
PS C:\Users\username> _
```
