[Variables]
GW=(450*#scale#)
GH=(250*#scale#)
P=(50*#Scale#)

Shuffle=0
Control=0
Repeat=0
Heart=0
Prog=1

;==============================================================================================
;==============================================================================================
;==============================================================================================


[IC]
Meter=Shape
X=(#GW#/2-#GH#/2)
Y=0
Shape=Rectangle 0,0,(#GH#),(#GH#),(#R#/2),(#R#/2) | StrokeWidth 0 | Fill RadialGradient This
This=0,0,0,0,(#GH#/2),(#GH#/2) | 0,0,0 ; 0.0 | 0,0,0,0 ; 0.5
Hidden=#HideAlbum#

[I]
Meter=Image
ImageName=[#PlayerType#Cover]
W=(#GH#)
H=(#GH#)
PreserveAspectRatio=2
Container=IC
Hidden=#HideAlbum#
DynamicVariables=1
Group=Music

[SName]
Meter=String
MeterStyle=S
X=(#GW#/2)
Y=(#GH#/2-#P#/4)
W=#GW#
UpdateDivider=1
ClipString=2
FontWeight=600
Text=%1
StringAlign=CenterBottom
FontSize=(20*#scale#)
FontColor=255,255,255
DynamicVariables=1
MeasureName=#PlayerType#Track
InlineSetting=Shadow | 0 | 0 | 2 | 0,0,0
Group=Music
[Line]
Meter=Shape
X=r
Y=(#GH#/2)
Shape=Line (-#GW#/2+#P#),0,(#GW#/2-#P#),0 | StrokeWidth 2 | StrokeStartCap Triangle | StrokeEndCap Triangle | Stroke Color 255,255,255,50
Shape2=Line (-#GW#/2+#P#),0,(-#GW#/2+#P#+(#GW#-#P#*2)*(Clamp([#PlayerType#Progress],0,100))/100),0 | StrokeWidth 2 | StrokeStartCap Triangle | StrokeEndCap Triangle | Stroke Color 255,255,255,255
DynamicVariables=1
UpdateDivider=1
[SArtist]
Meter=String
MeterStyle=S
X=r
Y=(#GH#/2+#P#/4)
W=#GW#
DynamicVariables=1
ClipString=1
StringAlign=Center
FontSize=(15*#scale#)
FontFace=Nunito Sans SemiBold
FontColor=255,255,255,150
MeasureName=#PlayerType#Artist
InlineSetting=Shadow | 0 | 0 | 2 | 0,0,0
Group=Music