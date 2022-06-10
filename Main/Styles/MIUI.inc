[Variables]
GW=(450*#scale#)
GH=(170*#scale#)
P=(22*#Scale#)


Shuffle=0
Control=1
Repeat=0
Heart=1
Prog=1
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

[LC1]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Light1
UpdateDivider=1

[BGC]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Background1
UpdateDivider=1

[FGC1]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Foreground1
UpdateDivider=1

[FGC2]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Foreground2
UpdateDivider=1

; [AvC]
; Measure=Plugin
; Plugin=Chameleon
; Parent=MainC
; Color=Average
; Group=Music

[Luminance]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Luminance
OnChangeAction=[!UpdateMeterGroup DynamicColors]
UpdateDivider=1

; [BackgroundColor]
; Measure=Calc
; IfConditionMode=1
; IfCondition=Luminance > 1
; IfTrueAction=[!SetVariable BackgroundColor "[FGC1]"][!SetVariable TextColor "[BGC]"][!SetVariable AltTextColor "[BGC]"]
; IfFalseAction=[!SetVariable BackgroundColor "[BGC]"][!SetVariable TextColor "[FGC2]"][!SetVariable AltTextColor "[FGC1]"]
; ; IfCondition2=Luminance > 0.5
; ; IfTrueAction2=[!SetVariable ContrastTextColor "0,0,0"]
; ; IfFalseAction2=[!SetVariable ContrastTextColor "255,255,255"]
; OnUpdateAction=

;==============================================================================================
;==============================================================================================
;==============================================================================================

[B]
Meter=Shape
Shape=Rectangle 0,0,#GW#,#GH#,#R#,#R# | StrokeWidth 0 | Fill Color [BGC]
DynamicVariables=1
Group=DynamicColors

[IC]
Meter=Shape
Shape=Rectangle 0,0,#GW#,#GH#,#R#,#R# | StrokeWidth 0 | Fill LinearGradient MyFillGradient
MyFillGradient=180 | 0,0,0,0 ; 0.65 | 0,0,255,255 ; 1.0
DynamicVariables=1

[I]
Meter=Image
ImageName=[#PlayerType#Cover]
X=(#GW#-#GH#)
W=#GH#
H=#GH#
PreserveAspectRatio=2
Container=IC
DynamicVariables=1
Group=Music

[SHead]
Meter=String
MeterStyle=S
X=#P#
Y=(#P#-5)
W=(#GW#-#GH#)
ClipString=2
FontWeight=400
Text=[#PlayerType#Player]
FontSize=(8*#scale#)
FontColor=[FGC2]60
DynamicVariables=1
Group=DynamicColors | Music

[SName]
Meter=String
MeterStyle=S
X=r
Y=(20*#scale#)r
W=(#GW#-#GH#)
H=(#GH#-2*#P#-(#GH#-[SArtist:Y]))
ClipString=1
FontWeight=600
FontSize=(15*#scale#)
FontColor=[FGC2]
DynamicVariables=1
MeasureName=#PlayerType#Track
Group=DynamicColors | Music
[SArtist]
Meter=String
MeterStyle=S
X=r
Y=(#GH#*0.42)
W=(#GW#-#GH#)
ClipString=1
FontWeight=600
FontSize=(8*#scale#)
FontColor=[FGC1]
DynamicVariables=1
MeasureName=#PlayerType#Artist
Group=DynamicColors | Music

[Heart]
Meter=Image
X=#P#
Y=(#GH#*0.6)
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=[FGC2]
DynamicVariables=1
Group=DynamicColors
[FullHeart]
ImageName=#@#Icons\HeartFull.png
LeftMouseUpAction=[!SetOption Heart MeterStyle EmptyHeart][!UpdateMeter Heart][!Redraw][!CommandMeasure State#NowPlayingMedia# "ToggleThumbsDown"]
[EmptyHeart]
ImageName=#@#Icons\Heart.png
LeftMouseUpAction=[!SetOption Heart MeterStyle Fullheart][!UpdateMeter Heart][!Redraw][!CommandMeasure State#NowPlayingMedia# "ToggleThumbsUp"]


[Previous]
Meter=Image
ImageName=#@#Icons\Previous.png
X=(20*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=[FGC2]
DynamicVariables=1
Group=DynamicColors
LeftMouseUpAction=[!CommandMeasure State#NowPlayingMedia# "Previous"]


[PlayPause]
Meter=Image
MeterStyle=
X=(20*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=[FGC2]
DynamicVariables=1
Group=DynamicColors
[Play]
ImageName=#@#Icons\Play.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Pause][!UpdateMeter PlayPause][!Redraw][!CommandMeasure State#NowPlayingMedia# "PlayPause"]
[Pause]
ImageName=#@#Icons\Pause.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw][!CommandMeasure State#NowPlayingMedia# "PlayPause"]

[Next]
Meter=Image
ImageName=#@#Icons\Next.png
X=(20*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=[FGC2]
DynamicVariables=1
Group=DynamicColors
LeftMouseUpAction=[!CommandMeasure State#NowPlayingMedia# "Next"]

[ProgBar]
Meter=Shape
X=#P#
Y=(#GH#*0.85)
Shape=Line 0,0,(#GW#-#P#*2),0 | StrokeWidth 2 | Fill Color 0,0,0,1 | Stroke Color [FGC2]60 | StrokeStartCap Round | StrokeEndCap Round
Shape2=Line 0,0,((#GW#-#P#*2)*(Clamp([#PlayerType#Progress],0,100))/100),0 | StrokeWidth 2 | Fill Color 0,0,0,1 | Stroke Color [FGC2] | StrokeStartCap Round | StrokeEndCap Round
Shape3=Ellipse ((#GW#-#P#*2)*(Clamp([#PlayerType#Progress],0,100))/100),0,4,4 | strokeWidth 0 | Fill Color [FGC2] | Scale #Scale#,#Scale#
DynamicVariables=1
UpdateDivider=1
Group=DynamicColors
LeftMouseUpAction=[!SetOption PosCalc Formula "($MouseX$/(#GW#-#P#*2)*100)"][!UpdateMeasure PosCalc]
[PosCalc]
Measure=calc
OnUpdateAction=[!CommandMeasure State#NowPlayingMedia# "SetPosition [PosCalc]"]
Disabled=1
DynamicVariables=1
UpdateDivider=-1
Group=NUOL

[CurrentTime]
Meter=String
MeterStyle=S
X=r
Y=R
FontColor=[FGC2]
DynamicVariables=1
FontSize=(8*#scale#)
MeasureName=#PlayerType#CurrentPosition
UpdateDivider=1
Group=DynamicColors | Music
[MediaLength]
Meter=String
MeterStyle=S
X=(#GW#-#P#*2)r
Y=r
FontColor=[FGC2]
StringAlign=Right
DynamicVariables=1
FontSize=(8*#scale#)
MeasureName=#PlayerType#Length
Group=DynamicColors | Music