[Rainmeter]
; SolidColor=255,255,255,25
; BackgroundMode=2
SkinWidth=#SW#
SkinHeight=#SH#

[Variables]
@includeWeather=#@#Includes\GlobalWeather.inc
SW=(500*#Scale#)
SH=(500*#Scale#)

[mTime]
Measure=Time
Format=%#2412##Seperator#%M
RegexpSubstitute=1
Substitute="^0":""
[mDate]
Measure=Time
Format=%A, %B %d

[Time]
Meter=String
MeasureName=mTime
FontFace=MetroPolis Semi Bold
FontSize=(70*#scale#)
MeterStyle=S | Time#Align#

[WeatherIcon]
Meter=Image
Y=R
W=(50*#Scale#*#Weather#)
H=(50*#Scale#*#Weather#)
ImageName=#@#Icons\JD Weather Icons\[mCurrentIcon].png
DynamicVariables=1
MeterStyle=Wea#Align#

[WeatherText]
Meter=String
MeterStyle=S | WeaText#Align#
Y=(50/2*#Scale#)r
FontSize=(20*#Scale#*#Weather#)
Text=%1%2
FontFace=MetroPolis Semi Bold
MeasureName=mCurrentTemperature
Measurename2=mUnitsTemperature

[DateText]
Meter=String
MeterStyle=S | Time#Align#
Y=R
FontSize=(#DateTimeRatio#*100*#Scale#*#date#)
Text=%1
FontFace=MetroPolis Semi Bold
MeasureName=mDate
DynamicVariables=1

;====================================================================================

[TimeLeft]
X=0
StringAlign=Left
[Timecenter]
X=(#SW#/2)
StringAlign=Center
[TimeRight]
X=#SW#
StringAlign=Right

[WeaLeft]
X=0
[WeaCenter]
X=(-([WeatherText:W]+50)/2*#Scale#+#CURRENTCONFIGWIDTH#/2)
[WeaRight]
X=(#SW#-[#CURRENTSECTION#:W])

[WeaTextLeft]
X=5R
StringAlign=LeftCenter
[WeaTextcenter]
X=5R
StringAlign=LeftCenter
[WeaTextRight]
X=-5r
StringAlign=RightCenter