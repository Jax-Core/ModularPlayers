[Rainmeter]
ContextTitle5=Align Left
ContextAction5=[!WriteKeyValue Variables Left "#ROOTCONFIGFOLDER#Player\Styles\Side.inc"]
ContextTitle6=Align Center
ContextAction6=[!WriteKeyValue Variables Center "#ROOTCONFIGFOLDER#Player\Styles\Side.inc"]
ContextTitle7=Align Right
ContextAction7=[!WriteKeyValue Variables Right "#ROOTCONFIGFOLDER#Player\Styles\Side.inc"]

[Variables]
GW=(450*#scale#)
GH=(250*#scale#)
P=(50*#Scale#)

Shuffle=0
Control=1
Repeat=0
Heart=0
Prog=0

Align=Left
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
UpdateDivider=1
OnChangeAction=[!UpdateMeter B]


;==============================================================================================
;==============================================================================================
;==============================================================================================

[B]
Meter=Shape
Shape=Rectangle 0,0,#GW#,#GH# | StrokeWidth 0 | Fill RadialGradient this
This=(-#GW#/2),0,0,0,(#GH#/2) | [AC] ; 0.2 | 0,0,0,1 ; 1.0
DynamicVariables=1


[CreateShadow]
Measure=Plugin
Plugin=MagickMeter
Image=Rectangle (35*#scale#),#P#,(#GH#-#P#*2),(#GH#-#P#*2),(#R#/2),(#R#/2) | Shadow 10,(5*#Scale#),0,0,1 ; #OppositeColor#

[IShadow]
Meter=Image
MeasureName=CreateShadow

[IC]
Meter=Shape
X=(35*#scale#)
Y=#P#
Shape=Rectangle 0,0,(#GH#-#P#*2),(#GH#-#P#*2),(#R#/2),(#R#/2) | StrokeWidth 0

[I]
Meter=Image
ImageName=[mCover]
W=(#GH#-#P#*2)
H=(#GH#-#P#*2)
PreserveAspectRatio=2
Container=IC
LeftMouseDownAction=[!Setvariable Mouse.0Pos $MouseX$]
LeftMouseUpAction=[!Setvariable Mouse.1Pos $MouseX$][!UpdateMeasure mAction]
DynamicVariables=1

[SName]
Meter=String
MeterStyle=S
X=(20*#scale#)R
Y=(#GH#/2)
ClipString=2
StringAlign=LeftCenter
FontWeight=600
Text=%1#CRLF#%2
FontSize=(20*#scale#)
FontColor=255,255,255
InLinePattern=#CRLF#(.*)
InlineSetting=Size | (15*#scale#)
InLinePattern2=#CRLF#(.*)
InlineSetting2=Weight | 450
InLinePattern3=#CRLF#(.*)
InlineSetting3=Color | 255,255,255,150
DynamicVariables=1
MeasureName=mTrack
MeasureName2=mArtist