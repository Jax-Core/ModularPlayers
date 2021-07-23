[Variables]
GW=(300*#Scale#)
GH=(300*#Scale#)
P=(10*#Scale#)
LumHnld=0
ShadowColor=0
TweenNode=0
TweenStep=50

Shuffle=0
Control=0
Repeat=1
Heart=1
Prog=1
;==============================================================================================
;==============================================================================================
;==============================================================================================

[mL]
Measure=Calc
OnUpdateAction=[!DisableMouseAction Darken MouseLeaveAction][!EnableMouseAction I MouseOverAction][!DisableMeasure mL]

[MainC]
Measure=Plugin
Plugin=Chameleon
Type=File
Path=[mCover]
Format=Dec
UpdateDivider=1

[DC2]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Dark2
UpdateDivider=1
OnChangeAction=[!UpdateMeter B]

[LC1]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Light1
OnChangeAction=[!UpdateMeterGroup DynamicColors][!Redraw]
UpdateDivider=1

[Lum]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Luminance
; OnChangeAction=[!CommandMeasure CreateShadow "Reload Image"][!UpdateMeter *][!Redraw]
UpdateDivider=1


;==============================================================================================
;==============================================================================================
;==============================================================================================

[ActionTimer]
Measure=Plugin
Plugin=ActionTimer
ActionList1=ShowMeters | Repeat Show,8,100
ActionList2=Repeat Hide,8,#TweenStep# | HideMeters
Show=[!SetVariable TweenNode "(Clamp(#TweenNode#+(100/#TweenStep#),0,100))"][!UpdateMeterGroup Tween][!UpdateMeasure ActionTimer][!Redraw]
ShowMeters=[!ShowMeterGroup Tween]
Hide=[!SetVariable TweenNode "(Clamp(#TweenNode#-(100/#TweenStep#),0,100))"][!UpdateMeterGroup Tween][!UpdateMeasure ActionTimer][!Redraw]
HideMeters=[!HideMeterGroup Tween]
DynamicVariables=1


[B]
Meter=Shape
Shape=Ellipse (#GW#/2),(#GW#/2),(#GW#/2),(#GW#/2) | StrokeWidth 0 | Fill Color [DC2]
LeftMouseDownAction=[!Setvariable Mouse.0Pos $MouseX$]
LeftMouseUpAction=[!Setvariable Mouse.1Pos $MouseX$][!UpdateMeasure mAction]
DynamicVariables=1

[CreateShadow]
Measure=Plugin
Plugin=MagickMeter
Image=Ellipse (#GH#/2),(#GH#/2),((#GH#-#P#*2)/2+1) | Innershadow 100,(10*#Scale#),0,0,1 ; 0,0,0

[RoundLine]
Meter=RoundLine
MeasureName=mProgressPer
X=0
Y=0
W=(#GW#)
H=(#GW#)
StartAngle=4.712
RotationAngle=6.283
LineLength=(#GW#/2)
LineColor=[LC1]
Solid=1
AntiAlias=1
DynamicVariables=1
UpdateDivider=1

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
MOuseOverAction=[!DisableMouseAction I MouseOverAction][!EnableMouseAction Darken MouseLeaveAction][!CommandMeasure ActionTimer "Stop 2"][!CommandMeasure ActionTimer "Execute 1"]
PreserveAspectRatio=2

[IShadow]
Meter=Image
MeasureName=CreateShadow

[Darken]
Meter=Shape
Shape=Ellipse (#GH#/2),(#GH#/2),((#GH#-#P#*2)/2),((#GH#-#P#*2)/2) | StrokeWidth 0 | Fill Color 0,0,0,(#TweenNode#/100*150)
Group=Tween
Hidden=1
DynamicVariables=1
MouseLeaveAction=[!DisableMouseAction Darken MouseLeaveAction][!EnableMouseAction I MouseOverAction][!CommandMeasure ActionTimer "Stop 1"][!CommandMeasure ActionTimer "Execute 2"]

[SName]
Meter=String
MeterStyle=S
X=(#GW#/2)
Y=(#GW#/2-([SName:H]+[SArtist:H])/2)
W=(#GW#-#P#*2-40*#scale#)
UpdateDivider=1
ClipString=2
StringAlign=Center
Text=%1
FontFace=IBM Plex Sans Semibold
FontSize=(15*#scale#)
FontColor=255,255,255,(#TweenNode#/100*255)
DynamicVariables=1
MeasureName=mTrack
Hidden=1
Group=Tween
[SArtist]
Meter=String
MeterStyle=S
X=r
Y=R
DynamicVariables=1
W=(#GW#-#P#*2-40*#scale#)
ClipString=2
FontSize=(10*#scale#)
StringAlign=Center
FontFace=IBM Plex Sans Light
FontColor=255,255,255,(#TweenNode#/100*150)
MeasureName=mArtist
Hidden=1
Group=Tween


[Previous]
Meter=Image
ImageName=#@#Icons\Previous.png
X=(#P#+10*#Scale#)
Y=(#GW#/2-10*#Scale#)
W=(20*#Scale#)
H=(20*#Scale#)
Grayscale=1
Group=DynamicColors | Tween
ImageTint=[LC1]
ImageAlpha=(#TweenNode#/100*255)
DynamicVariables=1
Hidden=1
LeftMouseUpAction=[!CommandMeasure mState "Previous"]


[Next]
Meter=Image
ImageName=#@#Icons\Next.png
X=(#GW#-#P#-30*#scale#)
Y=(#GW#/2-10*#Scale#)
W=(20*#Scale#)
H=(20*#Scale#)
Grayscale=1
Group=DynamicColors | Tween
ImageTint=[LC1]
ImageAlpha=(#TweenNode#/100*255)
DynamicVariables=1
Hidden=1
LeftMouseUpAction=[!CommandMeasure mState "Next"]

[Repeat]
Meter=Image
X=(#GW#/2-10*#Scale#)
Y=(#P#+10*#Scale#)
W=(20*#Scale#)
H=(20*#Scale#)
Grayscale=1
Group=DynamicColors | Tween
ImageTint=[LC1]
DynamicVariables=1
Hidden=1
LeftMouseUpAction=[!CommandMeasure mState "Repeat"]
[Repeat0]
ImageAlpha=(#TweenNode#/100*150)
ImageName=#@#Icons\Repeat.png
LeftMouseUpAction=[!SetOption Repeat MeterStyle Repeat1][!UpdateMeter Repeat][!Redraw][!CommandMeasure mState "Repeat"]
[Repeat1]
ImageAlpha=(#TweenNode#/100*255)
ImageName=#@#Icons\Repeat.png
LeftMouseUpAction=[!SetOption Repeat MeterStyle Repeat2][!UpdateMeter Repeat][!Redraw][!CommandMeasure mState "Repeat"]
[Repeat2]
ImageAlpha=(#TweenNode#/100*255)
ImageName=#@#Icons\RepeatOne.png
LeftMouseUpAction=[!SetOption Repeat MeterStyle Repeat0][!UpdateMeter Repeat][!Redraw][!CommandMeasure mState "Repeat"]

[Heart]
Meter=Image
X=(#GW#/2-10*#Scale#)
Y=(#GW#-#P#-30*#scale#)
W=(20*#Scale#)
H=(20*#Scale#)
Grayscale=1
Group=DynamicColors | Tween
ImageTint=[LC1]
DynamicVariables=1
Hidden=1
ImageAlpha=(#TweenNode#/100*255)
[FullHeart]
ImageName=#@#Icons\HeartFull.png
LeftMouseUpAction=[!SetOption Heart MeterStyle EmptyHeart][!UpdateMeter Heart][!Redraw][!CommandMeasure mState "ToggleThumbsDown"]
[EmptyHeart]
ImageName=#@#Icons\Heart.png
LeftMouseUpAction=[!SetOption Heart MeterStyle Fullheart][!UpdateMeter Heart][!Redraw][!CommandMeasure mState "ToggleThumbsUp"]