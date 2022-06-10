[Variables]
GW=(#Scale#*#W#)
GH=(#Scale#*#H#)

Shuffle=1
Control=1
Repeat=0
Heart=1
Prog=1

[String:S]
FontFace=#FontFace#
FontSize=(10*#scale#)
AntiAlias=1
FontColor=#FontColor#
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[B]
Meter=Shape
Shape=Rectangle 0,0,#GW#,#GH#,#R# | StrokeWidth #Stroke# | Fill Color #PrimaryColor#,#PrimaryOpacity# | Stroke Color #SecondaryColor#,#SecondaryOpacity#
Group=Music
[C]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,#GW#,#GH#,#R# | StrokeWidth 0
Group=Music 


[ImageFade]
Meter=Image
W=(#GW#)
H=(#GH#)
PreserveAspectRatio=2
MaskImageName=#@#Images\FadeMask.png
ImageName=[#PlayerType#Cover]
DynamicVariables=1
Group=Music | MediaImage
Container=C

[MusicIcon]
Meter=String
MeterStyle=String:S
X=(#P#)
Y=(#P#)
Text=[\xe3a1]
FontFace=Material Icons Round
FontSize=(12*#Scale#)
Group=Music
Container=C

[Name]
Meter=String
MeterStyle=String:S
X=(#P#*3)
Y=r
W=(#GW#-(80*#Scale#)-3*#P#)
ClipString=1
Text=[#PlayerType#Player]
DynamicVariables=1
FontSize=(9*#Scale#)
Group=Music
Container=C

[Track]
Meter=String
MeterStyle=String:S
X=(#P#)
Y=(#P#)R
W=(#GW#-(80*#Scale#)-3*#P#)
ClipString=1
Text=[#PlayerType#Track]
DynamicVariables=1
FontSize=(12*#Scale#)
FontWeight=650
Group=Music
Container=C

[Artist]
Meter=String
MeterStyle=String:S
X=r
Y=(5*#Scale#)R
W=(#GW#-(80*#Scale#)-3*#P#)
ClipString=1
Text=[#PlayerType#Artist]
DynamicVariables=1
Group=Music
Container=C

[ProgBar]
Meter=Shape
X=#P#
Y=(110*#scale#)
Shape=Line 0,0,(#GW#-#P#*2),0 | StrokeWidth 2 | Fill Color 0,0,0,1 | Stroke Color #FontColor2# | StrokeStartCap Round | StrokeEndCap Round
Shape2=Line 0,0,((#GW#-#P#*2)*(Clamp([#PlayerType#Progress],0,100))/100),0 | StrokeWidth 2 | Fill Color 0,0,0,1 | Stroke Color #AccentColor# | StrokeStartCap Round | StrokeEndCap Round
Shape3=Ellipse ((#GW#-#P#*2)*(Clamp([#PlayerType#Progress],0,100))/100),0,(#DotSize#/4),(#DotSize#/4) | strokeWidth 0 | Fill Color #AccentColor# | Scale #Scale#,#Scale#
LeftMouseUpAction=[!SetOption PosCalc Formula "($MouseX$/(#GW#-#P#*2)*100)"][!UpdateMeasure PosCalc]
DynamicVariables=1
UpdateDivider=1
Group=Music
Container=C
[PosCalc]
Measure=calc
OnUpdateAction=[!CommandMeasure state#NowPlayingMedia# "SetPosition [PosCalc]"][!UpdateMeasure #PlayerType#Progress]
Disabled=1
DynamicVariables=1
UpdateDivider=-1
Group=NUOL
[Current]
Meter=String
MeterStyle=String:S
X=r
Y=R
FontColor=#FontColor2#
DynamicVariables=1
UpdateDivider=1
FontSize=(8*#scale#)
MeasureName=#PlayerType#CurrentPosition
Group=Music
Container=C
[Length]
Meter=String
MeterStyle=String:S
X=(#GW#-#P#*2)r
Y=r
FontColor=#FontColor2#
StringAlign=Right
DynamicVariables=1
FontSize=(8*#scale#)
MeasureName=#PlayerType#Length
Group=Music
Container=C

[Heart]
Meter=Image
X=(#GW#/2-(20*5*#scale#+#P#*2*4)/2)
Y=(20*#scale#)R
X=(#P#*2)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Grayscale=1
ImageTint=#FontColor#
DynamicVariables=1
Group=Music
Container=C
[FullHeart]
ImageName=#@#Icons\HeartFull.png
LeftMouseUpAction=[!SetOption #CURRENTSECTION# MeterStyle "EmptyHeart"][!UpdateMeter #CURRENTSECTION#][!Redraw][!CommandMeasure state#NowPlayingMedia# "ToggleThumbsDown"]
[EmptyHeart]
ImageName=#@#Icons\Heart.png
LeftMouseUpAction=[!SetOption #CURRENTSECTION# MeterStyle "Fullheart"][!UpdateMeter #CURRENTSECTION#][!Redraw][!CommandMeasure state#NowPlayingMedia# "ToggleThumbsUp"]

[Prev]
Meter=Image
ImageName=#@#Icons\Previous.png
LeftMouseUpAction=[!CommandMeasure state#NowPlayingMedia# "Previous"]
X=(#P#*2)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Grayscale=1
ImageTint=#FontColor#
DynamicVariables=1
Group=Music
Container=C

[PlayPause]
Meter=Image
X=(#P#*2)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Grayscale=1
ImageTint=#FontColor#
DynamicVariables=1
Group=Music
Container=C
[Play]
ImageName=#@#Icons\Play.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Pause][!UpdateMeter PlayPause][!Redraw][!CommandMeasure State#NowPlayingMedia# "PlayPause"]
[Pause]
ImageName=#@#Icons\Pause.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw][!CommandMeasure State#NowPlayingMedia# "PlayPause"]

[Next]
Meter=Image
ImageName=#@#Icons\Next.png
LeftMouseUpAction=[!CommandMeasure state#NowPlayingMedia# "Next"]
X=(#P#*2)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Grayscale=1
ImageTint=#FontColor#
DynamicVariables=1
Group=Music
Container=C

[Shuffle]
Meter=Image
ImageName=#@#Icons\Shuffle.png
X=(#P#*2)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Grayscale=1
ImageTint=#FontColor#
DynamicVariables=1
Group=Music
Container=C
[Shuffle0]
ImageAlpha=150
LeftMouseUpAction=[!SetOption Shuffle MeterStyle "Shuffle1"][!UpdateMeter Shuffle][!Redraw][!CommandMeasure state#NowPlayingMedia# "Shuffle"]
[Shuffle1]
ImageAlpha=255
LeftMouseUpAction=[!SetOption Shuffle MeterStyle "Shuffle0"][!UpdateMeter Shuffle][!Redraw][!CommandMeasure state#NowPlayingMedia# "Shuffle"]


[Image]
Meter=Image
X=(#GW#-(80*#Scale#)-#P#)
Y=#P#
W=(80*#Scale#)
H=(80*#Scale#)
PreserveAspectRatio=2
MaskImageName=#@#Images\Mask.png
ImageName=[#PlayerType#Cover]
DynamicVariables=1
Group=Music | MediaImage
Container=C