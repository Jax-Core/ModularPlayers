[Rainmeter]
SkinWidth=(#SW#)
Skinheight=#SW#
; BackgroundMode=2
; SolidColor=255,255,255,25

[Variables]
GW=(450*#scale#)
GH=(120*#scale#)
SW=(500*#Scale#)
P=(10*#Scale#)


;==============================================================================================
;==============================================================================================
;==============================================================================================

[MagickMeter]
Measure=Plugin
Plugin=MagickMeter
DynamicVariables=1
Image=Rectangle (#SW#/2-#GW#/2),(#SW#/2-#GH#/2),#GW#,#GH#,#R#  | Color EFEEEE | Shadow 50,5,6,6 ; 000000 | Shadow 50,5,-6,-6 ; FFFFFF
UpdateDivider=-1
[I]
Meter=Image
MeasureName=MagickMeter

; [SName]
; Meter=String
; MeterStyle=S
; X=#P#R
; Y=((#GH#-#P#*2)/2-30/2)r
; W=(#GW#-(#P#*2+(#GH#-#P#*2)))
; ClipString=2
; StringAlign=LeftCenter
; FontWeight=600
; Text=%1#CRLF#%2
; FontSize=(15*#scale#)
; FontColor=255,255,255
; InLinePattern=#CRLF#(.*)
; InlineSetting=Size | (10*#scale#)
; InLinePattern2=#CRLF#(.*)
; InlineSetting2=Weight | 450
; InLinePattern3=#CRLF#(.*)
; InlineSetting3=Color | 255,255,255,150
; DynamicVariables=1
; MeasureName=mTrack
; MeasureName2=mArtist

; [Previous]
; Meter=Image
; ImageName=#@#Icons\Previous.png
; X=r
; Y=(#GH#-30*#scale#-#P#)
; W=(20*#scale#)
; H=(20*#scale#)
; Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
; Grayscale=1
; ImageTint=[FGC2]
; DynamicVariables=1
; Group=DynamicColors
; LeftMouseUpAction=[!CommandMeasure mState "Previous"]


; [PlayPause]
; Meter=Image
; MeterStyle=
; X=(20*#Scale#)R
; Y=r
; W=(20*#scale#)
; H=(20*#scale#)
; Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
; Grayscale=1
; ImageTint=[FGC2]
; DynamicVariables=1
; Group=DynamicColors
; [Play]
; ImageName=#@#Icons\Play.png
; LeftMouseUpAction=[!SetOption PlayPause MeterStyle Pause][!UpdateMeter PlayPause][!Redraw][!CommandMeasure mState "PlayPause"]
; [Pause]
; ImageName=#@#Icons\Pause.png
; LeftMouseUpAction=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw][!CommandMeasure mState "PlayPause"]

; [Next]
; Meter=Image
; ImageName=#@#Icons\Next.png
; X=(20*#Scale#)R
; Y=r
; W=(20*#scale#)
; H=(20*#scale#)
; Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
; Grayscale=1
; ImageTint=[FGC2]
; DynamicVariables=1
; Group=DynamicColors
; LeftMouseUpAction=[!CommandMeasure mState "Next"]