[Variables]
; GW=(450*#scale#)
; GH=(195*#scale#)
GP=(40*#Scale#)
GW=(385*#Scale#)
GH=(170*#Scale#)
P=(16*#Scale#)
R=(25*#Scale#)
Style.ImageSize=85

Shuffle=0
Control=1
Repeat=0
Heart=0
Prog=1

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;
[WallpaperPath]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=Control Panel\Desktop
RegValue=Wallpaper
UpdateDivider=-1
[WallpaperRegex]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=Control Panel\Desktop
RegValue=Wallpaper
Substitute="\":"\\",".":"\."
OnUpdateAction=[!UpdateMeasure WallpaperCheck:M]
UpdateDivider=-1
[WallpaperCheck:M]
Measure=String
String=#cache.wallpaper#
ifMatch=^[WallpaperRegex]$
ifMatchAction=[!Log "WallpaperChecked:match"]
ifnotmatchaction=[!Delay 200][!Toggle *][!Log "Wallpaper changed: [WallpaperPath]"]["#@#Actions\nircmd.exe" sendkeypress LWin+D][!Delay 200][!WriteKeyValue Variables Cache.Wallpaper "[WallpaperPath]" "#ROOTCONFIGPATH#Main\Vars\16.inc"][!WriteKeyValue #CURRENTCONFIG# AutoSelectScreen "1" "#SETTINGSPATH#Rainmeter.ini"][!UpdateMeasure MM][!UpdateMeasure ShadowMM][!CommandMeasure ShadowMM "Reload Image"][!CommandMeasure MM "Reload Image"][!Delay 1000][!Toggle *][!Refresh]
DynamicVariables=1
UpdateDivider=-1


[MM]
Measure=Plugin
Plugin=MagickMeter
DynamicVariables=1
Image=File Screenshot | RenderSize (#SCREENAREAWIDTH#/2),(#SCREENAREAWIDTH#/2) | Modulate #BlurModulate# | Blur #BlurRadius#,#BlurSigma#
ExportTo=#SKINSPATH#..\CoreData\ModularPlayers\Blur.png
UpdateDivider=-1
Disabled=1
Group=NUOL
[ShadowMM]
Measure=Plugin
Plugin=MagickMeter
DynamicVariables=1
Image=Rectangle #GP#,#GP#,#GW#,#GH#;#R# | Shadow 20,10,0,8,1
ExportTo=#SKINSPATH#..\CoreData\ModularPlayers\16Shadow.png
UpdateDivider=-1
Disabled=1
Group=NUOL

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[ShadowMeter]
Meter=Image
ImageName=#SKINSPATH#..\CoreData\ModularPlayers\16Shadow.png
[B]
Meter=Shape
X=#GP#
Y=#GP#
Shape=Rectangle 0,0,#GW#,#GH#,#R#,#R# | StrokeWidth 0
[ImageMeter]
Meter=Image
ImageName=#SKINSPATH#..\CoreData\ModularPlayers\Blur.png
DynamicVariables=1
W=#SCREENAREAWIDTH#
H=#SCREENAREAHEIGHT#
X=(-#CURRENTCONFIGX#+#SCREENAREAX#)
Y=(-#CURRENTCONFIGY#+#SCREENAREAY#)
UpdateDivider=1
COntainer=B

[IC]
Meter=Shape
X=(#GP#+#P#)
Y=(#GP#+#P#)
Shape=Rectangle 0,0,(#Style.ImageSize#*#scale#),(#Style.ImageSize#*#scale#),(#R#/2)

[I]
Meter=Image
W=(#Style.ImageSize#*#scale#)
H=(#Style.ImageSize#*#scale#)
ImageName=[#PlayerType#Cover]
PreserveAspectRatio=2
Container=IC
DynamicVariables=1
Group=Music

[SName]
Meter=String
MeterStyle=S
X=(#P#)R
Y=r
W=(#GW#-#P#*3-(#Style.ImageSize#*#Scale#))
ClipString=1
FontWeight=600
FontSize=(14*#scale#)
FontColor=#FontColor#
FontFace=SF Pro Display
DynamicVariables=1
MeasureName=#PlayerType#Track
Group=DynamicColors | Music
[SArtist]
Meter=String
MeterStyle=S
X=r
Y=R
W=(#GW#-#P#*3-(#Style.ImageSize#*#Scale#))
ClipString=1
FontSize=(14*#scale#)
FontColor=#FontColor#,150
FontFace=SF Pro Display
DynamicVariables=1
MeasureName=#PlayerType#Artist
Group=DynamicColors | Music

; ------------------------------------ Bar ----------------------------------- ;

[CurrentTime]
Meter=String
MeterStyle=S
X=r
Y=[I:YH]
W=(40*#scale#)
ClipString=1
FontColor=#FontColor#,75
FontFace=SF Pro Display
StringAlign=LeftBottom
DynamicVariables=1
FontSize=(8*#scale#)
MeasureName=#PlayerType#CurrentPosition
UpdateDivider=1
Group=DynamicColors | Music

[ProgBar]
Meter=Shape
X=(40*#scale#)r
Y=(-6*#scale#)r
Shape=Line 0,0,(#GW#-#P#*3-(#Style.ImageSize#+40*2)*#scale#),0 | StrokeWidth (6*#scale#) | Fill Color 0,0,0,1 | Stroke Color #FontColor#,75 | StrokeStartCap Round | StrokeEndCap Round
Shape2=Line 0,0,((#GW#-#P#*3-(#Style.ImageSize#+40*2)*#scale#)*(Clamp([#PlayerType#Progress],0,100))/100),0 | StrokeWidth (6*#Scale#) | Fill Color 0,0,0,1 | Stroke Color #FontColor# | StrokeStartCap Round | StrokeEndCap Round
DynamicVariables=1
UpdateDivider=1
Group=DynamicColors
LeftMouseUpAction=[!SetOption PosCalc Formula "($MouseX$/(#GW#-#P#*3-(#Style.ImageSize#+40*2)*#scale#)*100)"][!UpdateMeasure PosCalc]
[PosCalc]
Measure=calc
OnUpdateAction=[!CommandMeasure State#NowPlayingMedia# "SetPosition [PosCalc]"]
Disabled=1
DynamicVariables=1
UpdateDivider=-1
Group=NUOL

[MediaLength]
Meter=String
MeterStyle=S
X=(#GP#+#GW#-#P#)
Y=(6*#scale#)r
W=(40*#scale#)
ClipString=1
FontColor=#FontColor#,75
FontFace=SF Pro Display
StringAlign=RightBottom
DynamicVariables=1
FontSize=(8*#scale#)
MeasureName=#PlayerType#Length
Group=DynamicColors | Music

; --------------------------------- Controls --------------------------------- ;

[Previous]
Meter=Image
ImageName=#@#Icons\16Previous.png
X=(#GP#+(#GW#/2-((28+32+28+40*2)*#scale#)/2))
Y=(#GH#-#P#-30*#scale#+#GP#)
W=(28*#scale#)
H=(28*#scale#)
Grayscale=1
ImageTint=#FontColor#
DynamicVariables=1
Group=Music
LeftMouseUpAction=[!CommandMeasure State#NowPlayingMedia# "Previous"]


[PlayPause]
Meter=Image
MeterStyle=
X=(40*#Scale#)R
Y=(-2*#scale#)r
W=(32*#scale#)
H=(32*#scale#)
Grayscale=1
ImageTint=#FontColor#
DynamicVariables=1
Group=Music
[Play]
ImageName=#@#Icons\16Play.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Pause][!UpdateMeter PlayPause][!Redraw][!CommandMeasure State#NowPlayingMedia# "PlayPause"]
[Pause]
ImageName=#@#Icons\16Pause.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw][!CommandMeasure State#NowPlayingMedia# "PlayPause"]

[Next]
Meter=Image
ImageName=#@#Icons\16Next.png
X=(40*#Scale#)R
Y=(2*#scale#)r
W=(28*#scale#)
H=(28*#scale#)
Grayscale=1
ImageTint=#FontColor#
DynamicVariables=1
Group=Music
LeftMouseUpAction=[!CommandMeasure State#NowPlayingMedia# "Next"]
