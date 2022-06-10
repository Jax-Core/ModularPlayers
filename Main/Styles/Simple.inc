[Variables]
GW=(470*#scale#)
GH=(130*#scale#)
P=(20*#Scale#)

Shuffle=0
Control=1
Repeat=0
Heart=0
Prog=1
;==============================================================================================
;==============================================================================================
;==============================================================================================


;==============================================================================================
;==============================================================================================
;==============================================================================================

[B]
Meter=Shape
Shape=Rectangle 0,0,#GW#,#GH#,#R#,#R# | StrokeWidth 0 | Fill Color #Maincolor#
DynamicVariables=1

[SName]
Meter=String
MeterStyle=S
X=#P#
Y=(20*#scale#)r
W=([Previous:X]-40*#scale#)
DynamicVariables=1
ClipString=1
FontSize=(20*#scale#)
FontFace=Bebas Kai
MeasureName=#PlayerType#Track
Group=Music
[SArtist]
Meter=String
MeterStyle=S
X=r
Y=R
W=([Previous:X]-40*#scale#)
DynamicVariables=1
ClipString=1
FontWeight=600
FontSize=(10*#scale#)
MeasureName=#PlayerType#Artist
MeasureName2=#PlayerType#CurrentPosition
MeasureName3=#PlayerType#Length
Text=%1#CRLF#%2/%3
InlinePattern=#CRLF#.*
InlineSetting=Color | #OppositeColor#,200
UpdateDivider=1
Group=Music

[PlayPauseBackground]
Meter=Shape
X=([PlayPause:X]+10*#Scale#)
Y=([PlayPause:Y]+10*#Scale#)
DynamicVariables=1
Shape=Ellipse 0,0,25 | StrokeWidth 0 | Fill Color #Accent.1#,50 | Scale #Scale#,#Scale#
Shape2=Ellipse 0,0,20 | StrokeWidth 0 | Fill LinearGradient This | Scale #Scale#,#Scale#
This=0 | #Accent.1# ; 0.0 | #Accent.2# ; 1.0


[Previous]
Meter=Image
ImageName=#@#Icons\Previous.png
X=(#GW#-#P#-140*#scale#)
Y=(#GH#/2-10*#scale#)
W=(20*#scale#)
H=(20*#scale#)
Grayscale=1
ImageTint=#OppositeColor#
DynamicVariables=1
Group=Music
LeftMouseUpAction=[!CommandMeasure State#NowPlayingMedia# "Previous"]


[PlayPause]
Meter=Image
MeterStyle=
X=(40*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Grayscale=1
ImageTint=#OppositeColor#
DynamicVariables=1
Group=Music
[Play]
ImageName=#@#Icons\Play.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Pause][!UpdateMeter PlayPause][!Redraw][!CommandMeasure State#NowPlayingMedia# "PlayPause"]
[Pause]
ImageName=#@#Icons\Pause.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw][!CommandMeasure State#NowPlayingMedia# "PlayPause"]

[Next]
Meter=Image
ImageName=#@#Icons\Next.png
X=(40*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Grayscale=1
ImageTint=#OppositeColor#
DynamicVariables=1
Group=Music
LeftMouseUpAction=[!CommandMeasure State#NowPlayingMedia# "Next"]

[ProgBar]
Meter=Shape
X=#P#
Y=(#GH#-#P#)
Shape=Line 0,0,(#GW#-#P#*2),0 | StrokeWidth 2 | Fill Color 0,0,0,1 | Stroke Color #OppositeColor#,50 | StrokeStartCap Round | StrokeEndCap Round
Shape2=Line 0,0,((#GW#-#P#*2)*(Clamp([#PlayerType#Progress],0,100))/100),0 | StrokeWidth 4 | Fill Color 0,0,0,1 | Stroke LinearGradient This | StrokeStartCap Round | StrokeEndCap Round
This=0 | #Accent.1# ; 0.0 | #Accent.2# ; 1.0
DynamicVariables=1
UpdateDivider=1
Group=Music
LeftMouseUpAction=[!SetOption PosCalc Formula "($MouseX$/(#GW#-#P#*2)*100)"][!UpdateMeasure PosCalc]
[PosCalc]
Measure=calc
OnUpdateAction=[!CommandMeasure State#NowPlayingMedia# "SetPosition [PosCalc]"]
Disabled=1
DynamicVariables=1
UpdateDivider=-1
Group=NUOL
