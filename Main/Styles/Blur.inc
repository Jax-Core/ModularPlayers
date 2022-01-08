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
OnChangeAction=[!CommandMeasure CreateShadow "Reload Image"][!UpdateMeter *][!Redraw]
UpdateDivider=1


;==============================================================================================
;==============================================================================================
;==============================================================================================

[B]
Meter=Shape
Shape=Rectangle 0,0,#GW#,#GH#,#R#,#R# | StrokeWidth 0 | Fill Color #MainColor#
DynamicVariables=1

[ImageProcess]
Measure=Plugin
Plugin=MagickMeter
Image=File [#PlayerType#Cover] | Blur #BlurRadius#,#BlurSigma# | Modulate #BlurModulate#
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

[IShadow]
Meter=Image
MeasureName=CreateShadow

[IC]
Meter=Shape
Shape=Ellipse (#GH#/2),(#GH#/2),((#GH#-#P#*2)/2),((#GH#-#P#*2)/2) | StrokeWidth 0

[I]
Meter=Image
MeasureName=#PlayerType#Cover
X=#P#
Y=#P#
W=(#GH#-#P#*2)
H=(#GH#-#P#*2)
Container=IC
DynamicVariables=1
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
InlineSetting3=Shadow | 0 | 0 | 2 | ([Lum] > #LumHnld# ? 0 : 255),([Lum] > #LumHnld# ? 0 : 255),([Lum] > #LumHnld# ? 0 : 255),150
DynamicVariables=1
Group=DynamicColors
MeasureName=#PlayerType#Track
MeasureName2=#PlayerType#Artist
FontFace=IBM Plex Sans Semibold