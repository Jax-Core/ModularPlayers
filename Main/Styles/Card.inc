[Variables]
GW=(440*#Scale#)
GH=(250*#Scale#)
P=(17*#Scale#)
LumHnld=0.506

Shuffle=1
Control=1
Repeat=1
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
OnChangeAction=[!UpdateMeterGroup DynamicColors]
UpdateDivider=1


;==============================================================================================
;==============================================================================================
;==============================================================================================

[B]
Meter=Shape
Shape=Rectangle 0,0,#GW#,#GH#,#R#,#R# | StrokeWidth 0 | Fill Color #MainColor#,#MainOpacity#
DynamicVariables=1

[ImageProcess]
Measure=Plugin
Plugin=MagickMeter
Image=Rectangle #P#,#P#,(#GW#-#P#*2),(#GH#-#P#*2-40*#Scale#),(#R#/2),(#R#/2) | Shadow 100,10,0,(5*#scale#),1 ; [AC]
Disabled=#ColorMode#
DynamicVariables=1

[ImageGlow]
Meter=Image
Hidden=#ColorMode#
MeasureName=ImageProcess

[IC]
Meter=Shape
X=#P#
Y=#P#
Shape=Rectangle 0,0,(#GW#-#P#*2),(#GH#-#P#*2-40*#Scale#),(#R#/2),(#R#/2)  | StrokeWidth 0

[I]
Meter=Image
MeasureName=#PlayerType#Cover
W=(#GW#-#P#*2)
H=(#GH#-#P#*2-40*#Scale#)
PreserveAspectRatio=2
Container=IC
DynamicVariables=1

[FadeOut]
Meter=Shape
X=#P#
Y=#P#
Shape=Rectangle 0,0,(#GW#-#P#*2),(#GH#-#P#*2-40*#Scale#),(#R#/2),(#R#/2) | StrokeWidth 0  | Fill LinearGradient This
This=270 | [AC]00 ; 0.5 | [AC]C8 ; 1.0
DynamicVariables=1
Group=DynamicColors


[SName]
Meter=String
MeterStyle=S
X=(7.5*#scale#)r
Y=(-20*#scale#)R
W=(#GW#-#P#*3)
ClipString=1
StringAlign=LeftCenter
FontWeight=600
Text=%1 - %2
FontSize=(15*#scale#)
FontColor=([Lum] > #LumHnld# ? 0 : 255),([Lum] > #LumHnld# ? 0 : 255),([Lum] > #LumHnld# ? 0 : 255)
InLinePattern=-.*
InlineSetting=Size | (10*#scale#)
InLinePattern2=-.*
InlineSetting2=Weight | 450
DynamicVariables=1
Group=DynamicColors
MeasureName=#PlayerType#Track
MeasureName2=#PlayerType#Artist

[Shuffle]
Meter=Image
ImageName=#@#Icons\Shuffle.png
X=((#GW#-(30*11)*#scale#)/2)
Y=(#GH#-30*#Scale#-#P#)
W=(30*#Scale#)
H=(30*#Scale#)
Group=Music
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
DynamicVariables=1
ImageTint=#OppositeColor#
[Shuffle0]
ImageAlpha=150
LeftMouseUpAction=[!SetOption Shuffle MeterStyle Shuffle1][!UpdateMeter Shuffle][!Redraw][!CommandMeasure State#NowPlayingMedia# "Shuffle"]
[Shuffle1]
ImageAlpha=255
LeftMouseUpAction=[!SetOption Shuffle MeterStyle Shuffle0][!UpdateMeter Shuffle][!Redraw][!CommandMeasure State#NowPlayingMedia# "Shuffle"]

[Previous]
Meter=Image
ImageName=#@#Icons\Previous.png
X=(30*#Scale#)R
Y=r
W=(30*#Scale#)
H=(30*#Scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
Group=Music
ImageTint=#OppositeColor#
LeftMouseUpAction=[!CommandMeasure State#NowPlayingMedia# "Previous"]
DynamicVariables=1


[PlayPause]
Meter=Image
MeterStyle=
X=(30*#Scale#)R
Y=r
W=(30*#Scale#)
H=(30*#Scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
Group=Music
ImageTint=#OppositeColor#
DynamicVariables=1
[Play]
ImageName=#@#Icons\Play.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Pause][!UpdateMeter PlayPause][!Redraw][!CommandMeasure State#NowPlayingMedia# "PlayPause"]
[Pause]
ImageName=#@#Icons\Pause.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw][!CommandMeasure State#NowPlayingMedia# "PlayPause"]

[Next]
Meter=Image
ImageName=#@#Icons\Next.png
X=(30*#Scale#)R
Y=r
W=(30*#Scale#)
H=(30*#Scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
Group=Music
ImageTint=#OppositeColor#
LeftMouseUpAction=[!CommandMeasure State#NowPlayingMedia# "Next"]
DynamicVariables=1

[Repeat]
Meter=Image
X=(30*#Scale#)R
Y=r
W=(30*#Scale#)
H=(30*#Scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
Group=Music
ImageTint=#OppositeColor#
DynamicVariables=1
LeftMouseUpAction=[!CommandMeasure State#NowPlayingMedia# "Repeat"]
[Repeat0]
ImageAlpha=150
ImageName=#@#Icons\Repeat.png
LeftMouseUpAction=[!SetOption Repeat MeterStyle Repeat1][!UpdateMeter Repeat][!Redraw][!CommandMeasure State#NowPlayingMedia# "Repeat"]
[Repeat1]
ImageAlpha=255
ImageName=#@#Icons\Repeat.png
LeftMouseUpAction=[!SetOption Repeat MeterStyle Repeat2][!UpdateMeter Repeat][!Redraw][!CommandMeasure State#NowPlayingMedia# "Repeat"]
[Repeat2]
ImageAlpha=255
ImageName=#@#Icons\RepeatOne.png
LeftMouseUpAction=[!SetOption Repeat MeterStyle Repeat0][!UpdateMeter Repeat][!Redraw][!CommandMeasure State#NowPlayingMedia# "Repeat"]