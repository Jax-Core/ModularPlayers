[Rainmeter]
OnRefreshAction=

[MeasureOnLoad]
Measure=Calc
Formula=Counter
IfEqualValue=1
IfEqualAction=[!Delay 100][!enablemeasuregroup NUOL][!CommandMeasure Func "checkMedia#MediaType#()"]
IfAboveValue=1
IfAboveAction=[!Delay 10][!DeactivateConfig][!ActivateConfig "ModularPlayers\Main"]
UpdateDivider=-1

[Variables]
GW=(500*#scale#)
GH=(#H#*#scale#)
P=(50*#Scale#)

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
Path=[#PlayerType#Cover]
Format=Dec
UpdateDivider=-1
Group=Music

[AC]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Average
UpdateDivider=-1
Group=Music
OnChangeAction=[!UpdateMeter B]

[SliderScript]
Measure=Script
ScriptFile=#@#Lua\Slider.lua
UpdateDivider=(#AutoScroll# = 1 ? 1 : -1)
Disabled=(1-#AutoScroll#)
Group=Music

;==============================================================================================
;==============================================================================================
;==============================================================================================

[B]
Meter=Shape
MeterStyle=B#SideGlow##HideAlbum# | BScroll#AutoScroll#
DynamicVariables=1

[BScroll0]
MouseOverAction=[!EnableMeasure SliderScript][!CommandMeasure SliderScript "Animate()"]
MouseLeaveAction=[!DisableMeasure SliderScript][!CommandMeasure SliderScript "Reset()"]
[B10]
Shape=Rectangle 0,0,(200*#scale#),#GH# | StrokeWidth 0 | Fill RadialGradient this
Shape2=
This=(-(200*#scale#)/2),0,0,0,(#GH#/2),(#GH#/2) | [AC] ; 0.2 | 0,0,0,1 ; 1.0
[B00]
Shape=Rectangle 0,0,(200*#scale#),#GH# | StrokeWidth 0 | Fill Color 0,0,0,1
Shape2=
[B11]
Shape=Rectangle 0,0,(200*#scale#),#GH# | StrokeWidth 0 | Fill RadialGradient this
This=(-(200*#scale#)/2),0,0,0,(#GH#/2),(#GH#/2) | [AC] ; 0.2 | 0,0,0,1 ; 1.0
Shape2=Rectangle (20*#scale#),#P#,(#BarW#*#Scale#),(#GH#-#P#*2),(#BarCorner#*#scale#) | StrokeWidth 0 | Fill Color #MainColor#
[B01]
Shape=Rectangle 0,0,(200*#scale#),#GH# | StrokeWidth 0 | Fill Color 0,0,0,1
This=(-(200*#scale#)/2),0,0,0,(#GH#/2),(#GH#/2) | [AC] ; 0.2 | 0,0,0,1 ; 1.0
Shape2=Rectangle (20*#scale#),#P#,(#BarW#*#Scale#),(#GH#-#P#*2),(#BarCorner#*#scale#) | StrokeWidth 0 | Fill Color #MainColor#


[CreateShadow0]
Measure=Plugin
Plugin=MagickMeter
Disabled=#HideAlbum#
Image=Rectangle (35*#scale#),#P#,(#GH#-#P#*2),(#GH#-#P#*2),(#R#/2),(#R#/2) | Shadow 10,(5*#Scale#),0,0,1 ; #OppositeColor#

[IShadow]
Meter=Image
Hidden=#HideAlbum#
MeasureName=CreateShadow#HideAlbum#

[IC]
Meter=Shape
X=(35*#scale#)
Y=#P#
Shape=Rectangle 0,0,(#GH#-#P#*2),(#GH#-#P#*2),(#R#/2),(#R#/2) | StrokeWidth 0

[I]
Meter=Image
ImageName=[#PlayerType#Cover]
W=(#GH#-#P#*2)
H=(#GH#-#P#*2)
PreserveAspectRatio=2
Container=IC
Hidden=#HideAlbum#
DynamicVariables=1
Group=Music

[SMetaDataSection]
Meter=Shape
X=(#HideAlbum# = 0 ? (#GH#-#P#) : #P#)
Y=(#GH#/2-(50*#scale#)/2)
Shape=Rectangle 0,0,((#GW#)-120*#scale#),(#GH#-2*#P#) | StrokeWidth 0 | Fill LinearGradient This
This=180 | 0,0,0 ; 0.7 | 0,0,0,0 ; 1
DynamicVariables=1
Group=Music
[SName1]
Meter=String
MeterStyle=S
UpdateDivider=1
ClipString=2
FontWeight=600
FontSize=(16*#scale#)
FontColor=#MainColor#
DynamicVariables=1
MeasureName=#PlayerType#Track
Group=Music
Container=SMetaDataSection
[SName2]
Meter=String
MeterStyle=S | SName1
X=R
Text="  -  %1"
Hidden=([SName1:W]>380*#Scale#?0:1)
[SArtist1]
Meter=String
MeterStyle=S
Y=(29*#scale#)
DynamicVariables=1
ClipString=1
FontSize=(12*#scale#)
FontFace=Nunito Sans SemiBold
FontColor=#MainColor#,150
MeasureName=#PlayerType#Artist
Group=Music
Container=SMetaDataSection
[SArtist2]
Meter=String
MeterStyle=S | SArtist1
X=R
Y=r
Text="  -  %1"
Hidden=([SArtist1:W]>380*#Scale#?0:1)

[Heart]
Meter=String
[Shuffle]
Meter=String
[Repeat]
Meter=String