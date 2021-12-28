[Variables]
GW=(300*#Scale#)
GH=(300*#Scale#)
P=(5*#Scale#)
LumHnld=0
ShadowColor=0
TweenNode=0
TweenStep=50

Shuffle=0
Control=0
Repeat=0
Heart=1
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
UpdateDivider=1

[FC1]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Foreground1
UpdateDivider=1

[FC2]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Average
OnChangeAction=[!UpdateMeterGroup DynamicColors][!Redraw]
UpdateDivider=1


;==============================================================================================
;==============================================================================================
;==============================================================================================


; [B]
; Meter=Shape
; Shape=Ellipse (#GW#/2),(#GW#/2),(#GW#/2),(#GW#/2) | StrokeWidth 0 | Fill Color [DC2]
; LeftMouseDownAction=[!Setvariable Mouse.0Pos $MouseX$]
; LeftMouseUpAction=[!Setvariable Mouse.1Pos $MouseX$][!UpdateMeasure mAction]
; DynamicVariables=1

[CreateShadow]
Measure=Plugin
Plugin=MagickMeter
Image=Ellipse (#GH#*(2/3)/2+#P#),(#GH#*(2/3)/2+#P#),(#GH#*(2/3)/2+1) | Shadow 100,(5*#Scale#),0,0,1 ; 0,0,0

[CreateShadow2]
Measure=Plugin
Plugin=MagickMeter
Image=Ellipse (#GH#*(2/3)-10*#scale#),(#GH#*(2/3)-10*#scale#),(#GH#*(1/3)/2) | Shadow 100,(5*#Scale#),0,0,1 ; 0,0,0

[IShadow]
Meter=Image
MeasureName=CreateShadow

[IC]
Meter=Shape
Shape=Ellipse (#GH#*(2/3)/2),(#GH#*(2/3)/2),(#GH#*(2/3)/2) | StrokeWidth 0 | OffSet #P#,#P#

[I]
Meter=Image
MeasureName=#PlayerType#Cover
X=#P#
Y=#P#
W=(#GH#*(2/3))
H=(#GH#*(2/3))
Container=IC
PreserveAspectRatio=2
DynamicVariables=1

[IShadow2]
Meter=Image
MeasureName=CreateShadow2

[Button]
Meter=Shape
X=(#GH#*(2/3)-10*#scale#)
Y=(#GH#*(2/3)-10*#scale#)
Shape=Ellipse 0,0,(#GH#*(1/3)/2) | StrokeWidth 0 | Fill LinearGradient This
This=45 | [FC1] ; 0.0 | [FC2] ; 1.0
DynamicVariables=1
Group=DynamicColors


[SName]
Meter=String
MeterStyle=S
X=(-#P#-#GH#*(1/3)/2)r
Y=(230*#scale#)
W=(90*#scale#)
ClipString=1
StringAlign=RightCenter
FontWeight=600
Text=%1
FontSize=(12*#scale#)
FontColor=#MainColor#
DynamicVariables=1
MeasureName=#PlayerType#Track
FontFace=IBM Plex Sans Light