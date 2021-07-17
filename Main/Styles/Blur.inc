[Variables]
GW=(440*#Scale#)
GH=(150*#Scale#)
P=(25*#Scale#)
LumHnld=0.4
ShadowColor=0

Shuffle=0
Control=0
Repeat=0
Heart=0
Prog=0
;==============================================================================================
;==============================================================================================
;==============================================================================================

[MainC]
Measure=Plugin
Plugin=Chameleon
Type=File
Path=[mCover]
Format=Dec
UpdateDivider=1

[AC]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Average
OnChangeAction=[!CommandMeasure ImageProcess "Reload Image"][!UpdateMeter *][!Redraw]
UpdateDivider=1

[Lum]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Luminance
OnChangeAction=[!CommandMeasure CreateShadow "Reload Image"][!UpdateMeter *][!Redraw]
UpdateDivider=1


;==============================================================================================
;==============================================================================================
;==============================================================================================

[B]
Meter=Shape
Shape=Rectangle 0,0,#GW#,#GH#,#R#,#R# | StrokeWidth 0 | Fill Color #MainColor#
LeftMouseDownAction=[!Setvariable Mouse.0Pos $MouseX$]
LeftMouseUpAction=[!Setvariable Mouse.1Pos $MouseX$][!UpdateMeasure mAction]
DynamicVariables=1

[ImageProcess]
Measure=Plugin
Plugin=MagickMeter
Image=File [mCover] | Blur #BlurRadius#,#BlurSigma# | Modulate #BlurModulate#
DynamicVariables=1

[CreateShadow]
Measure=Plugin
Plugin=MagickMeter
Image=Ellipse (#GH#/2),(#GH#/2),((#GH#-#P#*2)/2) | Shadow 50,5,0,0,1 ; ([Lum] > #LumHnld# ? 0 : 255),([Lum] > #LumHnld# ? 0 : 255),([Lum] > #LumHnld# ? 0 : 255)
DynamicVariables=1

[ImageBlur]
Meter=Image
Container=B
W=#GW#
H=#GH#
PreserveAspectRatio=2
MeasureName=ImageProcess

[FadeOut]
Meter=Shape
Shape=Rectangle 0,0,#GW#,#GH#,#R#,#R# | StrokeWidth 0 | Fill LinearGradient This
This=270 | 0,0,0,0 ; 0.0 | [AC] ; 1.0
DynamicVariables=1

[IShadow]
Meter=Image
MeasureName=CreateShadow

[IC]
Meter=Shape
Shape=Ellipse (#GH#/2),(#GH#/2),((#GH#-#P#*2)/2),((#GH#-#P#*2)/2) | StrokeWidth 0

[I]
Meter=Image
MeasureName=mCover
X=#P#
Y=#P#
W=(#GH#-#P#*2)
H=(#GH#-#P#*2)
Container=IC
PreserveAspectRatio=2


[SName]
Meter=String
MeterStyle=S
X=(#P#)R
Y=(#GH#/2)r
W=(#GW#-(#GH#-#P#*2)-2*#P#)
ClipString=1
StringAlign=LeftCenter
FontWeight=600
Text=%1#CRLF#%2
FontSize=(15*#scale#)
FontColor=#OppositeColor#
InLinePattern=#CRLF#.*
InlineSetting=Size | (12*#scale#)
InLinePattern2=#CRLF#.*
InlineSetting2=Face | IBM Plex Sans Light
DynamicVariables=1
Group=DynamicColors
MeasureName=mTrack
MeasureName2=mArtist
FontFace=IBM Plex Sans Semibold