[Variables]
GW=(460*#scale#)
GH=(90*#scale#)
P=(25*#Scale#)

Shuffle=0
Control=1
Repeat=0
Heart=0
Prog=0
;==============================================================================================
;==============================================================================================
;==============================================================================================


;==============================================================================================
;==============================================================================================
;==============================================================================================

[B]
Meter=Shape
Shape=Rectangle 4,4,#GW#,#GH#,#R#,#R# | StrokeWidth 4 | Fill LinearGradient This | Stroke LinearGradient That
This=270 | #Grad.1# ; 0.0 | #Grad.2# ; 1.0
That=90 | #Grad.1# ; 0.0 | #Grad.2# ; 1.0
DynamicVariables=1
DynamicVariables=1

[CreateShadow]
Measure=Plugin
Plugin=MagickMeter
DynamicVariables=1
Image2=Ellipse ([PlayPause:X]+18*#Scale#),([PlayPause:Y]+18*#Scale#),(20*#scale#) | Shadow 25,(5*#Scale#),4,4,1 ; 0,0,0
Image=Ellipse ([PlayPause:X]+18*#Scale#),([PlayPause:Y]+18*#Scale#),(20*#scale#) | Shadow 25,(5*#Scale#),-4,-4,1 ; 255,255,255

[SName]
Meter=String
MeterStyle=S
X=(#P#+4)
Y=(#GH#/2-([SName:H]+[SArtist:H]-5*#scale#)/2+4)
W=([PlayPause:X]-#P#*3)
DynamicVariables=1
UpdateDivider=(#Rm.Updiv#/1000)
ClipString=1
FontSize=(16*#scale#)
FontFace=Nunito Sans SemiBold
FontColor=#Font.0#
MeasureName=#PlayerType#Track
Group=Music
[SArtist]
Meter=String
MeterStyle=S
X=r
Y=(-5*#scale#)R
W=([PlayPause:X]-#P#*3)
DynamicVariables=1
ClipString=1
FontSize=(14*#scale#)
FontFace=Nunito Sans SemiBold
FontColor=#Font.0#,150
MeasureName=#PlayerType#Artist
Group=Music



[IShadow]
Meter=Image
MeasureName=CreateShadow

[PlayPauseBackground]
Meter=Shape
X=([PlayPause:X]+18*#Scale#)
Y=([PlayPause:Y]+18*#Scale#)
DynamicVariables=1
Shape=Ellipse 0,0,20 | StrokeWidth 2 | Fill LinearGradient This | Scale #Scale#,#Scale# | Stroke Color #Accent.2#
This=225 | #Accent.1# ; 0.0 | #Accent.2# ; 1.0

[PlayPause]
Meter=Image
MeterStyle=
X=(#GW#-#P#-38*#scale#+4)
Y=(#GH#/2-18*#scale#+4)
W=(16*#scale#)
H=(16*#scale#)
Padding=(10*#scale#),(10*#scale#),(10*#scale#),(10*#scale#)
Grayscale=1
ImageTint=#Font.0#
DynamicVariables=1
Group=DynamicColors
[Play]
ImageName=#@#Icons\Play.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Pause][!UpdateMeter PlayPause][!Redraw][!CommandMeasure State#NowPlayingMedia# "PlayPause"]
[Pause]
ImageName=#@#Icons\Pause.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw][!CommandMeasure State#NowPlayingMedia# "PlayPause"]
