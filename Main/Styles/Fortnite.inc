[Rainmeter]
SkinWidth=#GW#
SkinHeight=#GH#
Rm.Updiv=1000

[Variables]
GW=(550*#scale#)
GH=(90*#scale#)
P=(25*#Scale#)

Grad.1=0,110,178
Grad.2=14,135,193
Accent.0=128,255,102
Accent.1=76,240,255
Accent.2=23, 149, 201
Font.0=178,255,255

Shuffle=0
Control=1
Repeat=0
Heart=0
Prog=1

TweenNode=0
TweenStep=5
;==============================================================================================
;==============================================================================================
;==============================================================================================

[ActionTimer]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Repeat Show,4,#TweenStep#
ActionList2=Repeat Hide,4,#TweenStep#
Show=[!SetVariable TweenNode "(Clamp(#TweenNode#+(100/#TweenStep#),0,100))"][!UpdateMeterGroup Tween][!UpdateMeasure ActionTimer][!Redraw]
Hide=[!SetVariable TweenNode "(Clamp(#TweenNode#-(100/#TweenStep#),0,100))"][!UpdateMeterGroup Tween][!UpdateMeasure ActionTimer][!Redraw]
DynamicVariables=1


;==============================================================================================
;==============================================================================================
;==============================================================================================



[B]
Meter=Shape
Shape=Rectangle 0,0,#GW#,#GH# | StrokeWidth 0 | Fill LinearGradient This
This=180 | #Grad.1# ; 0.0 | #Grad.2# ; 1.0
Shape2=Rectangle 0,0,#GW#,#GH# | StrokeWidth 0 | Fill Color #Accent.2#,(255*#TweenNode#/100)
Shape3=Rectangle 0,0,(7*#scale#),(#GH#) | StrokeWidth 0 | fill Color #Accent.0#,150
Shape4=Rectangle 0,(#GH#),(7*#scale#),(-#GH#*(Clamp([#PlayerType#Progress],0,100))/100) | StrokeWidth 0 | fill Color #Accent.0#
Shape5=Path That | StrokeWidth 0 | Fill Color #Accent.1#,(255*#TweenNode#/100) | OffSet (80*#scale#-80*#scale#*#Tweennode#/100),0
That=(#GW#-80*#scale#),0 | LineTo #GW#,0 | LineTo #GW#,#GH# | LineTo (#GW#-70*#Scale#),#GH# | ClosePath 1
DynamicVariables=1
MouseOverAction=[!CommandMeasure ActionTimer "Stop 2"][!CommandMeasure ActionTimer "Execute 1"]
MouseLeaveAction=[!CommandMeasure ActionTimer "Stop 1"][!CommandMeasure ActionTimer "Execute 2"]
UpdateDivider=1
Group=Tween

[I]
Meter=Image
MeasureName=#PlayerType#Cover
X=((7)*#scale#)
Y=0
W=(#GH#)
H=(#GH#)
PreserveAspectRatio=2
DynamicVariables=1
Group=Music

[SName]
Meter=String
MeterStyle=S
X=(#P#-(#TweenNode#/100*10*#scale#))R
Y=(#GH#/2-([SName:H]+[SArtist:H]+5*#scale#)/2)
W=([PlayPause:X]-#P#*3)
DynamicVariables=1
ClipString=1
FontSize=(16*#scale#)
FontColor=#Font.0#
FontWeight=600
FontFace=Roboto Bold
MeasureName=#PlayerType#Track
Group=Tween | Music
UpdateDivider=1
[SArtist]
Meter=String
MeterStyle=S
X=r
Y=(5*#scale#)R
W=([PlayPause:X]-#P#*3)
DynamicVariables=1
ClipString=1
FontSize=(12*#scale#)
FontColor=#Font.0#,150
FontFace=Roboto
Group=Music
MeasureName=#PlayerType#Artist

[PlayPause]
Meter=Image
MeterStyle=
X=(#GW#-#P#-25*#scale#)
Y=(#GH#/2-15*#scale#)
W=(30*#scale#)
H=(30*#scale#)
Grayscale=1
DynamicVariables=1
ImageAlpha=(255*#tWEENnODE#/100)
Group=Tween | Music
[Play]
ImageName=#@#Icons\Play.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Pause][!UpdateMeter PlayPause][!Redraw][!CommandMeasure State#NowPlayingMedia# "PlayPause"]
[Pause]
ImageName=#@#Icons\Pause.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw][!CommandMeasure State#NowPlayingMedia# "PlayPause"]
