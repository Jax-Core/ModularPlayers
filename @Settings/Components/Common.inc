[Variables]
@includeV=#@#Vars.inc
@includeVer=#@#Version.inc
SettingsSize=(#SCREENAREAWIDTH#/1920)
SetTP=20
SetW=(1200*#SettingsSize#)
SetH=(700*#SettingsSize#)
SetL=200
SetR=20
SetSH=(#SetH#+#SetTP#*2)

[mL]
Measure=Calc
onupdateaction=[!FadeDuration 500][!KeepOnScreen 0][!Delay 100][!EnableMeasureGroup NUOL]



[sString]
FontFace=Roboto
AntiAlias=1
FontSize=12
FontColor=255,255,255
Container=ContentContainer
SolidColor=0,0,0,1
[Divider]
X=r
y=15R
Container=ContentContainer
Shape=Line 0,0,(#SetW#-#SetL#-#SetTP#*3),0 | StrokeWidth 1 | Fill Color 0,0,0,0 | Stroke Color 255,255,255,25
[TextBox]
X=(#SetW#-#SetL#-#SetTP#*2-150)
Container=ContentContainer
DynamicVariables=1
Shape=Rectangle 0,0,150,30,3,3 | StrokeWidth 2 | Fill Color 0,0,0,1 | Extend Fill
Fill=Stroke Color 255,255,255,50
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color 255,255,255,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color 255,255,255,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=[!SetVariable Editing "#CURRENTSECTION#"][!SetOption Input X "([#CURRENTSECTION#:X]+5)"][!SetOption Input Y "([#CURRENTSECTION#:Y]+5)"][!CommandMeasure Input "ExecuteBatch ALl"]
[Value]
X=5r
Y=15r
StringAlign=LeftCenter
FontSize=10
DynamicVariables=1
[Bool]
X=(#SetW#-#SetL#-#SetTP#*2-50)
Shape=Rectangle 0,0,50,20,10,10 | StrokeWidth 0 | Extend Fill
Shape2=Ellipse ([##CURRENTSECTION#] = 1 ? 40 : 10),10,5,5 | StrokeWidth 0 | Fill Color 255,255,255
DynamicVariables=1
Fill=Fill Color ([##CURRENTSECTION#] = 1 ? 35 : 181),([##CURRENTSECTION#] = 1 ? 209 : 181),([##CURRENTSECTION#] = 1 ? 96 : 181)
Container=ContentContainer
Leftmouseupaction=[!WriteKeyvalue Variables "#CURRENTSECTION#" "([##CURRENTSECTION#] = 1 ? 0 : 1)" "#@#Vars.inc"][!Refresh][!Delay 1000][!Refresh "ModularPlayers\Main"]

[ShowInToolbar]
Measure=Plugin
Plugin=ShowInToolbar
WindowTitle=JaxOriginals - #CURRENTCONFIG#
WindowIcon=Logo.ico

[B]
Meter = Image
ImageName=#@#Images\SetBack.png

[Logo]
Meter=Image
ImageName=Logo.png
X=(#SetTP#)
Y=#SetTp#
W=64
H=64
[SettingsText]
Meter=String
MeterStyle=sString
Text=Players
X=R
Y=(64/2)r
StringAlign=LeftCenter
FontSize=14
FontWeight=500
Container=

;===========================================================================================================================
;===========================================================================================================================

[GeneralCategory]
Meter=String
MeterStyle=sString
Text=GENERAL
FontFace=Segoe UI
X=#setTP#
Y=(#setTP#*2+64)
StringAlign=Left
FontSize=8
Container=
FontColor=150,150,150

;===========================================================================================================================
;===========================================================================================================================

[PageBox]
X=#setTP#
Y=([#CURRENTSECTION#Icon:Y]-#SetTP#/2)
Shape=Rectangle 0,2.5,(#SetL#-#SetTP#*1.5),(24+#SetTP#-5),7,7 | StrokeWidth 0 | Extend Fill
Leftmouseupaction=[!ActivateConfig "ModularPlayers\@Settings" "#CURRENTSECTION#.ini"][!DeactivateConfig "ModularPlayers\@Settings\Components"]
DynamicVariables=1
[Info]
Meter=Shape
MeterStyle=PageBox
Fill=Fill Color 255,255,255,(#BarHandler# = 1 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 1 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 1 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Appearance]
Meter=Shape
MeterStyle=PageBox
Fill=Fill Color 255,255,255,(#BarHandler# = 2 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 2 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 2 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
; [Layout]
; Meter=Shape
; MeterStyle=PageBox
; Fill=Fill Color 255,255,255,(#BarHandler# = 3 ? 220 : 0)
; MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 3 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
; MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 3 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[General]
Meter=Shape
MeterStyle=PageBox
Fill=Fill Color 255,255,255,(#BarHandler# = 4 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 4 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 4 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
; [Media]
; Meter=Shape
; MeterStyle=PageBox
; Fill=Fill Color 255,255,255,(#BarHandler# = 5 ? 220 : 0)
; MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 5 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
; MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 5 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
; [Render]
; Meter=Shape
; MeterStyle=PageBox
; Fill=Fill Color 255,255,255,(#BarHandler# = 6 ? 220 : 0)
; MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 6 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
; MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 6 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

;===========================================================================================================================
;===========================================================================================================================

[PageIcon]
ImageName=Components\Icons\#CURRENTSECTION#.png
X=r
Y=(20+24)r
W=24
H=24
DynamicVariables=1
ImageAlpha=200
[InfoIcon]
Meter=Image
X=(#setTP#*1.5)
Y=(#setTP#*4+64)
MeterStyle=PageIcon
Greyscale=(#BarHandler# = 1 ? 1 : 0)
ImageTint=(#BarHandler# = 1 ? 0 : 255),(#BarHandler# = 1 ? 0 : 255),(#BarHandler# = 1 ? 0 : 255)
[AppearanceIcon]
Meter=Image
MeterStyle=PageIcon
Greyscale=(#BarHandler# = 2 ? 1 : 0)
ImageTint=(#BarHandler# = 2 ? 0 : 255),(#BarHandler# = 2 ? 0 : 255),(#BarHandler# = 2 ? 0 : 255)
; [LayoutIcon]
; Meter=Image
; MeterStyle=PageIcon
; Greyscale=(#BarHandler# = 3 ? 1 : 0)
; ImageTint=(#BarHandler# = 3 ? 0 : 255),(#BarHandler# = 3 ? 0 : 255),(#BarHandler# = 3 ? 0 : 255)
[GeneralIcon]
Meter=Image
MeterStyle=PageIcon
Greyscale=(#BarHandler# = 4 ? 1 : 0)
ImageTint=(#BarHandler# = 4 ? 0 : 255),(#BarHandler# = 4 ? 0 : 255),(#BarHandler# = 4 ? 0 : 255)
; [MediaIcon]
; Meter=Image
; MeterStyle=PageIcon
; Greyscale=(#BarHandler# = 5 ? 1 : 0)
; ImageTint=(#BarHandler# = 5 ? 0 : 255),(#BarHandler# = 5 ? 0 : 255),(#BarHandler# = 5 ? 0 : 255)
; [RenderIcon]
; Meter=Image
; MeterStyle=PageIcon
; Greyscale=(#BarHandler# = 6 ? 1 : 0)
; ImageTint=(#BarHandler# = 6 ? 0 : 255),(#BarHandler# = 6 ? 0 : 255),(#BarHandler# = 6 ? 0 : 255)

;===========================================================================================================================
;===========================================================================================================================

[PageText]
X=r
Y=44r
Container=
StringAlign=LeftCenter
FontColor=(#BarHandler# = #CURRENTSECTION# ? 0 : 255),(#BarHandler# = #CURRENTSECTION# ? 0 : 255),(#BarHandler# = #CURRENTSECTION# ? 0 : 255),(#BarHandler# = #CURRENTSECTION# ? 255 : 200)
FontSize=10
[1]
Meter=String
Text=Info
X=(#setTP#*1.5+24+5)
Y=([InfoIcon:Y]+24/2)
DynamicVariables-1
MeterStyle=sString | PageText
[2]
Meter=String
Text=Appearance
MeterStyle=sString | PageText
; [3]
; Meter=String
; Text=Layout
; MeterStyle=sString | PageText
[4]
Meter=String
Text=General
MeterStyle=sString | PageText
; [5]
; Meter=String
; Text=Media
; MeterStyle=sString | PageText
; [6]
; Meter=String
; Text=Render
; MeterStyle=sString | PageText

;===========================================================================================================================
;===========================================================================================================================


[HelpCategory]
Meter=String
MeterStyle=sString
Text=HELP
FontFace=Segoe UI
X=#setTP#
Y=(#SetH#-100)
StringAlign=Left
FontSize=8
Container=
FontColor=150,150,150

;===========================================================================================================================
;===========================================================================================================================

[Help]
Meter=Shape
MeterStyle=PageBox
Fill=Fill Color 255,255,255,(#BarHandler# = 11 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 11 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 11 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
[FAQ]
Meter=Shape
MeterStyle=PageBox
Fill=Fill Color 255,255,255,(#BarHandler# = 12 ? 220 : 0)
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 12 ? 220 : 100)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color 255,255,255,(#BarHandler# = 12 ? 220 : 0)"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[HelpIcon]
Meter=Image
X=(#setTP#*1.5)
Y=(#SetH#-100+#SetTP#*2)
MeterStyle=PageIcon
Greyscale=(#BarHandler# = 11 ? 1 : 0)
ImageTint=(#BarHandler# = 11 ? 0 : 255),(#BarHandler# = 11 ? 0 : 255),(#BarHandler# = 11 ? 0 : 255)
[FAQIcon]
Meter=Image
MeterStyle=PageIcon
Greyscale=(#BarHandler# = 12 ? 1 : 0)
ImageTint=(#BarHandler# = 12 ? 0 : 255),(#BarHandler# = 12 ? 0 : 255),(#BarHandler# = 12 ? 0 : 255)

[11]
Meter=String
Text=Help
X=(#setTP#*1.5+24+5)
Y=([HelpIcon:Y]+24/2)
DynamicVariables-1
MeterStyle=sString | PageText
[12]
Meter=String
Text=FAQ
MeterStyle=sString | PageText


[ContentContainer]
Meter=Shape
X=#SetL#
Y=#SetTP#
Shape=Rectangle (0),(0),(#SetW#-#SetL#-#SetTP#),(#SetH#),(#SetR#/2),(#SetR#/2) | StrokeWidth 0 | Fill Color 255,255,255
[Dumy]
Meter=String
Container=ContentContainer

[Esc]
Meter=Shape
Shape=Ellipse (#SetW#-15),(15),5,5 | StrokeWidth 10 | StrokeColor 0,0,0,1 | Extend FillE
FillE=Fill Color 255,255,255,50
MouseOverAction=[!SetOption Esc FillE "Fill Color 255,255,255"][!UpdateMeter Esc][!Redraw]
MouseLeaveAction=[!SetOption Esc FillE "Fill Color 255,255,255,50"][!UpdateMeter Esc][!Redraw]
LeftMouseUpAction=[!DeactivateConfig][!DeactivateConfig "ModularPlayers\@Settings\Components"][!ActivateConfig "ModularPlayers\Main"]